
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
        // MEMBER TYPES:
            typedef     T                                                 value_type;
            typedef     Alloc                                             allocator_type;
            typedef     allocator_type::value_type&                       reference;
            typedef     const allocator_type::value_type&                 const_reference;
            typedef     allocator_type::value_type*                       pointer;
            typedef     const allocator_type::value_type*                 const_pointer;

        // CONSTRUCTOR:
            explicit vector (const allocator_type& alloc = allocator_type())    // default
            {

            }
    };

};

#endif
