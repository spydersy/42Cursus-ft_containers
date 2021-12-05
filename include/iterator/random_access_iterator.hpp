
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
            typedef     Type                        value_type;
            typedef     Type*                       pointer;
            typedef     Type&                       reference;
            typedef     std::ptrdiff_t              difference_type;
            typedef     random_access_iterator_tag  iterator_category;

            /*
            ** Constructors:
            */
                /*
                ** Default Constructor:
                */            
                Iterator( void )
                {
                    arr[0] = 1;
                    arr[1] = 2;
                    arr[2] = 3;
                    arr[3] = 4;
                    arr[4] = 5;
                    arr[5] = 6;
                    arr[6] = 7;
                    arr[7] = 8;
                    arr[8] = 9;
                    arr[9] = 10;
                    this->_ptr = arr;
                    std::cout << "<void>: Iterator Constructor Called" << std::endl;
                }

                /*
                ** Copy Constructor:
                */
                Iterator( Iterator const & src )
                {
                    this->_ptr = src._ptr;
                    std::cout << "<copy>: Iterator Constructor Called" << std::endl;
                }

                /*
                ** Assign Constructor:
                */
                Iterator    &operator=( Iterator const & src )
                {
                    this->_ptr = src._ptr;
                    std::cout << "<assign>: Iterator Constructor Called" << std::endl;
                    return ( *this );
                }

                /*
                ** Default Destructor:
                */
                ~Iterator(){ std::cout << "Iterator Destructor Called" << std::endl; }

            /*
            ** Comparison for equivalence:
            */

                /*
                ** Equality opearator:
                */
                bool    operator==( Iterator const & src )
                {
                    std::cout << "< operator== >" << std::endl;
                    return (this->_ptr == src._ptr);
                }

                /*
                ** Inequality opearator:
                */
                bool    operator!=( Iterator const & src )
                {
                    std::cout << "< operator!= >" << std::endl;
                    return (this->_ptr != src._ptr);
                }

                Type    &operator*( void ) const
                {
                    return (*(this->_ptr));
                }

                Type    &operator->( void ) const
                {
                    return (*(this->_ptr));
                }
                
                Iterator    &operator++()
                {
                    this->_ptr++;
                    return (*this);
                }

                Iterator    operator++(int)
                {
                        Iterator   prev = *this;

                        this->_ptr++;
                        return (prev);
                }

                Iterator    &operator--()
                {
                    this->_ptr++;
                    return (*this);
                }

                Iterator    operator--(int)
                {
                        Iterator   prev = *this;

                        this->_ptr++;
                        return (prev);
                }

                Iterator   operator-(Iterator const & src) const
                {
                    Iterator   ret;

                    ret._ptr = this->_ptr - src._ptr;
                    return (ret);
                }

                Iterator   operator-(size_t value) const
                {
                    Iterator   ret;

                    ret._ptr = this->_ptr - value;
                    return (ret);
                }

                Iterator   operator+(size_t value) const
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

                Iterator    &operator+=( size_t value)
                {
                    this->operator+(value);
                    return (*this);
                }

                Iterator    &operator-=( size_t value)
                {
                    this->operator-(value);
                    return (*this);
                }

                Type    &operator[]( size_t index ) const
                {
                    return (this->_ptr[index]);
                }

        private:
            Type    *_ptr;
            int     arr[10];
    };
};


#endif
