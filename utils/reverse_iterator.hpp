
#ifndef REVRESE_ITERATOR_HPP
#define REVRESE_ITERATOR_HPP

#include "random_access_iterator.hpp"
#include "enable_if.hpp"

namespace ft
{
    template <typename Type>
    class reverse_iterator
    {
    public:

            typedef     Type                             value_type;
            typedef     Type*                            pointer;
            typedef     Type&                            reference;
            typedef     std::ptrdiff_t                   difference_type;
            typedef     std::random_access_iterator_tag  iterator_category;
            typedef     size_t                           size_type;

            /*
            ** Constructors:
            */
                /*
                ** Default Constructor:
                */
                reverse_iterator( void )
                {
                }

                /*
                ** Copy Constructor:
                */
                template<typename InputIterator>
                reverse_iterator( InputIterator const & src)
                {
                    this->_iterator = src;
                }

                reverse_iterator( typename ft::Iterator<value_type> src ) : _iterator(src)
                {
                }

                /*
                ** Assignment Operator:
                */
                reverse_iterator    &operator=( reverse_iterator const & src )
                {
                    this->_iterator = src._iterator;
                    return ( *this );
                }

                // const Iterator    &operator=( Iterator const & src ) const
                // {
                    // this->_ptr = src._ptr;
                    // return ( *this );
                // }

                /*
                ** Default Destructor:
                */
                ~reverse_iterator()
                {
                    return ;
                }

            /*
            ** Comparison for equivalence:
            */
                /*
                ** Equality opearator:
                */
                bool    operator==( reverse_iterator const & src ) const
                {
                    return (this->_iterator == src._iterator);
                }

                /*
                ** Inequality opearator:
                */
                bool    operator!=( reverse_iterator const & src ) const
                {
                    return (this->_iterator != src._iterator);
                }

            /*
            ** Incrementation / Decrementaion Operators:
            */
                /*
                ** Pre-increment opearator:
                */
                reverse_iterator    &operator++()
                {
                    this->_iterator--;
                    return (*this);
                }

                /*
                ** Post-increment opearator:
                */
                reverse_iterator    operator++( int )
                {
                        reverse_iterator   prev = *this;

                        this->_iterator.operator--(1);
                        return (prev);
                }

                /*
                ** Pre-decrement opearator:
                */
                reverse_iterator    &operator--() const
                {
                    this->_iterator++;
                    return (*this);
                }

                /*
                ** Post-decrement opearator:
                */
                reverse_iterator    operator--( int ) const
                {
                        reverse_iterator   prev = *this;

                        this->_iterator++(1);
                        return (prev);
                }

            /*
            ** Dereference Operators:
            */
                reference   operator*( void ) const
                {
                    return (this->_iterator.operator*());
                    // return (*(this->_iterator));
                }
                //  operator->() {}

                pointer   operator->( void ) const
                {
                    return (&this->_iterator.operator*());
                    // return (&operator*());
                }

                difference_type   operator-(reverse_iterator const & src)
                {
                    reverse_iterator   ret;

                    // ret._ptr = this->_ptr - src._ptr;
                    // return (ret);
                    return (this->_iterator - src._iterator);
                }

                reverse_iterator   operator-(size_type value)
                {
                    reverse_iterator   ret;

                    ret._iterator = this->_iterator + value;
                    return (ret);
                }

                reverse_iterator   operator+(size_type value)
                {
                    reverse_iterator   ret;

                    ret._iterator = this->_iterator - value;
                    return (ret);
                }

                bool    operator<( reverse_iterator const & src ) const
                {
                    return (this->_iterator >= src._iterator);
                }

                bool    operator<=( reverse_iterator const & src ) const
                {
                    return (this->_iterator > src._iterator);
                }

                // Iterator operator+(int n, Iterator const & src)
                // {
                    // return (&(*src) + n);
                // }

                bool    operator>( reverse_iterator const & src ) const
                {
                    return (this->_iterator <= src._iterator);
                }

                bool    operator>=( reverse_iterator const & src ) const
                {
                    return (this->_iterator < src._iterator);
                }

                reference   operator+=( size_type value)
                {
                    this->_iterator -= value;
                    return (*this);
                }

                reference   operator-=( size_type value)
                {
                    this->_iterator += value;
                    return (*this);
                }

                reference   operator[]( size_type index )
                {
                    return (this->_iterator[index]);
                }

                Iterator<Type> base() const
                {
                    return (this->_iterator);
                }

    private:
        ft::Iterator<Type> _iterator;
    };  // class reverse_iterator

}; // namespace ft


// namespace ft
// {
//     template <typename Iterator>
//     class reverse_iterator
//     {
//         public:
//         /*
//         **  Member Types:
//         */
//             typedef     Iterator                                                        iterator_type;
//             typedef     typename std::iterator_traits<Iterator>::iterator_category      iterator_category;
//             typedef     typename std::iterator_traits<Iterator>::value_type             value_type;
//             typedef     typename std::iterator_traits<Iterator>::difference_type	    difference_type;
//             typedef     typename std::iterator_traits<Iterator>::pointer	            pointer;
//             typedef     typename std::iterator_traits<Iterator>::reference              reference;
//         /*
//         **  Constructors:
//         */
//             /*
//             **  Default Constructor:
//             */
//             reverse_iterator()
//             {
//                 this->_iterator->_ptr = NULL;
//                 return ;
//             }
//             /*
//             **  Initialization Constructor:
//             */
//             explicit reverse_iterator (iterator_type it)
//             {
//                 this->_iterator->_ptr = it._ptr;
//             }
//             /*
//             ** Copy Constructor:
//             */
//             template <class Iter>
//             reverse_iterator (const reverse_iterator<Iter>& rev_it)
//             {
//                 this->_iterator->_ptr = rev_it._iterator._ptr;
//             }

//         /*
//         **  Base:
//         */
//             iterator_type base() const
//             {
//                 return (this->_iterator);
//             }

//         /*
//         **  Operator*:
//         */
//             reference operator*() const
//             {
//                 return (this->_iterator->operator*());
//             }

//         /*
//         **  Operator+:
//         */
//             reverse_iterator operator+ (difference_type n) const
//             {
//                 reverse_iterator    ret;

//                 ret._iterator._ptr = this->_iterator._ptr - n;
//                 return (ret);
//             }

//         private:
//             ft::Iterator<Iterator>  _iterator;

//     };
// };

#endif