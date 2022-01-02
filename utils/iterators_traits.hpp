
#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

#include <iostream>

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
	template <class Iterator>
	class iterator_traits // *Find out later why this needs to be implemented
	{
		public:
		typedef typename Iterator::difference_type			difference_type;
		typedef typename Iterator::value_type				value_type;
		typedef typename Iterator::pointer					pointer;
		typedef typename Iterator::reference				reference;
		typedef typename Iterator::iterator_category		iterator_category;

	};

	template <class T>
	class iterator_traits<T*>
	{
		public:
		typedef  std::ptrdiff_t									difference_type;
		typedef  T											value_type;
		typedef  T*											pointer;
		typedef  T&											reference;
		typedef typename std::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:
		typedef std::ptrdiff_t									difference_type;
		typedef  T											value_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef typename std::random_access_iterator_tag	iterator_category;
	};
}

// namespace ft
// {
    // // class iterators_traits
    // // {
        // // public:
            // // typedef     std::ptrdiff_t                   difference_type;
    // // };  // struct iterators_traits
    // template <typename T>
    // struct iterator_traits
    // {
        // typedef std::random_access_iterator_tag iterator_category;
        // typedef T                               value_type;
        // typedef T*                              pointer;
        // typedef T&                              reference;
        // typedef std::ptrdiff_t                  difference_type;
        // typedef size_t                          size_type;
    // };
// };  //  namespace ft

#endif
