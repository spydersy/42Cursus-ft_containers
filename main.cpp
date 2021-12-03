
#include "./include/vector/vector.hpp"
#include <memory>
#include <vector>
#include <iostream>

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

int     main()
{
    std::cout << KYEL << "SYS: ******************************************************" << KNRM << std::endl;
    {
        std::vector<int>    vect0;
        int     i = 0;

        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);

        std::cout << "<Vect0>: Size: " << vect0.size() << " Capacity: " << vect0.capacity() << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~" << std::endl;

        std::vector<int>    vect1(vect0);
        std::cout << "<Vect1>: Size: " << vect1.size() << " Capacity: " << vect1.capacity() << std::endl;
        for ( std::vector<int>::iterator b = vect1.begin(); b < vect1.end(); b++)
        {
            std::cout << "SYS: " << *b << std::endl;
        }
    }
    std::cout << KYEL << "USR: ******************************************************" << KNRM << std::endl;
    {
        std::vector<int>    vect0;
        int     i = 0;

        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);
        vect0.push_back(i++);

        std::cout << "<Vect0>: Size: " << vect0.size() << " Capacity: " << vect0.capacity() << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~" << std::endl;

        ft::vector<int>     tmp_vect(vect0.begin(), vect0.end());

        ft::vector<int>    vect1(tmp_vect);
    }
    return (0);
}

// int main()
// {
//     std::vector<int>    vect0;

//     vect0.push_back(0);
//     vect0.push_back(1);
//     vect0.push_back(2);
//     std::cout << "<Vect0>: Size: " << vect0.size() << "Capacity: " << vect0.capacity() << std::endl;

//     std::vector<int>    vect1(vect0);
//     std::cout << "<Vect1>: Size: " << vect1.size() << "Capacity: " << vect1.capacity() << std::endl;
//     return (0);
// }

// int     main()
// {
//     std::cout << KYEL << "SYS: ******************************************************" << KNRM << std::endl;
//     {
//         std::vector<int> vect0;
//         int                 i = 0;

//         vect0.push_back(i++);
//         vect0.push_back(i++);
//         vect0.push_back(i++);
//         vect0.push_back(i++);
//         vect0.push_back(i++);
//         vect0.push_back(i++);
//         vect0.push_back(i++);

        
//         std::cout << KGRN << "Size: " << vect0.size() << " Capacity: " << vect0.capacity() << KNRM << std::endl;

//         std::vector<int>::iterator  b = vect0.begin();
//         std::vector<int>::iterator  e = vect0.end();

//         std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

//         std::vector<int>            vect2(b, e);

//         std::cout << " vect2***** : Size: " << vect2.size() << " Capacity: " << vect2.capacity() << std::endl;
//         for (std::vector<int>::iterator  b2 = vect2.begin(); b2 < vect2.end(); b2++)
//         {
//             std::cout << "SYS: " << *b2 << std::endl;
//         }
//     }

//     std::cout << KYEL << "USR: ******************************************************" << KNRM << std::endl;
    
//     {
//         std::vector<int> vect0;
//         int                 i = 0;

//         vect0.push_back(i++);
//         vect0.push_back(i++);
//         vect0.push_back(i++);
//         vect0.push_back(i++);
//         vect0.push_back(i++);
//         vect0.push_back(i++);
//         vect0.push_back(i++);

        
//         std::cout << KGRN << "Size: " << vect0.size() << " Capacity: " << vect0.capacity() << KNRM << std::endl;

//         std::vector<int>::iterator  b = vect0.begin();
//         std::vector<int>::iterator  e = vect0.end();

//         std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

//         ft::vector<int>            vect2(b, e);
        
//         // std::vector<int>::iterator  b2 = vect0.begin();
//         // std::vector<int>::iterator  e2 = vect0.end();
        
//     }
//     return (0);
// }