
#include <iostream>
#include <vector>

#include <cstdlib>
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
	// {
		// std::vector<int>			vect;
		// std::vector<int>::iterator	it;

		// for (int i = 1; i < 11; i++)	vect.push_back(i);
		// it = vect.begin();
		// std::cout << *it++ << std::endl;
		// std::cout << *it << std::endl;
	// }
	// std::cout << "*********" << std::endl;
	// {
		// ft::vector<int>				vect;
		// ft::vector<int>::iterator	it;

		// for (int i = 1; i < 11; i++)	vect.push_back(i);
		// it = vect.begin();
		// std::cout << *it++ << std::endl;
		// std::cout << *it << std::endl;
	// }
	// return (0);
// }

// int	main()
// {
// 	{
// 		std::vector<std::string>	const vect(10, "test");

// 		std::vector<std::string>::const_reverse_iterator	rit(vect.end());
// 	}
// 	std::cout << "**********" << std::endl;
// 	{
// 		ft::vector<std::string>	const vect(10, "test");

// 		ft::vector<std::string>::const_reverse_iterator	rit(vect.end());
// 	}
// 	return (0);
// }

// int		main()
// {
// 	std::vector<std::string>	vect;

// 	vect.push_back("01");
// 	vect.push_back("02");
// 	vect.push_back("03");
// 	vect.push_back("04");
// 	vect.push_back("05");
// 	vect.push_back("06");
// 	vect.push_back("07");
// 	vect.push_back("08");
// 	vect.push_back("09");
// 	vect.push_back("10");

// 	std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 	vect.resize(4);
// 	for (int i = 0; i < 10; i++)

// 	return (0);
// }

// int		main()
// {
// 	{
// 		std::vector<int>	vect;
// 		for (int i = 1; i <= 10; i++)	vect.push_back(i);

// 		std::cout << *vect.end() << std::endl;
// 		std::vector<int>::reverse_iterator	rit(vect.end() - 2);
// 		std::cout << *rit++ << std::endl;
// 		std::cout << *rit++ << std::endl;
// 		std::cout << *rit++ << std::endl;
// 	}
// 	std::cout << "***********************" << std::endl;
// 	{
// 		ft::vector<int>	vect;
// 		for (int i = 1; i <= 10; i++)	vect.push_back(i);

// 		std::cout << *vect.end() << std::endl;
// 		ft::vector<int>::reverse_iterator	rit(vect.end() - 2);
// 		std::cout << *rit++ << std::endl;
// 		std::cout << *rit++ << std::endl;
// 		std::cout << *rit++ << std::endl;
// 	}
// 	return (0);
// }

int		main()
{
	{
		std::vector<int>	vect;
		for (int i = 1; i <= 10; i++)	vect.push_back(i);
		std::vector<int>::const_reverse_iterator	crit0(vect.end());
		std::vector<int>::const_reverse_iterator	crit1(vect.end() - 1);

		std::cout << "checke	r: " << *crit0 << " | " << *crit1 << std::endl;

		std::cout << *(crit0 + 1) << std::endl;
		std::cout << *(crit1) << std::endl;
		std::cout << *(crit1 + 1) << std::endl;

	}
	std::cout << "**************" << std::endl;
	{
		ft::vector<int>	vect;
		for (int i = 1; i <= 10; i++)	vect.push_back(i);
		ft::vector<int>::const_reverse_iterator	crit0(vect.end());
		ft::vector<int>::const_reverse_iterator	crit1(vect.end() - 1);

		std::cout << "checker: " << *crit0 << " | " << *crit1 << std::endl;

		std::cout << *(crit0 + 1) << std::endl;
		std::cout << *(crit1) << std::endl;
		std::cout << *(crit1 + 1) << std::endl;

	}
	return (0);
}