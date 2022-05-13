
#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <iostream>

namespace ft
{
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
};

#endif
