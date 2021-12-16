
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
                    this->_ptr = NULL;
                }

                /*
                ** Copy Constructor:
                */
                Iterator( Iterator const & src )
                {
                    this->_ptr = src._ptr;
                }

                /*
                ** Assignment Operator:
                */
                Iterator    &operator=( Iterator const & src ) const
                {
                    this->_ptr = src._ptr;
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
                ~Iterator()
                {
                    return ;
                }

            /*
            ** Comparison for equivalence:
            */
                /*
                ** Equality opearator:
                */
                bool    operator==( Iterator const & src ) const
                {
                    return (this->_ptr == src._ptr);
                }

                /*
                ** Inequality opearator:
                */
                bool    operator!=( Iterator const & src ) const
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
                Iterator    &operator++() const
                {
                    this->_ptr++;
                    return (*this);
                }

                /*
                ** Post-increment opearator:
                */
                Iterator    operator++( int ) const
                {
                        Iterator   prev = *this;

                        this->_ptr++;
                        return (prev);
                }

                /*
                ** Pre-decrement opearator:
                */
                Iterator    &operator--() const
                {
                    this->_ptr--;
                    return (*this);
                }

                /*
                ** Post-decrement opearator:
                */
                Iterator    operator--( int ) const
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

                pointer   operator->( void ) const
                {
                    return (&operator*());
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

                // Iterator operator+(int n, Iterator const & src)
                // {
                    // return (&(*src) + n);
                // }

                bool    operator>( Iterator const & src ) const
                {
                    return (this->_ptr > src._ptr);
                }

                bool    operator>=( Iterator const & src ) const
                {
                    return (this->_ptr >= src._ptr);
                }

                reference   operator+=( size_type value) const
                {
                    this->_ptr += value;
                    return (*this);
                }

                reference   operator-=( size_type value) const
                {
                    this->_ptr -= value;
                    return (*this);
                }

                reference   operator[]( size_type index ) const
                {
                    return (this->_ptr[index]);
                }

        private:
            value_type    *_ptr;
            // value_type      arr[10];
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
    };
};

#endif
