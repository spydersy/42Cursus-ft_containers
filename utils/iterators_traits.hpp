
#ifndef __ITERATOR_TRAITS__
# define __ITERATOR_TRAITS__

# include <iostream>

namespace ft
{
    // Iterators Category :
    struct  input_iterator_tag          : public std::input_iterator_tag {};
    struct  output_iterator_tag         : public std::output_iterator_tag {};
    struct  forward_iterator_tag        : public input_iterator_tag {};
    struct  bidirectional_iterator_tag  : public forward_iterator_tag {};
    struct  random_access_iterator_tag  : public bidirectional_iterator_tag {};

    // Iterators Traits :
    template <class Iterator>
    class iterator_traits
    {
        public:
            // Member Types :
            typedef  typename    Iterator::difference_type   difference_type;
            typedef  typename    Iterator::value_type        value_type;
            typedef  typename    Iterator::pointer           pointer;
            typedef  typename    Iterator::reference         reference;
            typedef  typename    Iterator::iterator_category iterator_category;
    };

    template <class T>
    class iterator_traits<T*>
    {
        public:
            // Member Types :
            typedef std::ptrdiff_t                  difference_type;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    class iterator_traits<const T*>
    {
        public:
            // Member Types :
            typedef std::ptrdiff_t                  difference_type;
            typedef T                               value_type;
            typedef const T*                        pointer;
            typedef const T&                        reference;
            typedef ft::random_access_iterator_tag  iterator_category;
    };
};

#endif




Iterator traits are templates that allow you to customize the behavior of iterators based on their characteristics. They provide a way to determine the properties of an iterator, such as its category and the type of elements it can access.
Reverse iterators are a type of iterator that allow you to iterate through a container in reverse order. They are typically implemented as a wrapper around another iterator that provides the opposite traversal order.



