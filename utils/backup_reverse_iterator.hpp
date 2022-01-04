
#ifndef REVRESE_ITERATOR_HPP
#define REVRESE_ITERATOR_HPP

#include "random_access_iterator.hpp"
#include "enable_if.hpp"
// #include "vector.hpp"

namespace ft
{
    template <typename Type>
    class reverse_iterator : public ft::iterator_traits<Type>
    {
    public:

            // typedef     Type                             value_type;
            // typedef     Type*                            pointer;
            // typedef     typename ft::Iterator<Type>::reference                            reference;
            // typedef     std::ptrdiff_t                   difference_type;
            // typedef     std::random_access_iterator_tag  iterator_category;
            // typedef     size_t                           size_type;

            typedef     typename Type::iterator_category  iterator_category;
            typedef     typename Type::value_type         value_type;
            typedef     typename Type::pointer            pointer;
            typedef     typename Type::reference          reference;
            typedef     typename Type::difference_type    difference_type;
            typedef     size_t                            size_type;

            // typedef typename ft::Iterator<Type> iterator;

            // typedef     Type                             value_type;
            // typedef     const Type                             const_value_type;
            // typedef     Type*                            pointer;
            // typedef     Type&                            reference;
            // typedef     std::ptrdiff_t                   difference_type;
            // typedef     std::random_access_iterator_tag  iterator_category;
            // typedef     size_t                           size_type;


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
                reverse_iterator( InputIterator const & src) : _iterator(src)
                {
                    // this->_iterator = src;
                }

                reverse_iterator( Type const & src) : _iterator(src)
                {
                    // this->_iterator = src;
                }

                reverse_iterator( typename ft::Iterator<value_type> src ) : _iterator(src)
                {
                }

                /*
                ** Assignment Operator:
                */
            //    template<typename InputIterator>
                reverse_iterator    &operator=( Type const & src )
                {
                    this->_iterator = src;
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
                bool    operator==( reverse_iterator const & src )
                {
                    return ((this->_iterator == src._iterator));
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
                reverse_iterator    operator--( int )
                {
                        reverse_iterator   prev = *this;

                        this->_iterator++(1);
                        return (prev);
                }

            /*
            ** Dereference Operators:
            */
                reference   operator*( void )
                {
                    return (*_iterator);
                    // return (*(this->_iterator));
                }
                //  operator->() {}

                pointer   operator->( void )
                {
                    return (_iterator.operator->());
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
                    return (this->base()[-index-1]);
                    // return (this->_iterator[index]);
                }

                Iterator<Type> base() const
                {
                    return (this->_iterator);
                }

                operator reverse_iterator<const Type>()
                {
                    return (reverse_iterator< const Type>(_iterator));
                }


    private:
        Type _iterator;


    };  // class reverse_iterator

    template< typename Type>
    reverse_iterator<Type>   operator+(size_t value, const reverse_iterator<Type> & src)
    {
        reverse_iterator<Type>   ret(src);

        // ret._ptr = src._ptr + value;
        ret += value;
        return (ret);
    }
}; // namespace ft

#endif