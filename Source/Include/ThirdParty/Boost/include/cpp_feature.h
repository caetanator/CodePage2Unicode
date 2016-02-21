/* has_feature.h
Provides SG-10 feature checking for all C++ compilers
(C) 2014 Niall Douglas http://www.nedprod.com/
File Created: Nov 2014


Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef BOOST_BINDLIB_HAS_FEATURE_H
#define BOOST_BINDLIB_HAS_FEATURE_H

// VS2010: _MSC_VER=1600
// VS2012: _MSC_VER=1700
// VS2013: _MSC_VER=1800
// VS2015: _MSC_VER=1900
#ifdef _MSC_VER

#if !defined(__cpp_exceptions) && defined(_CPPUNWIND)
# define __cpp_exceptions 190000
#endif

#if !defined(__cpp_rtti) && defined(_CPPRTTI)
# define __cpp_rtti 190000
#endif


// C++ 11
//#if !defined(__cpp_access_control_sfinae)
//# define __cpp_access_control_sfinae 190000
//#endif

#if !defined(__cpp_alias_templates) && _MSC_VER >= 1800
# define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_alignas) && _MSC_VER >= 1900
# define __cpp_alignas 190000
#endif

#if !defined(__cpp_attributes)
# define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr)
# define __cpp_constexpr 190000
#endif

#if !defined(__cpp_decltype) && _MSC_VER >= 1600
# define __cpp_decltype 190000
#endif

#if !defined(__cpp_default_function_template_args) && _MSC_VER >= 1800
# define __cpp_default_function_template_args 190000
#endif

#if !defined(__cpp_defaulted_functions) && _MSC_VER >= 1800
# define __cpp_defaulted_functions 190000
#endif

#if !defined(__cpp_delegating_constructors) && _MSC_VER >= 1800
# define __cpp_delegating_constructors 190000
#endif

#if !defined(__cpp_deleted_functions) && _MSC_VER >= 1800
# define __cpp_deleted_functions 190000
#endif

#if !defined(__cpp_explicit_conversions) && _MSC_VER >= 1800
# define __cpp_explicit_conversions 190000
#endif

#if !defined(__cpp_generalized_initializers) && _MSC_VER >= 1800
# define __cpp_generalized_initializers 190000
#endif

#if !defined(__cpp_implicit_moves) && _MSC_VER >= 1900
# define __cpp_implicit_moves 190000
#endif

#if !defined(__cpp_inheriting_constructors) && _MSC_VER >= 1900
# define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_inline_namespaces) && _MSC_VER >= 1900
# define __cpp_inline_namespaces 190000
#endif

#if !defined(__cpp_lambdas) && _MSC_VER >= 1600
# define __cpp_lambdas 190000
#endif

#if !defined(__cpp_local_type_template_args) && _MSC_VER >= 1600
# define __cpp_local_type_template_args 190000
#endif

#if !defined(__cpp_noexcept) && _MSC_VER >= 1900
# define __cpp_noexcept 190000
#endif

#if !defined(__cpp_nonstatic_member_init) && _MSC_VER >= 1800
# define __cpp_nonstatic_member_init 190000
#endif

#if !defined(__cpp_nullptr) && _MSC_VER >= 1600
# define __cpp_nullptr 190000
#endif

#if !defined(__cpp_override_control) && _MSC_VER >= 1700
# define __cpp_override_control 190000
#endif

#if !defined(__cpp_reference_qualified_functions) && _MSC_VER >= 1900
# define __cpp_reference_qualified_functions 190000
#endif

#if !defined(__cpp_range_for) && _MSC_VER >= 1700
# define __cpp_range_for 190000
#endif

#if !defined(__cpp_raw_strings) && _MSC_VER >= 1800
# define __cpp_raw_strings 190000
#endif

#if !defined(__cpp_rvalue_references) && _MSC_VER >= 1600
# define __cpp_rvalue_references 190000
#endif

#if !defined(__cpp_static_assert) && _MSC_VER >= 1600
# define __cpp_static_assert 190000
#endif

#if !defined(__cpp_thread_local) && _MSC_VER >= 1900
# define __cpp_thread_local 190000
#endif

#if !defined(__cpp_auto_type) && _MSC_VER >= 1600
# define __cpp_auto_type 190000
#endif

#if !defined(__cpp_strong_enums) && _MSC_VER >= 1700
# define __cpp_strong_enums 190000
#endif

#if !defined(__cpp_trailing_return) && _MSC_VER >= 1600
# define __cpp_trailing_return 190000
#endif

//#if !defined(__cpp_unicode_literals)
//# define __cpp_unicode_literals 190000
//#endif

#if !defined(__cpp_unrestricted_unions) && _MSC_VER >= 1900
# define __cpp_unrestricted_unions 190000
#endif

#if !defined(__cpp_user_defined_literals) && _MSC_VER >= 1900
# define __cpp_user_defined_literals 190000
#endif

#if !defined(__cpp_variadic_templates) && _MSC_VER >= 1800
# define __cpp_variadic_templates 190000
#endif


// C++ 14
#if !defined(__cpp_binary_literals) && _MSC_VER >= 1900
# define __cpp_binary_literals 190000
#endif

#if !defined(__cpp_contextual_conversions) && _MSC_VER >= 1800
# define __cpp_contextual_conversions 190000
#endif

#if !defined(__cpp_decltype_auto) && _MSC_VER >= 1900
# define __cpp_decltype_auto 190000
#endif

//#if !defined(__cpp_aggregate_nsdmi) && _MSC_VER >= 1900
//# define __cpp_aggregate_nsdmi 190000
//#endif

#if !defined(__cpp_digit_separators) && _MSC_VER >= 1900
# define __cpp_digit_separators 190000
#endif

#if !defined(__cpp_init_captures) && _MSC_VER >= 1900
# define __cpp_init_captures 190000
#endif

#if !defined(__cpp_generic_lambdas) && _MSC_VER >= 1900
# define __cpp_generic_lambdas 190000
#endif

//#if !defined(__cpp_relaxed_constexpr)
//# define __cpp_relaxed_constexpr 190000
//#endif

#if !defined(__cpp_return_type_deduction) && _MSC_VER >= 1900
# define __cpp_return_type_deduction 190000
#endif

//#if !defined(__cpp_runtime_arrays)
//# define __cpp_runtime_arrays 190000
//#endif

//#if !defined(__cpp_variable_templates)
//# define __cpp_variable_templates 190000
//#endif

#endif // _MSC_VER




// Much to my surprise, GCC's support of these is actually incomplete, so fill in the gaps
#if (defined(__GNUC__) && !defined(__clang__))

#define BOOST_BINDLIB_GCC (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#if !defined(__cpp_exceptions) && defined(__EXCEPTIONS)
# define __cpp_exceptions 190000
#endif

#if !defined(__cpp_rtti) && defined(__GXX_RTTI)
# define __cpp_rtti 190000
#endif


// C++ 11
#if defined(__GXX_EXPERIMENTAL_CXX0X__)

#if !defined(__cpp_access_control_sfinae) && (BOOST_BINDLIB_GCC >= 40400)
# define __cpp_access_control_sfinae 190000
#endif

#if !defined(__cpp_alias_templates) && (BOOST_BINDLIB_GCC >= 40700)
# define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_alignas) && (BOOST_BINDLIB_GCC >= 40800)
# define __cpp_alignas 190000
#endif

#if !defined(__cpp_attributes) && (BOOST_BINDLIB_GCC >= 40800)
# define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr) && (BOOST_BINDLIB_GCC >= 40600)
# define __cpp_constexpr 190000
#endif

#if !defined(__cpp_decltype) && (BOOST_BINDLIB_GCC >= 40300)
# define __cpp_decltype 190000
#endif

#if !defined(__cpp_default_function_template_args) && (BOOST_BINDLIB_GCC >= 40300)
# define __cpp_default_function_template_args 190000
#endif

#if !defined(__cpp_defaulted_functions) && (BOOST_BINDLIB_GCC >= 40400)
# define __cpp_defaulted_functions 190000
#endif

#if !defined(__cpp_delegating_constructors) && (BOOST_BINDLIB_GCC >= 40700)
# define __cpp_delegating_constructors 190000
#endif

#if !defined(__cpp_deleted_functions) && (BOOST_BINDLIB_GCC >= 40400)
# define __cpp_deleted_functions 190000
#endif

#if !defined(__cpp_explicit_conversions) && (BOOST_BINDLIB_GCC >= 40500)
# define __cpp_explicit_conversions 190000
#endif

#if !defined(__cpp_generalized_initializers) && (BOOST_BINDLIB_GCC >= 40600)
# define __cpp_generalized_initializers 190000
#endif

#if !defined(__cpp_implicit_moves) && (BOOST_BINDLIB_GCC >= 40600)
# define __cpp_implicit_moves 190000
#endif

#if !defined(__cpp_inheriting_constructors) && (BOOST_BINDLIB_GCC >= 40800)
# define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_inline_namespaces) && (BOOST_BINDLIB_GCC >= 40400)
# define __cpp_inline_namespaces 190000
#endif

#if !defined(__cpp_lambdas) && (BOOST_BINDLIB_GCC >= 40500)
# define __cpp_lambdas 190000
#endif

#if !defined(__cpp_local_type_template_args) && (BOOST_BINDLIB_GCC >= 40500)
# define __cpp_local_type_template_args 190000
#endif

#if !defined(__cpp_noexcept) && (BOOST_BINDLIB_GCC >= 40600)
# define __cpp_noexcept 190000
#endif

#if !defined(__cpp_nonstatic_member_init) && (BOOST_BINDLIB_GCC >= 40700)
# define __cpp_nonstatic_member_init 190000
#endif

#if !defined(__cpp_nullptr) && (BOOST_BINDLIB_GCC >= 40600)
# define __cpp_nullptr 190000
#endif

#if !defined(__cpp_override_control) && (BOOST_BINDLIB_GCC >= 40700)
# define __cpp_override_control 190000
#endif

#if !defined(__cpp_reference_qualified_functions) && (BOOST_BINDLIB_GCC >= 40801)
# define __cpp_reference_qualified_functions 190000
#endif

#if !defined(__cpp_range_for) && (BOOST_BINDLIB_GCC >= 40600)
# define __cpp_range_for 190000
#endif

#if !defined(__cpp_raw_strings) && (BOOST_BINDLIB_GCC >= 40500)
# define __cpp_raw_strings 190000
#endif

// __cpp_rvalue_reference deviation
#if !defined(__cpp_rvalue_references) && defined(__cpp_rvalue_reference)
# define __cpp_rvalue_references __cpp_rvalue_reference
#endif

#if !defined(__cpp_static_assert) && (BOOST_BINDLIB_GCC >= 40300)
# define __cpp_static_assert 190000
#endif

#if !defined(__cpp_thread_local) && (BOOST_BINDLIB_GCC >= 40800)
# define __cpp_thread_local 190000
#endif

#if !defined(__cpp_auto_type) && (BOOST_BINDLIB_GCC >= 40400)
# define __cpp_auto_type 190000
#endif

#if !defined(__cpp_strong_enums) && (BOOST_BINDLIB_GCC >= 40400)
# define __cpp_strong_enums 190000
#endif

#if !defined(__cpp_trailing_return) && (BOOST_BINDLIB_GCC >= 40500)
# define __cpp_trailing_return 190000
#endif

#if !defined(__cpp_unicode_literals) && (BOOST_BINDLIB_GCC >= 40500)
# define __cpp_unicode_literals 190000
#endif

#if !defined(__cpp_unrestricted_unions) && (BOOST_BINDLIB_GCC >= 40600)
# define __cpp_unrestricted_unions 190000
#endif

#if !defined(__cpp_user_defined_literals) && (BOOST_BINDLIB_GCC >= 40700)
# define __cpp_user_defined_literals 190000
#endif

#if !defined(__cpp_variadic_templates) && (BOOST_BINDLIB_GCC >= 40400)
# define __cpp_variadic_templates 190000
#endif


// C++ 14
////#if !defined(__cpp_binary_literals)
////# define __cpp_binary_literals 190000
////#endif

// Strangely missing!
#if !defined(__cpp_contextual_conversions) && (BOOST_BINDLIB_GCC >= 40900)
# define __cpp_contextual_conversions 190000
#endif

////#if !defined(__cpp_decltype_auto)
////# define __cpp_decltype_auto 190000
////#endif

//#if !defined(__cpp_aggregate_nsdmi)
//# define __cpp_aggregate_nsdmi 190000
//#endif

////#if !defined(__cpp_digit_separators)
////# define __cpp_digit_separators 190000
////#endif

////#if !defined(__cpp_init_captures)
////# define __cpp_init_captures 190000
////#endif

////#if !defined(__cpp_generic_lambdas)
////# define __cpp_generic_lambdas 190000
////#endif

//#if !defined(__cpp_relaxed_constexpr)
//# define __cpp_relaxed_constexpr 190000
//#endif

//#if !defined(__cpp_return_type_deduction)
//# define __cpp_return_type_deduction 190000
//#endif

////#if !defined(__cpp_runtime_arrays)
////# define __cpp_runtime_arrays 190000
////#endif

//#if !defined(__cpp_variable_templates)
//# define __cpp_variable_templates 190000
//#endif

#endif // __GXX_EXPERIMENTAL_CXX0X__

#endif // GCC



// clang deviates in some places from the present SG-10 draft, plus older
// clangs are quite incomplete
#if defined(__clang__)

#define BOOST_BINDLIB_CLANG (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)

#if !defined(__cpp_exceptions) && defined(__EXCEPTIONS)
# define __cpp_exceptions 190000
#endif

#if !defined(__cpp_rtti) && defined(__GXX_RTTI)
# define __cpp_rtti 190000
#endif


// C++ 11
#if defined(__GXX_EXPERIMENTAL_CXX0X__)

#if !defined(__cpp_access_control_sfinae) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_access_control_sfinae 190000
#endif

#if !defined(__cpp_alias_templates) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_alignas) && (BOOST_BINDLIB_CLANG >= 30300)
# define __cpp_alignas 190000
#endif

#if !defined(__cpp_attributes) && (BOOST_BINDLIB_CLANG >= 30300)
# define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr) && (BOOST_BINDLIB_CLANG >= 30100)
# define __cpp_constexpr 190000
#endif

#if !defined(__cpp_decltype) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_decltype 190000
#endif

#if !defined(__cpp_default_function_template_args) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_default_function_template_args 190000
#endif

#if !defined(__cpp_defaulted_functions) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_defaulted_functions 190000
#endif

#if !defined(__cpp_delegating_constructors) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_delegating_constructors 190000
#endif

#if !defined(__cpp_deleted_functions) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_deleted_functions 190000
#endif

#if !defined(__cpp_explicit_conversions) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_explicit_conversions 190000
#endif

#if !defined(__cpp_generalized_initializers) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_generalized_initializers 190000
#endif

#if !defined(__cpp_implicit_moves) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_implicit_moves 190000
#endif

#if !defined(__cpp_inheriting_constructors) && (BOOST_BINDLIB_CLANG >= 30300)
# define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_inline_namespaces) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_inline_namespaces 190000
#endif

#if !defined(__cpp_lambdas) && (BOOST_BINDLIB_CLANG >= 30100)
# define __cpp_lambdas 190000
#endif

#if !defined(__cpp_local_type_template_args) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_local_type_template_args 190000
#endif

#if !defined(__cpp_noexcept) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_noexcept 190000
#endif

#if !defined(__cpp_nonstatic_member_init) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_nonstatic_member_init 190000
#endif

#if !defined(__cpp_nullptr) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_nullptr 190000
#endif

#if !defined(__cpp_override_control) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_override_control 190000
#endif

#if !defined(__cpp_reference_qualified_functions) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_reference_qualified_functions 190000
#endif

#if !defined(__cpp_range_for) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_range_for 190000
#endif

// __cpp_raw_string_literals deviation
#if !defined(__cpp_raw_strings) && defined(__cpp_raw_string_literals)
# define __cpp_raw_strings __cpp_raw_string_literals
#endif
#if !defined(__cpp_raw_strings) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_raw_strings 190000
#endif


// __cpp_rvalue_reference deviation
#if !defined(__cpp_rvalue_references) && defined(__cpp_rvalue_reference)
# define __cpp_rvalue_references __cpp_rvalue_reference
#endif
#if !defined(__cpp_rvalue_references) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_rvalue_references 190000
#endif

#if !defined(__cpp_static_assert) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_static_assert 190000
#endif

#if !defined(__cpp_thread_local) && (BOOST_BINDLIB_CLANG >= 30300)
# define __cpp_thread_local 190000
#endif

#if !defined(__cpp_auto_type) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_auto_type 190000
#endif

#if !defined(__cpp_strong_enums) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_strong_enums 190000
#endif

#if !defined(__cpp_trailing_return) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_trailing_return 190000
#endif

#if !defined(__cpp_unicode_literals) && (BOOST_BINDLIB_CLANG >= 30000)
# define __cpp_unicode_literals 190000
#endif

#if !defined(__cpp_unrestricted_unions) && (BOOST_BINDLIB_CLANG >= 30100)
# define __cpp_unrestricted_unions 190000
#endif

// __cpp_user_literals deviation
#if !defined(__cpp_user_defined_literals) && defined(__cpp_user_literals)
# define __cpp_user_defined_literals __cpp_user_literals
#endif
#if !defined(__cpp_user_defined_literals) && (BOOST_BINDLIB_CLANG >= 30100)
# define __cpp_user_defined_literals 190000
#endif

#if !defined(__cpp_variadic_templates) && (BOOST_BINDLIB_CLANG >= 20900)
# define __cpp_variadic_templates 190000
#endif


// C++ 14
////#if !defined(__cpp_binary_literals)
////# define __cpp_binary_literals 190000
////#endif

////#if !defined(__cpp_contextual_conversions)
////# define __cpp_contextual_conversions 190000
////#endif

////#if !defined(__cpp_decltype_auto)
////# define __cpp_decltype_auto 190000
////#endif

////#if !defined(__cpp_aggregate_nsdmi)
////# define __cpp_aggregate_nsdmi 190000
////#endif

////#if !defined(__cpp_digit_separators)
////# define __cpp_digit_separators 190000
////#endif

////#if !defined(__cpp_init_captures)
////# define __cpp_init_captures 190000
////#endif

////#if !defined(__cpp_generic_lambdas)
////# define __cpp_generic_lambdas 190000
////#endif

////#if !defined(__cpp_relaxed_constexpr)
////# define __cpp_relaxed_constexpr 190000
////#endif

////#if !defined(__cpp_return_type_deduction)
////# define __cpp_return_type_deduction 190000
////#endif

// __cpp_runtime_array deviation
#if !defined(__cpp_runtime_arrays) && defined(__cpp_runtime_array)
# define __cpp_runtime_arrays __cpp_runtime_array
#endif

////#if !defined(__cpp_variable_templates)
////# define __cpp_variable_templates 190000
////#endif

#endif // __GXX_EXPERIMENTAL_CXX0X__

#endif // clang

#endif