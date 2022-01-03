
#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "iterators_traits.hpp"

namespace ft
{
    template <typename Iter>
    class reverse_iterator
    {
        public:
    /*
    **  Member types:
    */
        typedef Iter                                            iterator_type;
        typedef typename ft::iterator_traits<Iter>::iterator_category    iterator_category;
        typedef typename ft::iterator_traits<Iter>::value_type           value_type;
        typedef typename ft::iterator_traits<Iter>::difference_type      difference_type;
        typedef typename ft::iterator_traits<Iter>::pointer              pointer;
        typedef typename ft::iterator_traits<Iter>::reference            reference;
    /*
    **  Memeber functions:
    */
        /*
        **  Constructor:
        */
        reverse_iterator()
        {
            // std::cout << KYEL << "DBG_REVITERATOR: (default constructor)" << std::endl << KNRM;
        }

        explicit reverse_iterator( iterator_type x ) : _iterator(x)
        {
            // std::cout << KYEL << "DBG_REVITERATOR: (iterator constructor)" << std::endl << KNRM;
        }

        template< class U >
        reverse_iterator( const reverse_iterator<U>& other )
        {
            this->_iterator = other.base();
            // std::cout << KYEL << "DBG_REVITERATOR: (copy constructor)" << std::endl << KNRM;
        }
        /*
        **  Operator= :
        */
        template< class U >
        reverse_iterator& operator=( const reverse_iterator<U>& other )
        {
            // std::cout << KYEL << "DBG_REVITERATOR: operator= " << std::endl << KNRM;
            this->_iterator = other.base();
            return (*this);
        }
        /*
        **  Base:
        */
        iterator_type base() const
        {
            return (this->_iterator);
        }
        /*
        **  Operator* :
        */
        reference operator*() const
        {
            iterator_type it2(_iterator);
            return *--it2;
        }
        /*
        **  Operator-> :
        */
        pointer operator->() const
        {
            return ((this->base() - 1).operator->());
        }
        /*
        **  Operator[] :
        */
        reference operator[]( difference_type n ) const
        {
            return (this->base()[-n - 1]);
        }

        /*
        **  Operator++ :
        */
        reverse_iterator& operator++()
        {
            this->_iterator--;
            return (*this);
        }
        /*
        **  Operator++( int ) :
        */
        reverse_iterator operator++( int )
        {
            reverse_iterator    prev = *this;

            this->_iterator--;
            return (prev);
        }
        /*
        **  Operator-- :
        */
        reverse_iterator& operator--()
        {
            this->_iterator++;
            return (*this);
        }
        /*
        **  Operator--( int ) :
        */
        reverse_iterator operator--( int )
        {
            reverse_iterator    prev = *this;

            this->_iterator++;
            return (prev);
        }
        /*
        **  Operator+( difference_type n ) :
        */
        reverse_iterator operator+( difference_type n ) const
        {
            // reverse_iterator    ret(this->_iterator.operator-(n));
            (this->base() - 1) -= n;
            // return (reverse_iterator(this->base() - n));
            return (*this);
        }
        /*
        **  Operator-( difference_type n ) :
        */
        reverse_iterator operator-( difference_type n ) const
        {
            reverse_iterator    ret;

            ret._iterator = (this->base() + n);
            return (ret);
        }
        /*
        **  Operator+= :
        */
        reverse_iterator& operator+=( difference_type n )
        {
            this->_iterator -= n;
            return (*this);
        }
        /*
        **  Operator-= :
        */
        reverse_iterator& operator-=( difference_type n )
        {
            this->_iterator += n;
            return (*this);
        }

        private:
            iterator_type   _iterator;
    };  //  Class reverse_iterator

    template< class Iterator1, class Iterator2 >
    bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (lhs.base() == rhs.base());
    }

    template< class Iter >
    reverse_iterator<Iter>
        operator+( typename reverse_iterator<Iter>::difference_type n,
                    const reverse_iterator<Iter>& it )
    {
        reverse_iterator<Iter>  ret(it);

        ret += n;
        return (ret);
    }

    template< class Iterator >
    typename reverse_iterator<Iterator>::difference_type
        operator-( const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs )
    {
        return (rhs.base() - lhs.base());
    }

    template< class Iterator1, class Iterator2 >
    bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (lhs.base() != rhs.base());
    }

    template< class Iterator1, class Iterator2 >
    bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (!(lhs.base() < rhs.base()));
    }

    template< class Iterator1, class Iterator2 >
    bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (!(lhs.base() <= rhs.base()));
    }

    template< class Iterator1, class Iterator2 >
    bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (!(lhs.base() > rhs.base()));
    }

    template< class Iterator1, class Iterator2 >
    bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (!(lhs.base() >= rhs.base()));
    }
};  //  namespace ft

#endif
