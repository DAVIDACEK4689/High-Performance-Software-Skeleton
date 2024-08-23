#ifndef dcnnelements_hpp_
#define dcnnelements_hpp_

#include "tagged.hpp"

#include <cassert>
#include <random>
#include <cmath>

/// @cond INTERNAL
namespace dcnnsol {

	template< typename SP, typename PP>
	class deep_data;

	template< typename SP, typename PP>
	class backward_deep_data;

	template< typename CSP, typename PP>
	class linear_data;

	template< typename CSP, typename PP>
	class backward_linear_data;

	template< typename KSP, typename CSPI, typename CSPO, typename PP>
	class deep_weights;

	template< typename KSP, typename CSPI, typename CSPO, typename PP>
	class backward_deep_weights;

	template< typename KSP, typename CSPI, typename CSPO, typename PP>
	class backward_deep_internal;

	template< typename CSP, typename PP>
	class deep_bias;

	template< typename CSP, typename PP>
	class backward_deep_bias;
}
/// @endcond

namespace dcnnasgn {

	/// @addtogroup tags
	/// 
	/// @{

	/// @cond INTERNAL
	struct input_tag : tagged::tag_base {};
	using input_range = tagged::range_class< input_tag>;
	using input_index = tagged::index_class< input_tag>;
	/// @endcond

	/// <summary>
	/// Tag: Images within a minibatch
	/// </summary>
	struct batch_tag : tagged::tag_base {};

	/// @}

	/// @addtogroup config
	/// 
	/// @{

	/// <summary>
	/// The range of images within a minibatch
	/// </summary>
	using batch_range = tagged::range_class< batch_tag>;

	/// @}

	/// @addtogroup tags
	/// 
	/// @{

	/// <summary>
	/// Tag: Height dimension of an image
	/// </summary>
	struct height_selector : tagged::tag_base {};
	/// <summary>
	/// Tag: Width dimension of an image
	/// </summary>
	struct width_selector : tagged::tag_base {};

	/// @cond INTERNAL
	template< std::size_t H>
	struct height_stag : tagged::sr_tag<height_selector, 0, H> {};

	template< std::size_t W>
	struct width_stag : tagged::sr_tag<width_selector, 0, W> {};
	/// @endcond

	/// @}

	/// @addtogroup sizing 
	/// 
	/// @{

	/// <summary>
	/// Image size policy
	/// </summary>
	/// <typeparam name="H">Image height</typeparam>
	/// <typeparam name="W">Image width</typeparam>
	template< std::size_t H, std::size_t W>
	struct image_size_policy {
		/// <summary>
		/// Tag: Height dimension of an image, statically sized
		/// </summary>
		using height_tag = height_stag<H>;
		/// <summary>
		/// Tag: Width dimension of an image, statically sized
		/// </summary>
		using width_tag = width_stag<W>;

		/// <summary>
		/// Height range of an image, statically sized
		/// </summary>
		inline static constexpr tagged::range_class< height_tag> hr{ H };
		/// <summary>
		/// Width range of an image, statically sized
		/// </summary>
		inline static constexpr tagged::range_class< width_tag> wr{ W };
	};

	/// @}

	/// @addtogroup tags
	/// 
	/// @{

	/// <summary>
	/// Tag: Channel dimension
	/// </summary>
	struct channel_selector : tagged::tag_base {};

	/// @cond INTERNAL
	template< std::size_t C>
	struct channel_stag : tagged::sr_tag<channel_selector, 0, C> {};
	/// @endcond

	/// <summary>
	/// Tag: Kernel height dimension
	/// 
	/// The height dimension of a convolution or aggregate layer,
	/// i.e. the height dimension of the associated weight matrix 
	/// </summary>
	struct kernel_height_selector : tagged::tag_base {};
	/// <summary>
	/// Tag: Kernel width dimension
	/// 
	/// The width dimension of a convolution or aggregate layer,
	/// i.e. the width dimension of the associated weight matrix 
	/// </summary>
	struct kernel_width_selector : tagged::tag_base {};

	/// @}

	/// @addtogroup sizing
	/// 
	/// @{

	/// @cond INTERNAL
	using batch_mapping = tagged::tensor_class< input_index, batch_tag>;

	template< typename ISP>
	struct input_data_policy : ISP {
		using typename ISP::height_tag;
		using typename ISP::width_tag;

		using ISP::hr;
		using ISP::wr;

		using images_t = tagged::tensor_class< std::uint8_t, input_tag, height_tag, width_tag>;
		using batch_t = tagged::tensor_class< std::uint8_t, batch_tag, height_tag, width_tag>;
	};

	template< typename ISP>
	class input_data {
	public:
		using policy = input_data_policy< ISP>;
		input_data(const input_range& inr) : images(inr& policy::hr& policy::wr) {}
		policy::images_t images;
	};

	template< typename ISP>
	class batch_data {
	public:
		using policy = input_data_policy< ISP>;

		using height_tag = typename policy::height_tag;
		using width_tag = typename policy::width_tag;

		batch_data(const batch_range& nr) : images(nr& policy::hr& policy::wr) {}
		typename policy::batch_t images;
		void init(const typename policy::images_t& ind, const input_range& inr)
		{
			auto hr = policy::hr;
			auto wr = policy::wr;

			assert(ind.range().template get<height_tag>() == hr);
			assert(ind.range().template get<width_tag>() == wr);

			assert(images.range().template get<height_tag>() == hr);
			assert(images.range().template get<width_tag>() == wr);

			assert(images.range().template get<batch_tag>().size() == inr.size());

			auto inrb = (*inr.begin()).value();
			for (auto i : inr)
			{
				tagged::index_class<batch_tag> b(i.value() - inrb);
				for (auto h : hr)
				{
					for (auto w : wr)
					{
						images[b & h & w] = ind[i & h & w];
					}
				}
			}
		}
		void init(const typename policy::images_t& ind, const batch_mapping& bmap)
		{
			auto hr = policy::hr;
			auto wr = policy::wr;

			assert(ind.range().template get<height_tag>() == hr);
			assert(ind.range().template get<width_tag>() == wr);

			assert(images.range().template get<height_tag>() == hr);
			assert(images.range().template get<width_tag>() == wr);

			assert(images.range().template get<batch_tag>() == bmap.range().get<batch_tag>());

			for (auto b : bmap.range())
			{
				auto i = bmap[b];
				for (auto h : hr)
				{
					for (auto w : wr)
					{
						images[b & h & w] = ind[i & h & w];
					}
				}
			}
		}
	};

	struct gold_labels_policy {
		using labels_t = tagged::tensor_class< std::uint8_t, input_tag>;
		using batch_t = tagged::tensor_class< std::uint8_t, batch_tag>;
	};

	class gold_labels {
	public:
		using policy = gold_labels_policy;
		gold_labels(const input_range& inr) : labels(inr) {}
		policy::labels_t labels;
	};

	class gold_data {
	public:
		using policy = gold_labels_policy;
		gold_data(const batch_range& nr) : labels(nr) {}
		policy::batch_t labels;
		void init(const policy::labels_t& ind, const input_range& inr)
		{
			assert(labels.range().get<batch_tag>().size() == inr.size());

			auto inrb = (*inr.begin()).value();
			for (auto i : inr)
			{
				tagged::index_class<batch_tag> b(i.value() - inrb);
				labels[b] = ind[i];
			}
		}
		void init(const policy::labels_t& ind, const batch_mapping& bmap)
		{
			assert(labels.range().get<batch_tag>().size() == bmap.range().size());

			for (auto b : bmap.range())
			{
				auto i = bmap[b];
				labels[b] = ind[i];
			}
		}
	};
	/// @endcond

	/// @}

	/// @addtogroup sizing
	/// 
	/// @{

	/// <summary>
	/// Channel size policy
	/// </summary>
	/// <typeparam name="C">Number of channels</typeparam>
	template< std::size_t C>
	struct channel_size_policy {
		/// <summary>
		/// Tag: The channel dimension, statically sized
		/// </summary>
		using channel_tag = channel_stag<C>;

		/// <summary>
		/// Channel index range, statically sized
		/// </summary>
		inline static constexpr tagged::range_class< channel_tag> cr{ C };
	};

	/// <summary>
	/// Combined image and channel size policy
	/// </summary>
	/// <typeparam name="ISP">Image size policy</typeparam>
	/// <typeparam name="CSP">Channel size policy</typeparam>
	template< typename ISP, typename CSP>
	struct deep_data_size_policy : ISP, CSP {
		/// <summary>
		/// Image size policy
		/// </summary>
		using image_policy = ISP;
		/// <summary>
		/// Channel size policy
		/// </summary>
		using channel_policy = CSP;
	};

	/// <summary>
	/// Internal layer activation data policy
	/// </summary>
	/// <typeparam name="SP">Sizing policy</typeparam>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename SP, typename PP>
	struct deep_data_policy : SP {
		/// <summary>
		/// Tag: Image height dimension, statically sized
		/// </summary>
		using typename SP::height_tag;
		/// <summary>
		/// Tag: Image width dimension, statically sized
		/// </summary>
		using typename SP::width_tag;
		/// <summary>
		/// Tag: Channel index, statically sized
		/// </summary>
		using typename SP::channel_tag;

		/// <summary>
		/// Image height range, statically sized
		/// </summary>
		inline static constexpr auto hr = SP::hr;
		/// <summary>
		/// Image width range, statically sized
		/// </summary>
		inline static constexpr auto wr = SP::wr;
		/// <summary>
		/// Channel index range, statically sized
		/// </summary>
		inline static constexpr auto cr = SP::cr;

		/// <summary>
		/// 4-dimensional tensor type carrying activations
		/// 
		/// Layout: Indexes nested according to permutation policy (\ref dcnnsol::permutation_policy::data)
		/// </summary>
		using values_t = tagged::permute_tensor_class< typename PP::data, float, height_tag, width_tag, channel_tag, batch_tag>;
		/// <summary>
		/// 4-dimensional tensor type carrying loss derivatives wrt. activations
		/// 
		/// Same as \ref values_t but indexes co-tagged according to tensor theory.
		/// 
		/// Layout: Indexes nested according to permutation policy (\ref dcnnsol::permutation_policy::data)
		/// </summary>
		using co_values_t = tagged::permute_tensor_class< tagged::co_list< typename PP::data>, float, tagged::co<height_tag>, tagged::co<width_tag>, tagged::co<channel_tag>, tagged::co<batch_tag>>;
	};

	/// <summary>
	/// Final layer activation data policy
	/// </summary>
	/// <typeparam name="CSP">Channel sizing policy</typeparam>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename CSP, typename PP>
	struct linear_data_policy : CSP {
		using typename CSP::channel_tag;

		/// <summary>
		/// Channel index range, statically sized
		/// </summary>
		inline static constexpr auto cr = CSP::cr;

		/// <summary>
		/// 2-dimensional tensor type carrying activations
		/// 
		/// Layout: Indexes nested according to permutation policy (\ref dcnnsol::permutation_policy::linear_data)
		/// </summary>
		using values_t = tagged::permute_tensor_class< typename PP::linear_data, float, channel_tag, batch_tag>;
		/// <summary>
		/// 2-dimensional tensor type carrying loss derivatives wrt. activations
		/// 
		/// Same as \ref values_t but indexes co-tagged according to tensor theory.
		/// 
		/// Layout: Indexes nested according to permutation policy (\ref dcnnsol::permutation_policy::linear_data)
		/// </summary>
		using co_values_t = tagged::permute_tensor_class< tagged::co_list<typename PP::linear_data>, float, tagged::co<channel_tag>, tagged::co<batch_tag>>;
	};

	/// <summary>
	/// Loss data policy
	/// </summary>
	struct loss_data_policy {
		/// <summary>
		/// 1-dimensional tensor type carrying loss values for images in a minibatch
		/// </summary>
		using loss_t = tagged::tensor_class< float, batch_tag>;
	};

	/// @}

	/// @addtogroup data
	/// 
	/// @{

	/// <summary>
	/// Loss data class
	/// </summary>
	class loss_data {
	public:
		using policy = loss_data_policy;
		loss_data(const batch_range& nr) : loss(nr) {}
		policy::loss_t loss;
	};

	/// @}

	/// @addtogroup sizing
	/// 
	/// @{

	/// @cond INTERNAL
	template< tagged::tag CT>
	struct learning_data_policy {
		using range_t = tagged::range_class< CT>;
		using memory_t = tagged::tensor_class< float, CT>;

		inline static constexpr range_t cr{};
	};

	template< tagged::tag CT>
	class learning_data {
	public:
		using policy = learning_data_policy<CT>;
		learning_data(const typename policy::range_t& r) : sumx2v(r), norm(r), scale(r) {}
		typename policy::memory_t sumx2v;
		typename policy::memory_t norm;
		typename policy::memory_t scale;
		float target_floating_rate = 0.125f;
		float floating_rate = 1.0f;
		float epsilon = 0.00001f;
	};

	template< tagged::tag CT>
	struct learning_adjustment
		: learning_data_policy< CT>
	{
	private:
		using base_ = learning_data_policy< CT>;
	public:
		using ld_t = learning_data< CT>;

		using base_::cr;

		static void init(ld_t& ld, float summary_backprop_variance)
		{
			float backprop_variance = summary_backprop_variance / cr.size();
			for (auto c : cr)
			{
				ld.norm[c] = backprop_variance;
			}
		}

		static void zeros(ld_t& ld)
		{
			auto&& sumx2v = ld.sumx2v;

			for (auto c : cr)
			{
				sumx2v[c] = 0.0f;
			}
		}

		static void setup(ld_t& ld)
		{
			auto&& sumx2v = ld.sumx2v;
			auto&& norm = ld.norm;
			auto&& scale = ld.scale;
			auto floating_rate = ld.floating_rate;
			ld.floating_rate = ld.target_floating_rate;	// next time use the target
			auto epsilon = ld.epsilon;

			float target_delta = 1.0f / cr.size();

			for (auto c : cr)
			{
				auto tn = sumx2v[c];
				auto on = norm[c];
				auto nn = (1.0f - floating_rate) * on + floating_rate * tn;
				norm[c] = nn;
				scale[c] = target_delta / (nn + epsilon);
			}
		}
	};
	/// @endcond

	/// @}

	/// @addtogroup functors 
	/// 
	/// @{

	/// <summary>
	/// Functor to add a fixed value
	/// </summary>
	/// <typeparam name="T1">Input index tag</typeparam>
	/// <typeparam name="T2">Output index tag</typeparam>
	template< tagged::tag T1, tagged::tag T2>
	struct delta_functor {
		delta_functor(std::ptrdiff_t delta)
			: delta_(delta)
		{}

		std::ptrdiff_t delta() const
		{
			return delta_;
		}

		tagged::index_class<T2> operator()(const tagged::index_class<T1>& ko) const
		{
			auto dox = ko.value();
			return tagged::index_class<T2>(dox + delta_);
		}
	private:
		std::ptrdiff_t delta_;
	};

	/// <summary>
	/// Functor to subtract from a fixed value
	/// </summary>
	/// <typeparam name="T1">Input index tag</typeparam>
	/// <typeparam name="T2">Output index tag</typeparam>
	template< tagged::tag T1, tagged::tag T2>
	struct neg_delta_functor {
		neg_delta_functor(std::ptrdiff_t delta)
			: delta_(delta)
		{}

		std::ptrdiff_t delta() const
		{
			return delta_;
		}

		tagged::index_class<T2> operator()(const tagged::index_class<T1>& ko) const
		{
			auto dox = ko.value();
			return tagged::index_class<T2>(delta_ - dox);
		}
	private:
		std::ptrdiff_t delta_;
	};

	/// <summary>
	/// Functor to multiply by a constant and add a fixed value
	/// </summary>
	/// <typeparam name="T1">Input index tag</typeparam>
	/// <typeparam name="T2">Output index tag</typeparam>
	/// <typeparam name="MUL">The constant multiplier</typeparam>
	template< tagged::tag T1, tagged::tag T2, std::ptrdiff_t MUL>
	struct mul_delta_functor {
		mul_delta_functor(std::ptrdiff_t delta)
			: delta_(delta)
		{}

		std::ptrdiff_t delta() const
		{
			return delta_;
		}

		inline static constexpr std::ptrdiff_t multiplier = MUL;

		tagged::index_class<T2> operator()(const tagged::index_class<T1>& ko) const
		{
			auto dox = ko.value();
			return tagged::index_class<T2>(delta_ + multiplier * dox);
		}
	private:
		std::ptrdiff_t delta_;
	};

	/// @}

	/// @addtogroup data
	/// 
	/// @{

	/// @cond INTERNAL
	class first_stat {
	public:
		first_stat() : sumx(0), sumx2(0), E(0.0f), var(0.0f), scale(0.0f) {}
		std::uint64_t sumx;
		std::uint64_t sumx2;
		float E;
		float var;
		float scale;
	};
	/// @endcond

	/// @}

	/// @addtogroup base
	/// 
	/// @{

	/// <summary>
	/// Utility base class for the first normalizing layer
	/// </summary>
	/// <typeparam name="SP">Size policy</typeparam>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename SP, typename PP>
	struct first_normalize_layer_base {
	private:
		using ISP = typename SP::image_policy;
		using CSP = typename SP::channel_policy;
	public:
		/// <summary>
		/// Input activations
		/// </summary>
		using input_data = batch_data<ISP>;
		/// <summary>
		/// Statistics
		/// </summary>
		using stat_data = first_stat;
		/// <summary>
		/// Output activations
		/// </summary>
		using output_data = dcnnsol::deep_data< SP, PP>;

		/// <summary>
		/// Tag: Image height dimension
		/// </summary>
		using height_tag = typename SP::height_tag;
		/// <summary>
		/// Tag: Image width dimension
		/// </summary>
		using width_tag = typename SP::width_tag;
		/// <summary>
		/// Tag: Output channel index
		/// 
		/// The range associated with this tag is always [0,1).
		/// The tag is present to make the layer compatible with the following convolution layer.
		/// </summary>
		using channel_out_tag = typename SP::channel_tag;

		inline static constexpr auto hr = SP::hr;	///< Index range along image height
		inline static constexpr auto wr = SP::wr;	///< Index range along image width
		inline static constexpr auto cor = SP::cr;	///< Output channel index range [0,1)
		inline static constexpr tagged::index_class< tagged::selector<channel_out_tag>> coi{ 0 };	///< The one and only output channel index (0)

		/// Argument compatibility check for the \ref forward function
		static tagged::range_class<batch_tag> forward_check(const input_data& ind, stat_data& cd, output_data& outd)
		{
			auto&& inv = ind.images;
			auto&& sumx = cd.sumx;
			auto&& sumx2 = cd.sumx2;
			auto&& E = cd.E;
			auto&& var = cd.var;
			auto&& scale = cd.scale;
			auto&& outv = outd.values;

			auto&& inr = inv.range();
			auto&& outr = outv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_tag>() == hr);
			assert(inr.template get<width_tag>() == wr);

			assert(outr.template get<height_tag>() == hr);
			assert(outr.template get<width_tag>() == wr);
			assert(outr.template get<channel_out_tag>() == cor);

			assert(outr.template get<batch_tag>() == br);

			return br;
		}

		/// @cond INTERNAL
		static std::size_t forward_complexity( const batch_range & br)
		{
			return (br & hr & wr).size();
		}
		/// @endcond
	};

	/// @}

	/// @addtogroup tags
	/// 
	/// @{

	/// @cond INTERNAL
	template< std::size_t KH>
	struct kernel_height_stag : tagged::sr_tag<kernel_height_selector, 0, KH> {};

	template< std::size_t KW>
	struct kernel_width_stag : tagged::sr_tag<kernel_width_selector, 0, KW> {};
	/// @endcond 

	/// @}

	/// @addtogroup sizing
	/// 
	/// @{

	/// <summary>
	/// Policy class: Convolution kernel dimensions
	/// 
	/// The dimensions are static, determined by template arguments.
	/// </summary>
	/// <typeparam name="KH">Kernel height</typeparam>
	/// <typeparam name="KW">Kernel width</typeparam>
	template< std::size_t KH, std::size_t KW>
	struct convolution_kernel_size_policy {
		/// @name Dimension tags
		/// 
		/// The tags carry the static dimensioning information
		/// @{

		using kernel_height_tag = kernel_height_stag<KH>;	///< Kernel (convolution) height
		using kernel_width_tag = kernel_width_stag<KW>;	///< Kernel (convolution) width

		/// @}

		/// @name Dimension ranges
		/// 
		/// The ranges are determined at compile time and therefore \c constexpr
		/// @{

		inline static constexpr tagged::range_class< kernel_height_tag> khr{ KH };	///< Kernel (convolution) height range
		inline static constexpr tagged::range_class< kernel_width_tag> kwr{ KW };	///< Kernel (convolution) width range

		/// @}
	};

	/// <summary>
	/// Policy class: Model weight dimensions for convolutional/aggregate layers
	/// 
	/// The dimensions are static, determined by template arguments.
	/// </summary>
	/// <typeparam name="KSP">Kernel size policy</typeparam>
	/// <typeparam name="CSPI">Input channel policy</typeparam>
	/// <typeparam name="CSPO">Output channel policy</typeparam>
	template< typename KSP, typename CSPI, typename CSPO>
	struct deep_weight_size_policy : KSP {
		/// @name Dimension tags
		/// 
		/// The tags carry the static dimensioning information
		/// @{

		using typename KSP::kernel_height_tag;
		using typename KSP::kernel_width_tag;

		using channel_in_tag = typename CSPI::channel_tag;	///< Input channel tag
		using channel_out_tag = typename CSPO::channel_tag;	///< Output channel tag

		/// @}

		/// @name Dimension ranges
		/// 
		/// The ranges are determined at compile time and therefore \c constexpr
		/// @{

		using KSP::khr;
		using KSP::kwr;
		inline static constexpr auto cir = CSPI::cr;	///< Input channel range
		inline static constexpr auto cor = CSPO::cr;	///< Output channel range

		/// @}
	};

	/// <summary>
	/// Policy class: Model weight data types for convolutional/aggregate layers
	/// </summary>
	/// <typeparam name="KSP"></typeparam>
	/// <typeparam name="CSPI"></typeparam>
	/// <typeparam name="CSPO"></typeparam>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename KSP, typename CSPI, typename CSPO, typename PP>
	struct deep_weight_policy : deep_weight_size_policy< KSP, CSPI, CSPO> {
	private:
		using base_ = deep_weight_size_policy< KSP, CSPI, CSPO>;
	public:
		using typename base_::kernel_height_tag;
		using typename base_::kernel_width_tag;
		using typename base_::channel_in_tag;
		using typename base_::channel_out_tag;

		/// @name Data classes
		/// 
		/// Each data class is a \ref tagged::tensor_class with statically sized dimensions
		/// determined by the sizing-policy arguments of this policy class template.
		/// The physical layout (order of indexes) of each \ref tagged::tensor_class
		/// is determined by the permutation-policy argument.
		/// @{

		/// <summary>
		/// The tensor containing the weights of the convolution.
		/// 
		/// The input channel tag is modified by the \ref tagged::co prefix to distinguish it 
		/// from the output channel tag (which may be otherwise identical).
		/// This co-tagging is also consistent with the meaning of the tensor 
		/// as a transformation from input channels to output channels.
		/// </summary>
		using weights_t = tagged::permute_tensor_class< typename PP::weights, float, kernel_height_tag, kernel_width_tag, tagged::co<channel_in_tag>, channel_out_tag>;
		/// <summary>
		/// The tensor containing the partial derivatives of the loss wrt. the weights of the convolution, aka. the gradient.
		/// 
		/// This tensor is the core part of the Stochastic Gradient Descent method used in the learning.
		/// 
		/// The indexes of this tensor are co-tagged wrt the weight tensor according 
		/// to the fact that the gradient is wrt. 
		/// </summary>
		using co_weights_t = tagged::permute_tensor_class< tagged::co_list<typename PP::weights>, float, tagged::co<kernel_height_tag>, tagged::co<kernel_width_tag>, channel_in_tag, tagged::co<channel_out_tag>>;
		using weightbs_t = tagged::permute_tensor_class< typename PP::weights_batch, float, kernel_height_tag, kernel_width_tag, tagged::co<channel_in_tag>, channel_out_tag, batch_tag>;
		using co_weightbs_t = tagged::permute_tensor_class< tagged::co_list<typename PP::weights_batch>, float, tagged::co<kernel_height_tag>, tagged::co<kernel_width_tag>, channel_in_tag, tagged::co<channel_out_tag>, tagged::co<batch_tag>>;
		using ld_t = learning_data<channel_out_tag>;

		/// @}
	};

	/// @}

	/// @addtogroup functors
	/// 
	/// @{

	/// @cond INTERNAL
	template<std::size_t KD>
	struct convolution_traits {
		inline static constexpr std::size_t LPAD = (KD - 1) / 2;
		inline static constexpr std::size_t SHIFT = (KD - 1) / 2;
		inline static constexpr std::size_t RPAD = KD / 2;
		// KD == LPAD + 1 + RPAD
	};
	/// @endcond

	/// <summary>
	/// Functor: Output index to kernel index range
	/// </summary>
	/// <typeparam name="TK">Kernel dimension tag</typeparam>
	/// <typeparam name="TO">Output dimension tag</typeparam>
	/// <typeparam name="D">Image size</typeparam>
	/// <typeparam name="KD">Kernel size</typeparam>
	template< tagged::tag TK, tagged::tag TO, std::size_t D, std::size_t KD>
	struct convolution_ok_range_functor {
		using traits = convolution_traits<KD>;
		static_assert(D > traits::LPAD);
		static_assert(D > traits::RPAD);
		tagged::range_class<tagged::selector<TK>> operator()(const tagged::index_class<TO>& o) const
		{
			auto dox = o.value();
			return tagged::range_class< tagged::selector<TK>>(traits::LPAD - std::min(dox, traits::LPAD), (KD + D - traits::RPAD - 1) - std::max(dox, D - traits::RPAD - 1));
		}
	};

	/// <summary>
	/// Functor: Output index to \ref delta_functor
	/// </summary>
	/// <typeparam name="TI">Input dimension tag</typeparam>
	/// <typeparam name="TK">Kernel dimension tag</typeparam>
	/// <typeparam name="TO">Output dimension tag</typeparam>
	/// <typeparam name="KD">Kernel size</typeparam>
	template< tagged::tag TI, tagged::tag TK, tagged::tag TO, std::size_t KD>
	struct convolution_oki_map_functor {
		using traits = convolution_traits<KD>;
		using df = delta_functor<TK, TI>;
		df operator()(const tagged::index_class<TO>& o) const
		{
			auto dox = o.value();
			return df(dox - traits::SHIFT);
		}
	};

	/// <summary>
	/// Functor: Input index to kernel index range
	/// </summary>
	/// <typeparam name="TI">Input dimension tag</typeparam>
	/// <typeparam name="TK">Kernel dimension tag</typeparam>
	/// <typeparam name="D">Image size</typeparam>
	/// <typeparam name="KD">Kernel size</typeparam>
	template< tagged::tag TI, tagged::tag TK, std::size_t D, std::size_t KD>
	struct convolution_ik_range_functor {
		using traits = convolution_traits<KD>;
		static_assert(D > traits::LPAD);
		static_assert(D > traits::RPAD);
		tagged::range_class< tagged::selector<TK>> operator()(const tagged::index_class<TI>& i) const
		{
			auto dix = i.value();
			return tagged::range_class< tagged::selector<TK>>(std::max(dix, D - traits::LPAD - 1) - (D - traits::LPAD - 1), (KD - traits::RPAD) + std::min(dix, traits::RPAD));
		}
	};

	/// <summary>
	/// Functor: Input index to \ref neg_delta_functor
	/// </summary>
	/// <typeparam name="TI">Input dimension tag</typeparam>
	/// <typeparam name="TK">Kernel dimension tag</typeparam>
	/// <typeparam name="TO">Output dimension tag</typeparam>
	/// <typeparam name="KD">Kernel size</typeparam>
	template< tagged::tag TI, tagged::tag TK, tagged::tag TO, std::size_t KD>
	struct convolution_iko_map_functor {
		using traits = convolution_traits<KD>;
		using df = neg_delta_functor<TK, TO>;
		df operator()(const tagged::index_class<TI>& i) const
		{
			auto dix = i.value();
			return df(dix + traits::SHIFT);
		}
	};

	/// <summary>
	/// Functor: Kernel index to output index range
	/// </summary>
	/// <typeparam name="TK">Kernel dimension tag</typeparam>
	/// <typeparam name="TO">Output dimension tag</typeparam>
	/// <typeparam name="D">Image size</typeparam>
	/// <typeparam name="KD">Kernel size</typeparam>
	template< tagged::tag TK, tagged::tag TO, std::size_t D, std::size_t KD>
	struct convolution_ko_range_functor {
		using traits = convolution_traits<KD>;
		static_assert(D > traits::LPAD);
		static_assert(D > traits::RPAD);
		tagged::range_class<tagged::selector<TO>> operator()(const tagged::index_class<TK>& k) const
		{
			auto dkx = k.value();
			return tagged::range_class< tagged::selector<TO>>(traits::LPAD - std::min(dkx, traits::LPAD), (D + KD - traits::RPAD - 1) - std::max(dkx, KD - traits::RPAD - 1));
		}
	};

	/// <summary>
	/// Functor: Kernel index to \ref delta_functor
	/// </summary>
	/// <typeparam name="TI">Input dimension tag</typeparam>
	/// <typeparam name="TK">Kernel dimension tag</typeparam>
	/// <typeparam name="TO">Output dimension tag</typeparam>
	/// <typeparam name="KD">Kernel size</typeparam>
	template< tagged::tag TK, tagged::tag TO, tagged::tag TI, std::size_t KD>
	struct convolution_koi_map_functor {
		using traits = convolution_traits<KD>;
		using df = delta_functor<TO, TI>;
		df operator()(const tagged::index_class<TK>& k) const
		{
			auto dkx = k.value();
			return df(dkx - traits::SHIFT);
		}
	};

	/// @}

	/// @addtogroup base
	/// 
	/// @{

	/// <summary>
	/// Utility base class for the convolutional layer
	/// </summary>
	/// <typeparam name="SPI">Input size policy</typeparam>
	/// <typeparam name="SPO">Output size policy</typeparam>
	/// <typeparam name="KSP">Kernel size policy</typeparam>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename SPI, typename SPO, typename KSP, typename PP>
	struct deep_cnn_layer_base
	{
	private:
		using CSPI = typename SPI::channel_policy;
		using CSPO = typename SPO::channel_policy;
	public:
		/// @name Data classes
		/// @{

		/// <summary>
		/// Input activations
		/// </summary>
		using input_data = dcnnsol::deep_data<SPI, PP>;
		/// <summary>
		/// Model weights
		/// </summary>
		using weights = dcnnsol::deep_weights<KSP, CSPI, CSPO, PP>;
		/// <summary>
		/// Output activations
		/// </summary>
		using output_data = dcnnsol::deep_data<SPO, PP>;
		/// <summary>
		/// Backward-propagated loss derivatives wrt. this layer output (input to this layer \ref backward function)
		/// </summary>
		using backward_output_data = dcnnsol::backward_deep_data<SPO, PP>;
		/// <summary>
		/// Loss gradient over weights (output of this layer \ref backward function)
		/// </summary>
		using backward_weights = dcnnsol::backward_deep_weights<KSP, CSPI, CSPO, PP>;
		/// <summary>
		/// Detailed loss gradient over weights and inputs (internal to this layer \ref backward function)
		/// </summary>
		using backward_internal = dcnnsol::backward_deep_internal<KSP, CSPI, CSPO, PP>;
		/// <summary>
		/// Backward-propagated loss derivatives wrt. this layer input (output of this layer \ref backward function)
		/// </summary>
		using backward_input_data = dcnnsol::backward_deep_data<SPI, PP>;
		///  @}

		/// @name Dimension tags
		/// @{
		
		using height_in_tag = typename SPI::height_tag;	///< Input image height
		using width_in_tag = typename SPI::width_tag;	///< Input image width
		using channel_in_tag = typename SPI::channel_tag;	///< Input image channel

		using kernel_height_tag = typename KSP::kernel_height_tag;	///< Kernel height
		using kernel_width_tag = typename KSP::kernel_width_tag;	///< Kernel width

		using height_out_tag = typename SPO::height_tag;	///< Output image height
		using width_out_tag = typename SPO::width_tag;	///< Output image width
		using channel_out_tag = typename SPO::channel_tag;	///< Output image channel

		/// @}

		static_assert(tagged::same_tag<height_in_tag, height_out_tag>);
		static_assert(tagged::same_tag<width_in_tag, width_out_tag>);

		/// @name Dimension ranges
		/// 
		/// Each dimension range allows enumeration of all indexes in that dimension,
		/// using the \c for(:) loop
		/// @{

		inline static constexpr auto hir = SPI::hr;	///< Input image height range
		inline static constexpr auto wir = SPI::wr;	///< Input image width range
		inline static constexpr auto cir = SPI::cr;	///< Input image channel range
		inline static constexpr auto khr = KSP::khr;	///< Kernel height range
		inline static constexpr auto kwr = KSP::kwr;	///< Kernel width range
		inline static constexpr auto hor = SPO::hr;	///< Output image height range
		inline static constexpr auto wor = SPO::wr;	///< Output image width range
		inline static constexpr auto cor = SPO::cr;	///< Output image channel range

		/// @}
		
		inline static constexpr std::size_t fanin = khr.size() * kwr.size() * cir.size();	///< Number of inputs for each output element

		using adjustment = learning_adjustment<channel_out_tag>;

		/// @name Input-kernel-output index convertors
		/// 
		/// Each quadruplet of functors serves for a different order of loop nesting, i.e.
		/// loops like 
		/// \code
		/// for ( auto top_index_value : top_index_range )
		/// {   auto mapping_functor = mf(top_index_value)
		///     for ( auto mid_index_value : rf(top_index_value) )
		///     {
		///         auto bottom_index_value = mapping_functor(mid_index_value);
		///         /*...*/
		///     }
		/// }
		/// \endcode
		/// Each \c -rf functor computes a mid-index range from a top-index value.
		/// The purpose is to handle clipping of valid index ranges at the borders
		/// of the images because output images have the same dimensions as
		/// the input images despite being generated by convolution
		/// from neighboring values. Thus, the available kernel-index range must be clipped
		/// for an output or input index at a border and vice versa.
		/// 
		/// Each \c -mf functor produces another functor from a top-index value that converts a mid-index value to a bottom-index value.
		/// The produced functor handles the required shifts (and sign changes) that result from
		/// the top-index value. In addition, it also handles the fact that kernels are indexed by [0,3) instead of [-1,1].
		/// 
		/// \c h- and \c w- functors work along image heights and widths, respectively.
		/// 
		/// @{
		
		inline static constexpr convolution_ok_range_functor<tagged::selector<kernel_height_tag>, tagged::selector<height_out_tag>, hir.size(), khr.size()> hokrf{}; ///< output-height index to kernel-height range
		inline static constexpr convolution_oki_map_functor< tagged::selector<height_in_tag>, tagged::selector<kernel_height_tag>, tagged::selector<height_out_tag>, khr.size()> hokimf{}; ///< output-height index to kernel-height index to input-height index
		inline static constexpr convolution_ok_range_functor< tagged::selector<kernel_width_tag>, tagged::selector<width_out_tag>, wir.size(), kwr.size()> wokrf{}; ///< output-width index to kernel-width range
		inline static constexpr convolution_oki_map_functor< tagged::selector<width_in_tag>, tagged::selector<kernel_width_tag>, tagged::selector<width_out_tag>, kwr.size()> wokimf{}; ///< output-width index to kernel-width index to input-width index

		inline static constexpr convolution_ik_range_functor< tagged::selector<height_in_tag>, tagged::selector<kernel_height_tag>, hir.size(), khr.size()> hikrf{};	///< input-height index to kernel-height range
		inline static constexpr convolution_iko_map_functor< tagged::selector<height_in_tag>, tagged::selector<kernel_height_tag>, tagged::selector<height_out_tag>, khr.size()> hikomf{};	 ///< input-height index to kernel-height index to output-height index
		inline static constexpr convolution_ik_range_functor< tagged::selector<width_in_tag>, tagged::selector<kernel_width_tag>, wir.size(), kwr.size()> wikrf{};  ///< input-width index to kernel-width range
		inline static constexpr convolution_iko_map_functor< tagged::selector<width_in_tag>, tagged::selector<kernel_width_tag>, tagged::selector<width_out_tag>, kwr.size()> wikomf{}; ///< input-width index to kernel-width index to output-width index

		inline static constexpr convolution_ko_range_functor< tagged::selector<kernel_height_tag>, tagged::selector<height_out_tag>, hir.size(), khr.size()> hkorf{};   ///< kernel-height index to output-height range
		inline static constexpr convolution_koi_map_functor< tagged::selector<kernel_height_tag>, tagged::selector<height_out_tag>, tagged::selector<height_in_tag>, khr.size()> hkoimf{};	///< kernel-height index to output-height index to input-height index
		inline static constexpr convolution_ko_range_functor< tagged::selector<kernel_width_tag>, tagged::selector<width_out_tag>, wir.size(), kwr.size()> wkorf{};  ///< kernel-width index to output-width range
		inline static constexpr convolution_koi_map_functor< tagged::selector<kernel_width_tag>, tagged::selector<width_out_tag>, tagged::selector<width_in_tag>, kwr.size()> wkoimf{}; ///< kernel-width index to output-width index to input-width index

		/// @}

		/// @name Check functions
		/// @{

		/// <summary>
		/// Check argument compatibility for the \c forward function
		/// </summary>
		/// <param name="ind">Input activations</param>
		/// <param name="wtd">Weights</param>
		/// <param name="outd">Output activations</param>
		/// <returns>The minibatch range</returns>
		static tagged::range_class<batch_tag> forward_check(const input_data& ind, const weights& wtd, output_data& outd)
		{
			auto&& inv = ind.values;
			auto&& wtv = wtd.weights;
			auto&& outv = outd.values;

			auto&& inr = inv.range();
			auto&& wtr = wtv.range();
			auto&& outr = outv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_in_tag>() == hir);
			assert(inr.template get<width_in_tag>() == wir);
			assert(inr.template get<channel_in_tag>() == cir);

			assert(wtr.template get<kernel_height_tag>() == khr);
			assert(wtr.template get<kernel_width_tag>() == kwr);
			assert(wtr.template get< tagged::co<channel_in_tag>>() == ~cir);
			assert(wtr.template get<channel_out_tag>() == cor);

			assert(outr.template get<height_out_tag>() == hor);
			assert(outr.template get<width_out_tag>() == wor);
			assert(outr.template get<channel_out_tag>() == cor);

			assert(outr.template get<batch_tag>() == br);

			return br;
		}

		/// <summary>
		/// Check argument compatibility for the \c backward function
		/// </summary>
		/// <param name="ind"></param>
		/// <param name="wtd"></param>
		/// <param name="boutd"></param>
		/// <param name="bwtd"></param>
		/// <param name="bid"></param>
		/// <param name="bind"></param>
		/// <returns></returns>
		static tagged::range_class<batch_tag> backward_check(const input_data& ind, const weights& wtd, const backward_output_data& boutd, backward_weights& bwtd, backward_internal& bid, backward_input_data& bind)
		{
			auto&& inv = ind.values;
			auto&& wtv = wtd.weights;
			auto&& boutv = boutd.bvalues;
			auto&& bwtv = bwtd.bweights;
			auto&& bwtbv = bid.bweightbs;
			auto&& binv = bind.bvalues;

			auto&& inr = inv.range();
			auto&& wtr = wtv.range();
			auto&& boutr = boutv.range();
			auto&& bwtr = bwtv.range();
			auto&& bwtbr = bwtbv.range();
			auto&& binr = binv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_in_tag>() == hir);
			assert(inr.template get<width_in_tag>() == wir);
			assert(inr.template get<channel_in_tag>() == cir);

			assert(wtr.template get<kernel_height_tag>() == khr);
			assert(wtr.template get<kernel_width_tag>() == kwr);
			assert(wtr.template get< tagged::co<channel_in_tag>>() == ~cir);
			assert(wtr.template get<channel_out_tag>() == cor);

			assert(boutr.template get< tagged::co<height_out_tag>>() == ~hor);
			assert(boutr.template get< tagged::co<width_out_tag>>() == ~wor);
			assert(boutr.template get< tagged::co<channel_out_tag>>() == ~cor);

			assert(boutr.template get< tagged::co<batch_tag>>() == ~br);

			assert(bwtr.template get< tagged::co<kernel_height_tag>>() == ~khr);
			assert(bwtr.template get< tagged::co<kernel_width_tag>>() == ~kwr);
			assert(bwtr.template get< channel_in_tag>() == cir);
			assert(bwtr.template get< tagged::co<channel_out_tag>>() == ~cor);

			assert(bwtbr.template get< tagged::co<kernel_height_tag>>() == ~khr);
			assert(bwtbr.template get< tagged::co<kernel_width_tag>>() == ~kwr);
			assert(bwtbr.template get< channel_in_tag>() == cir);
			assert(bwtbr.template get< tagged::co<channel_out_tag>>() == ~cor);

			assert(bwtbr.template get< tagged::co<batch_tag>>() == ~br);

			assert(binr.template get< tagged::co<height_in_tag>>() == ~hir);
			assert(binr.template get< tagged::co<width_in_tag>>() == ~wir);
			assert(binr.template get< tagged::co<channel_in_tag>>() == ~cir);

			return br;
		}

		/// <summary>
		/// Check argument compatibility for the \c learn function
		/// </summary>
		/// <param name="bwtd">Gradient over weights</param>
		/// <param name="wtd">Weights to be updated</param>
		static void learn_check(const backward_weights& bwtd, weights& wtd)
		{
			auto&& wtv = wtd.weights;
			auto&& bwtv = bwtd.bweights;
			auto&& scalev = bwtd.ld.scale;

			auto&& wtr = wtv.range();
			auto&& bwtr = bwtv.range();
			auto&& scaler = scalev.range();

			assert(wtr.template get<kernel_height_tag>() == khr);
			assert(wtr.template get<kernel_width_tag>() == kwr);
			assert(wtr.template get< tagged::co<channel_in_tag>>() == ~cir);
			assert(wtr.template get<channel_out_tag>() == cor);

			assert(bwtr.template get< tagged::co<kernel_height_tag>>() == ~khr);
			assert(bwtr.template get< tagged::co<kernel_width_tag>>() == ~kwr);
			assert(bwtr.template get< channel_in_tag>() == cir);
			assert(bwtr.template get<tagged::co<channel_out_tag>>() == ~cor);

			assert(scaler.template get<channel_out_tag>() == cor);
		}
		
		/// @cond INTERNAL
		static std::size_t forward_complexity( const batch_range & br)
		{
			return (br & khr & kwr & hor & wor & ~cir & cor).size();
		}

		static std::size_t backward_complexity( const batch_range & br)
		{
			return (br & khr & kwr & hor & wor & ~cir & cor).size();
		}
		/// @endcond

		/// @}
	};

	/// @}

	/// @addtogroup sizing
	/// 
	/// @{

	/// @cond INTERNAL
	template< typename CSP>
	struct deep_stat_policy : CSP {
		using typename CSP::channel_tag;

		using CSP::cr;

		using stat_t = tagged::tensor_class< float, channel_tag>;
	};
	/// @endcond 

	/// @}

	/// @addtogroup data
	/// 
	/// @{

	/// @cond INTERNAL
	template< typename CSP>
	class deep_stat {
	public:
		using policy = deep_stat_policy< CSP>;
		deep_stat() : sumxs(policy::cr), sumx2s(policy::cr), Es(policy::cr), vars(policy::cr), scales(policy::cr) {}
		policy::stat_t sumxs;
		policy::stat_t sumx2s;
		policy::stat_t Es;
		policy::stat_t vars;
		policy::stat_t scales;
	};
	/// @endcond 

	/// @}

	/// @addtogroup base
	/// 
	/// @{

	/// <summary>
	/// Utility base class for a normalizing layer
	/// </summary>
	/// <typeparam name="SP">Size policy</typeparam>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename SP, typename PP>
	struct deep_normalize_layer_base {
	private:
		using CSP = typename SP::channel_policy;
	public:
		/// <summary>
		/// Input activations
		/// </summary>
		using input_data = dcnnsol::deep_data<SP, PP>;
		/// <summary>
		/// Statistics
		/// </summary>
		using stat_data = deep_stat<CSP>;
		/// <summary>
		/// Output activations
		/// </summary>
		using output_data = dcnnsol::deep_data<SP, PP>;

		/// <summary>
		/// Loss derivatives wrt. input activations
		/// </summary>
		using backward_input_data = dcnnsol::backward_deep_data<SP, PP>;
		/// <summary>
		/// Loss derivatives wrt. output activations
		/// </summary>
		using backward_output_data = dcnnsol::backward_deep_data<SP, PP>;

		/// <summary>
		/// Tag: Image height dimension
		/// </summary>
		using height_tag = typename SP::height_tag;
		/// <summary>
		/// Tag: Image width dimension
		/// </summary>
		using width_tag = typename SP::width_tag;
		/// <summary>
		/// Tag: Channel index
		/// </summary>
		using channel_tag = typename SP::channel_tag;

		inline static constexpr auto hr = SP::hr;	///< Index range along image height
		inline static constexpr auto wr = SP::wr;	///< Index range along image width
		inline static constexpr auto cr = SP::cr;	///< Index range along image width

		static tagged::range_class<batch_tag> forward_check(const input_data& ind, stat_data& cd, output_data& outd)
		{
			auto&& inv = ind.values;
			auto&& sumxv = cd.sumxs;
			auto&& sumx2v = cd.sumx2s;
			auto&& Ev = cd.Es;
			auto&& varv = cd.vars;
			auto&& scalev = cd.scales;
			auto&& outv = outd.values;

			auto&& inr = inv.range();
			auto&& sumxr = sumxv.range();
			auto&& sumx2r = sumx2v.range();
			auto&& Er = Ev.range();
			auto&& varr = varv.range();
			auto&& scaler = scalev.range();
			auto&& outr = outv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_tag>() == hr);
			assert(inr.template get<width_tag>() == wr);
			assert(inr.template get<channel_tag>() == cr);

			assert(sumxr.template get<channel_tag>() == cr);

			assert(sumx2r.template get<channel_tag>() == cr);

			assert(Er.template get<channel_tag>() == cr);

			assert(varr.template get<channel_tag>() == cr);

			assert(scaler.template get<channel_tag>() == cr);

			assert(outr.template get<height_tag>() == hr);
			assert(outr.template get<width_tag>() == wr);
			assert(outr.template get<channel_tag>() == cr);

			assert(outr.template get<batch_tag>() == br);

			return br;
		}

		static tagged::range_class<batch_tag> backward_check(const stat_data& cd, const output_data& outd, const backward_output_data& boutd, backward_input_data& bind)
		{
			auto&& outv = outd.values;
			auto&& scalev = cd.scales;
			auto&& boutv = boutd.bvalues;
			auto&& binv = bind.bvalues;

			auto&& outr = outv.range();
			auto&& scaler = scalev.range();
			auto&& boutr = boutv.range();
			auto&& binr = binv.range();

			auto&& br = ~(boutr.template get<tagged::co<batch_tag>>());

			assert(outr.template get<height_tag>() == hr);
			assert(outr.template get<width_tag>() == wr);
			assert(outr.template get<channel_tag>() == cr);

			assert(scaler.template get<channel_tag>() == cr);

			assert(boutr.template get< tagged::co<height_tag>>() == ~hr);
			assert(boutr.template get< tagged::co<width_tag>>() == ~wr);
			assert(boutr.template get< tagged::co<channel_tag>>() == ~cr);

			assert(binr.template get< tagged::co<height_tag>>() == ~hr);
			assert(binr.template get< tagged::co<width_tag>>() == ~wr);
			assert(binr.template get<tagged::co<channel_tag>>() == ~cr);

			return br;
		}
		
		/// @cond INTERNAL
		static std::size_t forward_complexity( const batch_range & br)
		{
			return (br & hr & wr & cr).size();
		}

		static std::size_t backward_complexity( const batch_range & br)
		{
			return (br & hr & wr & cr).size();
		}
		/// @endcond
	};

	/// @}

	/// @addtogroup sizing
	/// 
	/// @{

	template< typename CSP, typename PP>
	struct deep_bias_policy : CSP {
		using typename CSP::channel_tag;

		using CSP::cr;

		using bias_t = tagged::tensor_class< float, channel_tag>;
		using co_bias_t = tagged::tensor_class< float, tagged::co<channel_tag>>;
	};

	/// @}

	/// @addtogroup base
	/// 
	/// @{

	/// <summary>
	/// Utility base class for the deep linear layer
	/// </summary>
	/// <typeparam name="SP">Size policy</typeparam>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename SP, typename PP>
	struct deep_linear_layer_base {
	private:
		using CSP = typename SP::channel_policy;
	public:
		/// @name Data classes
		/// @{

		/// <summary>
		/// Input activations
		/// </summary>
		using input_data = dcnnsol::deep_data<SP, PP>;
		/// <summary>
		/// Model biases
		/// </summary>
		using bias_data = dcnnsol::deep_bias<CSP, PP>;
		/// <summary>
		/// Output activations
		/// </summary>
		using output_data = dcnnsol::deep_data<SP, PP>;

		/// <summary>
		/// Backward-propagated loss derivatives wrt. this layer output (input to this layer \ref backward function)
		/// </summary>
		using backward_output_data = dcnnsol::backward_deep_data<SP, PP>;
		/// <summary>
		/// Loss gradient over biases (output of this layer \ref backward function)
		/// </summary>
		using backward_bias_data = dcnnsol::backward_deep_bias<CSP, PP>;
		/// <summary>
		/// Backward-propagated loss derivatives wrt. this layer input (output of this layer \ref backward function)
		/// </summary>
		using backward_input_data = dcnnsol::backward_deep_data<SP, PP>;
		///  @}

		/// @name Dimension tags
		/// @{

		using height_tag = typename SP::height_tag;	///< Image height
		using width_tag = typename SP::width_tag;	///< Image width
		using channel_tag = typename SP::channel_tag;	///< Image channel
		/// @}

		/// @name Dimension ranges
		/// 
		/// Each dimension range allows enumeration of all indexes in that dimension,
		/// using the \c for(:) loop
		/// @{

		inline static constexpr auto hr = SP::hr;	///< Image height range
		inline static constexpr auto wr = SP::wr;	///< Image width range
		inline static constexpr auto cr = SP::cr;	///< Image channel range

		/// @}

		using adjustment = learning_adjustment<channel_tag>;

		/// @name Check functions
		/// @{

		/// <summary>
		/// Check argument compatibility for the \c forward function
		/// </summary>
		/// <param name="ind">Input activations</param>
		/// <param name="cd">Biases</param>
		/// <param name="outd">Output activations</param>
		/// <returns>The minibatch range</returns>
		static tagged::range_class<batch_tag> forward_check(const input_data& ind, const bias_data& cd, output_data& outd)
		{
			auto&& inv = ind.values;
			auto&& betav = cd.betas;
			auto&& outv = outd.values;

			auto&& inr = inv.range();
			auto&& betar = betav.range();
			auto&& outr = outv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_tag>() == hr);
			assert(inr.template get<width_tag>() == wr);
			assert(inr.template get<channel_tag>() == cr);

			assert(betar.template get<channel_tag>() == cr);

			assert(outr.template get<height_tag>() == hr);
			assert(outr.template get<width_tag>() == wr);
			assert(outr.template get<channel_tag>() == cr);

			assert(outr.template get<batch_tag>() == br);

			return br;
		}

		/// <summary>
		/// Check argument compatibility for the \c backward function
		/// </summary>
		/// <param name="boutd"></param>
		/// <param name="bcd"></param>
		/// <param name="bind"></param>
		/// <returns></returns>
		static tagged::range_class<batch_tag> backward_check(const backward_output_data& boutd, backward_bias_data& bcd, backward_input_data& bind)
		{
			auto&& boutv = boutd.bvalues;
			auto&& bbetav = bcd.bbetas;
			auto&& binv = bind.bvalues;

			auto&& boutr = boutv.range();
			auto&& bbetar = bbetav.range();
			auto&& binr = binv.range();

			auto&& br = ~(binr.template get< tagged::co<batch_tag>>());

			assert(boutr.template get< tagged::co<height_tag>>() == ~hr);
			assert(boutr.template get< tagged::co<width_tag>>() == ~wr);
			assert(boutr.template get< tagged::co<channel_tag>>() == ~cr);

			assert(boutr.template get< tagged::co<batch_tag>>() == ~br);

			assert(bbetar.template get< tagged::co<channel_tag>>() == ~cr);

			assert(binr.template get< tagged::co<height_tag>>() == ~hr);
			assert(binr.template get< tagged::co<width_tag>>() == ~wr);
			assert(binr.template get< tagged::co<channel_tag>>() == ~cr);

			return br;
		}

		static void learn_check(const backward_bias_data& bcd, bias_data& cd)
		{
			auto&& bbetav = bcd.bbetas;
			auto&& scalev = bcd.ld.scale;
			auto&& betav = cd.betas;

			auto&& bbetar = bbetav.range();
			auto&& scaler = scalev.range();
			auto&& betar = betav.range();

			assert(bbetar.template get< tagged::co<channel_tag>>() == ~cr);

			assert(scaler.template get<channel_tag>() == cr);

			assert(betar.template get<channel_tag>() == cr);
		}

		/// @cond INTERNAL
		static std::size_t forward_complexity( const batch_range & br)
		{
			return (br & hr & wr & cr).size();
		}

		static std::size_t backward_complexity( const batch_range & br)
		{
			return (br & hr & wr & cr).size();
		}
		/// @endcond
	};

	template< typename SP, typename PP>
	struct deep_relu_layer_base {
		using input_data = dcnnsol::deep_data<SP, PP>;
		using output_data = dcnnsol::deep_data<SP, PP>;

		using backward_output_data = dcnnsol::backward_deep_data<SP, PP>;
		using backward_input_data = dcnnsol::backward_deep_data<SP, PP>;

		using height_tag = typename SP::height_tag;
		using width_tag = typename SP::width_tag;
		using channel_tag = typename SP::channel_tag;

		inline static constexpr auto hr = SP::hr;
		inline static constexpr auto wr = SP::wr;
		inline static constexpr auto cr = SP::cr;

		static tagged::range_class<batch_tag> forward_check(const input_data& ind, output_data& outd)
		{
			auto&& inv = ind.values;
			auto&& outv = outd.values;

			auto&& inr = inv.range();
			auto&& outr = outv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_tag>() == hr);
			assert(inr.template get<width_tag>() == wr);
			assert(inr.template get<channel_tag>() == cr);

			assert(outr.template get<height_tag>() == hr);
			assert(outr.template get<width_tag>() == wr);
			assert(outr.template get<channel_tag>() == cr);

			assert(outr.template get<batch_tag>() == br);

			return br;
		}

		static tagged::range_class<batch_tag> backward_check(const input_data& ind, const backward_output_data& boutd, backward_input_data& bind)
		{
			auto&& inv = ind.values;
			auto&& boutv = boutd.bvalues;
			auto&& binv = bind.bvalues;

			auto&& inr = inv.range();
			auto&& boutr = boutv.range();
			auto&& binr = binv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_tag>() == hr);
			assert(inr.template get<width_tag>() == wr);
			assert(inr.template get<channel_tag>() == cr);

			assert(boutr.template get< tagged::co<height_tag>>() == ~hr);
			assert(boutr.template get< tagged::co<width_tag>>() == ~wr);
			assert(boutr.template get< tagged::co<channel_tag>>() == ~cr);

			assert(boutr.template get< tagged::co<batch_tag>>() == ~br);

			assert(binr.template get< tagged::co<height_tag>>() == ~hr);
			assert(binr.template get< tagged::co<width_tag>>() == ~wr);
			assert(binr.template get< tagged::co<channel_tag>>() == ~cr);

			return br;
		}

		/// @cond INTERNAL
		static std::size_t forward_complexity( const batch_range & br)
		{
			return (br & hr & wr & cr).size();
		}

		static std::size_t backward_complexity( const batch_range & br)
		{
			return (br & hr & wr & cr).size();
		}
		/// @endcond
	};

	/// @}

	/// @addtogroup tags
	/// 
	/// @{

	struct maxpool_height_selector : tagged::tag_base {};
	struct maxpool_width_selector : tagged::tag_base {};

	template< std::size_t KH>
	struct maxpool_height_stag : tagged::sr_tag<maxpool_height_selector, 0, KH> {};

	template< std::size_t KW>
	struct maxpool_width_stag : tagged::sr_tag<maxpool_width_selector, 0, KW> {};

	/// @}

	/// @addtogroup functors
	/// 
	/// @{

	template< tagged::tag TK, tagged::tag TO, tagged::tag TI, std::size_t KD>
	struct maxpool_koi_map_functor {
		using df = mul_delta_functor<TO, TI, KD>;
		df operator()(const tagged::index_class<TK>& k) const
		{
			auto dkx = k.value();
			return df(dkx);
		}
	};

	/// @}

	/// @addtogroup base
	/// 
	/// @{

	template< typename SPI, typename SPO, typename PP>
	struct deep_maxpool_layer_base {

		static_assert(SPI::hr.size() % SPO::hr.size() == 0);
		static_assert(SPI::wr.size() % SPO::wr.size() == 0);
		static_assert(SPI::cr == SPO::cr);

		static constexpr std::size_t KH = SPI::hr.size() / SPO::hr.size();
		static constexpr std::size_t KW = SPI::wr.size() / SPO::wr.size();

		using input_data = dcnnsol::deep_data<SPI, PP>;
		using output_data = dcnnsol::deep_data<SPO, PP>;

		using backward_output_data = dcnnsol::backward_deep_data<SPO, PP>;
		using backward_input_data = dcnnsol::backward_deep_data<SPI, PP>;

		using height_in_tag = typename SPI::height_tag;
		using width_in_tag = typename SPI::width_tag;
		using channel_tag = typename SPI::channel_tag;

		using height_out_tag = typename SPO::height_tag;
		using width_out_tag = typename SPO::width_tag;

		static_assert(tagged::same_tag<channel_tag, typename SPO::channel_tag>);

		inline static constexpr auto hir = SPI::hr;
		inline static constexpr auto wir = SPI::wr;
		inline static constexpr auto cr = SPI::cr;

		using maxpool_height_tag = maxpool_height_stag< KH>;
		using maxpool_width_tag = maxpool_width_stag< KW>;

		inline static constexpr tagged::range_class< maxpool_height_tag> khr{ KH };
		inline static constexpr tagged::range_class< maxpool_width_tag> kwr{ KW };

		inline static constexpr auto hor = SPO::hr;
		inline static constexpr auto wor = SPO::wr;

		inline static constexpr maxpool_koi_map_functor<tagged::selector< maxpool_height_tag>, tagged::selector<height_out_tag>, tagged::selector<height_in_tag>, KH> hkoimf{};
		inline static constexpr maxpool_koi_map_functor<tagged::selector< maxpool_width_tag>, tagged::selector<width_out_tag>, tagged::selector<width_in_tag>, KW> wkoimf{};

		static tagged::range_class<batch_tag> forward_check(const input_data& ind, output_data& outd)
		{
			auto&& inv = ind.values;
			auto&& outv = outd.values;

			auto&& inr = inv.range();
			auto&& outr = outv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_in_tag>() == hir);
			assert(inr.template get<width_in_tag>() == wir);
			assert(inr.template get<channel_tag>() == cr);

			assert(outr.template get<height_out_tag>() == hor);
			assert(outr.template get<width_out_tag>() == wor);
			assert(outr.template get<channel_tag>() == cr);

			assert(outr.template get<batch_tag>() == br);

			return br;
		}

		static tagged::range_class<batch_tag> backward_check(const input_data& ind, const output_data& outd, const backward_output_data& boutd, backward_input_data& bind)
		{
			auto&& inv = ind.values;
			auto&& outv = outd.values;
			auto&& boutv = boutd.bvalues;
			auto&& binv = bind.bvalues;

			auto&& inr = inv.range();
			auto&& outr = outv.range();
			auto&& boutr = boutv.range();
			auto&& binr = binv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_in_tag>() == hir);
			assert(inr.template get<width_in_tag>() == wir);
			assert(inr.template get<channel_tag>() == cr);

			assert(outr.template get<height_out_tag>() == hor);
			assert(outr.template get<width_out_tag>() == wor);
			assert(outr.template get<channel_tag>() == cr);

			assert(outr.template get<batch_tag>() == br);

			assert(boutr.template get< tagged::co<height_out_tag>>() == ~hor);
			assert(boutr.template get< tagged::co<width_out_tag>>() == ~wor);
			assert(boutr.template get< tagged::co<channel_tag>>() == ~cr);

			assert(boutr.template get< tagged::co<batch_tag>>() == ~br);

			assert(binr.template get< tagged::co<height_in_tag>>() == ~hir);
			assert(binr.template get< tagged::co<width_in_tag>>() == ~wir);
			assert(binr.template get< tagged::co<channel_tag>>() == ~cr);

			assert(binr.template get< tagged::co<batch_tag>>() == ~br);

			return br;
		}

		/// @cond INTERNAL
		static std::size_t forward_complexity( const batch_range & br)
		{
			return (br & khr & kwr & hor & wor & cr).size();
		}

		static std::size_t backward_complexity( const batch_range & br)
		{
			return (br & khr & kwr & hor & wor & cr).size();
		}
		/// @endcond
	};

	/// @}

	/// @addtogroup sizing
	/// 
	/// @{

	/// <summary>
	/// @brief Retag input dimension policy as kernel dimension policy
	/// 
	/// The tags and ranges in the resulting policy have different names and types but the same sizes.
	/// </summary>
	/// <typeparam name="CSP"></typeparam>
	template< typename CSP>
	struct as_kernel
	{
		using kernel_height_tag = tagged::retag< dcnnasgn::kernel_height_selector, typename CSP::height_tag>;
		using kernel_width_tag = tagged::retag< dcnnasgn::kernel_width_selector, typename CSP::width_tag>;

		inline static constexpr auto khr = CSP::hr.template retag< kernel_height_tag>();
		inline static constexpr auto kwr = CSP::wr.template retag< kernel_width_tag>();
	};

	/// @}

	/// @addtogroup functors
	/// 
	/// @{

	/// <summary>
	/// Functor to cast input to kernel indexes (without any change in value).
	/// </summary>
	/// <typeparam name="TI">Input tag</typeparam>
	/// <typeparam name="TK">Output tag</typeparam>
	template< tagged::tag TI, tagged::tag TK>
	struct aggregate_ik_map_functor {
		tagged::index_class<TK> operator()(const tagged::index_class<TI>& i) const
		{
			return i.template retag<TK>();
		}
	};

	/// @}

	/// @addtogroup base
	/// 
	/// @{

	/// <summary>
	/// Utility base class for the aggregate layer
	/// </summary>
	/// <typeparam name="SPI">Input size policy</typeparam>
	/// <typeparam name="CSPO">Output channel policy</typeparam>
	/// <typeparam name="PP">Permutation policy</typeparam>
	template< typename SPI, typename CSPO, typename PP>
	struct aggregate_cnn_layer_base
		: as_kernel< typename SPI::image_policy>
	{
	private:
		using CSPI = typename SPI::channel_policy;
		using KSP = as_kernel< typename SPI::image_policy>;
	public:
		/// @name Data classes
		/// @{

		/// <summary>
		/// Input activations
		/// </summary>
		using input_data = dcnnsol::deep_data<SPI, PP>;
		/// <summary>
		/// Model weights
		/// </summary>
		using weights = dcnnsol::deep_weights< KSP, CSPI, CSPO, PP>;
		/// <summary>
		/// Output activations
		/// </summary>
		using output_data = dcnnsol::linear_data<CSPO, PP>;

		/// <summary>
		/// Backward-propagated loss derivatives wrt. this layer output (input to this layer \ref backward function)
		/// </summary>
		using backward_output_data = dcnnsol::backward_linear_data<CSPO, PP>;
		/// <summary>
		/// Loss gradient over weights (output of this layer \ref backward function)
		/// </summary>
		using backward_weights = dcnnsol::backward_deep_weights<KSP, CSPI, CSPO, PP>;
		/// <summary>
		/// Detailed loss gradient over weights and inputs (internal to this layer \ref backward function)
		/// </summary>
		using backward_internal = dcnnsol::backward_deep_internal<KSP, CSPI, CSPO, PP>;
		/// <summary>
		/// Backward-propagated loss derivatives wrt. this layer input (output of this layer \ref backward function)
		/// </summary>
		using backward_input_data = dcnnsol::backward_deep_data<SPI, PP>;
		///  @}

		/// @name Dimension tags
		/// @{

		using height_in_tag = typename SPI::height_tag;	///< Input image height
		using width_in_tag = typename SPI::width_tag;	///< Input image width
		using channel_in_tag = typename SPI::channel_tag;	///< Input image channel

		using typename KSP::kernel_height_tag;	///< Kernel height
		using typename KSP::kernel_width_tag;	///< Kernel width

		using channel_out_tag = typename CSPO::channel_tag;	///< Output image channel

		/// @}

		/// @name Dimension ranges
		/// 
		/// Each dimension range allows enumeration of all indexes in that dimension,
		/// using the \c for(:) loop
		/// @{

		inline static constexpr auto hir = SPI::hr;	///< Input image height range
		inline static constexpr auto wir = SPI::wr;	///< Input image width range
		inline static constexpr auto cir = SPI::cr;	///< Input image channel range
		inline static constexpr auto cor = CSPO::cr;	///< Output image channel range

		/// @}

		inline static constexpr std::size_t fanin = hir.size() * wir.size() * cir.size();	///< Number of inputs for each output element

		/// @name Input-to-kernel index convertors
		/// 
		/// For similarity to convolutional layer weights, 
		/// the dimensions of aggregate layer weights also carry
		/// tags different from the tags attached to the input dimensions.
		/// Consequently, indexed must be converted (cast)  
		/// from input dimensions to kernel dimensions
		/// accoring to this scheme:
		/// \code
		/// for ( auto in_index_value : in_index_range )
		/// {   auto kernel_index_value = ikmf(in_index_value);
		///     /*...*/
		/// }
		/// \endcode
		/// \c h- and \c w- functors work along image heights and widths, respectively.
		/// 
		/// @{
		inline static constexpr aggregate_ik_map_functor<tagged::selector<height_in_tag>, tagged::selector<kernel_height_tag>> hikmf{};
		inline static constexpr aggregate_ik_map_functor<tagged::selector<width_in_tag>, tagged::selector<kernel_width_tag>> wikmf{};

		/// @}

		using adjustment = learning_adjustment<channel_out_tag>;

		/// @name Check functions
		/// @{

		/// <summary>
		/// Check argument compatibility for the \c forward function
		/// </summary>
		/// <param name="ind">Input activations</param>
		/// <param name="wtd">Weights</param>
		/// <param name="outd">Output activations</param>
		/// <returns>The minibatch range</returns>
		static tagged::range_class<batch_tag> forward_check(const input_data& ind, const weights& wtd, output_data& outd)
		{
			auto&& inv = ind.values;
			auto&& wtv = wtd.weights;
			auto&& outv = outd.values;

			auto&& inr = inv.range();
			auto&& wtr = wtv.range();
			auto&& outr = outv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_in_tag>() == hir);
			assert(inr.template get<width_in_tag>() == wir);
			assert(inr.template get<channel_in_tag>() == cir);

			assert(wtr.template get< tagged::co<channel_in_tag>>() == ~cir);
			assert(wtr.template get<channel_out_tag>() == cor);

			assert(outr.template get<channel_out_tag>() == cor);

			assert(outr.template get<batch_tag>() == br);

			return br;
		}

		/// <summary>
		/// Check argument compatibility for the \c backward function
		/// </summary>
		/// <param name="ind"></param>
		/// <param name="wtd"></param>
		/// <param name="boutd"></param>
		/// <param name="bwtd"></param>
		/// <param name="bid"></param>
		/// <param name="bind"></param>
		/// <returns></returns>
		static tagged::range_class<batch_tag> backward_check(const input_data& ind, const weights& wtd, const backward_output_data& boutd, backward_weights& bwtd, backward_internal& bid, backward_input_data& bind)
		{
			auto&& inv = ind.values;
			auto&& wtv = wtd.weights;
			auto&& boutv = boutd.bvalues;
			auto&& bwtv = bwtd.bweights;
			auto&& bwtbv = bid.bweightbs;
			auto&& binv = bind.bvalues;

			auto&& inr = inv.range();
			auto&& wtr = wtv.range();
			auto&& boutr = boutv.range();
			auto&& bwtr = bwtv.range();
			auto&& bwtbr = bwtbv.range();
			auto&& binr = binv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<height_in_tag>() == hir);
			assert(inr.template get<width_in_tag>() == wir);
			assert(inr.template get<channel_in_tag>() == cir);

			assert(wtr.template get< tagged::co<channel_in_tag>>() == ~cir);
			assert(wtr.template get<channel_out_tag>() == cor);

			assert(boutr.template get< tagged::co<channel_out_tag>>() == ~cor);

			assert(boutr.template get< tagged::co<batch_tag>>() == ~br);

			assert(bwtr.template get< channel_in_tag>() == cir);
			assert(bwtr.template get< tagged::co<channel_out_tag>>() == ~cor);

			assert(bwtbr.template get< channel_in_tag>() == cir);
			assert(bwtbr.template get< tagged::co<channel_out_tag>>() == ~cor);

			assert(bwtbr.template get< tagged::co<batch_tag>>() == ~br);

			assert(binr.template get< tagged::co<height_in_tag>>() == ~hir);
			assert(binr.template get< tagged::co<width_in_tag>>() == ~wir);
			assert(binr.template get< tagged::co<channel_in_tag>>() == ~cir);

			return br;
		}

		static void learn_check(const backward_weights& bwtd, weights& wtd)
		{
			auto&& wtv = wtd.weights;
			auto&& bwtv = bwtd.bweights;
			auto&& scalev = bwtd.ld.scale;

			auto&& wtr = wtv.range();
			auto&& bwtr = bwtv.range();
			auto&& scaler = scalev.range();

			assert(wtr.template get< tagged::co<channel_in_tag>>() == ~cir);
			assert(wtr.template get< channel_out_tag>() == cor);

			assert(bwtr.template get< channel_in_tag>() == cir);
			assert(bwtr.template get<tagged::co<channel_out_tag>>() == ~cor);

			assert(scaler.template get<channel_out_tag>() == cor);
		}

		/// @cond INTERNAL
		static std::size_t forward_complexity( const batch_range & br)
		{
			return (br & hir & wir & ~cir & cor).size();
		}

		static std::size_t backward_complexity( const batch_range & br)
		{
			return (br & hir & wir & ~cir & cor).size();
		}
		/// @endcond
	};

	template< typename CSP, typename PP>
	struct final_linear_layer_base : CSP {
		using input_data = dcnnsol::linear_data<CSP, PP>;
		using bias_data = dcnnsol::deep_bias<CSP, PP>;
		using output_data = dcnnsol::linear_data<CSP, PP>;

		using backward_input_data = dcnnsol::backward_linear_data<CSP, PP>;
		using backward_bias_data = dcnnsol::backward_deep_bias<CSP, PP>;
		using backward_output_data = dcnnsol::backward_linear_data<CSP, PP>;

		using typename CSP::channel_tag;

		using CSP::cr;

		using adjustment = learning_adjustment<channel_tag>;

		static tagged::range_class<batch_tag> forward_check(const input_data& ind, const bias_data& cd, output_data& outd)
		{
			auto&& inv = ind.values;
			auto&& betav = cd.betas;
			auto&& outv = outd.values;

			auto&& inr = inv.range();
			auto&& betar = betav.range();
			auto&& outr = outv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<channel_tag>() == cr);

			assert(betar.template get<channel_tag>() == cr);

			assert(outr.template get<channel_tag>() == cr);

			assert(outr.template get<batch_tag>() == br);

			return br;
		}

		static tagged::range_class<batch_tag> backward_check(const backward_output_data& boutd, backward_bias_data& bcd, backward_input_data& bind)
		{
			auto&& boutv = boutd.bvalues;
			auto&& bbetav = bcd.bbetas;
			auto&& binv = bind.bvalues;

			auto&& boutr = boutv.range();
			auto&& bbetar = bbetav.range();
			auto&& binr = binv.range();

			auto&& br = ~(binr.template get<tagged::co<batch_tag>>());

			assert(boutr.template get< tagged::co<channel_tag>>() == ~cr);

			assert(boutr.template get< tagged::co<batch_tag>>() == ~br);

			assert(bbetar.template get< tagged::co<channel_tag>>() == ~cr);

			assert(binr.template get< tagged::co<channel_tag>>() == ~cr);

			return br;
		}

		static void learn_check(const backward_bias_data& bcd, bias_data& cd)
		{
			auto&& bbetav = bcd.bbetas;
			auto&& scalev = bcd.ld.scale;
			auto&& betav = cd.betas;

			auto&& bbetar = bbetav.range();
			auto&& scaler = scalev.range();
			auto&& betar = betav.range();

			assert(bbetar.template get< tagged::co<channel_tag>>() == ~cr);

			assert(scaler.template get<channel_tag>() == cr);

			assert(betar.template get<channel_tag>() == cr);
		}

		/// @cond INTERNAL
		static std::size_t forward_complexity( const batch_range & br)
		{
			return (br & cr).size();
		}

		static std::size_t backward_complexity( const batch_range & br)
		{
			return (br & cr).size();
		}
		/// @endcond
	};

	template< typename CSP, typename PP>
	struct loss_layer_base
	{
		using input_data = dcnnsol::linear_data<CSP, PP>;
		using output_data = loss_data;

		using backward_input_data = dcnnsol::backward_linear_data<CSP, PP>;

		using channel_tag = typename CSP::channel_tag;

		inline static constexpr auto cr = CSP::cr;

		static tagged::range_class<batch_tag> forward_check(const input_data& ind, const gold_data& gd, output_data& outd)
		{
			auto&& inv = ind.values;
			auto&& labelv = gd.labels;
			auto&& outv = outd.loss;

			auto&& inr = inv.range();
			auto&& labelr = labelv.range();
			auto&& outr = outv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<channel_tag>() == cr);

			assert(labelr.template get<batch_tag>() == br);

			assert(outr.template get<batch_tag>() == br);

			return br;
		}

		static tagged::range_class<batch_tag> backward_check(const input_data& ind, const gold_data& gd, backward_input_data& bind)
		{
			auto&& inv = ind.values;
			auto&& labelv = gd.labels;
			auto&& binv = bind.bvalues;

			auto&& inr = inv.range();
			auto&& labelr = labelv.range();
			auto&& binr = binv.range();

			auto&& br = inr.template get<batch_tag>();

			assert(inr.template get<channel_tag>() == cr);

			assert(labelr.template get<batch_tag>() == br);

			assert(binr.template get< tagged::co<channel_tag>>() == ~cr);

			assert(binr.template get< tagged::co<batch_tag>>() == ~br);

			return br;
		}

		/// @cond INTERNAL
		static std::size_t forward_complexity( const batch_range & br)
		{
			return (br & cr).size();
		}

		static std::size_t backward_complexity( const batch_range & br)
		{
			return (br & cr).size();
		}
		/// @endcond
	};
	/// @}
}

#endif
