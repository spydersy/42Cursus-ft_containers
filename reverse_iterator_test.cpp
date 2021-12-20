
#include <iostream>
#include <vector>

#include "./include/vector/vector.hpp"
#include "./utils/random_access_iterator.hpp"
#include "./utils/reverse_iterator.hpp"

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
// 	std::vector<int>	vect;
// 	std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 	vect.resize(15, 4);
// 	std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 	vect.resize(19, 4);
// 	std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 	vect.resize(31, 4);
// 	std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 	vect.resize(39, 4);
// 	std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// }
	// std::cout << "********************" << std::endl;
	// {
		// ft::vector<int>	vect;
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		// vect.resize(15, 4);
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		// vect.resize(19, 4);
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		// vect.resize(31, 4);
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

		// vect.resize(39, 4);
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

	// }
	// return (0);
// }

// int	main()
// {
// 	ft::vector<int> abc;
//     ft::vector<int> data(20);
//     ft::vector<int>::const_iterator it;

//     for (int i = 0; i < 10;i++)
//         abc.push_back(i);
//     it = data.begin();
//     it = it + 3;
//     data.insert(it,abc.begin(),abc.end());
// 	return (0);
// }

// int		main()
// {
// 	ft::vector<int>	vect;
// 	for (int i = 1; i <= 10; i++)	vect.push_back(i);

// 	ft::vector<int>::const_iterator	cit = vect.begin();

// 	for (; cit < vect.end(); cit++)
// 	{
// 		std::cout << "*Cit: " << *cit << std::endl;
// 	}


// 	return (0);
// }

// int	main()
// {
// 	{
// 		std::vector<int>	sys;

// 		for (int i = 1; i < 11; i++)
// 		{
// 			sys.push_back(i);
// 		}

// 		std::vector<int>		vect(sys.begin(), sys.end());
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		vect.resize(5, 4);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		for (std::vector<int>::iterator i = vect.begin(); i < vect.end(); i++)
// 		{
// 			std::cout << "*it: " << *i << std::endl;
// 		}

// 		std::vector<int>::iterator	it = vect.end();
// 		std::cout << "check value: " << *it++ << std::endl;
// 		std::cout << "check value: " << *it++ << std::endl;
// 		std::cout << "check value: " << *it++ << std::endl;

// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		vect.resize(21, 1337);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		std::cout << "				~~~~~~~~~~~" << std::endl;
// 		for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "It checker: " << *it << std::endl;
// 		}

// 	}
// }
// 	std::cout << "***************************************" << std::endl;
// 	{
// 		std::vector<int>	sys;

// 		for (int i = 1; i < 11; i++)
// 		{
// 			sys.push_back(i);
// 		}

// 		ft::vector<int>		vect(sys.begin(), sys.end());
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		vect.resize(5, 4);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		for (ft::vector<int>::iterator i = vect.begin(); i < vect.end(); i++)
// 		{
// 			std::cout << "*it: " << *i << std::endl;
// 		}

// 		ft::vector<int>::iterator	it = vect.end();
// 		std::cout << "check value: " << *it++ << std::endl;
// 		std::cout << "check value: " << *it++ << std::endl;
// 		std::cout << "check value: " << *it++ << std::endl;

// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		vect.resize(21, 1337);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		std::cout << "				~~~~~~~~~~~" << std::endl;
// 		for (ft::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "It checker: " << *it << std::endl;
// 		}

// 	}
// 	return (0);
// }


// int		main()
// {
		// std::vector<int>	vect;

		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
		// vect.resize(12, 1337);
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// }

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

// int		main()
// {
	// std::vector<int>	vect;

	// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
	// vect.assign(7, 100);
	// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
	// vect.assign(2, 1337);
	// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

	// for (size_t i = 0; i < 7; i++)
	// {
		// std::cout << vect[i] << std::endl;
	// }

	// std::cout << (vect <= vect) << std::endl;

	// return (0);
// }

// int		main()
// {
// 	std::vector<int>	vect(50, 1337);
// 	std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 	vect.reserve(60);
// 	std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 	vect.insert(vect.begin() + 10, 11, 42);
// 	std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 	for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 	{
// 		std::cout << "It: " << *it << std::endl;
// 	}

// 	return (0);
// }

// int		main()
// {
// 	{
// 		std::vector<int>	vect;
// 		vect.reserve(10);

// 		for (int i = 1; i < 11; i++)
// 		{
// 			vect.push_back(i);
// 		}
// 		for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "DBG: " << *it << std::endl;
// 		}

// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		vect.insert(vect.begin(), 100);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		int		i = 0;
// 		for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "It["<< i++ << "]: " << *it << std::endl;
// 		}

// 	}
// 	std::cout << "****************************************" << std::endl;
// 	{
// 		ft::vector<int>		vect;
// 		vect.reserve(10);

// 		for (int i = 1; i < 11; i++)
// 		{
// 			vect.push_back(i);
// 		}
// 		for (ft::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "DBG: " << *it << std::endl;
// 		}

// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		vect.insert(vect.begin(), 100);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		int		i = 0;
// 		for (ft::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "It["<< i++ << "]: " << *it << std::endl;
// 		}
// 	}

// 	return (0);
// }

// int		main()
// {
	// {
		// std::vector<int>	vect;
		// vect.reserve(100);
		// for (int i = 1; i < 11; i++)
		// {
			// vect.push_back(i);
		// }
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
		// vect.insert(vect.end(), 15, 1337);

		// for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
		// {
			// std::cout << "It: " << *it << std::endl;
		// }
		// std::cout << "Size: " << vect.size() << "Capacity: " << vect.capacity() << std::endl;
	// }
	// std::cout << "******************************************************" << std::endl;
	// {
		// ft::vector<int>	vect;
		// vect.reserve(100);
		// for (int i = 1; i < 11; i++)
		// {
			// vect.push_back(i);
		// }
		// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
		// vect.insert(vect.end(), 15, 1337);

		// for (ft::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
		// {
			// std::cout << "It: " << *it << std::endl;
		// }
		// std::cout << "Size: " << vect.size() << "Capacity: " << vect.capacity() << std::endl;
	// }
	// return (0);
// }

// int		main()
// {
// 	{
// 		std::vector<int>		tmp;
// 		for (int i = 50; i < 61; i++)
// 		{
// 			tmp.push_back(i);
// 		}

// 		std::vector<int>	vect;
// 		vect.reserve(100);
// 		for (int i = 1; i < 11; i++)
// 		{
// 			vect.push_back(i);
// 		}
// 		vect.insert(vect.begin() + 3, tmp.begin() + 4, tmp.end());
// 		for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "It: " << *it << std::endl;
// 		}
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 	}
// 	std::cout << "***************************" << std::endl;
// 	{
// 		ft::vector<int>		tmp;
// 		for (int i = 50; i < 61; i++)
// 		{
// 			tmp.push_back(i);
// 		}

// 		ft::vector<int>	vect;
// 		vect.reserve(100);
// 		for (int i = 1; i < 11; i++)
// 		{
// 			vect.push_back(i);
// 		}
// 		vect.insert(vect.begin() + 3, tmp.begin() + 4, tmp.end());
// 		for (ft::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "It: " << *it << std::endl;
// 		}
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 	}
// 	return (0);
// }

// int		main()
// {
// 	std::vector<int>	tmp;
// 	for (int i = 50; i < 61; i++)
// 	{
// 		tmp.push_back(i);
// 	}

// 	{
// 		std::vector<int>	vect;
// 		vect.push_back(42);
// 		vect.push_back(13);
// 		vect.push_back(125);

// 		vect.insert(vect.begin() + 1, tmp.begin(), tmp.end());

// 		for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "It: " << *it << std::endl;
// 		}
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 	}
// 	std::cout << "***********************" << std::endl;
// 	{
// 		ft::vector<int>	vect;
// 		vect.push_back(42);
// 		vect.push_back(13);
// 		vect.push_back(125);

// 		vect.insert(vect.begin() + 1, tmp.begin(), tmp.end());

// 		for (ft::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "It: " << *it << std::endl;
// 		}
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 	}
// 	return (0);
// }

// int	main()
// {
// 	{
// 		std::vector<int>	vect;
// 		for (int i = 1; i < 50; i++)	vect.push_back(i);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		vect.erase(vect.begin() + 2, vect.end() - 5);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		int	c = 0;
// 		for (std::vector<int>::iterator it = vect.begin() ; it < vect.end(); it++)
// 		{
// 			std::cout << "It[" << c++ << "]: " << *it << std::endl;
// 		}
// 	}
// 	std::cout << "*************************" << std::endl;
// 	{
// 		ft::vector<int>	vect;
// 		for (int i = 1; i < 50; i++)	vect.push_back(i);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		vect.erase(vect.begin() + 2, vect.end() - 5);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		int	c = 0;
// 		for (ft::vector<int>::iterator it = vect.begin() ; it < vect.end(); it++)
// 		{
// 			std::cout << "It[" << c++ << "]: " << *it << std::endl;
// 		}

// 	}
// 	return (0);
// }

// int	main()
// {
	// std::vector<int>	vect;

	// for (int i = 1; i <= 10; i++)	vect.push_back(i);
	// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

	// vect.clear();
	// std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
	// return (0);
// }

// int		main()
// {
	// std::vector<int>	vect1;
	// std::vector<int>	vect2;

	// vect1.reserve(10000);
	// for (int i = 1; i<11; i++) vect1.push_back(i);
	// for (int i = 1; i<11; i++) vect2.push_back(i);

	// std::cout << (vect1 == vect2) << std::endl;
	// std::cout << (vect1 > vect2) << std::endl;
	// return (0);
// }

// int		main()
// {
	// std::vector<int>	vect1;
	// std::vector<int>	vect2;

	// for (int i = 1; i <= 10; i++) vect1.push_back(i);
	// for (int i = 1; i <= 5; i++) vect2.push_back(i);

	// std::cout <<(vect1 < vect2)<< std::endl;
	// std::cout <<(vect2 < vect1)<< std::endl;

	// return (0);
// }

// int		main()
// {
// 	{
// 		std::vector<int>	vect;
// 		for (int i = 1; i < 21; i++)	vect.push_back(i);
// 		for (std::vector<int>::reverse_iterator it = vect.rend(); it < vect.rbegin(); it++)
// 		{
// 			std::cout << "*it: " << *it << std::endl;
// 		}
// 	}
// 	std::cout << "**************************" << std::endl;
// 	{
// 		ft::vector<int>	vect;
// 		for (int i = 1; i < 21; i++)	vect.push_back(i);
// 		for (ft::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "*it: " << *it << std::endl;
// 		}
// 	}
// 	return (0);
// }

// int main ()
// {
// 	{
//   std::vector<int> myvector (5);  // 5 default-constructed ints

//   int i=0;

//   std::vector<int>::reverse_iterator rit = myvector.rbegin();
//   for (; rit!= myvector.rend(); ++rit)
//     *rit = ++i;

//   std::cout << "myvector contains:";
//   for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
// 	}
// 	{
//   ft::vector<int> myvector (5);  // 5 default-constructed ints

//   int i=0;

//   ft::vector<int>::reverse_iterator rit = myvector.rbegin();
//   for (; rit!= myvector.rend(); ++rit)
//     *rit = ++i;

//   std::cout << "myvector contains:";
//   for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

// 	}
//   return 0;
// }

// int	main()
// {
// 	{
// 		std::vector<int>					vect;
// 		std::vector<int>::reverse_iterator	rit;

// 		for(int i = 1; i < 11 ; i++) vect.push_back(i);

// 		rit = vect.rbegin();
// 		// std::cout << *rit << std::endl;
// 		std::cout << *vect.rbegin() << std::endl;
// 		std::cout << *vect.rend() << " DBG" << std::endl;
// 		if (rit <= vect.rend())	std::cout << "Yeeeeeeees" << std::endl;
// 		else	                std::cout << "Nooooooooo" << std::endl;
// 		for (; rit < vect.rend(); rit++)
// 		{
// 			std::cout << "Rit: " << *rit << std::endl;
// 		}

// 	}
// 	std::cout << "**************************" << std::endl;
// 	{
// 		ft::vector<int>					vect;
// 		ft::vector<int>::reverse_iterator	rit;

// 		for(int i = 1; i < 11 ; i++) vect.push_back(i);

// 		rit = vect.rbegin();
// 		// std::cout << *rit << std::endl;
// 		std::cout << *vect.rbegin() << std::endl;
// 		std::cout << *vect.rend() << " DBG" << std::endl;
// 		if (rit <= vect.rend())	std::cout << "Yeeeeeeees" << std::endl;
// 		else	                std::cout << "Nooooooooo" << std::endl;
// 		for (; rit < vect.rend(); rit++)
// 		{
// 			std::cout << "Rit: " << *rit << std::endl;
// 		}
// 	}
// 	return (0);
// }

// int		main()
// {
// 	ft::vector<int>	vect;

// 	for (int i = 1; i <= 20; i++)	vect.push_back(i);

// 	ft::vector<int>::iterator			it = vect.end() - 1;
// 	ft::vector<int>::reverse_iterator	rit = vect.rbegin();

// 	for (; it >= vect.begin() - 5; it--)
// 	{
// 		std::cout << "*it: " << *it << " *rit: " << *rit << std::endl;
// 		rit++;
// 	}


// 	return (0);
// }

// int	main()
// {
// 	{
// 		std::vector<int>	vect(15, 12);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

// 		for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
// 		{
// 			std::cout << "*it: " << *it << std::endl;
// 		}
// 	}
// 	std::cout << "**************************************************************" << std::endl;
// 	{
// 		ft::vector<int>	vect(15, 12);
// 		std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
// 		ft::vector<int>::iterator it = vect.begin();

// 		for (; it < vect.end(); it++)
// 		{
// 			std::cout << "*it: " << *it << std::endl;
// 		}
// 	}
// }

int		main()
{
	ft::vector<int>	vect;

	for (int i = 1; i <= 10; i++) vect.push_back(i);

	ft::vector<int>::const_iterator	it = vect.begin();

	std::cout << *(++it) << std::endl;

	for (; it < vect.end(); it++)
	{

		std::cout << *it << std::endl;
	}

	return (0);
}