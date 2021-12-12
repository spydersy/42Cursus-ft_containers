
#ifndef REVRESE_ITERATOR_HPP
#define REVRESE_ITERATOR_HPP

#include "random_access_iterator.hpp"

namespace ft
{
    template <typename Iterator>
    class reverse_iterator
    {
        public:
        /*
        **  Member Types:
        */
            typedef     Iterator                                                        iterator_type;
            typedef     typename std::iterator_traits<Iterator>::iterator_category      iterator_category;
            typedef     typename std::iterator_traits<Iterator>::value_type             value_type;
            typedef     typename std::iterator_traits<Iterator>::difference_type	    difference_type;
            typedef     typename std::iterator_traits<Iterator>::pointer	            pointer;
            typedef     typename std::iterator_traits<Iterator>::reference              reference;
        /*
        **  Constructors:
        */
            /*
            **  Default Constructor:
            */
            reverse_iterator()
            {
                this->_iterator->_ptr = NULL;
                return ;
            }
            /*
            **  Initialization Constructor:
            */
            explicit reverse_iterator (iterator_type it)
            {
                this->_iterator->_ptr = it._ptr;
            }
            /*
            ** Copy Constructor:
            */
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
            {
                this->_iterator->_ptr = rev_it._iterator._ptr;
            }

        /*
        **  Base:
        */
            iterator_type base() const
            {
                return (this->_iterator);
            }

        /*
        **  Operator*:
        */
            reference operator*() const
            {
                return (this->_iterator->operator*());
            }

        /*
        **  Operator+:
        */
            reverse_iterator operator+ (difference_type n) const
            {
                reverse_iterator    ret;

                ret._iterator._ptr = this->_iterator._ptr - n;
                return (ret);
            }

        private:
            ft::Iterator<Iterator>  _iterator;

    };
};

#endif