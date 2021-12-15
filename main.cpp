
#include "./include/vector/vector.hpp"
#include "./include/iterator/random_access_iterator.hpp"
#include <memory>
#include <vector>
#include <iostream>

// // template <typename T, typename std::enable_if<std::is_integral<T>::value> >
// template <typename T>
// T   min(T a, T b)
// {
//     std::cout << "ENABLE_IF IS INT : DONE" << std::endl;
//     if (a <= b)
//         return (a);
//     return (b);
// }

// template <typename T, typename std::enable_if<std::is_integral<T>::value> >
// T   min(T a, T b)
// {
//     std::cout << "ENABLE_IF IS STRING : DONE" << std::endl;
//     if (a <= b)
//         return (a);
//     return (b);
// }

// int main()
// {
//     std::cout << "min: " << min(3, 6) << std::endl;
//     std::cout << "min: " << min("3", "6") << std::endl;
//     return (0);
// }

// int main()
// {
//     int     i = 0;

//     std::vector<int>    vect;
//     std::cout << "Size: " << vect.size() << " | Capacity: " << vect.capacity() << std::endl << std::endl;

//     vect.push_back(i++);
//     std::cout << "Size: " << vect.size() << " | Capacity: " << vect.capacity() << std::endl << std::endl;


//     vect.push_back(i++);
//     std::cout << "Size: " << vect.size() << " | Capacity: " << vect.capacity() << std::endl << std::endl;


//     vect.push_back(i++);
//     std::cout << "Size: " << vect.size() << " | Capacity: " << vect.capacity() << std::endl << std::endl;


//     vect.push_back(i++);
//     std::cout << "Size: " << vect.size() << " | Capacity: " << vect.capacity() << std::endl << std::endl;


//     vect.push_back(i++);
//     std::cout << "Size: " << vect.size() << " | Capacity: " << vect.capacity() << std::endl << std::endl;


//     vect.push_back(i++);
//     std::cout << "Size: " << vect.size() << " | Capacity: " << vect.capacity() << std::endl << std::endl;

//     return (0);
// }

//     vect0.push_back(0);
//     vect0.push_back(1);
//     vect0.push_back(2);
//     std::cout << "<Vect0>: Size: " << vect0.size() << "Capacity: " << vect0.capacity() << std::endl;

//     std::vector<int>    vect1(vect0);
//     std::cout << "<Vect1>: Size: " << vect1.size() << "Capacity: " << vect1.capacity() << std::endl;
//     return (0);
// }

int main()
{
    std::vector<int>        vect1;

    for (int i = 1; i <= 10; i++)
    {
        vect1.push_back(i);
    }

    std::vector<int>        vect2;

    for (int i = 100; i >= 50; i--)
    {
        vect2.push_back(i);
    }

    vect1 = vect2;

    for (std::vector<int>::iterator it = vect1.begin(); it < vect1.end(); it++)
    {
        std::cout << *it << std::endl;
    }


    return (0);
}