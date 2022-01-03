
#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>
#include <iterator>
#include "iterators_traits.hpp"

namespace   ft
{
	//?https://www.cplusplus.com/reference/iterator/InputIterator/
	struct input_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/OutputIterator/
  	struct output_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/ForwardIterator/
  	struct forward_iterator_tag : public input_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/BidirectionalIterator/
  	struct bidirectional_iterator_tag : public forward_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
 	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/iterator/
	template <class Category, class T, class Distance = std::ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct base_iterator
	{
		public:
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category 	iterator_category;
	};

    template <typename Type>
    class   Iterator : public ft::base_iterator<std::random_access_iterator_tag, Type>
    {
        public:

            /*
            ** Member Types:
            */
            // typedef     typename ft::iterator_traits<Type>::iterator_category  iterator_category;
            // typedef     typename ft::iterator_traits<Type>::value_type         value_type;
            // typedef     typename ft::iterator_traits<Type>::pointer            pointer;
            // typedef     typename ft::iterator_traits<Type>::reference          reference;
            // typedef     typename ft::iterator_traits<Type>::difference_type    difference_type;
            // typedef     typename ft::iterator_traits<Type>::size_type          size_type;
            typedef     Type                             value_type;
            typedef     const Type                             const_value_type;
            typedef     Type*                            pointer;
            typedef     Type&                            reference;
            typedef     std::ptrdiff_t                   difference_type;
            typedef     size_t                           size_type;

                Iterator( void )
                {
                    this->_ptr = NULL;
                    // std::cout << KYEL << "DBG_ITERATOR: (default constructor) | _ptr = " << _ptr << std::endl << KNRM;
                }

                Iterator( Iterator const & src )
                {
                    this->_ptr = src._ptr;
                    // std::cout << KYEL << "DBG_ITERATOR: (copy constructor) | _ptr = " << _ptr << std::endl << KNRM;
                }

                Iterator( value_type &src )
                {
                    this->_ptr = &src;
                    // std::cout << KYEL << "DBG_ITERATOR: (ptr constructor) | _ptr = " << _ptr << std::endl << KNRM;
                }

                Iterator    &operator=( Iterator const & src)
                {
                    this->_ptr = src._ptr;
                    // std::cout << KYEL << "DBG_ITERATOR: (operator=) | _ptr = " << _ptr << std::endl << KNRM;
                    return ( *this );
                }

                ~Iterator() { return ; }

                bool    operator==( Iterator const & src ) const
                {
                    return (this->_ptr == src._ptr);
                }

                bool    operator!=( Iterator const & src ) const
                {
                    return (this->_ptr != src._ptr);
                }

            /*
            ** Incrementation / Decrementaion Operators:
            */
                /*
                ** Pre-increment opearator:
                */
                Iterator    &operator++()
                {
                    this->_ptr++;
                    return (*this);
                }

                /*
                ** Post-increment opearator:
                */
                Iterator    operator++( int )
                {
                        Iterator   prev = *this;

                        this->_ptr++;
                        return (prev);
                }

                /*
                ** Pre-decrement opearator:
                */
                Iterator    &operator--()
                {
                    this->_ptr--;
                    return (*this);
                }

                /*
                ** Post-decrement opearator:
                */
                Iterator    operator--( int )
                {
                        Iterator   prev = *this;

                        this->_ptr--;
                        return (prev);
                }

            /*
            ** Dereference Operators:
            */
                reference   operator*( void )
                {
                    // std::cout << "*******DBG" << &this->_ptr << "END" << std::endl;
                    return (*(this->_ptr));
                }

                pointer   operator->( void )
                {
                    return (this->_ptr);
                }

                difference_type   operator-(Iterator const & src)
                {
                    // ret._ptr = this->_ptr - src._ptr;
                    // return (ret);
                    return (this->_ptr - src._ptr);
                }

                Iterator   operator-(difference_type value)
                {
                    Iterator   ret;

                    ret._ptr = this->_ptr - value;
                    return (ret);
                }

                Iterator   operator+(size_type value)
                {
                    Iterator   ret;

                    ret._ptr = this->_ptr + value;
                    return (ret);
                }

                bool    operator<( Iterator const & src ) const
                {
                    return (this->_ptr < src._ptr);
                }

                bool    operator<=( Iterator const & src ) const
                {
                    return (this->_ptr <= src._ptr);
                }

                bool    operator>( Iterator const & src ) const
                {
                    return (this->_ptr > src._ptr);
                }

                bool    operator>=( Iterator const & src ) const
                {
                    return (this->_ptr >= src._ptr);
                }

                Iterator operator+=( size_type const value)
                {
                    this->_ptr += value;
                    return (*this);
                }

                Iterator   operator-=( difference_type value)
                {
                    std::cout << "imheeere : " << *_ptr << std::endl;
                    this->_ptr -= value;
                    std::cout << "imheeere : " << *_ptr << std::endl;
                    return (*this);
                }

                reference   operator[]( size_type index ) const
                {
                    return (this->_ptr[index]);
                }
                // operator    value_type() { return _ptr; }
                operator Iterator<const Type>()
                {
                    return (Iterator< const Type>(*_ptr));
                }

        private:
            pointer    _ptr;
    };

    template< typename Type>
    Iterator<Type>   operator+(size_t value, const Iterator<Type> & src)
    {
        Iterator<Type>   ret(src);

        // ret._ptr = src._ptr + value;
        ret += value;
        return (ret);
    }
};

#endif
