/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:35:27 by abelarif          #+#    #+#             */
/*   Updated: 2021/11/20 04:25:34 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iterator>
#include <memory>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        private:
            T   *_myVector;
        public:

        /*
        **  Member types :
        */
            typedef     T                                                   value_type;
            typedef     Alloc                                               allocator_type;
            typedef     typename Alloc::reference                           reference;
            typedef     typename Alloc::const_reference                     const_reference;
            typedef     typename Alloc::pointer                             pointer;
            typedef     typename Alloc::const_pointer                       const_pointer;
            typedef     typename std::size_t                                size_type;
            typedef     typename std::ptrdiff_t                             difference_type;


        /*
        **  Constructors :
        */
            explicit vector (const allocator_type& alloc = allocator_type()){
                std::cout << "DBG : JUSRT FOR TEST" << std::endl;
                _myVector = allocator_type.allocate(0);
                allocator_type.construct(_myVector, 0);
            }
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
            template <class InputIterator>
                vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            vector (const vector& x);

        /*
        **  Destructors :
        */
            ~vector(void);

        /*
        **  operator= :
        */
            vector& operator= (const vector& x);

        /*
        **  Iterator :
        */
            //  begin :
            iterator begin();
            const_iterator begin() const;

            //  end :
            iterator end();
            const_iterator end() const;

            //  rbegin :
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;

            //  rend :
            reverse_iterator rend();
            const_reverse_iterator rend() const;


        /*
        **  Capacity :
        */
            //  size :
                size_type size() const;

            //  max_size :
                size_type max_size() const;

            //  resize :
                void resize (size_type n, value_type val = value_type());

            //  capacity :
                size_type capacity() const;

            //  empty :
                bool empty() const;

            //  reserve :
                void reserve (size_type n);

        /*
        **  Capacity :
        */
            //  operator[] :
                reference operator[] (size_type n);
                const_reference operator[] (size_type n) const;

            //  at :
                reference at (size_type n);
                const_reference at (size_type n) const;

            //  front :
                reference front();
                const_reference front() const;

            //  back :
                reference back();
                const_reference back() const;

        /*
        **  Modifiers :
        */
            //  assign :
            template <class InputIterator>
                void assign (InputIterator first, InputIterator last);
            void assign (size_type n, const value_type& val);

            //  push_back :
            void push_back (const value_type& val);

            //  pop_back :
            void pop_back();

            //  insert :
            iterator insert (iterator position, const value_type& val);
            void insert (iterator position, size_type n, const value_type& val);
            template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last);

            //  erase :
            iterator erase (iterator position);
            iterator erase (iterator first, iterator last);

            //  swap :
            void swap (vector& x);

            //  clear :
            void clear();

        /*
        **  Allocator :
        */
            //  get_allocator :
            allocator_type get_allocator() const;

        /*
        **  Non-member function overloads :
        */
            //  relational operators :
            template <class T, class Alloc>
                bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

            template <class T, class Alloc>
                bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

            template <class T, class Alloc>
                bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

            template <class T, class Alloc>
                bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

            template <class T, class Alloc>
                bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

            template <class T, class Alloc>
                bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

            //  swap :
            template <class T, class Alloc>
                void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

    };  // class vector

}   // namespace ft


#endif  // VECTOR_HPP
