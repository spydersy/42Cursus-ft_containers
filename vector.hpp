/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:35:27 by abelarif          #+#    #+#             */
/*   Updated: 2021/11/20 03:02:14 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        private:

        public:

        /*
        **  Member types :
        */
            typedef     T                                       value_type;
            typedef     Alloc                                   allocator_type;
            typedef     allocator_type::reference               reference;
            typedef     allocator_type::const_reference         const_reference;
            typedef     allocator_type::pointer                 pointer;
            typedef     allocator_type::const_pointer           const_pointer;
            typedef     std::size_t                             size_type;
            typedef     std::ptrdiff_t                          difference_type;


        /*
        **  Constructors :
        */
            template <class InputIterator>
            vector(void);
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            explicit vector (const allocator_type& alloc = allocator_type());
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

        /*
        **  Destructors :
        */
            ~vector(void);

        /*
        **  operator= :
        */
            vector& operator= (const vector& x);

    };

/*
    vector::vector()
    {
    }

    vector::~vector()
    {
    }
*/

} // namespace ft


#endif  // VECTOR_HPP
