
#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

#include <iostream>

namespace ft
{
    // class iterators_traits
    // {
        // public:
            // typedef     std::ptrdiff_t                   difference_type;
    // };  // struct iterators_traits
    template <typename T>
    struct iterator_traits
    {
        typedef std::random_access_iterator_tag iterator_category;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::ptrdiff_t                  difference_type;
        typedef size_t                          size_type;
    };
};  //  namespace ft
#endif
