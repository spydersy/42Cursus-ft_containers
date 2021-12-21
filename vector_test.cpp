
#include <iostream>
#include <vector>

#include "./include/vector/vector.hpp"
#include "./utils/random_access_iterator.hpp"
#include "./utils/reverse_iterator.hpp"

int		main()
{
	{
		ft::vector<int>	vect0; for (int i = 1; i < 11; i++) vect0.push_back(i);
		ft::vector<int>	vect1; for (int i = 10; i < 21; i++) vect1.push_back(i);

		ft::swap(vect0, vect1);

		for (ft::vector<int>::iterator it = vect0.begin(); it < vect0.end(); it++)
		{
			std::cout << "It0:" << *it << std::endl;
		}
		std::cout << "***************" << std::endl;
		for (ft::vector<int>::iterator it = vect1.begin(); it < vect1.end(); it++)
		{
			std::cout << "It1:" << *it << std::endl;
		}


		std::cout << (vect0 == vect1) << std::endl;
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	{
		std::vector<int>	vect0; for (int i = 1; i < 11; i++) vect0.push_back(i);
		std::vector<int>	vect1; for (int i = 10; i < 21; i++) vect1.push_back(i);

		std::swap(vect0, vect1);

		for (std::vector<int>::iterator it = vect0.begin(); it < vect0.end(); it++)
		{
			std::cout << "It0:" << *it << std::endl;
		}
		std::cout << "***************" << std::endl;
		for (std::vector<int>::iterator it = vect1.begin(); it < vect1.end(); it++)
		{
			std::cout << "It1:" << *it << std::endl;
		}


		std::cout << (vect0 == vect1) << std::endl;
	}
	return (0);
}
