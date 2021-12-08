
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
// #include <type_traits>
#include "../iterator/random_access_iterator.hpp"
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
                typedef     const iterator                          const_iterator;
                // typedef     ft::enable_if<true, value_type>         enable_if;
                // typedef    	typename allocator_type::reference      reference;

        public:
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

                    this->_array = this->_vector_allocator.allocate(n);
                    for (size_type i = 0; i < n; i++)
                    {
                        this->_array[i] = val;
                    }
                    this->_size = n;
                    this->_capacity = n;
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
                    this->_size = last - first;
                    this->_capacity = this->_size;
                    this->_vector_allocator = alloc;

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

            /*
            ** Destructor:
            */
            ~vector()
            {
                // std::cout << "<vector>: Default Destructor Called" << std::endl;
                this->_vector_allocator.deallocate(this->_array, this->_capacity);
                return ;
            }

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
                // size_type max_size() const
                // {
                //     return (std::pow(2, std::pow(sizeof(this->_array), 2)) / sizeof(value_type) - 1);
                // }

                /*
                ** Resize:
                */
                // void resize (size_type n, value_type val = value_type()); Not Completed;

                /*
                ** Capacity:
                */
                // size_type capacity() const
                // {
                //     return (this->_capacity == 0);
                // }

                /*
                ** Capacity:
                */
                // bool empty() const
                // {
                //     return ();
                // }

                /*
                ** Capacity:
                */
                // void reserve (size_type n)
                // {
                //     if (n > 0 && this->capacity < n)
                //     {
                //         size_type   index = 0;
                //         value_type  *new_arr = allocator_type->allocate(n);
                //         for (iterator it = this->begin(); it < this->end(); it++)
                //         {
                //             new_arr[index] = *it;
                //             index++;
                //         }
                //         allocator_type->deallocate(this->_array, this->_capacity);
                //         this->_array = new_arr;
                //         this->_capacity = n;
                //     }
                // }

        private:
            value_type                  *_array;
            allocator_type              _vector_allocator;
            size_type                   _size;
            size_type                   _capacity;
            iterator                    _iterator;

            size_type        ___capacity_calculator(size_type const current_size)
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
