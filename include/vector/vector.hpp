
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>

#include "../../utils/reverse_iterator.hpp"
#include "../../utils/random_access_iterator.hpp"
#include "../../utils/enable_if.hpp"
#include "../../utils/is_integral.hpp"

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
                typedef     ft::Iterator<value_type const>                const_iterator;
                // typedef     const iterator                          const_iterator;
                typedef     ft::reverse_iterator<value_type>        reverse_iterator;
                typedef     const reverse_iterator                  const_reverse_iterator;
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
                    this->_array = _vector_allocator.allocate(0);
                    this->_capacity = 0;
                    this->_size = 0;
                    // std::cout << "<vector>: Default Constructor Called | Size:" << _size << " | Capacity:" << _capacity << std::endl;
                }
                /*
                ** Fill Constructor:
                */
                explicit vector (size_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type())
                {
                    this->_vector_allocator = alloc;
                    this->assign(n, val);
                    // this->_vector_allocator = alloc;

                    // this->_array = this->_vector_allocator.allocate(n);
                    // for (size_type i = 0; i < n; i++)
                    // {
                        // this->_array[i] = val;
                    // }
                    // this->_size = n;
                    // this->_capacity = n;
                    // std::cout << "<vector>: Fill Constructor Called | Size:" << _size << " | Capacity:" << _capacity << std::endl;
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
                    // this->_size = last - first;
                    // this->_capacity = this->_size;
                    // this->_vector_allocator = alloc;

                    // // std::cout << "<USR> Size: " << this->_size << " Capacity: " << this->_capacity << std::endl;
                    // this->_array = this->_vector_allocator.allocate(this->_capacity);

                    // size_type   c = 0;
                    // while (first != last)
                    // {
                        // this->_array[c] = *first;
                        // // std::cout << "USR: " << this->_array[c] << std::endl;
                        // c++;
                        // first++;
                    // }
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
                    // std::cout << "Copy Constructor: ---------------------------------------" << std::endl;
                    // std::cout << "USR: Size: " << this->_size << " Capacity: " << this->_capacity << std::endl;
                    for (size_type i = 0; i < x._size; i++)
                    {
                        this->_array[i] = x._array[i];
                        // std::cout << "USR: " << this->_array[i] << std::endl;
                    }
                }
/* Destructor: *****************************************************************************************************/
            /*
            ** Destructor:
            */
            ~vector()
            {
                // std::cout << "<vector>: Default Destructor Called" << std::endl;
                this->_vector_allocator.deallocate(this->_array, this->_capacity);
                return ;
            }
/* Operator=: ****************************************************************************************************/
            /*
            ** Operator=:
            */
            vector& operator=(const vector& x)
            {
                size_type   index = 0;
                iterator    end = x.end();
                iterator    begin = x.begin();

                this->_capacity = x._capacity;
                this->_size = x._size;
                this->_vector_allocator.deallocate(this->_array, this->_capacity);
                std::cout << "DBG: x_capcacity: " << x._capacity << std::endl;
                std::cout << "DBG: this_capcacity: " << _capacity << std::endl;
                this->_array = this->_vector_allocator.allocate(x._capacity);
                for (; begin < end; begin++)
                {
                    this->_array[index++] = *begin;
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
                const_iterator begin() const
                {
                    iterator    it(this->_array[0]);

                    // *it = this->_array[0];
                    // it.setPtr(this->_array[0]);
                    return (it);
                }

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
                    iterator    it(this->_array[this->_size]);

                    // *it = this->_array[this->_size];

                    // it.setPtr(this->_array[this->_size]);
                    return (it);
                }

                reverse_iterator rbegin()
                {
                    reverse_iterator    rit(this->end() - 1);

                    // rit._iterator = this->end() - 1;
                    return (rit);
                }

                const_reverse_iterator rbegin() const
                {
                    reverse_iterator    rit(this->end() - 1);
                    return (rit);
                }

                reverse_iterator rend()
                {
                    reverse_iterator    rit(this->begin() - 2);
                    return (rit);
                }

                const_reverse_iterator rend() const
                {
                    reverse_iterator    rit(this->begin() - 2);
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
                    if (n <= this->_size)
                    {
                        std::cout << "DBG_A" << std::endl;
                        this->_size = n;
                    }
                    if (n > this->_size && n <= this->_capacity)
                    {
                        std::cout << "DBG_B" << std::endl;
                        iterator    it = this->end();
                        for (size_type i = this->_size; i < n; i++)
                        {
                            *it = val;
                            it++;
                        }
                        this->_size = n;

                    }
                    if (n > this->_size && n > this->_capacity)
                    {
                        std::cout << "DBG_C" << std::endl;
                        size_type   index = 0;
                        value_type  *new_array = _vector_allocator.allocate(n);

                        for (iterator it = this->begin(); it < this->end(); it++)
                        {
                            new_array[index++] = *it;
                        }
                        while (index < n)
                        {
                            new_array[index++] = val;
                        }
                        _vector_allocator.deallocate(this->_array, this->_capacity);
                        // std::cout << "LIVE_DBG: " << (this->_capacity = this->_size * 2) << std::endl;
                        this->_size = n;
                        std::cout << "LIVE_DBG: " << (this->_capacity = n) << std::endl;
                        this->_array = new_array;
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

                /*  Const Front:
                **
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
                    this->_capacity = this->_size;
                    // this->_vector_allocator = alloc;

                    // std::cout << "<USR> Size: " << this->_size << " Capacity: " << this->_capacity << std::endl;
                    this->_array = this->_vector_allocator.allocate(this->_capacity);

                    size_type   c = 0;
                    while (first != last)
                    {
                        this->_array[c] = *first;
                        // std::cout << "USR: " << this->_array[c] << std::endl;
                        c++;
                        first++;
                    }
                }

                /*
                **  Fill Assignment:
                */
                void assign (size_type n, const value_type& val)
                {

                    this->_array = this->_vector_allocator.allocate(n);
                    for (size_type i = 0; i < n; i++)
                    {
                        this->_array[i] = val;
                    }
                    this->_size = n;
                    this->_capacity = n;
                }

                /*
                **  Push Back:
                */
                void push_back (const value_type& val)
                {
                    if (this->_size + 1 <= this->_capacity)
                    {
                        this->_array[this->_size] = val;
                    }
                    else
                    {
                        size_type   index = 0;
                        if (this->_capacity == 0)
                            this->_capacity++;
                        pointer new_array = this->_vector_allocator.allocate(this->_capacity * 2);
                        this->_capacity *= 2;
                        while (index < this->_size)
                        {
                            new_array[index] = this->_array[index];
                            index++;
                        }
                        new_array[index] = val;
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
                    if (this->_size == 0)
                        return;
                    for (size_type i = 0; i + 1 < this->_size; i++)
                    {
                        this->_array[i] = this->_array[i + 1];
                    }
                    this->_size--;
                }
                /*
                **  Single Elament - Insert:
                */
                iterator insert (iterator position, const value_type& val)
                {

                    if (this->_size + 1 <= this->_capacity)
                    {
                        iterator    it = this->end() - 1;
                        for (; it >= position + 1; it--)
                        {
                            *(it + 1) = *it;
                        }
                        *(it + 1) = *it;
                        *it = val;
                        this->_size++;
                        return (it);
                    }
                    else
                    {
                        iterator    ret;
                        pointer     new_array = this->_vector_allocator.allocate(this->_size * 2);
                        size_type   index = 0;

                        for (iterator it = this->begin(); it <= this->end(); it++)
                        {
                            if (it == position)
                            {
                                new_array[index++] = val;
                                new_array[index++] = *it;
                                ret = it;
                            }
                            else
                            {
                                new_array[index++] = *it;
                            }
                        }
                        this->_vector_allocator.deallocate(this->_array, this->_capacity);
                        this->_array = new_array;
                        this->_capacity = this->_size * 2;
                        this->_size++;
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
                        iterator    it = this->end() - 1;
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
                                    new_array[index++] = val;
                                    tmp--;
                                }
                                it++;
                            }
                            else
                            {
                                new_array[index] = *it;
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
                    size_type   n = last - first;
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
                        pointer     new_array = this->_vector_allocator.allocate(this->_size + n);
                        iterator    it = this->begin();
                        for (size_type index = 0; index <= this->_size + n; index++)
                        {
                            if (it == position)
                            {
                                while (first < last)
                                {
                                    new_array[index++] = *first;
                                    first++;
                                }
                            }
                            else
                            {
                                new_array[index] = *it;
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
                            new_array[index] = *it;
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
                                new_array[index] = *it;
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
            iterator                    _iterator;

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
        if (lhs.size() != rhs.size())
            return (false);
        typename ft::vector<T>::iterator     lit = lhs.begin();
        typename ft::vector<T>::iterator     rit = rhs.begin();

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
        typename    ft::vector<T>::iterator lit = lhs.begin();
        typename    ft::vector<T>::iterator rit = rhs.begin();

        for (; lit < lhs.end(), rit < rhs.end(); lit++, rit++)
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
        return (operator<(rhs, lhs));
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(operator<(rhs, lhs)));
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
