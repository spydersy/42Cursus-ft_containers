
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include "utils/reverse_iterator.hpp"
#include "utils/random_access_iterator.hpp"
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> > // generic template
    class vector
    {
        public:
            /*
            ** Member types:
            */
                typedef     T                                       value_type;
                typedef     Alloc                                   allocator_type;
                typedef     value_type&                             reference;
                typedef     const value_type&                       const_reference;
                typedef     value_type*                             pointer;
                typedef     const value_type*                       const_pointer;
                typedef     size_t                                  size_type;
                typedef     ft::Iterator<value_type>                iterator;
                typedef     ft::Iterator<value_type const>          const_iterator;
                typedef     ft::reverse_iterator<iterator>          reverse_iterator;
                typedef     ft::reverse_iterator< const_iterator>   const_reverse_iterator;
        public:
/* Constructors: *****************************************************************************************************/
            /*
            ** Constructors:
            */
                /*
                ** Default Constructor:
                */
                explicit vector (const allocator_type& alloc = allocator_type())
                {
                    this->_vector_allocator = alloc;
                    this->_capacity = 0;
                    this->_size = 0;
                    this->_array = this->_vector_allocator.allocate(0);
                }
                /*
                ** Fill Constructor:
                */
                explicit vector (size_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type())
                {
                    this->_size = 0;
                    this->_capacity = 0;
                    this->_vector_allocator = alloc;
                    this->_array = this->_vector_allocator.allocate(0);
                    this->assign(n, val);
                }
                /*
                ** Range Constructor:
                */
                template<typename InputIterator>
                vector(InputIterator first,
                        InputIterator last,
                        const allocator_type& alloc = allocator_type(),
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
                {
                    this->_vector_allocator = alloc;
                    this->assign(first, last);

                }
                /*
                ** Copy Constructor:
                */
                vector (const vector& x)
                {
                    this->_size = x._size;
                    this->_capacity = x._size;
                    this->_vector_allocator = x._vector_allocator;

                    this->_array = this->_vector_allocator.allocate(this->_size);
                    for (size_type i = 0; i < x._size; i++)
                    {
                        this->_vector_allocator.construct(this->_array + i, x._array[i]);
                    }
                }
/* Destructor: *****************************************************************************************************/
            /*
            ** Destructor:
            */
            ~vector()
            {
                //allocator.destruct( ... );
                // this->_vector_allocator.deallocate(this->_array, this->_capacity);
                return ;
            }
/* Operator=: ****************************************************************************************************/
            /*
            ** Operator=:
            */
            vector& operator=(const vector& x)
            {
                if (*this != x)
                {
                    size_type   index = 0;
                    size_type   xsize = x.size();

                    this->_capacity = x._capacity;
                    this->_size = x._size;
                    this->_vector_allocator.deallocate(this->_array, this->_capacity);
                    this->_array = this->_vector_allocator.allocate(x._capacity);
                    while (index < xsize)
                    {
                        this->_vector_allocator.construct(_array + index, x[index]);
                        index++;
                    }
                }
                return (*this);
            }
/* Iterators: ****************************************************************************************************/
            /*
            ** Iterators:
            */
                /*
                ** Begin:
                */
                iterator begin( void )
                {
                    iterator    it(this->_array[0]);

                    // it.setPtr(this->_array[0]);
                    return (it);
                }

                /*
                ** Const Begin:
                */
                const_iterator begin() const {  return const_iterator(this->_array[0]); }

                /*
                ** End:
                */
                iterator end()
                {
                    iterator    it(_array[this->_size]);

                    // *it = this->_array[this->_size];

                    // it.setPtr(this->_array[this->_size]);
                    return (it);
                }

                /*
                ** Const End:
                */
                const_iterator end() const
                {
                    const_iterator    it(this->_array[this->_size]);

                    // *it = this->_array[this->_size];

                    // it.setPtr(this->_array[this->_size]);
                    return (it);
                }

                reverse_iterator rbegin()
                {
                    reverse_iterator    rit(this->end());

                    // rit._iterator = this->end() - 1;
                    return (rit);
                }

                const_reverse_iterator rbegin() const
                {
                    // reverse_iterator(this->end() - 1)
                    // reverse_iterator    rit(this->end() - 1);
                    return (const_reverse_iterator(this->end()));
                }

                reverse_iterator rend()
                {
                    reverse_iterator    rit(this->begin());
                    return (rit);
                }

                const_reverse_iterator rend() const
                {
                    const_reverse_iterator    rit(this->begin());
                    return (rit);
                }
/* Capacity: ****************************************************************************************************/
            /*
            ** Capacity:
            */
                /*
                ** Size:
                */
                size_type size() const
                {
                    return (this->_size);
                }

                /*
                ** Max Size:
                */
                size_type max_size() const
                {
                    return (this->_vector_allocator.max_size());
                }

                /*
                ** Resize:
                */
                void resize (size_type n, value_type val = value_type())
                {
                    if (n == this->_size)
                        return ;
                    else if (n < this->_size)
                    {
                        for (size_type i = n; i < n; i++)
                        {
                            this->_vector_allocator.destroy(this->_array + i);
                        }
                        this->_size = n;
                    }
                    else
                    {
                        this->insert(this->end(), n - this->_size, val);
                        this->_size = n;
                    }
                }

                /*
                ** Capacity:
                */
                size_type capacity() const
                {
                    return (this->_capacity);
                }

                /*
                ** Empty:
                */
                bool empty() const
                {
                    return (this->_size == 0);
                }

                /*
                ** Reserve:
                */
                void reserve (size_type n)
                {
                    if (n > 0 && this->capacity() < n)
                    {
                        size_type   index = 0;
                        value_type  *new_arr = this->_vector_allocator.allocate(n);
                        for (iterator it = this->begin(); it < this->end(); it++)
                        {
                            new_arr[index] = *it;
                            index++;
                        }
                        _vector_allocator.deallocate(this->_array, this->_capacity);
                        this->_array = new_arr;
                        this->_capacity = n;
                    }
                }

            /*
            ** Element Access: ********************************************************************
            */
                /*
                **  Operator[]:
                */
                reference operator[] (size_type n) { return (this->_array[n]); }

                /*
                **  Const Operator[]:
                */
                const_reference operator[] (size_type n) const { return (this->_array[n]); }

                /*
                **  At:
                */
                reference at (size_type n)
                {
                    if (n >= this->_size)
                    {
                        throw std::out_of_range("Out Of Range.");
                    }
                    return (this->_array[n]);
                }

                /*
                **  Const At:
                */
                const_reference at (size_type n) const
                {
                    if (n >= this->_size)
                    {
                        throw std::out_of_range("Out Of Range.");
                    }
                    return (this->_array[n]);
                }

                /*
                **  Front:
                */
                reference front()
                {
                    return (this->_array[0]);
                }

                /*
                **  Const Front:
                */
                const_reference front() const
                {
                    return (this->_array[0]);
                }

                /*
                **  Back:
                */
                reference back() { return (this->_array[this->_size - 1]); }

                /*
                **  Const Back:
                */
                const_reference back() const { return (this->_array[this->_size - 1]); }

            /*
            ** Modifiers: *************************************************************************
            */
                /*
                **  Range Assignment:
                */
                template <class InputIterator>
                void assign (InputIterator first, InputIterator last,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
                {
                    this->_size = last - first;
                    // this->_vector_allocator = alloc;
                    if (this->_capacity < this->_size)
                    {
                        this->_capacity = this->_size;
                        this->_array = this->_vector_allocator.allocate(this->_capacity);
                    }

                    // this->_array = this->_vector_allocator.allocate(this->_capacity);

                    size_type   c = 0;
                    while (first != last)
                    {
                        this->_vector_allocator.construct(this->_array + c, *first);
                        c++;
                        first++;
                    }
                }

                /*
                **  Fill Assignment:
                */
                void assign (size_type n, const value_type& val)
                {
                    if (this->_capacity < n)
                    {
                        this->_array = this->_vector_allocator.allocate(n);
                        this->_capacity = n;
                    }
                    for (size_type i = 0; i < n; i++)
                    {
                        this->_vector_allocator.construct(this->_array + i, val);
                    }
                    this->_size = n;
                }

                /*
                **  Push Back:
                */
                void push_back (const value_type& val)
                {
                    if (this->_size + 1 <= this->_capacity)
                    {
                        this->_vector_allocator.construct(this->_array + this->_size, val);
                        // this->_array[this->_size] = val;
                    }
                    else
                    {
                        pointer new_array;
                        size_type   index = 0;
                        if (this->_capacity == 0)
                        {
                            this->_capacity++;
                            new_array = this->_vector_allocator.allocate(this->_capacity * 2);
                        }
                        else
                        {
                            new_array = this->_vector_allocator.allocate(this->_capacity * 2);
                            this->_capacity *= 2;
                        }
                        while (index < this->_size)
                        {
                            this->_vector_allocator.construct(new_array + index, this->_array[index]);
                            index++;
                        }
                        // new_array[index] = val;
                        this->_vector_allocator.construct(new_array + index, val);
                        this->_vector_allocator.deallocate(this->_array, this->_capacity);
                        this->_array = new_array;
                    }
                    this->_size++;
                }
                /*
                **  Pop Back:
                */
                void pop_back()
                {
                    this->_vector_allocator.destroy(&this->back());
                    this->_size--;
                }
                /*
                **  Single Elament - Insert:
                */
                iterator insert (iterator position, const value_type& val)
                {
                    if (this->_size == 0)
                    {
                        iterator    ret;

                        if (this->begin() == position)
                        {
                            this->_array = this->_vector_allocator.allocate(1);
                            this->_vector_allocator.construct(this->_array , val);
                            this->_size++;
                            this->_capacity = this->_size;
                            ret = this->begin();
                        }
                        return (ret);
                    }
                    else if (this->_size + 1 <= this->_capacity)
                    {
                        iterator    it = this->end() - 1;
                        for (; it >= position + 1; it--)
                        {
                            *(it + 1) = *it;
                        }
                        *( it + 1) = *it;
                        *it = val;
                        this->_size++;
                        return (it);
                    }
                    else
                    {
                        iterator    ret;
                        int         ret_index = 0;
                        pointer     new_array = this->_vector_allocator.allocate(this->_size * 2);
                        size_type   index = 0;

                        for (iterator it = this->begin(); it <= this->end() ; it++)
                        {
                            if (it == position)
                            {
                                this->_vector_allocator.construct(new_array + index, val);
                                this->_vector_allocator.construct(new_array + index + 1, *it);
                                ret_index = index;
                                index++;
                            }
                            else
                            {
                                this->_vector_allocator.construct(new_array + index, *it);
                            }
                            index++;
                        }
                        this->_array = new_array;
                        this->_capacity = this->_size * 2;
                        this->_size++;
                        ret = this->begin() + ret_index;
                        return (ret);
                    }
                }
                /*
                **  Fill - Insert:
                */
                void insert (iterator position, size_type n, const value_type& val)
                {
                    if (n == 0)
                        return ;
                    if (this->_size + n <= this->_capacity)
                    {
                        iterator    it = this->end();
                        size_type   tmp = n;

                        for (; it > position; it--)
                        {
                            *(it + n) = *it;
                        }
                        while (n)
                        {
                            *it = val;
                            it++;
                            n--;
                        }
                        this->_size += tmp;
                    }
                    else
                    {
                        pointer     new_array = this->_vector_allocator.allocate(this->_size + n);
                        iterator    it = this->begin();
                        size_type   tmp = n;
                        for (size_type index = 0; index <= this->_size + n; index++)
                        {
                            if (it == position && tmp)
                            {
                                while (tmp)
                                {
                                    this->_vector_allocator.construct(new_array + index, val);
                                    tmp--;
                                    index++;
                                }
                                it++;
                            }
                            else
                            {
                                this->_vector_allocator.construct(new_array + index, *it);
                                it++;
                            }
                        }
                        this->_vector_allocator.deallocate(this->_array, this->_capacity);
                        this->_array = new_array;
                        this->_size += n;
                        this->_capacity = this->_size;
                    }
                }

                /*
                **  Range - Insert:
                */
                template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
                {
                    const size_type   n = last - first;
                    if (n == 0)
                        return ;
                    if (this->_size + n <= this->_capacity)
                    {
                        iterator    it = this->end() - 1;

                        for (; it > position; it--)
                        {
                            *(it + n) = *it;
                        }
                        while (first < last)
                        {
                            *it = *first;
                            it++;
                            first++;
                        }
                        this->_size += n;
                    }
                    else
                    {
                        std::cout << "Size: " << this->_size << " Capacity: " << this->_capacity  <<std::endl;
                        std::cout << "DBGFIRST: " << *first << std::endl;
                        // std::cout << "DBGLAST: " << (last == NULL) << std::endl;
                        /*
                            vect.insert(vect.begin(), v0.begin(), v0.end());
                        */
                        std::cout << "DBG_NEW_CAPACITY00: " << this->_size << " + " << n  << " = " << this->_size + n << std::endl;
                        pointer     new_array = this->_vector_allocator.allocate((this->_size * 2) + n);
                        std::cout << "DBG_NEW_CAPACITY01: " << this->_size << " + " << n  << " = " << this->_size + n << std::endl;

                        iterator    it = this->begin();
                        size_type   index = 0;


                        for (; it != this->end(); it++)
                        {
                            if (it == position)
                                break;
                            else
                            {
                                this->_vector_allocator.construct(new_array + index, *it);
                                index++;
                            }
                        }
                        size_type insert_index = index;
                        std::cout << "DBG_FIRST_LAST: " << *first << " | " << *(last - 1) << std::endl;
                        while (first < last)
                        {
                            this->_vector_allocator.construct(new_array + insert_index, *first);
                            first++;
                            insert_index++;
                        }
                        // for (; it != this->end(); it++)
                        // {
                        //     this->_vector_allocator.construct(new_array + insert_index, *it);
                        // }

                        this->_vector_allocator.deallocate(this->_array, this->_capacity);
                        this->_array = new_array;
                        this->_size += n;
                        this->_capacity = this->_size;
                    }
                }
            /*
            ** Erase: *************************************************************************
            */
                /*
                **  Position-Erase:
                */
                iterator erase (iterator position)
                {
                    pointer     new_array = this->_vector_allocator.allocate(this->_capacity);
                    size_type   index = 0;
                    iterator    ret;

                    for (iterator it = this->begin(); it < this->end(); it++)
                    {
                        if (it != position)
                        {
                            this->_size--;
                            this->_vector_allocator.construct(new_array + index, *it);
                            // new_array[index] = *it;
                            index++;
                            ret = position;
                        }
                    }
                    this->_vector_allocator.deallocate(this->_array, this->_capacity);
                    this->_array = new_array;
                    return (ret);
                }
                /*
                **  Range-Erase:
                */
                iterator erase (iterator first, iterator last)
                {
                    pointer     new_array = this->_vector_allocator.allocate(this->_capacity);
                    size_type   index = 0;
                    size_type   n = last - first;
                    iterator    ret = first;

                    if (n)
                    {
                        for(iterator it = this->begin(); it < this->end(); it++)
                        {
                            if (!(first <= it && it < last))
                            {
                                if (it == first - 1)
                                    ret = it;
                                // new_array[index] = *it;
                                this->_vector_allocator.construct(new_array + index, *it);
                                index++;
                            }
                        }
                        this->_vector_allocator.deallocate(this->_array, this->_capacity);
                        this->_array = new_array;
                        this->_size -= n;
                    }
                    return (ret);
                }
            /*
            ** Swap: *************************************************************************
            */
            void swap (vector& x)
            {
                pointer         tmp_pointer = this->_array;
                size_type       tmp_size = this->_size;
                size_type       tmp_capacity = this->_capacity;
                allocator_type  tmp_allocator = this->_vector_allocator;

                this->_array = x._array;
                this->_size = x._size;
                this->_capacity = x._capacity;
                this->_vector_allocator = x._vector_allocator;

                x._array = tmp_pointer;
                x._size = tmp_size;
                x._capacity = tmp_capacity;
                x._vector_allocator = tmp_allocator;
            }
            /*
            ** Clear: *************************************************************************
            */
            void clear()
            {
                this->_size = 0;
            }

            /*
            ** Allocator: *************************************************************************
            */
                /*
                **  Get_allocator:
                */
                allocator_type get_allocator() const
                {
                    return (this->_vector_allocator);
                }

/*****************************************************************************************************/
        private:
            value_type                  *_array;
            allocator_type              _vector_allocator;
            size_type                   _size;
            size_type                   _capacity;
            // iterator                    _iterator;

            size_type        capacity_calculator(size_type const current_size)
            {
                if (current_size == 0)
                {
                    return (0);
                }
                for (size_type capacity = 1;; capacity *= 2)
                {
                    if (capacity >= current_size)
                    {
                        return (capacity);
                    }
                }
            }
    };

    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        typedef     ft::Iterator<T const>                const_iterator;


        if (lhs.size() != rhs.size())
            return (false);
        const_iterator     lit = lhs.begin();
        const_iterator     rit = rhs.begin();

        for (; lit < lhs.end(); lit++, rit++)
        {
            if (*lit != *rit)
            {
                return (false);
            }
        }
        return (true);
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(operator==(lhs, rhs)));
    }

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        typedef     ft::Iterator<T const>                const_iterator;

        const_iterator lit = lhs.begin();
        const_iterator rit = rhs.begin();

        for (; lit < lhs.end() && rit < rhs.end(); lit++, rit++)
        {
            if (*lit < *rit)
            {
                return (true);
            }
        }
        return (false);
    }

    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!operator<(rhs, lhs));
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(operator>(rhs, lhs)));
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(operator<(lhs, rhs)));
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
};

#endif
