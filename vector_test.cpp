
#include <iostream>
#include <vector>

#include "vector.hpp"
#include "utils/random_access_iterator.hpp"
// #include "../reverse_iterator.hpp"

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

// int		main()
// {
// 	{
// 		std::vector<int>	vect;
// 		for (int i = 1; i < 11; i++) vect.push_back(i);

// 		std::vector<int>::iterator	it = vect.begin();
// 		std::cout << "it + 1: " << *(it + 1) << std::endl;
// 		std::cout << "1 + it: " << *(1 + it) << std::endl;
// 	}
// 	std::cout << "***********************************************" << std::endl;
// 	{
// 		ft::vector<int>	vect;
// 		for (int i = 1; i < 11; i++) vect.push_back(i);

// 		ft::vector<int>::iterator	it = vect.begin();
// 		std::cout << "it + 1: " << *(it + 1) << std::endl;
// 		std::cout << "1 + it: " << *(1 + it) << std::endl;
// 	}
// }

// int		main()
// {
// 	{
// 		std::vector<std::string>	vect;

// 		vect.push_back("1");
// 		vect.push_back("22");
// 		vect.push_back("333");
// 		vect.push_back("4444");
// 		vect.push_back("55555");
// 		vect.push_back("666666");
// 		vect.push_back("7777777");
// 		vect.push_back("88888888");
// 		vect.push_back("999999999");
// 		vect.push_back("1000000000");

// 		std::vector<std::string>::reverse_iterator	it = vect.rbegin() + 4;

// 		std::cout << it->length() << std::endl;
// 	}
// 	std::cout << "**************************" << std::endl;
// 	{
// 		ft::vector<std::string>	vect;

// 		vect.push_back("1");
// 		vect.push_back("22");
// 		vect.push_back("333");
// 		vect.push_back("4444");
// 		vect.push_back("55555");
// 		vect.push_back("666666");
// 		vect.push_back("7777777");
// 		vect.push_back("88888888");
// 		vect.push_back("999999999");
// 		vect.push_back("1000000000");

// 		ft::vector<std::string>::reverse_iterator	it = vect.rbegin() + 4;

// 		std::cout << it->length() << std::endl;

// 	}
// 	return (0);
// }

// int		main()
// {
// 	{
// 		ft::vector<std::string>		vect;

// 		vect.push_back("1");
// 		vect.push_back("22");
// 		vect.push_back("333");
// 		vect.push_back("4444");
// 		vect.push_back("55555");
// 		vect.push_back("666666");
// 		vect.push_back("7777777");
// 		vect.push_back("88888888");
// 		vect.push_back("999999999");
// 		vect.push_back("1000000000");

// 		ft::vector<std::string>::reverse_iterator	rit = vect.rbegin() + 4;

// 		std::cout << rit->length() << std::endl;
// 	}
// 	std::cout << "***************************" << std::endl;
// 	{
// 		ft::vector<std::string>		vect;

// 		vect.push_back("1");
// 		vect.push_back("22");
// 		vect.push_back("333");
// 		vect.push_back("4444");
// 		vect.push_back("55555");
// 		vect.push_back("666666");
// 		vect.push_back("7777777");
// 		vect.push_back("88888888");
// 		vect.push_back("999999999");
// 		vect.push_back("1000000000");

// 		ft::vector<std::string>::reverse_iterator	rit = vect.rbegin() + 4;

// 		std::cout << rit->length() << std::endl;

// 	}
// 	return (0);
// }

// int		main()
// {
	// std::vector<std::string> v(3, "hello");

    // std::reverse_iterator<std::vector<std::string>::iterator> rit(v.end());
    // ft::reverse_iterator<std::vector<std::string>::iterator> my_rit(v.end());

	// return (0);
// }

// int		main()
// {
	// ft::vector<int>	vect;
	// for (int i = 1; i <= 10; i++) vect.push_back(i);

	// for(ft::vector<int>::reverse_iterator	rit = vect.rbegin(); rit < vect.rend(); rit++)
	// {
		// std::cout << "Rit: " << *rit << std::endl;
	// }

	// return (0);
// }

int		main()
{
	{
		ft::vector<int>	vect;
		for(int i = 1; i <= 11; i++)	vect.push_back(i);

		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		for (ft::vector<int>::reverse_iterator it = vect.rbegin(); it < vect.rend(); it++)
		{
			std::cout << "It: " << *it << std::endl;
		}
	}
	std::cout << "******************" << std::endl;
	{
		std::vector<int>	vect;
		for(int i = 1; i <= 11; i++)	vect.push_back(i);

		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		for (std::vector<int>::reverse_iterator it = vect.rbegin(); it < vect.rend(); it++)
		{
			std::cout << "It: " << *it << std::endl;
		}

	}
	return (0);
}