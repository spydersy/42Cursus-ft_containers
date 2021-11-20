
// #include <iostream>
// #include <vector>

// int     main()
// {
    // std::vector<std::string> vctr;

    // vctr.push_back("a");
    // vctr.push_back("b");
    // vctr.push_back("c");
    // vctr.push_back("c");
    // vctr.push_back("c");
    // std::cout << vctr.size() << std::endl;
    // std::cout << vctr[2] << std::endl;
    // std::cout << vctr.capacity() << std::endl;
    // return (0);
// }

#include "./include/vector/vector.hpp"

int     main()
{
    try
    {
        ft::vector<std::string> v;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
