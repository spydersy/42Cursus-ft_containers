
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

int     main()
{
    // std::cout << KYEL << "SYS: ******************************************************" << KNRM << std::endl;
    // {
    //     std::vector<int> vect0;
    //     int                 i = 0;

    //     vect0.push_back(i++);
    //     vect0.push_back(i++);
    //     vect0.push_back(i++);
    //     vect0.push_back(i++);
    //     vect0.push_back(i++);
    //     vect0.push_back(i++);
    //     vect0.push_back(i++);


    //     std::cout << KGRN << "Size: " << vect0.size() << " Capacity: " << vect0.capacity() << KNRM << std::endl;

    //     std::vector<int>::iterator  b = vect0.begin();
    //     std::vector<int>::iterator  e = vect0.end();

    //     std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    //     std::vector<int>            vect2(b, e);

    //     std::cout << " vect2***** : Size: " << vect2.size() << " Capacity: " << vect2.capacity() << std::endl;
    //     for (std::vector<int>::iterator  b2 = vect2.begin(); b2 < vect2.end(); b2++)
    //     {
    //         std::cout << "SYS: " << *b2 << std::endl;
    //     }
    // }

    std::cout << KYEL << "USR: ******************************************************" << KNRM << std::endl;
    // {
    //     ft::vector<int>     vect(12, 15);
    // }
    {
        std::vector<int> vect0;
        int                 i = 1;

        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);


        std::cout << KGRN << "Size: " << vect0.size() << " Capacity: " << vect0.capacity() << KNRM << std::endl;

        std::vector<int>::iterator  b = vect0.begin();
        std::vector<int>::iterator  e = vect0.end();

        std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

        ft::vector<int>            vect2(b, e);
        std::cout << KBLU << "~~~~~~~~~~~~~~~~~~~~~~" <<  KWHT << std::endl;

        // for (ft::vector<int>::iterator it = vect2.begin(); it < vect2.end(); it++)
        // {
            // std::cout << *it << std::endl;
        // }

        ft::vector<int>::iterator it = vect2.begin();
        ft::vector<int>::iterator end = vect2.end();
        while (it < end)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    return (0);
}