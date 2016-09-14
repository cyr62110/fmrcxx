#ifndef FMRCXX_MACRO_H_
#define FMRCXX_MACRO_H_

/**
 * \brief Macro allowing private member to become public for testing (_FMRCXX_TESTING defined)
 */
#define FMRCXX_PRIVATE private

#ifdef _FMRCXX_TESTING
#undef FMRCXX_PRIVATE
#define FMRCXX_PRIVATE public
#endif
