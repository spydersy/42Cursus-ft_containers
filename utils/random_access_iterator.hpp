
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
            typedef     const Type                             const_value_type;
            typedef     Type*                            pointer;
            typedef     Type&                            reference;
            typedef     std::ptrdiff_t                   difference_type;
            typedef     std::random_access_iterator_tag  iterator_category;
            typedef     size_t                           size_type;

                Iterator( void )
                {
                    this->_ptr = NULL;
                }

                Iterator( Iterator const & src )
                {
                    this->_ptr = src._ptr;
                }

                Iterator( value_type &src )
                {
                    this->_ptr = &src;
                }

                Iterator    &operator=( Iterator const & src)
                {
                    this->_ptr = src._ptr;
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
                    // std::cout << "DBBBBBBBBBBBBG: " << &(this->_ptr) << std::endl;
                    // std::cout << "DBBBBBBBBBBBBG: " <<  (this->_ptr) << std::endl;
                    return (*(this->_ptr));
                }

                pointer   operator->( void ) const
                {
                    return (&operator*());
                }

                difference_type   operator-(Iterator const & src)
                {
                    Iterator   ret;

                    // ret._ptr = this->_ptr - src._ptr;
                    // return (ret);
                    return (this->_ptr - src._ptr);
                }

                Iterator   operator-(size_type value)
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

                Iterator   operator-=( size_type value)
                {
                    this->_ptr -= value;
                    return (*this);
                }

                reference   operator[]( size_type index ) const
                {
                    return (this->_ptr[index]);
                }
                // operator    value_type() { return _ptr; }
                operator Iterator<const Type>()
                {
                    // std::cout << "Operator Callleed" << std::endl;
                    return (Iterator< const Type>(*_ptr));
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
                    this->_ptr = &address;
                }
    };
};

#endif
