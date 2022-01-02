
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

int	main()
{
	{
		std::vector<std::string>	vect;

		vect.push_back("01");
		vect.push_back("02");
		vect.push_back("03");
		vect.push_back("04");
		vect.push_back("05");
		vect.push_back("06");
		vect.push_back("07");
		vect.push_back("08");
		vect.push_back("09");
		vect.push_back("10");

		std::vector<std::string>::reverse_iterator	rit = vect.rbegin();
		std::cout << (rit <= rit+1) << std::endl;
	}
	std::cout << "***************" << std::endl;
	{
		ft::vector<std::string>	vect1;

		vect1.push_back("01");
		vect1.push_back("02");
		vect1.push_back("03");
		vect1.push_back("04");
		vect1.push_back("05");
		vect1.push_back("06");
		vect1.push_back("07");
		vect1.push_back("08");
		vect1.push_back("09");
		vect1.push_back("10");

		ft::vector<std::string>::reverse_iterator	rit = vect1.rbegin();

		std::cout << (rit <= rit + 1) << std::endl;
	}
	return (0);
}