
#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>

namespace ft
{
    template <typename Type>
    class iterator : public std::iterator<random_access_iterator_tag, Type>
    {
        public:
            iterator(){}
            ~iterator(){}

        public:
            iterator &operator=( const iterator & src)
            {
                this->_ptr = src._ptr;
                return (*this);
            }
            bool    operator==( const iterator & src )
            {
                return ((this->_ptr == src._ptr));
            }
            bool    operator!=( const iterator & src )
            {
                return ((this->_ptr != src._ptr));
            }
            bool    operator<( const iterator & src )
            {
                return ((this->_ptr < src._ptr));
            }
            bool    operator<=( const iterator & src )
            {
                return ((this->_ptr <= src._ptr));
            }
            bool    operator>( const iterator & src )
            {
                return ((this->_ptr > src._ptr));
            }
            bool    operator>=( const iterator & src )
            {
                return ((this->_ptr >= src._ptr));
            }
            iterator    operator+(iterator const & src) const
            {
                iterator	ret;

                ret._ptr = this->_ptr + src._ptr;
                return (ret);
            }
            iterator    operator+(int nbr) const
            {
                iterator	ret;

                ret._ptr = this->_ptr + nbr;
                return (ret);
            }

        private:
            T*  _ptr;
    };
    
} // namespace ft


#endif
