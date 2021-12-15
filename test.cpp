
// #include "./include/iterator/random_access_iterator.hpp"
#include "./include/vector/vector.hpp"
#include <vector>
#include <iostream>

#include "./include/iterator/reverse_iterator.hpp"

// int main()
// {
    // ft::vector<int>     vect0(15, 10);
    // std::vector<int>    vect1;

    // for (ft::vector<int>::iterator it = vect0.begin(); it < vect0.end(); it++)
    // {
        // std::cout << "it: " << *it << std::endl;
    // }

    // return (0);
// }

int main()
{
    std::vector<int>     vect0;

    for (int i = 1; i <= 10; i++)
    {
        vect0.push_back(i);
    }

    std::cout << "vect1 (Range Constructor) : **************************************" << std::endl;
        ft::vector<int>     vect1(vect0.begin(), vect0.end());
        ft::vector<int>::iterator   beg1 =vect1.begin();
        ft::vector<int>::iterator   end1 =vect1.end();
        for (; beg1 < end1; beg1++)
        {
            std::cout << "vect1: " << *beg1 << std::endl;
        }

    std::cout << std::endl << "vect2 (Fill Constructor) : **************************************" << std::endl;
        ft::vector<int>         vect2(20, 42);
        ft::vector<int>::iterator   beg2 =vect2.begin();
        ft::vector<int>::iterator   end2 =vect2.end();
        for (; beg2 < end2; beg2++)
        {
            std::cout << "vect2: " << *beg2 << std::endl;
        }

    std::cout << std::endl << "vect3 (Copy Constructor) : **************************************" << std::endl;
        ft::vector<int>         vect3(vect2);
        ft::vector<int>::iterator   beg3 =vect3.begin();
        ft::vector<int>::iterator   end3 =vect3.end();
        for (; beg3 < end3; beg3++)
        {
            std::cout << "vect3: " << *beg3 << std::endl;
        }

    std::cout << std::endl << "operator= (vect1 = vect3) : **************************************" << std::endl;
        vect1 = vect3;
        beg1 =vect1.begin();
        end1 =vect1.end();
        for (; beg1 < end1; beg1++)
        {
            std::cout << "vect1: " << *beg1 << std::endl;
        }
        std::cout << "~~~~~~~~~~~~~~~" << std::endl;
        beg3 =vect3.begin();
        end3 =vect3.end();
        for (; beg3 < end3; beg3++)
        {
            std::cout << "vect3: " << *beg3 << std::endl;
        }

    std::cout << "**************************************" << std::endl;

    ft::vector<int>::iterator       beg = vect1.begin();
    ft::vector<int>::iterator       end = vect1.end();

    for (; beg < end; beg++)
    {
        std::cout << "operator= test: " << *beg << std::endl;
    }

    return (0);
}

// int main()
// {
//     {
//         ft::Iterator<std::string>   iterator;

//         // std::cout << *iterator++ << std::endl;
//         // std::cout << *iterator << std::endl;
//     }
//     std::cout << "************************************" << std::endl;
//     {
//         std::vector<std::string>             vect;

//         vect.push_back("1");
//         vect.push_back("2");
//         vect.push_back("3");
//         vect.push_back("4");
//         vect.push_back("5");
//         vect.push_back("6");
//         vect.push_back("7");
//         vect.push_back("8");
//         vect.push_back("9");
//         vect.push_back("10");
//         std::vector<std::string>::iterator   it = vect.begin();

//         std::cout << "[" << *it << "]" << std::endl;
//         vect.begin()->clear();
//         std::cout << "[" << *it << "]" << std::endl;
//         std::cout << "[" << *it++ << "]" << std::endl;
//         std::cout << "[" << *it << "]" << std::endl;
//     }
//     return (0);

// }

// int main()
// {
//     std::vector<int>    vect;

//     std::cout << (vect.begin() == vect.end()) << std::endl;
//     vect.push_back(15);
//     std::cout << (vect.begin() == vect.end()) << std::endl;
//     return (0);
// }

// int main()
// {
//     ft::Iterator<int>   it0;
//     std::cout << "index test00: " << it0[4] << std::endl;

//     it0++;
//     std::cout << "index test01: " << it0[4] << std::endl;

//     ft::Iterator<int>   it1(it0);
//     std::cout << "*******************" << std::endl;
//     ft::Iterator<int>   it2;

//     it2 = it1;
//     std::cout << (it2 == it1) << std::endl;
//     std::cout << (it0 != it1) << std::endl;

//     std::cout << *(it0 + 5);
//     std::cout << *it0 << std::endl;
//     std::cout << *(it0++) << std::endl;
//     std::cout << *it0 << std::endl;
//     std::cout << *(++it0) << std::endl;
//     std::cout << *it0 << std::endl;

//     std::cout << "Initial Position: " << *it0 << std::endl;

//     it0 = it0 + 5;

//     std::cout << "Initial Position + 5: " << *(it0) << std::endl;
//     std::cout << "Initial Position + 2: " << *(it0 - 3) << std::endl;
//     it0 += 3;
//     it0 -= 3;
//     std::cout << "Initial Position + 2: " << *(it0 - 3) << std::endl;

//     std::cout << "--------------------------------------" << std::endl;

//     std::cout << "DBG MODE: " << *it0++ << std::endl;
//     std::cout << "DIFFPTR : " << (it0 - it1) << std::endl;
//     return (0);
// }

// int     main()
// {
    // ft::Iterator<int>   it0;
    // ft::Iterator<int>   it1(it0);

    // it0++;
    // it0++;
    // it0++;
    // it0++;
    // it0++;
    // std::cout << "IT0 +=5   : " << *it0   << std::endl;
    // std::cout << "**************************" << std::endl;
    // std::cout << "IT1       : " << *it1   << std::endl;
    // std::cout << "it0 - it1 : " << it1 - it0 << std::endl;
    // return (0);
// }

// int     main()
// {
    // ft::vector<int>     intVect(10, 12);

    // std::cout << "***************************" << std::endl;
    // ft::vector<int>::iterator   it;

    // it = intVect.begin();
    // for (ft::vector<int>::iterator it = intVect.begin(); it < intVect.end(); it++)
    // {
        // std::cout << *it << std::endl;
    // }

    // return (0);
// }


// int main()
// {
//     std::vector<int>    vect;

//     vect.push_back(1);
//     vect.push_back(3);
//     vect.push_back(5);
//     vect.push_back(7);
//     vect.push_back(9);
//     vect.push_back(11);
//     vect.push_back(13);
//     vect.push_back(15);
//     vect.push_back(17);
//     vect.push_back(19);

//     std::vector<int>::iterator      it;
//     std::vector<int>::iterator      it0 = vect.begin();

//     it = vect.begin();

//     std::cout << *it++ << std::endl;
//     std::cout << *it << std::endl;
//     std::cout << *it0 << std::endl;

//     it++;
//     std::cout << it[5] << std::endl;
//     return (0);
// }

// int main()
// {
    // std::vector<int>::iterator  it;
    // std::vector<int>::iterator  ite;

    // std::vector<int>            vect;

    // vect.push_back(1);
    // vect.push_back(2);
    // vect.push_back(3);
    // vect.push_back(4);
    // vect.push_back(5);
    // vect.push_back(6);
    // vect.push_back(7);
    // vect.push_back(8);
    // vect.push_back(9);
    // vect.push_back(10);

    // it = vect.begin();
    // ite = vect.end();

    // // std::cout << it << std::endl;
    // // std::cout << *it++ << std::endl;
    // std::cout << *(it + 5) << std::endl;
    // // std::cout << ite + it << std::endl;
    // return (0);
// }