
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

// int		main()
// {
// 	{
// 		std::vector<int>	vect;
// 		for (int i = 1; i <= 10; i++)	vect.push_back(i);
// 		std::vector<int>::const_reverse_iterator	crit0(vect.end());
// 		std::vector<int>::const_reverse_iterator	crit1(vect.end() - 1);

// 		std::cout << "checke	r: " << *crit0 << " | " << *crit1 << std::endl;

// 		std::cout << *(crit0 + 1) << std::endl;
// 		std::cout << *(crit1) << std::endl;
// 		std::cout << *(crit1 + 1) << std::endl;

// 	}
// 	std::cout << "**************" << std::endl;
// 	{
// 		ft::vector<int>	vect;
// 		for (int i = 1; i <= 10; i++)	vect.push_back(i);
// 		ft::vector<int>::const_reverse_iterator	crit0(vect.end());
// 		ft::vector<int>::const_reverse_iterator	crit1(vect.end() - 1);

// 		std::cout << "checker: " << *crit0 << " | " << *crit1 << std::endl;

// 		std::cout << *(crit0 + 1) << std::endl;
// 		std::cout << *(crit1) << std::endl;
// 		std::cout << *(crit1 + 1) << std::endl;

// 	}
// 	return (0);
// }

// int	main()
// {
//     /*------------------ std::vectors ---------------------*/
//     std::vector<std::string> v1(10, "string2");
//     std::vector<std::string> const v2(10, "string2");
//     /*-----------------------------------------------------*/
//     /*------------------ ft::vectors ---------------------*/
//     ft::vector<std::string> ft_v1(10, "string2");
//     ft::vector<std::string> const ft_v2(10, "string2");
//     /*----------------------------------------------------*/
//     /*------------------ strings to store the results ----*/
//     std::string res, ft_res, c_res, c_ft_res;
//     /*----------------------------------------------------*/
//     for (std::vector<std::string>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); ++rit) // fill res from v1
//         res += *rit;
//     for (std::vector<std::string>::const_reverse_iterator rit = v2.rbegin(); rit != v2.rend(); ++rit) // fill c_res from const v1
//         c_res += *rit;

//     for (ft::vector<std::string>::reverse_iterator rit = ft_v1.rbegin(); rit != ft_v1.rend(); ++rit) // fill ft_res from ft_v1
//         ft_res += *rit;
//     for (ft::vector<std::string>::const_reverse_iterator rit = ft_v2.rbegin(); rit != ft_v2.rend(); ++rit) // fill c_ft_res from const ft_v1
//         c_ft_res += *rit;

// 	std::cout << "    res: " <<    res << std::endl;
// 	std::cout << " ft_res: " << ft_res << std::endl;

// 	std::cout << "*****************************************" << std::endl;

// 	std::cout << "    res: " <<    c_res << std::endl;
// 	std::cout << " ft_res: " << c_ft_res << std::endl;

// 	return (0);
// }



int		main()
{
    /*-------------------------------------- time limit test -----------------------------------*/
    {
        time_t start = 0, end = 0, diff;
        /*
         * test with n greater than vector capacity
         */
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        // start = get_time();
        v1.resize(1e6);
        // end = get_time();
        diff = end - start;
        // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        // ualarm(diff * 1e3, 0);
        ft_v1.resize(1e6);
        // ualarm(0, 0);
        /*----------------------------------------------------*/
        /*
         *	test with n lesser than capacity and greater than size
         */
        /*------------------ std::vectors ---------------------*/
        v1.resize(20);
        // start = get_time();
        v1.resize(1e5);
        // end = get_time();
        diff = end - start;
        // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        /*------------------ ft::vectors ---------------------*/
        ft_v1.resize(20);
        // ualarm(diff * 1e3, 0);
        ft_v1.resize(1e5);
        // ualarm(0, 0);
        /*----------------------------------------------------*/
        /*
         * test with n lesser than capacity and lesser an size
         */
        /*------------------ std::vectors ---------------------*/
        v1.resize(100);
        // start = get_time();
        v1.resize(50);
        // end = get_time();
        diff = end - start;
        // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
        /*------------------ ft::vectors ---------------------*/
        ft_v1.resize(100);
        // ualarm(diff * 1e3, 0);
        ft_v1.resize(50);
        // ualarm(0, 0);
        /*----------------------------------------------------*/
    }
    /*
     * Strings to store the results
     */
    std::string s1, s2, s3, s4, ft_s1, ft_s2, ft_s3, ft_s4;
    std::string sit1, sit2, sit3, ft_sit1, ft_sit2, ft_sit3; // strings to store the result by iterators
    /*
     * Var to store the size and the capacity
     */
    size_t z1, z2, z3, z4, ft_z1, ft_z2, ft_z3, ft_z4;
    size_t c1, c2, c3, c4, ft_c1, ft_c2, ft_c3, ft_c4;
    /*
     * iterators to check the iterator validity
     *  it : iterator, eit : iterator to the end
     */
    std::vector<std::string>::iterator valid_it, valid_eit;
    ft::vector<std::string>::iterator ft_valid_it, ft_valid_eit;
    /*
     * test with n greater than vector capacity
     */
    /*------------------ std::vectors ---------------------*/
    std::vector<std::string> v1(10, "string2");
    v1.resize(1e6, "hello");
    /*------------------ ft::vectors ---------------------*/
    ft::vector<std::string> ft_v1(10, "string2");
    ft_v1.resize(1e6, "hello");

    z1 = v1.size();
    ft_z1 = ft_v1.size();
    c1 = v1.capacity();
    ft_c1 = ft_v1.capacity();
    for (size_t i = 0; i < v1.size(); ++i)
        s1 += v1[i];

    for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
        ft_s1 += *it;
    /*----------------------------------------------------*/
    /*
     *	test with n lesser than capacity and greater than size
     */
    /*------------------ std::vectors ---------------------*/
    v1.resize(20);
    valid_it = v1.begin();
    valid_eit = v1.end();
    v1.resize(1e5);
    /*------------------ ft::vectors ---------------------*/
    ft_v1.resize(20);
    ft_valid_it = ft_v1.begin();
    ft_valid_eit = ft_v1.end();
		std::cout << "***************************" << std::endl;
    ft_v1.resize(1e5);

    z2 = v1.size();
    ft_z2 = ft_v1.size();
    c2 = v1.capacity();
    ft_c2 = ft_v1.capacity();
    for (size_t i = 0; i < v1.size(); ++i)
        s2 += v1[i];

    for (; valid_it != valid_eit; ++valid_it)
        sit1 += *valid_it;

    for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
        ft_s2 += *it;

    for (; ft_valid_it != ft_valid_eit; ++ft_valid_it)
        ft_sit1 += *ft_valid_it;
    /*----------------------------------------------------*/
    /*
     * test with n lesser than capacity and lesser an size
     */
    /*------------------ std::vectors ---------------------*/
    valid_it = v1.begin();
    v1.resize(50);
    /*------------------ ft::vectors ---------------------*/
    ft_valid_it = ft_v1.begin();
    ft_v1.resize(50);

    z3 = v1.size();
    ft_z3 = ft_v1.size();
    c3 = v1.capacity();
    ft_c3 = ft_v1.capacity();
    for (size_t i = 0; i < v1.size(); ++i)
        s3 += v1[i];

    for (; valid_it != v1.end(); ++valid_it)
        sit2 += *valid_it;

    for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
        ft_s3 += *it;

    for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
        ft_sit2 += *ft_valid_it;
    /*----------------------------------------------------*/
    /*
     * test with n = 0
     */
    /*------------------ std::vectors ---------------------*/
    valid_it = v1.begin();
    v1.resize(0, "string4");
    /*------------------ ft::vectors ---------------------*/
    ft_valid_it = ft_v1.begin();
    ft_v1.resize(0, "string4");

    z4 = v1.size();
    ft_z4 = ft_v1.size();
    c4 = v1.capacity();
    ft_c4 = ft_v1.capacity();
    for (size_t i = 0; i < v1.size(); ++i)
        s4 += v1[i];

    for (; valid_it != v1.end(); ++valid_it)
        sit3 += *valid_it;

    for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
        ft_s4 += *it;

    for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
        ft_sit3 += *ft_valid_it;
    /*----------------------------------------------------*/
    }
