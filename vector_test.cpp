
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

int	main()
{
	{
		std::vector<std::string>	const vect(10, "test");

		std::vector<std::string>::const_reverse_iterator	rit(vect.end());
	}
	std::cout << "**********" << std::endl;
	{
		ft::vector<std::string>	const vect(10, "test");

		ft::vector<std::string>::const_reverse_iterator	rit(vect.end());
	}
	return (0);
}