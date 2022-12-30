
#ifndef __BIDIRECTIONAL_ITERATOR_HPP
# define __BIDIRECTIONAL_ITERATOR_HPP

# include "iterators_traits.hpp"
# include "iterator.hpp"
# include <iostream>
# include "../containers/map.hpp"
# include "avl_self_balancing_binary_search_tree_utils.hpp"



namespace ft
{
    template < typename TreeNode, class Type>
    class   bidirectional_iterator  : public ft::iterator_traits<ft::iterator<ft::bidirectional_iterator_tag, Type> >
    {
        private:
            typedef typename Type::first_type                            Key;
            typedef typename Type::second_type                           Value;
        public:

            typedef typename ft::iterator_traits<ft::iterator<ft::bidirectional_iterator_tag, Type> >::value_type        value_type;
            typedef typename ft::iterator_traits<ft::iterator<ft::bidirectional_iterator_tag, Type> >::difference_type   difference_type;
            typedef typename ft::iterator_traits<ft::iterator<ft::bidirectional_iterator_tag, Type> >::pointer           pointer;
            typedef typename ft::iterator_traits<ft::iterator<ft::bidirectional_iterator_tag, Type> >::reference         reference;
            typedef typename ft::iterator_traits<ft::iterator<ft::bidirectional_iterator_tag, Type> >::iterator_category iterator_category;
            typedef          size_t                                                                                      size_type;

            bidirectional_iterator( const bidirectional_iterator& src)
            {
                this->__ptr = src.__ptr;
                this->__tree = src.__tree;
            }

            bidirectional_iterator( TreeNode* x, TreeNode* tree )
            {
                this->__ptr = x;
                this->__tree = tree;
            }

            bidirectional_iterator( void ) : __ptr(nullptr), __tree(nullptr)
            { return; }

            ~bidirectional_iterator( void ) { return; }

            bidirectional_iterator    &operator=( bidirectional_iterator const & src)
            {
                if (this != &src)
                {
                    this->__ptr = src.__ptr;
                    this->__tree = src.__tree;
                }
                return ( *this );
            }

            value_type *base() const { return this->__ptr; }

            template< class AnotherNodeType, class AnotherType>
            bool    operator==( bidirectional_iterator<AnotherNodeType, AnotherType> const & src ) const
            { return (this->__ptr == src.__ptr && this->__tree == src.__tree); }

            template< class AnotherNodeType, class AnotherType>
            bool    operator!=( bidirectional_iterator<AnotherNodeType, AnotherType> const & src )
            { return !(*this == src); }

            bidirectional_iterator    &operator++()
            {
        		if (this->__ptr == nullptr)
                {
        			this->__ptr = this->__tree;
        			while (this->__ptr != nullptr && this->__ptr->__left != nullptr)
        				this->__ptr = this->__ptr->__left;
        		}
        		else if (this->__ptr->__right != nullptr)
                {
        			this->__ptr = this->__ptr->__right;
        			while (this->__ptr->__left != nullptr)
        				this->__ptr = this->__ptr->__left;
        		}
        		else
                {
        			TreeNode* top_node = this->__ptr->__parent;
        			while (top_node != nullptr && this->__ptr == top_node->__right)
                    {
        				this->__ptr = top_node;
        				top_node = top_node->__parent;
        			}
        			this->__ptr = top_node;
        		}
        		return (*this);
            }

            bidirectional_iterator    operator++( int )
            {
			    bidirectional_iterator tmp = *this;
			    ++(*this);
			    return (tmp);
            }

            bidirectional_iterator    &operator--()
            {
			    if (this->__ptr == nullptr)
                {
			    	this->__ptr = this->__tree;
			    	while (this->__ptr != nullptr && this->__ptr->__right != nullptr)
			    		this->__ptr = this->__ptr->__right;
			    }
			    else if (this->__ptr->__left != nullptr)
                {
			    	this->__ptr = this->__ptr->__left;
			    	while (this->__ptr->__right != nullptr)
			    		this->__ptr = this->__ptr->__right;
			    }
			    else
                {
			    	TreeNode* top_node = this->__ptr->__parent;
			    	while (top_node != nullptr && this->__ptr == top_node->__left)
                    {
			    		this->__ptr = top_node;
			    		top_node = top_node->__parent;
			    	}
			    	this->__ptr = top_node;
			    }
			    return (*this);
            }

            bidirectional_iterator    operator--( int )
            {
			    bidirectional_iterator tmp = *this;
			    --(*this);
			    return (tmp);
            }

            reference       operator*( void ) const { return this->__ptr->__pair; }
            pointer         operator->( void ) const { return &(operator*()); }

            operator bidirectional_iterator<TreeNode,const Type>()
            {
                return (bidirectional_iterator< TreeNode, const Type>(__ptr, __tree));
            }
        private:
            TreeNode*     __ptr;
            TreeNode*     __tree;
    };
}

#endif
