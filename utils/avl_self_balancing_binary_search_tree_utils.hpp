#ifndef __AVL_SELF_BALANCED_BINARY_SEARCH_TREE_UTILS__
# define __AVL_SELF_BALANCED_BINARY_SEARCH_TREE_UTILS__

#include <iostream>
#include "pair.hpp"

# define KNRM       "\x1B[0m"
# define KRED       "\x1B[31m"
# define KGRN       "\x1B[32m"
# define KYEL       "\x1B[33m"
# define KBLU       "\x1B[34m"
# define KMAG       "\x1B[35m"
# define KCYN       "\x1B[36m"
# define KWHT       "\x1B[37m"

    template < class Key,                                          // map::key_type
               class T,                                            // map::mapped_type
               class Alloc>                                        // map::allocator_type
    class TreeNode
    {
    /*
    ** Member Types :
    */
    private:
        typedef ft::pair<const Key, T>  value_type;

    public:
        int             __height;

        TreeNode*       __left;
        TreeNode*       __right;
        TreeNode*       __parent;

        Alloc           __allocator;
        value_type      __pair;

    public:
        TreeNode(const value_type& pair) : __height(0),
                                     __left(nullptr),
                                     __right(nullptr),
                                     __parent(nullptr),
                                     __pair(pair)
        { return; }

        ~TreeNode( void )
        { return; }

        TreeNode &operator=(TreeNode const & src)
        {
            this->__allocator.construct(&this->__pair, src.__pair);
            this->__height = src.__height;
            this->__left = src.__left;
            this->__right = src.__right;
            this->__parent = src.__parent;
            return *this;
        };
    }; // class TreeNode

#endif
