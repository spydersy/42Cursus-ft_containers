
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
// #include <type_traits>
#include "../iterator/random_access_iterator.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../iterator/enable_if.hpp"
#include "../iterator/is_integral.hpp"

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

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
                typedef     ft::reverse_iterator<value_type>        reverse_iterator;
                typedef     const iterator                          const_iterator;
                // typedef     ft::enable_if<true, value_type>         enable_if;
                // typedef    	typename allocator_type::reference      reference;

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
                    iterator    it;

                    it.setPtr(this->_array[0]);
                    return (it);
                }

                /*
                ** Const Begin:
                */
                const_iterator begin() const
                {
                    iterator    it;

                    it.setPtr(this->_array[0]);
                    return (it);
                }

                /*
                ** End:
                */
                iterator end()
                {
                    iterator    it;

                    it.setPtr(this->_array[this->_size]);
                    return (it);
                }

                /*
                ** Const End:
                */
                const_iterator end() const
                {
                    iterator    it;

                    it.setPtr(this->_array[this->_size]);
                    return (it);
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
                // void resize (size_type n, value_type val = value_type())
                // {
                //     if (n <= this->_size)
                //     {
                //         std::cout << "DBG_A" << std::endl;
                //         this->_size = n;
                //     }
                //     if (n > this->_size && n <= this->_capacity)
                //     {
                //         std::cout << "DBG_B" << std::endl;
                //         iterator    it = this->end();
                //         for (size_type i = this->_size; i < n; i++)
                //         {
                //             *it = val;
                //             it++;
                //         }
                //         this->_size = n;

                //     }
                //     if (n > this->_size && n > this->_capacity)
                //     {
                //         std::cout << "DBG_C" << std::endl;
                //         size_type   index = 0;
                //         value_type  *new_array = _vector_allocator.allocate(n);

                //         for (iterator it = this->begin(); it < this->end(); it++)
                //         {
                //             new_array[index++] = *it;
                //         }
                //         while (index < n)
                //         {
                //             new_array[index++] = val;
                //         }
                //         _vector_allocator.deallocate(this->_array, this->_capacity);
                //         // std::cout << "LIVE_DBG: " << (this->_capacity = this->_size * 2) << std::endl;
                //         this->_size = n;
                //         std::cout << "LIVE_DBG: " << (this->_capacity = n) << std::endl;
                //         this->_array = new_array;
                //     }
                // }

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
                    return (this->size == 0);
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
                        // size_type   c = this->_size - 1;
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
                        size_type   c = 0;

                        for (iterator it = this->begin(); it <= this->end(); it++)
                        {
                            if (it == position)
                            {
                                // std::cout << "Trueee condition" << std::endl;
                                new_array[c++] = val;
                                // it--;
                                new_array[c++] = *it;
                                ret = it;
                            }
                            else
                            {
                                // std::cout << "Faaaalse condition" << std::endl;
                                new_array[c++] = *it;
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
                // void insert (iterator position, size_type n, const value_type& val)
                // {
                    // if (this->_size + n <= this->_capacity)
                    // {

                    // }
                    // else
                    // {

                    // }
                // }
                /*
                **  Range - Insert:
                */
                // template <class InputIterator>
                // void insert (iterator position, InputIterator first, InputIterator last)
                // {

                // }
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
};

#endif
