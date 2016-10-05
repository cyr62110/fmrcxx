#ifndef FMRCXX_INTERNAL_TYPEUTILS_H_
#define FMRCXX_INTERNAL_TYPEUTILS_H_

namespace fmrcxx {
namespace internal {

template <typename _Tp> struct remove_ref_or_ptr { using type = _Tp; };
template <typename _Tp> struct remove_ref_or_ptr<_Tp&> { using type = _Tp; };
template <typename _Tp> struct remove_ref_or_ptr<_Tp&&> { using type = _Tp; };
template <typename _Tp> struct remove_ref_or_ptr<_Tp*> { using type = _Tp; };
template <typename _Tp> struct remove_ref_or_ptr<_Tp* const> { using type = _Tp; };
template <typename _Tp> struct remove_ref_or_ptr<_Tp* volatile> { using type = _Tp; };
template <typename _Tp> struct remove_ref_or_ptr<_Tp* const volatile> { using type = _Tp; };

/**
 * \internal
 * \brief Provide static methods to manipulate types
 * \tparam T Type that will be manipulated
 * \tparam _Tp Same type of T but with reference and pointer removed.
 */
template <typename T, typename _Tp = typename remove_ref_or_ptr<T>::type>
class TypeUtils {
public:
	/**
	 * \brief Return a reference to the value reference by the provided reference or pointer.
	 */
	static _Tp& toReference(_Tp& ref) {
		return ref;
	}
	/**
	 * \brief Return a reference to the value reference by the provided reference or pointer.
	 */
	static _Tp& toReference(_Tp&& ref) {
		return ref;
	}
	/**
	 * \brief Return a reference to the value reference by the provided reference or pointer.
	 */
	static _Tp& toReference(_Tp* ptr) {
		return *ptr;
	}
};

}}

#endif
