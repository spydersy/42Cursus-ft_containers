
#include <vector>
#include <iostream>

int	main()
{
	std::vector<int>	vect;

	std::cout << "Capacity0: " << vect.capacity() << std::endl;
	for (int i = 1; i <= 100; i++)
	{
		vect.push_back(i);
	}
	std::cout << "Capacity1: " << vect.capacity() << std::endl;
	
	vect.reserve(0);
	std::cout << "Capacity2: " << vect.capacity() << std::endl;

	for (std::vector<int>::iterator b = vect.begin(); b <= vect.end(); b++)
	{
		std::cout << "vect: " << *b << std::endl;
	}
	return (0);
}
