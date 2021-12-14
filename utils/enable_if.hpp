
#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

#include <iostream>

namespace ft
{
    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };
};

#endif

/*
**    template<typename U = T>
**    A(int n, typename std::enable_if<U::value>::type* = 0) : val(n) { }
*/