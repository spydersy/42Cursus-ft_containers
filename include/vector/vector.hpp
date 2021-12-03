
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>

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
            ** Member types: *********************************************************************************
            */
                typedef     T                                       value_type;
                typedef     Alloc                                   allocator_type;
                typedef    	typename allocator_type::reference      reference;
                typedef     size_t                                  size_type;
            /*
            ** Constructors: *********************************************************************************
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
                    std::cout << "<vector>: Default Constructor Called | Size:" << _size << " | Capacity:" << _capacity << std::endl;
                }

                /*
                ** Fill Constructor:
                */
                explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
                {
                    this->_vector_allocator = alloc;

                    this->_array = this->_vector_allocator.allocate(n);
                    for (size_type i = 0; i < n; i++)
                    {
                        this->_array[i] = val;
                    }
                    this->_size = n;
                    this->_capacity = n;
                    std::cout << "<vector>: Fill Constructor Called | Size:" << _size << " | Capacity:" << _capacity << std::endl;
                    for (size_type i = 0; i < n; i++)
                    {
                        std::cout << this->_array[i] << std::endl;
                    }
                }

                /*
                ** Range Constructor:
                */
                template <class InputIterator>
                vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
                {
                    this->_size = last - first;
                    this->_capacity = this->_size;
                    this->_vector_allocator = alloc;

                    std::cout << "<USR> Size: " << this->_size << " Capacity: " << this->_capacity << std::endl;
                    this->_array = this->_vector_allocator.allocate(this->_capacity);

                    size_type   c = 0;
                    while (first != last)
                    {
                        this->_array[c] = *first;
                        std::cout << "USR: " << this->_array[c] << std::endl;
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
                    std::cout << "Copy Constructor: ---------------------------------------" << std::endl;
                    std::cout << "USR: Size: " << this->_size << " Capacity: " << this->_capacity << std::endl;
                    for (size_type i = 0; i < x._size; i++)
                    {
                        this->_array[i] = x._array[i];
                        std::cout << "USR: " << this->_array[i] << std::endl;
                    }
                }

            /*
            ** Destructor: *********************************************************************************
            */
            ~vector(){ std::cout << "<vector>: Default Destructor Called" << std::endl; }

        private:
            value_type       *_array;
            allocator_type   _vector_allocator;
            size_type        _size;
            size_type        _capacity;
            
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
