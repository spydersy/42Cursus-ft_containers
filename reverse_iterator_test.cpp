
#include <iostream>
#include <vector>

#include "./include/iterator/reverse_iterator.hpp"
#include "./include/vector/vector.hpp"

// int	main()
// {
	// std::vector<int>	vect;
	// std::cout << "size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

	// for (int i = 1; i <= 10; i++)
	// {
		// vect.push_back(i);
	// }
	// std::cout << "size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
	// std::cout << "*****************" << std::endl;
	// vect.reserve(5);
	// std::cout << "size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// }

// int	main()
// {
	// std::vector<int>	vect;for (int i = 1; i <= 10; i++) { vect.push_back(i); }
	// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

	// std::cout << "***********************************" << std::endl;
	// vect.resize(5, 4);
	// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
	// for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
	// {
		// std::cout << "*it: " << *it << std::endl;
	// }

	// return (0);
// }

int	main()
{
	{
		std::vector<int>	vect;
		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		vect.resize(15, 4);
		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		vect.resize(19, 4);
		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		vect.resize(31, 4);
		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		vect.resize(39, 4);
		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

	}
	std::cout << "********************" << std::endl;
	{
		ft::vector<int>	vect;
		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		vect.resize(15, 4);
		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		vect.resize(19, 4);
		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		vect.resize(31, 4);
		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		vect.resize(39, 4);
		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

	}
	return (0);
}

// int	main()
// {
	// {
		// std::vector<int>	sys;

		// for (int i = 1; i < 11; i++)
		// {
			// sys.push_back(i);
		// }

		// std::vector<int>		vect(sys.begin(), sys.end());
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		// vect.resize(5, 4);
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		// for (std::vector<int>::iterator i = vect.begin(); i < vect.end(); i++)
		// {
			// std::cout << "*it: " << *i << std::endl;
		// }

		// std::vector<int>::iterator	it = vect.end();
		// std::cout << "check value: " << *it++ << std::endl;
		// std::cout << "check value: " << *it++ << std::endl;
		// std::cout << "check value: " << *it++ << std::endl;

		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
		// vect.resize(21, 1337);
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
		// std::cout << "				~~~~~~~~~~~" << std::endl;
		// for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
		// {
			// std::cout << "It checker: " << *it << std::endl;
		// }

	// }
	// std::cout << "***************************************" << std::endl;
	// {
		// std::vector<int>	sys;

		// for (int i = 1; i < 11; i++)
		// {
			// sys.push_back(i);
		// }

		// ft::vector<int>		vect(sys.begin(), sys.end());
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		// vect.resize(5, 4);
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		// for (ft::vector<int>::iterator i = vect.begin(); i < vect.end(); i++)
		// {
			// std::cout << "*it: " << *i << std::endl;
		// }

		// ft::vector<int>::iterator	it = vect.end();
		// std::cout << "check value: " << *it++ << std::endl;
		// std::cout << "check value: " << *it++ << std::endl;
		// std::cout << "check value: " << *it++ << std::endl;

		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
		// vect.resize(21, 1337);
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
		// std::cout << "				~~~~~~~~~~~" << std::endl;
		// for (ft::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
		// {
			// std::cout << "It checker: " << *it << std::endl;
		// }

	// }
	// return (0);
// }


// int		main()
// {
// 	{
// 		std::vector<int>	vect;

// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		vect.resize(12, 1337);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		for (std::vector<int>::iterator it = vect.begin() ; it < vect.end(); it++)
// 		{
// 			std::cout << "*it: " << *it << std::endl;
// 		}

// 	}
// 	std::cout << "***************************************" << std::endl;
// 	{
// 		ft::vector<int>	vect;

// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		vect.resize(12, 1337);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		for (ft::vector<int>::iterator it = vect.begin() ; it < vect.end(); it++)
// 		{
// 			std::cout << "*it: " << *it << std::endl;
// 		}

// 	}
// 	return (0);
// }