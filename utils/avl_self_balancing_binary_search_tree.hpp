
#ifndef __AVL_SELF_BALANCING_BINARY_SEARCH_TREE__
# define __AVL_SELF_BALANCING_BINARY_SEARCH_TREE__

# include "avl_self_balancing_binary_search_tree_utils.hpp"
# include "../containers/vector.hpp"
# include "pair.hpp"
# include "make_pair.hpp"

# define ROOT_NODE  0
# define LEFT_NODE  -1
# define RIGHT_NODE 1

template < class Key,                         // map::key_type
           class T,                           // map::mapped_type
           class Compare,                     // map::key_compare
           class Alloc, class node_allocator> // map::allocator_type
class avl_sbbst
{
private:

    typedef TreeNode<Key, T, Alloc>   node;
public:
    typedef Key                                                      key_type;
    typedef T                                                        mapped_type;
    typedef Compare                                                  key_compare;
    typedef ft::pair<const key_type,mapped_type>                     value_type;
    typedef class value_compare_class                                value_comp;
    typedef Alloc                                                    allocator_type;
    typedef value_type&                                              reference;
    typedef const value_type&                                        const_reference;
    typedef value_type*                                              pointer;
    typedef const value_type*                                        const_pointer;
    typedef ft::bidirectional_iterator<node, value_type>             iterator;
    typedef ft::bidirectional_iterator<node, const value_type>       const_iterator;
    typedef ft::reverse_iterator<iterator>                           reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>                     const_reverse_iterator;
	typedef	typename ft::iterator_traits<iterator>::difference_type  difference_type;
	typedef size_t													 size_type;
private:
    node_allocator __node_allocator;
    allocator_type __allocator;
    key_compare    __key_comp;
    node*          __root;
    size_type      __size;
public:
    explicit avl_sbbst (const key_compare& comp = key_compare(),
                  const allocator_type& alloc = allocator_type())
    {
        this->__key_comp = comp;
        this->__allocator = alloc;
        this->__root = nullptr;
        this->__size = 0;
    }

    template <class InputIterator>
    avl_sbbst (InputIterator first, InputIterator last,
           const key_compare& comp = key_compare(),
           const allocator_type& alloc = allocator_type())
    {
        this->__key_comp = comp;
        this->__allocator = alloc;
        this->__root = nullptr;
        this->__size = 0;

        this->insert(first, last);
    }

    avl_sbbst (const avl_sbbst& x)
    {
        this->__root = nullptr;
        this->__size = 0;
        this->operator=(x);
    }

    ~avl_sbbst()
    { free_all_nodes(this->__root); }

    avl_sbbst& operator= (const avl_sbbst& x)
    {
        if (this != &x)
        {
            if (this->__size)
                this->clear();
            this->__key_comp = x.__key_comp;
            this->__node_allocator = x.__node_allocator;
            this->__allocator = x.__allocator;
            this->__key_comp = x.__key_comp;
            this->__size = 0;
            this->__root = nullptr;

            if (x.__size == 0)
                return *this;
            insert(x.begin(), x.end());
        }
        return *this;
    }

    iterator begin()
    {
        node* min_val = get_min_val();
        if (this->__size == 0)
            return this->end();
        return iterator(min_val, this->__root);
    }

    const_iterator begin() const
    {
        node* min_val = get_min_val();
        if (this->__size == 0)
            return this->end();
        return const_iterator(min_val, this->__root);
    }

    iterator end()
    { return iterator(nullptr, this->__root); }

    const_iterator end() const
    { return const_iterator(nullptr, this->__root); }

    reverse_iterator rbegin()
    { return reverse_iterator(this->end()); }

    const_reverse_iterator rbegin() const
    { return const_reverse_iterator(this->end()); }

    reverse_iterator rend()
    { return reverse_iterator(this->begin()); }

    const_reverse_iterator rend() const
    { return const_reverse_iterator(this->begin()); }

    bool empty() const
    { return this->__size == 0; }

    size_type size() const
    { return this->__size; }

    size_type max_size() const
    { return this->__allocator.max_size(); }

    mapped_type& operator[] (const key_type& k)
    { return insert(ft::make_pair<key_type, mapped_type>(k, mapped_type())).first->second; }

    ft::pair<iterator,bool> insert (const value_type& val)
    {
        if (__root == nullptr)
        {
            node node_val(val);
            this->__root = this->__node_allocator.allocate(1);
            this->__node_allocator.construct(&this->__root[0], node_val);
            this->__size++;
            return ft::make_pair<iterator, bool>(iterator(this->__root, this->__root), true);
        }
        else
        {
            iterator it = find(val.first);
            if (it != end())
            {
                return ft::make_pair<iterator, bool>(it, false);
            }
            __root = recursive_insertion(this->__root, val);
            return ft::make_pair<iterator, bool>(find(val.first), true);
        }
    }

    iterator insert (iterator position, const value_type& val)
    {
        (void)position;
        return this->insert(val).first;
    }

    template <class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            this->insert(*first);
            first++;
        }
    }

    void erase (iterator position)
    {
        key_type key = position->first;
        erase(key);
    }

    size_type erase (const key_type& k)
    {
        iterator it = find(k);

        if (it == end())
            return 0;
        this->__root = recursive_erase(this->__root, k);
        return 1;
    }

    void erase (iterator first, iterator last)
    {
        ft::vector<key_type>                     keys;
        typename ft::vector<key_type>::iterator it_end;

        while (first != last)
        {
            keys.push_back(first->first);
            first++;
        }
        it_end = keys.end();
        for (typename ft::vector<key_type>::iterator it = keys.begin(); it != it_end; it++)
            erase(*it);
    }

    void swap (avl_sbbst& x)
    {
        if (this != &x)
        {
            node_allocator tmp__node_allocator = x.__node_allocator;
            allocator_type tmp__allocator = x.__allocator;
            key_compare    tmp__key_comp = x.__key_comp;
            node*          tmp__root = x.__root;
            size_type      tmp__size = x.__size;

            x.__node_allocator = this->__node_allocator;
            x.__allocator = this->__allocator;
            x.__key_comp = this->__key_comp;
            x.__root = this->__root;
            x.__size = this->__size;

            this->__node_allocator = tmp__node_allocator;
            this->__allocator = tmp__allocator;
            this->__key_comp = tmp__key_comp;
            this->__root = tmp__root;
            this->__size = tmp__size;
        }
    }

    void clear()
    {
        if (this->__size)
            erase(begin(), end());
        this->__root = nullptr;
    }

    key_compare key_comp() const
    { return this->__key_comp; }

    iterator find (const key_type& k)
    {
        node*   it = this->__root;

        while (it != nullptr)
        {
            if (this->__key_comp(it->__pair.first, k))
                it = it->__right;
            else if (this->__key_comp(k, it->__pair.first))
                it = it->__left;
            else
                return iterator(it, this->__root);
        }
        return this->end();
    }

    const_iterator find (const key_type& k) const
    {
        node*   it = this->__root;

        while (it != nullptr)
        {
            if (this->__key_comp(it->__pair.first, k))
                it = it->__right;
            else if (this->__key_comp(k, it->__pair.first))
                it = it->__left;
            else
                return const_iterator(it, this->__root);
        }
        return this->end();
    }

    size_type count (const key_type& k) const
    {
        const_iterator it = this->find(k);

        if (it == this->end())
            return 0;
        return 1;
    }

    iterator lower_bound (const key_type& k)
    {
		if (__key_comp(k, this->begin()->first))
			return this->begin();
		else if (__key_comp(k, this->rbegin()->first))
        {
            iterator it = find(k);
			if (it != end())
				return it;
			it = this->begin();
            iterator end_it = this->end();
			while (it != end_it)
            {
				if (__key_comp(k, it->first) || it->first == k)
					return (it);
				it++;
			}
		}
		return this->end();
    }

    const_iterator lower_bound (const key_type& k) const
    {
		if (__key_comp(k, this->begin()->first))
			return this->begin();
		else if (__key_comp(k, this->rbegin()->first))
        {
            const_iterator it = find(k);
			if (it != end())
				return it;
			it = this->begin();
            const_iterator end_it = this->end();
			while (it != end_it)
            {
				if (__key_comp(k, it->first) || it->first == k)
					return (it);
				it++;
			}
		}
		return this->end();
    }

    iterator upper_bound (const key_type& k)
    {
        iterator it = find(k);
        iterator tmp_it;

        if (it == end())
        {
            if (this->__size <= 1)
                return it;
            it = --end();
            if (it == end())
                return it;
            while (it != end() && __key_comp(k, it->first))
            {
                tmp_it = it;
                it--;
            }
            return tmp_it;
        }
        it++;
        return it;
    }

    const_iterator upper_bound (const key_type& k) const
    {
        const_iterator it = find(k);
        const_iterator tmp_it;

        if (it == end())
        {
            if (this->__size <= 1)
                return it;
            it = --end();
            if (it == end())
                return it;
            while (it != end() && __key_comp(k, it->first))
            {
                tmp_it = it;
                it--;
            }
            return tmp_it;
        }
        it++;
        return it;
    }

    ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
    {
        const_iterator    it = find(k);
        if (it != end())
        {
            const_iterator next = it;
            return ft::pair<const_iterator, const_iterator>(it, ++next);
        }
        else
        {
            const_iterator lower_bound_it = lower_bound(k);
            return ft::pair<const_iterator, const_iterator>(lower_bound_it, lower_bound_it);
        }
    }

    ft::pair<iterator,iterator> equal_range (const key_type& k)
    {
        iterator    it = find(k);
        if (it != end())
        {
            iterator next = it;
            return ft::pair<iterator, iterator>(it, ++next);
        }
        else
        {
            iterator lower_bound_it = lower_bound(k);
            return ft::pair<iterator, iterator>(lower_bound_it, lower_bound_it);
        }
    }

    allocator_type get_allocator() const
    { return this->__allocator; }

private:

    void free_all_nodes(node * root)
    {
        if (root != nullptr)
        {
            free_all_nodes(root->__right);
            free_all_nodes(root->__left);
            deallocate_node(root);
            this->__size--;
        }
        root = nullptr;
    }

    int balance_factor_value(node* n)
    {
        if(n->__left && n->__right)
            return n->__left->__height - n->__right->__height;
        else if(n->__left && n->__right == nullptr)
            return n->__left->__height;
        else if(n->__left== nullptr && n->__right )
            return -n->__right->__height;
        return 0;
    }

    int balance_factor_bool(node* n)
    {
        int balance_factor = 0;

        if(n->__left && n->__right)
            balance_factor = n->__left->__height - n->__right->__height;
        else if(n->__left && n->__right == nullptr)
            balance_factor = n->__left->__height;
        else if(n->__left== nullptr && n->__right )
            balance_factor = -n->__right->__height;
        return (-1 <= balance_factor && balance_factor <= 1);
    }

    int calcul_height(node* n)
    {
        if(n->__left && n->__right)
        {
            if (n->__left->__height < n->__right->__height)
                return (n->__right->__height + 1);
            else
                return  (n->__left->__height + 1);
        }
        else if(n->__left && n->__right == nullptr)
            return (n->__left->__height + 1);
        else if(n->__left == nullptr && n->__right)
            return (n->__right->__height + 1);
        return 1;
    }

    node*   do_some_magic_after_erase(node* n)
    {
        if (balance_factor_value(n) == 2)
        {
            if (balance_factor_value(n) == -1)
            {
                n = left_right_rotation(n);
            }
            else if (balance_factor_value(n) == 0 || balance_factor_value(n) == 1)
            {
                n = left_rotation(n);
            }
        }
        else if (balance_factor_value(n) == -2)
        {
            if (balance_factor_value(n) == -1 || balance_factor_value(n) == 0)
            {
                n = right_rotation(n);
            }
            else if (balance_factor_value(n) == 1)
            {
                n = right_left_rotation(n);
            }
        }
        return n;
    }

    node*   recursive_erase(node* n, const key_type& k)
    {
        if(n == nullptr)
            return n;

        int cmp = this->__key_comp(k, n->__pair.first);
        if(cmp)
            n->__left = recursive_erase(n->__left, k);
        else if(cmp == false && n->__right && n->__pair.first != k)
            n->__right = recursive_erase(n->__right, k);
        else
        {
            if(n->__left == nullptr || n->__right == nullptr)
            {
                node* temp = nullptr;
                if(n->__left)
                    temp = n->__left;
                else
                    temp = n->__right;
                if(temp == nullptr)
                {
                    temp = n;
                    n = nullptr;
                }
                else
                {
                    temp->__parent = n->__parent;
                    *n = *temp;
                }
                deallocate_node(temp);
                this->__size--;
            }
            else
            {
                node *parent = n->__parent;
                node *temp = min_node(n->__right);
                this->__allocator.construct(&(n->__pair), temp->__pair);
                n->__parent = parent;
                n->__right = recursive_erase(n->__right, temp->__pair.first);
            }
        }
        if(n == nullptr)
            return n;
        n->__height = calcul_height(n);
        if (balance_factor_bool(n) == false)
        {
            n = do_some_magic_after_erase(n);
        }
        return n;
    }

    node*   do_some_magic_after_insertion(node* n)
    {
        if (balance_factor_value(n) == 2)
        {
            if (balance_factor_value(n->__left) == 1)
                n = left_rotation(n);
            else if (balance_factor_value(n->__left) == -1)
                n = left_right_rotation(n);
        }
        else
        {
            if (balance_factor_value(n->__right) == 1)
                n = right_left_rotation(n);
            else if (balance_factor_value(n->__right) == -1)
                n = right_rotation(n);
        }
        return n;
    }

    node*   recursive_insertion(node* n, const value_type& val)
    {
        if(n == nullptr)
        {
            n = append_node(val);
            n->__left = nullptr;
            n->__right = nullptr;
            n->__parent = nullptr;
            n->__height = 1;
            return n;
        }
        else
        {
            if(this->__key_comp(val.first, n->__pair.first))
            {
                node* new_node = recursive_insertion(n->__left, val);
                n->__left = new_node;
                new_node->__parent = n;
            }
            else
            {
                node* new_node = recursive_insertion(n->__right, val);
                n->__right = new_node;
                new_node->__parent = n;
            }
        }
        n->__height = calcul_height(n);
        if (balance_factor_bool(n) == false)
        {
            n = do_some_magic_after_insertion(n);
        }
        return n;
    }

    void    deallocate_node(node* n)
    {
        this->__node_allocator.destroy(&n[0]);
        this->__node_allocator.deallocate(n, 1);
        n = nullptr;
    }

    node*    append_node(value_type pair)
    {
        node* n = this->__node_allocator.allocate(1);
        node  val(pair);
        this->__node_allocator.construct(&n[0], val);
        this->__size++;
        return n;
    }

    node*   get_min_val() const
    {
        node* it = this->__root;
        if (it == nullptr)
            return it;
        while (it->__left != nullptr)
            it = it->__left;
        return it;
    }

    node *min_node(node *n)
    {
        while (n->__left != nullptr)
            n = n->__left;
        return n;
    }

    /* ************************************************************************************ *
    *                                                                                       *
    *  T1, T2, T3 and T4 are subtrees.                                                      *
    *                                                                                       *
    *                   Z                                       Y                           *
    *                 /  \                                    /  \                          *
    *                /    \                                  /    \                         *
    *               /      \                                /      \                        *
    *              Y      T4       Left  Rotate (z)        X       Z                        *
    *            /  \              =============>         / \     / \                       *
    *           /    \                                   /   \   /   \                      *
    *          X     T3                                 T1   T2 T3   T4                     *
    *         / \                                                                           *
    *        /   \                                                                          *
    *       T1   T2                                                                         *
    *                                                                                       *
    * ************************************************************************************ */
    node* left_rotation(node *n)
    {
        node *left_subtree = n->__left;

        n->__left = left_subtree->__right;
        left_subtree->__right = n;

        left_subtree->__parent = n->__parent;
        n->__parent = left_subtree;
        if (n->__left)
        {
            n = n->__left;
            n->__parent = left_subtree->__right;
        }
        n->__height = calcul_height(n);
        left_subtree->__height = calcul_height(left_subtree);
        return (left_subtree);
    }

    /* ************************************************************************************ *
    *                                                                                       *
    *  T1, T2, T3 and T4 are subtrees.                                                      *
    *                                                                                       *
    *             Z                                                      Y                  *
    *           /  \                                                   /  \                 *
    *          /    \                                                 /    \                *
    *         /      \                                               /      \               *
    *        T1      Y                Right Rotate (x)              Z       X               *
    *               / \               =============>               / \     / \              *
    *              /   \                                          /   \   /   \             *
    *            T2    X                                         T1   T2 T3   T4            *
    *                 / \                                                                   *
    *                /   \                                                                  *
    *               T3   T4                                                                 *
    *                                                                                       *
    * ************************************************************************************ */
    node* right_rotation(node *n)
    {
        node*   right_subtree = n->__right;

        n->__right = right_subtree->__left;
        right_subtree->__left = n;
        right_subtree->__parent = n->__parent;
        n->__parent = right_subtree;
        if (n->__right)
        {
            n = n->__right;
            n->__parent = right_subtree->__left;
        }
        n->__height = calcul_height(n);
        right_subtree->__height = calcul_height(right_subtree);
        return (right_subtree);
    }

    /* ************************************************************************************ *
     *                                                                                      *
     *  T1, T2, T3 and T4 are subtrees.                                                     *
     *                                                                                      *
     *           Z                             Z                               X            *
     *          / \                           / \                            /   \          *
     *         /   \                         /   \                          /     \         *
     *        Y    T4                       X    T4                        /       \        *
     *      /  \        Right Rotate (y)   / \       Left Rotate(z)       Y         Z       *
     *     /   \       =============>     /   \      =============>      / \       / \      *
     *    T1   X                         Y    T3                        /   \     /   \     *
     *        / \                       / \                            /     \   /     \    *
     *       /   \                     /   \                          T1    T2  T3     T4   *
     *      T2   T3                   T1   T2                                               *
     *                                                                                      *
     * ************************************************************************************ */
    node* left_right_rotation(node *n)
    {
        node*  left_subtree;

        left_subtree = n->__left;
        n->__left = right_rotation(left_subtree);
        return (left_rotation(n));
    }

    /* ************************************************************************************ *
     *                                                                                      *
     *  T1, T2, T3 and T4 are subtrees.                                                     *
     *                                                                                      *
     *       Z                              Z                                    X          *
     *     /  \                            / \                                 /   \        *
     *    /    \                          /   \                               /     \       *
     *   T1     Y                       T1     X                             /       \      *
     *         / \     Left Rotate(y)         / \     Right Rotate(z)       Z         Y     *
     *        /  \     =============>        /   \     =============>      / \       / \    *
     *       X   T4                         T2   Y                        /   \     /   \   *
     *      / \                                 / \                      /     \   /     \  *
     *     /   \                               /   \                    T1    T2  T3     T4 *
     *    T2   T3                             T3   T4                                       *
     *                                                                                      *
     * ************************************************************************************ */
    node* right_left_rotation(node *n)
    {
        node *right_subtree;

        right_subtree = n->__right;
        n->__right = left_rotation(right_subtree);
        return (right_rotation(n));
    }
}; // Class avl_sbbst;

#endif
