
#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <iostream>

namespace ft
{
    // template<typename T>
    // struct is_integral
    // {
        // static const bool value;
    // };

    // template<typename>
    // struct is_integral_base: std::false_type {};

    // template<> struct is_integral_base<bool>: std::true_type {};
    // template<> struct is_integral_base<int>: std::true_type {};
    // template<> struct is_integral_base<short>: std::true_type {};

    // template<typename T>
    // struct is_integral: is_integral_base<std::remove_cv_t<T>>
    // {
        // static const bool value;

    // };

    // template<typename T> struct is_integral { const bool value = false; };


    template<typename T> struct is_integral  { static const bool value = false; };

    template<> struct is_integral<bool>       { static const bool value = true; };
    template<> struct is_integral<char>       { static const bool value = true; };
    template<> struct is_integral<char16_t>   { static const bool value = true; };
    template<> struct is_integral<char32_t>   { static const bool value = true; };
    template<> struct is_integral<wchar_t>    { static const bool value = true; };
    template<> struct is_integral<short>      { static const bool value = true; };
    template<> struct is_integral<int>        { static const bool value = true; };
    template<> struct is_integral<long>       { static const bool value = true; };
    template<> struct is_integral<long long>  { static const bool value = true; };

    // template<typename T>
    // struct is_integral
    // {
        // const bool value = false;
    // };

};

#endif