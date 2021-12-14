
#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>
#include <iterator>

namespace   ft
{
    template <typename Type>
    class   Iterator
    {
        public:

            /*
            ** Member Types:
            */
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
                Iterator( void )
                {
                    // arr[0] = 1;
                    // arr[1] = 2;
                    // arr[2] = 3;
                    // arr[3] = 4;
                    // arr[4] = 5;
                    // arr[5] = 6;
                    // arr[6] = 7;
                    // arr[7] = 8;
                    // arr[8] = 9;
                    // arr[9] = 10;
                    // this->_ptr = arr;

                    this->_ptr = NULL;
                    // this->_ptr = std::nullptr_t;
                    // std::cout << "<void>: Iterator Constructor Called" << std::endl;
                }

                /*
                ** Copy Constructor:
                */
                Iterator( Iterator const & src )
                {
                    this->_ptr = src._ptr;
                    // std::cout << "<copy>: Iterator Constructor Called" << std::endl;
                }

                /*
                ** Assignment Operator:
                */
                Iterator    &operator=( Iterator const & src )
                {
                    this->_ptr = src._ptr;
                    // std::cout << "<assign>: Iterator Constructor Called" << std::endl;
                    return ( *this );
                }

                /*
                ** Default Destructor:
                */
                ~Iterator()
                {
                    // std::cout << "Iterator Destructor Called" << std::endl;
                }

            /*
            ** Comparison for equivalence:
            */
                /*
                ** Equality opearator:
                */
                bool    operator==( Iterator const & src )
                {
                    // std::cout << "< operator== >" << std::endl;
                    return (this->_ptr == src._ptr);
                }

                /*
                ** Inequality opearator:
                */
                bool    operator!=( Iterator const & src )
                {
                    // std::cout << "< operator!= >" << std::endl;
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
                reference   operator*( void ) const
                {
                    return (*(this->_ptr));
                }
                //  operator->() {}

                reference   operator->( void ) const
                {
                    return (*(this->_ptr));
                }

                difference_type   operator-(Iterator const & src) const
                {
                    Iterator   ret;

                    // ret._ptr = this->_ptr - src._ptr;
                    // return (ret);
                    return (this->_ptr - src._ptr);
                }

                Iterator   operator-(size_type value) const
                {
                    Iterator   ret;

                    ret._ptr = this->_ptr - value;
                    return (ret);
                }

                Iterator   operator+(size_type value) const
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

                Iterator    &operator+=( size_type value)
                {
                    this->operator+(value);
                    return (*this);
                }

                Iterator    &operator-=( size_type value)
                {
                    this->operator-(value);
                    return (*this);
                }

                reference   operator[]( size_type index ) const
                {
                    return (this->_ptr[index]);
                }

            /*
            ** Setters:
            */
                /*
                **  _ptr Setter:
                */
                void    setPtr( reference address )
                {
                    _ptr = &address;
                }
        private:
            value_type    *_ptr;
            // value_type      arr[10];
    };
};

#endif
