# ft_containers:

Ft_containers is a project made in C++ and was about recoding some containers from the STL.

In order to succeed, a good comprehension of how templates, iterators, containers and algorithms work was necessary. Of course, STL is not allowed. That means you cannot use <iterator> or even <utility>.

Here are the specificities of the implemented containers:

## containers:

➡️ **Vector (/containers/vector.hpp):** a dynamic array that allows insertion at the end of the container. Elements can be easily access by corresponding index, but it's not the most optimal container if a lot of insertion / deletion are needed.

➡️ **Stack (/containers/stack.hpp):** a container adaptator (LIFO, last in first out).

➡️ **Map (/containers/map.hpp):** a sorted container using an AVL binary tree (Self-Balancing-Binary-Search-Tree to optimize the time to find a value in the tree), in order to store the datas like in a dictionnary (a key associated to its value).
All my containers use an allocator to manage properly their memory, iterators to access their datas, and handle the same constructors / methods than the containers from the STL in C++98.

## utilities:

➡️ **Iterators:** are a way to represent a position within a container, such as an array or linked list. They allow you to access elements within the container and perform various operations on them. There are different categories of iterators based on the capabilities they provide.

➡️ **random access iterator (/utils/random_access_iterator.hpp):** allow you to jump directly to any element within the container using arithmetic operations. They are implemented using pointers, so they provide fast access to elements.

➡️ **bidirectional iterator (/utils/bidirectional_iterator.hpp):** allow you to move forward and backward through the container, but you cannot jump directly to a specific element. They are typically implemented using pointers or class objects.

➡️ **iterator base (/utils/iterator.hpp):** is a class that defines the common interface for all iterators. It specifies the functions that all iterators must implement, such as operator++ for moving to the next element.

➡️ **Iterator traits (/utils/iterator_traits.hpp):** are templates that allow you to customize the behavior of iterators based on their characteristics. They provide a way to determine the properties of an iterator, such as its category and the type of elements it can access.

➡️ **Reverse iterators (/utils/reverse_iterator.hpp):** are a type of iterator that allow you to iterate through a container in reverse order. They are typically implemented as a wrapper around another iterator that provides the opposite traversal order.

➡️ **AVL Tree (/utils/avl_self_balancing_binary_search_tree\*.hpp):** is a self-balancing binary search tree, named after its inventors Adelson-Velsky and Landis. In an AVL tree, the heights of the two child subtrees of any node differ by at most one, so the tree is more balanced than a normal binary search tree. This balancing allows for efficient insertion, deletion, and lookup of elements in the tree. The balance factor of a node in an AVL tree is the height of its right subtree minus the height of its left subtree. If the balance factor is greater than 1 or less than -1, the tree is unbalanced and a rotation is needed to balance it. There are four types of rotations that can be performed to balance an AVL tree: right rotation, left rotation, right-left rotation, and left-right rotation. These rotations are used to ensure that the tree remains balanced after an insertion or deletion.

➡️ **enable_if (/utils/enable_if.hpp):** `std::enable_if` is a type trait in C++ that allows you to conditionally enable or disable a function or class template based on a boolean constant. It is defined in the `<type_traits>` header.

The basic syntax for using `std::enable_if` is as follows:


```
template <typename T, typename = std::enable_if<condition>>
void function(T arg);
```

In this example, function is a template that takes a single type parameter T. The second template parameter is a default template parameter of type `std::enable_if<condition>`. If condition is true, then function is enabled and can be used. If condition is false, then function is disabled and a compilation error will occur if it is called.

Here is an example of how std::enable_if can be used to enable or disable a function based on whether a type is an integral type:

```
#include <type_traits>

template <typename T, typename = std::enable_if<std::is_integral<T>::value>>
void print_int(T x) {
    std::cout << x << std::endl;
}

int main() {
    print_int(10); // OK
    print_int(10.5); // Compilation error
}
```
In this example, the print_int function is only enabled for integral types. If it is called with a non-integral type, a compilation error will occur.




➡️ **equal (/utils/equal.hpp):** In C++, the `std::equal` function is a function template that compares the elements in two ranges and returns a bool indicating whether they are equal. It is defined in the `<algorithm>` header.

The basic syntax for using std::equal is as follows:

```
template <class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);
```

This function compares the elements in the range [first1, last1) with the elements in the range beginning at first2. The ranges must have the same length, and the elements must be equal for the function to return true.

Here is an example of how std::equal can be used to compare the elements in two arrays:

```
#include <algorithm>
#include <iostream>

int main() {
    int a1[] = {1, 2, 3};
    int a2[] = {1, 2, 3};
    int a3[] = {1, 2, 4};

    std::cout << std::equal(std::begin(a1), std::end(a1), std::begin(a2)) << std::endl; // Outputs 1
    std::cout << std::equal(std::begin(a1), std::end(a1), std::begin(a3)) << std::endl; // Outputs 0
}
```
In this example, the first call to std::equal compares the elements in a1 and a2 and returns true because they are equal. The second call compares the elements in a1 and a3 and returns false because the last element is different.

➡️ **is_integral (/utils/is_integral.hpp):** `std::is_integral` is a type trait that determines whether a type is an integral type. It is defined in the `<type_traits>` header.

An integral type is a data type that represents integral (whole) numbers. In C++, the integral types are char, signed char, unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, long long, and unsigned long long.

To use `std::is_integral`, you can use the `::value` member of the `std::is_integral` template. For example:

```
#include <type_traits>
#include <iostream>

int main() {
    std::cout << std::is_integral<int>::value << std::endl; // Outputs 1
    std::cout << std::is_integral<float>::value << std::endl; // Outputs 0
}
```

In this example, the first call to `std::is_integral::value` returns 1 because int is an integral type. The second call returns 0 because float is not an integral type.

You can also use `std::is_integral` as a type trait in template programming to enable or disable a function or class template based on whether a type is an integral type. For example:

```
#include <type_traits>

template <typename T, typename = std::enable_if<std::is_integral<T>::value>>
void print_int(T x) {
    std::cout << x << std::endl;
}

int main() {
    print_int(10); // OK
    print_int(10.5); // Compilation error
}
```

In this example, the print_int function is only enabled for integral types. If it is called with a non-integral type, a compilation error will occur.

➡️ **lexicographical_compare (/utils/lexicographical_compare.hpp):** `std::lexicographical_compare` is a function that compares the elements in two ranges lexicographically (i.e., based on their ASCII or Unicode values) and returns a bool indicating whether the first range is lexicographically less than the second range. It is defined in the `<algorithm>` header.

The basic syntax for using `std::lexicographical_compare` is as follows:

```
template <class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2);
This function compares the elements in the range [first1, last1) with the elements in the range [first2, last2). If the elements in the first range are lexicographically less than the elements in the second range, the function returns true. Otherwise, it returns false.
```
Here is an example of how `std::lexicographical_compare` can be used to compare two strings:

```
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string s1 = "hello";
    std::string s2 = "world";
    std::string s3 = "hello";

    std::cout << std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) << std::endl; // Outputs 1
    std::cout << std::lexicographical_compare(s1.begin(), s1.end(), s3.begin(), s3.end()) << std::endl; // Outputs 0
}
```

In this example, the first call to `std::lexicographical_compare` compares the strings "hello" and "world" and returns true because "hello" is lexicographically less than "world". The second call compares the strings "hello" and "hello" and returns false because they are equal.

➡️ **pair / make_pair (/utils/\*pair.hpp):** `std::pair` is a template class that represents a pair of values, which can be of different types. It is defined in the `<utility>` header.

`std::make_pair` is a function that creates a `std::pair` object. It is also defined in the `<utility>` header.

The basic syntax for using std::pair is as follows:


```
std::pair<T1, T2> p;
```
This creates a std::pair object p that can hold two values of types T1 and T2. You can access the values in the pair using the first and second members:

```
p.first = 10;
p.second = "hello";
```
You can also use the `std::make_pair` function to create a `std::pair` object:

```
auto p = std::make_pair(10, "hello");
```
This creates a std::pair object p with the values 10 and "hello".

Here is an example of how you can use std::pair and std::make_pair in a program:

```
#include <iostream>
#include <utility>

int main() {
    std::pair<int, std::string> p;
    p.first = 10;
    p.second = "hello";
    std::cout << p.first << " " << p.second << std::endl;

    auto q = std::make_pair(20, "world");
    std::cout << q.first << " " << q.second << std::endl;
}
```
This program outputs the following:

```
10 hello
20 world
```
# Unit tests:
Unit test links: https://github.com/divinepet/ft_containers-unit-test, https://github.com/mli42/containers_test

## Vector unit test:
![vector GIF](https://github.com/spydersy/42Cursus-ft_containers/blob/master/gif/vector_tests.gif)

## Stack unit test:
![stack GIF](https://github.com/spydersy/42Cursus-ft_containers/blob/master/gif/stack_tests.gif)

## Map unit test:
![map GIF](https://github.com/spydersy/42Cursus-ft_containers/blob/master/gif/map_tests.gif)