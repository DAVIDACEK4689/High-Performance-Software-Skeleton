#ifndef dcnncombined_hpp_
#define dcnncombined_hpp_

#include "dcnnelements.hpp"
#include "dcnnbinfile.hpp"

/// @cond INTERNAL
namespace dcnnsol {
	template< typename SP, typename PP>
	struct first_normalize_layer;

	template< typename SPI, typename SPO, typename KSP, typename PP>
	struct deep_cnn_layer;

	template< typename SP, typename PP>
	struct deep_normalize_layer;

	template< typename SP, typename PP>
	struct deep_linear_layer;

	template< typename SP, typename PP>
	struct deep_relu_layer;

	template< typename SPI, typename SPO, typename PP>
	struct deep_maxpool_layer;

	template< typename SPI, typename CSPO, typename PP>
	struct aggregate_cnn_layer;

	template< typename CSP, typename PP>
	struct final_linear_layer;

	template< typename CSP, typename PP>
	struct loss_layer;
}
/// @endcond

namespace dcnnasgn {

	/// @addtogroup config 
	/// 
	/// @{

	/// <summary>
	/// Number of categories (digits)
	/// </summary>
	inline constexpr std::size_t LABELS = 10;

	/// <summary>
	/// Policy: Input image size
	/// </summary>
	struct large_image : image_size_policy< 28, 28> {};
	/// <summary>
	/// Policy: Image after the first MaxPool layer
	/// </summary>
	struct medium_image : image_size_policy< 14, 14> {};
	/// <summary>
	/// Policy: Image after the second MaxPool layer
	/// </summary>
	struct small_image : image_size_policy< 7, 7> {};

	/// <summary>
	/// Policy: Input image channels
	/// </summary>
	struct monochrome_channel : channel_size_policy<1> {};
	/// <summary>
	/// Policy: Internal activation channels
	/// </summary>
	struct internal_channel : channel_size_policy<8> {};
	/// <summary>
	/// Policy: Final linear layer channels
	/// </summary>
	struct labels_channel : channel_size_policy<LABELS> {};

	/// <summary>
	/// Policy: Convolution kernel size
	/// </summary>
	struct standard_kernel : convolution_kernel_size_policy< 3, 3> {};

	/// @}

	/// @addtogroup completelayer 
	/// 
	/// @{

	/// <summary>
	/// Model data of a complete layer
	/// </summary>
	template< typename CSPI, typename CSPO, typename KSP, typename PP>
	class complete_cnn_model {
	public:
		using model_c = dcnnsol::deep_weights< KSP, CSPI, CSPO, PP>;
		using model_b = dcnnsol::deep_bias< CSPO, PP>;

		model_c c;
		model_b b;
	};

	/// <summary>
	/// Back-propagated gradients for the model data of a complete layer
	/// </summary>
	template< typename CSPI, typename CSPO, typename KSP, typename PP>
	class backward_complete_cnn_model {
	public:
		using model_c = dcnnsol::backward_deep_weights< KSP, CSPI, CSPO, PP>;
		using model_b = dcnnsol::backward_deep_bias< CSPO, PP>;

		model_c c;
		model_b b;
	};

	/// <summary>
	/// Internal activation and normalization-state data of a complete layer
	/// </summary>
	template< typename SPI, typename SPO, typename PP>
	struct complete_cnn_internal {
	private:
		using CSPI = typename SPI::channel_policy;
		using CSPO = typename SPO::channel_policy;
	public:
		using data_c = dcnnsol::deep_data< SPO, PP>;
		using internal_n = deep_stat< CSPO>;
		using data_n = dcnnsol::deep_data< SPO, PP>;
		using data_b = dcnnsol::deep_data< SPO, PP>;

		data_c c;
		internal_n in;
		data_n n;
		data_b b;

		complete_cnn_internal(const batch_range& nr)
			: c(nr), n(nr), b(nr)
		{}
	};

	/// <summary>
	/// Internal back-propagation data of a complete layer
	/// </summary>
	template< typename SPI, typename SPO, typename KSP, typename PP>
	struct backward_complete_cnn_internal {
	private:
		using CSPI = typename SPI::channel_policy;
		using CSPO = typename SPO::channel_policy;
	public:
		using internal_c = dcnnsol::backward_deep_internal< KSP, CSPI, CSPO, PP>;
		using data_c = dcnnsol::backward_deep_data< SPO, PP>;
		using data_n = dcnnsol::backward_deep_data< SPO, PP>;
		using data_b = dcnnsol::backward_deep_data< SPO, PP>;

		internal_c ic;
		data_c c;
		data_n n;
		data_b b;

		backward_complete_cnn_internal(const batch_range& nr)
			: ic(nr), c(nr), n(nr), b(nr)
		{}
	};

	/// <summary>
	/// A complete layer
	/// 
	/// Combined from a convolution, normalization, linear (bias) and ReLU layers
	/// </summary>
	template< typename SPI, typename SPO, typename KSP, typename PP>
	struct complete_cnn_layer {
	private:
		using CSPI = typename SPI::channel_policy;
		using CSPO = typename SPO::channel_policy;
	public:
		using layer_c = dcnnsol::deep_cnn_layer< SPI, SPO, KSP, PP>;
		using layer_n = dcnnsol::deep_normalize_layer< SPO, PP>;
		using layer_b = dcnnsol::deep_linear_layer< SPO, PP>;
		using layer_r = dcnnsol::deep_relu_layer< SPO, PP>;

		using input_data = dcnnsol::deep_data< SPI, PP>;
		using model = complete_cnn_model< CSPI, CSPO, KSP, PP>;
		using internal_data = complete_cnn_internal< SPI, SPO, PP>;
		using output_data = dcnnsol::deep_data< SPO, PP>;

		using backward_output_data = dcnnsol::backward_deep_data< SPO, PP>;
		using backward_internal_data = backward_complete_cnn_internal< SPI, SPO, KSP, PP>;
		using backward_model = backward_complete_cnn_model< CSPI, CSPO, KSP, PP>;
		using backward_input_data = dcnnsol::backward_deep_data< SPI, PP>;

		static void init_forward(model& md, std::mt19937_64& engine)
		{
			layer_c::init_forward(md.c, engine, 1.0f);
			layer_b::init_forward(md.b, 0.0f);
		}

		static void init_backward(backward_model& bmd, float summary_backprop_variance)
		{
			layer_c::init_backward(bmd.c, summary_backprop_variance);
			layer_b::init_backward(bmd.b, summary_backprop_variance);
		}

		static void forward(const input_data& ind, const model& md, internal_data& td, output_data& outd)
		{
			layer_c::forward(ind, md.c, td.c);
			layer_n::forward(td.c, td.in, td.n);
			layer_b::forward(td.n, md.b, td.b);
			layer_r::forward(td.b, outd);
		}

		static void backward(const input_data& ind, const model& md, const internal_data& td, const backward_output_data& boutd, backward_model& bmd, backward_internal_data& btd, backward_input_data& bind)
		{
			layer_r::backward(td.b, boutd, btd.b);
			layer_b::backward(btd.b, bmd.b, btd.n);
			layer_n::backward(td.in, td.n, btd.n, btd.c);
			layer_c::backward(ind, md.c, btd.c, bmd.c, btd.ic, bind);
		}

		static void learn(const backward_model& bmd, model& md, float rate)
		{
			layer_c::learn(bmd.c, md.c, rate);
			layer_b::learn(bmd.b, md.b, rate);
		}

		/// @cond INTERNAL
		static std::size_t forward_complexity(const batch_range& br)
		{
			std::size_t s = 0;
			s += layer_c::forward_complexity(br);
			s += layer_n::forward_complexity(br);
			s += layer_b::forward_complexity(br);
			s += layer_r::forward_complexity(br);
			return s;
		}

		static std::size_t backward_complexity(const batch_range& br)
		{
			std::size_t s = 0;
			s += layer_r::backward_complexity(br);
			s += layer_b::backward_complexity(br);
			s += layer_n::backward_complexity(br);
			s += layer_c::backward_complexity(br);
			return s;
		}
		/// @endcond 
	};

	/// @}

	/// @addtogroup config
	/// 
	/// @{

	using idp = input_data_policy< large_image>;

	struct first_large_data : deep_data_size_policy< large_image, monochrome_channel> {};
	struct large_data : deep_data_size_policy< large_image, internal_channel> {};
	struct medium_data : deep_data_size_policy< medium_image, internal_channel> {};
	struct small_data : deep_data_size_policy< small_image, internal_channel> {};

	/// @}

	/// @addtogroup network 
	/// 
	/// @{

	/// <summary>
	/// Policy: The complete network
	/// 
	/// Initial normalization, two pairs of complete layers followed by MaxPool layers, 
	/// the final aggregate and linear layers, and the loss layer.
	/// </summary>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename PP>
	struct combined_policy
	{
		using layer_0n = dcnnsol::first_normalize_layer< first_large_data, PP>;
		using layer_1 = complete_cnn_layer< first_large_data, large_data, standard_kernel, PP>;
		using layer_2 = complete_cnn_layer< large_data, large_data, standard_kernel, PP>;
		using layer_2m = dcnnsol::deep_maxpool_layer< large_data, medium_data, PP>;
		using layer_3 = complete_cnn_layer< medium_data, medium_data, standard_kernel, PP>;
		using layer_4 = complete_cnn_layer< medium_data, medium_data, standard_kernel, PP>;
		using layer_4m = dcnnsol::deep_maxpool_layer< medium_data, small_data, PP>;
		using layer_5c = dcnnsol::aggregate_cnn_layer< small_data, labels_channel, PP>;
		using layer_5b = dcnnsol::final_linear_layer< labels_channel, PP>;
		using loss = dcnnsol::loss_layer<labels_channel, PP>;
	};

	/// <summary>
	/// Model data (weights and biases) of the complete network
	/// </summary>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename PP>
	class combined_model {
	public:
		using policy = combined_policy< PP>;

		using model_1 = typename policy::layer_1::model;
		using model_2 = typename policy::layer_2::model;
		using model_3 = typename policy::layer_3::model;
		using model_4 = typename policy::layer_4::model;
		using model_5c = dcnnsol::deep_weights< as_kernel<small_image>, internal_channel, labels_channel, PP>;
		using model_5b = dcnnsol::deep_bias< labels_channel, PP>;

		model_1 m_1;
		model_2 m_2;
		model_3 m_3;
		model_4 m_4;
		model_5c m_5c;
		model_5b m_5b;
	};

	/// <summary>
	/// Model gradients of the complete network
	/// </summary>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename PP>
	class backward_combined_model {
	public:
		using policy = combined_policy< PP>;

		using bmodel_1 = typename policy::layer_1::backward_model;
		using bmodel_2 = typename policy::layer_2::backward_model;
		using bmodel_3 = typename policy::layer_3::backward_model;
		using bmodel_4 = typename policy::layer_4::backward_model;
		using bmodel_5c = dcnnsol::backward_deep_weights< as_kernel<small_image>, internal_channel, labels_channel, PP>;
		using bmodel_5b = dcnnsol::backward_deep_bias< labels_channel, PP>;

		bmodel_1 bm_1;
		bmodel_2 bm_2;
		bmodel_3 bm_3;
		bmodel_4 bm_4;
		bmodel_5c bm_5c;
		bmodel_5b bm_5b;
	};

	/// <summary>
	/// Input data, forward-propagated activations, and loss of the complete network
	/// </summary>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename PP>
	class combined_data {
	public:
		using policy = combined_policy< PP>;

		using data_0 = batch_data< large_image>;
		using internal_0n = first_stat;
		using data_0n = dcnnsol::deep_data< first_large_data, PP>;
		using internal_1 = typename policy::layer_1::internal_data;
		using data_1r = dcnnsol::deep_data< large_data, PP>;
		using internal_2 = typename policy::layer_2::internal_data;
		using data_2r = dcnnsol::deep_data< large_data, PP>;
		using data_2m = dcnnsol::deep_data< medium_data, PP>;
		using internal_3 = typename policy::layer_3::internal_data;
		using data_3r = typename policy::layer_3::output_data;
		using internal_4 = typename policy::layer_4::internal_data;
		using data_4r = dcnnsol::deep_data< medium_data, PP>;
		using data_4m = dcnnsol::deep_data< small_data, PP>;
		using data_5c = dcnnsol::linear_data< labels_channel, PP>;
		using data_5b = dcnnsol::linear_data< labels_channel, PP>;

		gold_data g;
		data_0 d_0;

		data_0n d_0n;
		data_1r d_1r;
		data_2r d_2r;
		data_2m d_2m;
		data_3r d_3r;
		data_4r d_4r;
		data_4m d_4m;
		data_5c d_5c;
		data_5b d_5b;

		internal_0n i_0n;
		internal_1 i_1;
		internal_2 i_2;
		internal_3 i_3;
		internal_4 i_4;

		loss_data d_loss;

		combined_data(const batch_range& br)
			: g(br),
			d_0(br),
			d_0n(br),
			d_1r(br),
			d_2r(br),
			d_2m(br),
			d_3r(br),
			d_4r(br),
			d_4m(br),
			d_5c(br),
			d_5b(br),
			i_1(br),
			i_2(br),
			i_3(br),
			i_4(br),
			d_loss(br)
		{}
	};

	/// <summary>
	/// Backward-propagated gradients of the complete network
	/// </summary>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename PP>
	class backward_combined_data {
	public:
		using policy = combined_policy< PP>;

		using bdata_0n = dcnnsol::backward_deep_data< first_large_data, PP>;
		using binternal_1 = typename policy::layer_1::backward_internal_data;
		using bdata_1r = dcnnsol::backward_deep_data< large_data, PP>;
		using binternal_2 = typename policy::layer_2::backward_internal_data;
		using bdata_2r = dcnnsol::backward_deep_data< large_data, PP>;
		using bdata_2m = dcnnsol::backward_deep_data< medium_data, PP>;
		using binternal_3 = typename policy::layer_3::backward_internal_data;
		using bdata_3r = typename policy::layer_3::backward_output_data;
		using binternal_4 = typename policy::layer_4::backward_internal_data;
		using bdata_4r = dcnnsol::backward_deep_data< medium_data, PP>;
		using bdata_4m = dcnnsol::backward_deep_data< small_data, PP>;
		using binternal_5c = dcnnsol::backward_deep_internal< as_kernel<small_image>, internal_channel, labels_channel, PP>;
		using bdata_5c = dcnnsol::backward_linear_data< labels_channel, PP>;
		using layer_5b = dcnnsol::final_linear_layer< labels_channel, PP>;
		using bdata_5b = dcnnsol::backward_linear_data< labels_channel, PP>;

		binternal_1 bi_1;
		binternal_2 bi_2;
		binternal_3 bi_3;
		binternal_4 bi_4;
		binternal_5c bi_5c;

		bdata_0n bd_0n;
		bdata_1r bd_1r;
		bdata_2r bd_2r;
		bdata_2m bd_2m;
		bdata_3r bd_3r;
		bdata_4r bd_4r;
		bdata_4m bd_4m;
		bdata_5c bd_5c;
		bdata_5b bd_5b;

		backward_combined_data(const batch_range& br)
			: bi_1(br),
			bi_2(br),
			bi_3(br),
			bi_4(br),
			bi_5c(br),
			bd_0n(br),
			bd_1r(br),
			bd_2r(br),
			bd_2m(br),
			bd_3r(br),
			bd_4r(br),
			bd_4m(br),
			bd_5c(br),
			bd_5b(br)
		{}
	};

	using train_labels_t = tagged::tensor_class<std::uint8_t, input_tag>;
	using train_images_t = tagged::tensor_class<std::uint8_t, input_tag, idp::height_tag, idp::width_tag>;

	/// <summary>
	/// Random initialization of the model of the complete network
	/// </summary>
	/// <typeparam name="PP">Permutation policy</typeparam>
	/// <param name="m">Model</param>
	/// <param name="eng">Random engine</param>
	/// <param name="final_expected_multiplier">Expected statistical property</param>
	template< typename PP>
	inline void combined_init_forward(combined_model< PP>& m, std::mt19937_64& eng, float final_expected_multiplier)
	{
		using policy = combined_policy< PP>;

		policy::layer_1::init_forward(m.m_1, eng);
		policy::layer_2::init_forward(m.m_2, eng);
		policy::layer_3::init_forward(m.m_3, eng);
		policy::layer_4::init_forward(m.m_4, eng);
		policy::layer_5c::init_forward(m.m_5c, eng, final_expected_multiplier);
		policy::layer_5b::init_forward(m.m_5b, 1.0f / LABELS);
	}

	/// <summary>
	/// Initialization of internal/statistic data of the complete network
	/// </summary>
	/// <typeparam name="PP"></typeparam>
	/// <param name="bm"></param>
	/// <param name="final_summary_backprop_variance"></param>
	/// <param name="internal_summary_backprop_variance"></param>
	template< typename PP>
	inline void combined_init_backward(backward_combined_model< PP>& bm, float final_summary_backprop_variance, float internal_summary_backprop_variance)
	{
		using policy = combined_policy< PP>;

		policy::layer_5b::init_backward(bm.bm_5b, final_summary_backprop_variance);
		policy::layer_5c::init_backward(bm.bm_5c, final_summary_backprop_variance);
		policy::layer_4::init_backward(bm.bm_4, internal_summary_backprop_variance);
		policy::layer_3::init_backward(bm.bm_3, internal_summary_backprop_variance);
		policy::layer_2::init_backward(bm.bm_2, internal_summary_backprop_variance);
		policy::layer_1::init_backward(bm.bm_1, internal_summary_backprop_variance);
	}

	/// <summary>
	/// The forward-propagation function of the complete network
	/// 
	/// Includes creation of a minibatch by 
	/// selection of the specified input images from the training dataset
	/// </summary>
	/// <typeparam name="mapping">Input selection mapping</typeparam>
	/// <typeparam name="PP">Permutation policy</typeparam>
	/// <param name="train_images">Training image dataset</param>
	/// <param name="train_labels">Ground-truth dataset</param>
	/// <param name="bmap">Input selection mapping</param>
	/// <param name="m">Network model data</param>
	/// <param name="d">Forward-propagation data</param>
	/// <returns>Total loss over the minibatch</returns>
	template< typename mapping, typename PP>
	inline float combined_forward(const train_images_t& train_images, const train_labels_t& train_labels, mapping&& bmap, const combined_model< PP>& m, combined_data< PP>& d)
	{
		using policy = combined_policy< PP>;

		d.g.init(train_labels, bmap);
		d.d_0.init(train_images, bmap);

		policy::layer_0n::forward(d.d_0, d.i_0n, d.d_0n);

		policy::layer_1::forward(d.d_0n, m.m_1, d.i_1, d.d_1r);

		policy::layer_2::forward(d.d_1r, m.m_2, d.i_2, d.d_2r);
		policy::layer_2m::forward(d.d_2r, d.d_2m);

		policy::layer_3::forward(d.d_2m, m.m_3, d.i_3, d.d_3r);

		policy::layer_4::forward(d.d_3r, m.m_4, d.i_4, d.d_4r);
		policy::layer_4m::forward(d.d_4r, d.d_4m);

		policy::layer_5c::forward(d.d_4m, m.m_5c, d.d_5c);
		policy::layer_5b::forward(d.d_5c, m.m_5b, d.d_5b);

		policy::loss::forward(d.d_5b, d.g, d.d_loss);

		float total_loss = 0.0f;
		for (auto x : d.d_loss.loss.range())
		{
			total_loss += d.d_loss.loss[x];
		}

		return total_loss;
	}

	/// <summary>
	/// The backward-propagation function of the complete network
	/// </summary>
	/// <typeparam name="PP">Permutation policy</typeparam>
	/// <param name="m">Network model data</param>
	/// <param name="d">Forward-propagation data</param>
	/// <param name="bm">Backward-propagated model gradients</param>
	/// <param name="bd">Backward-propagation data</param>
	template< typename PP>
	inline void combined_backward(const combined_model< PP>& m, const combined_data< PP>& d, backward_combined_model< PP>& bm, backward_combined_data<PP>& bd)
	{
		using policy = combined_policy< PP>;

		policy::loss::backward(d.d_5b, d.g, bd.bd_5b);

		policy::layer_5b::backward(bd.bd_5b, bm.bm_5b, bd.bd_5c);
		policy::layer_5c::backward(d.d_4m, m.m_5c, bd.bd_5c, bm.bm_5c, bd.bi_5c, bd.bd_4m);

		policy::layer_4m::backward(d.d_4r, d.d_4m, bd.bd_4m, bd.bd_4r);

		policy::layer_4::backward(d.d_3r, m.m_4, d.i_4, bd.bd_4r, bm.bm_4, bd.bi_4, bd.bd_3r);

		policy::layer_3::backward(d.d_2m, m.m_3, d.i_3, bd.bd_3r, bm.bm_3, bd.bi_3, bd.bd_2m);

		policy::layer_2m::backward(d.d_2r, d.d_2m, bd.bd_2m, bd.bd_2r);

		policy::layer_2::backward(d.d_1r, m.m_2, d.i_2, bd.bd_2r, bm.bm_2, bd.bi_2, bd.bd_1r);

		policy::layer_1::backward(d.d_0n, m.m_1, d.i_1, bd.bd_1r, bm.bm_1, bd.bi_1, bd.bd_0n);
	}

	/// <summary>
	/// The learn function of the complete network
	/// </summary>
	/// <typeparam name="PP">Permutation policy</typeparam>
	/// <param name="bm">Backward-propagated model gradients</param>
	/// <param name="m">Network model data</param>
	/// <param name="rate">Learning rate</param>
	template< typename PP>
	inline void combined_learn(const backward_combined_model<PP>& bm, combined_model<PP>& m, float rate)
	{
		using policy = combined_policy< PP>;

		policy::layer_1::learn(bm.bm_1, m.m_1, rate);
		policy::layer_2::learn(bm.bm_2, m.m_2, rate);
		policy::layer_3::learn(bm.bm_3, m.m_3, rate);
		policy::layer_4::learn(bm.bm_4, m.m_4, rate);
		policy::layer_5c::learn(bm.bm_5c, m.m_5c, rate);
		policy::layer_5b::learn(bm.bm_5b, m.m_5b, rate);
	}

	/// @cond INTERNAL
	template< typename PP>
	inline std::size_t combined_forward_complexity(const batch_range & br)
	{
		using policy = combined_policy< PP>;
		std::size_t s = 0;

		s += policy::layer_0n::forward_complexity(br);

		s += policy::layer_1::forward_complexity(br);

		s += policy::layer_2::forward_complexity(br);
		s += policy::layer_2m::forward_complexity(br);

		s += policy::layer_3::forward_complexity(br);

		s += policy::layer_4::forward_complexity(br);
		s += policy::layer_4m::forward_complexity(br);

		s += policy::layer_5c::forward_complexity(br);
		s += policy::layer_5b::forward_complexity(br);

		s += policy::loss::forward_complexity(br);

		return s;
	}

	template< typename PP>
	inline std::size_t combined_backward_complexity(const batch_range & br)
	{
		using policy = combined_policy< PP>;
		std::size_t s = 0;

		s += policy::loss::backward_complexity(br);

		policy::layer_5b::backward_complexity(br);
		policy::layer_5c::backward_complexity(br);

		policy::layer_4m::backward_complexity(br);

		policy::layer_4::backward_complexity(br);

		policy::layer_3::backward_complexity(br);

		policy::layer_2m::backward_complexity(br);

		policy::layer_2::backward_complexity(br);

		policy::layer_1::backward_complexity(br);

		return s;
	}
	/// @endcond

	/// @}

	/// @addtogroup execution 
	/// 
	/// @{

	/// <summary>
	/// The global state, shared by all threads
	/// 
	/// Includes the training dataset, network model and meta-parameters
	/// </summary>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename PP>
	class global_state {
	public:
		train_labels_t train_labels;
		train_images_t train_images;
		combined_model<PP> m;
		float final_expected_multiplier;
		float final_summary_backprop_variance;
		float internal_summary_backprop_variance;
		float rate;
		batch_range br;

		global_state(std::size_t batch_size)
			: final_expected_multiplier(std::sqrt(LABELS - 1.0f) / LABELS),
			final_summary_backprop_variance((LABELS - 1.0f) / LABELS),
			internal_summary_backprop_variance(final_summary_backprop_variance* final_expected_multiplier* final_expected_multiplier),
			rate(0.125f),
			br(batch_size)
		{}

		void read_data(const std::filesystem::path data_folder)
		{
			train_labels = load_data<std::uint8_t, input_tag>(data_folder / "train-labels.idx1-ubyte");
			train_images = load_data<std::uint8_t, input_tag, idp::height_tag, idp::width_tag>(data_folder / "train-images.idx3-ubyte");
		}

		void init(std::mt19937_64& eng)
		{
			combined_init_forward(m, eng, final_expected_multiplier);
		}
	};

	/// <summary>
	/// The thread-related state
	/// 
	/// Includes network state related to a minibatch
	/// </summary>
	/// <typeparam name="PP"></typeparam>
	template< typename PP>
	class thread_state {
	public:
		batch_mapping bmap;
		backward_combined_model<PP> bm;
		combined_data<PP> d;
		backward_combined_data<PP> bd;
		float loss;

		thread_state(const global_state<PP>& gs)
			: bmap(gs.br), d(gs.br), bd(gs.br), loss(0.0f)
		{
			combined_init_backward(bm, gs.final_summary_backprop_variance, gs.internal_summary_backprop_variance);
		}

		template< typename IIG>
		void minibatch_init(IIG&& input_index_generator)
		{
			for (auto b : bmap.range())
			{
				auto i = input_index_generator();
				bmap[b] = i;
			}
		}

		void minibatch_run(const global_state<PP>& gs)
		{
			loss = combined_forward(gs.train_images, gs.train_labels, bmap, gs.m, d);

			combined_backward(gs.m, d, bm, bd);
		}

		void minibatch_collect(global_state<PP>& gs)
		{
			combined_learn(bm, gs.m, gs.rate);
		}

		std::size_t minibatch_run_complexity(const global_state<PP>&)
		{
			auto fc = combined_forward_complexity<PP>(bmap.range());
			auto bc = combined_backward_complexity<PP>(bmap.range());
			return fc + bc;
		}

	};
	/// @}
}

#endif
