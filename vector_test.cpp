
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

// int     main()
// {
//     {
//         std::vector<int>    vect;
//         for(int i = 1; i < 11; i++) vect.push_back(i);
//         std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

//         vect.insert(vect.end(), 12, 22);
//         std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
//         for(std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++) std::cout << "*it: " << *it << std::endl;
//     }
//     std::cout << "-----------------------------------" << std::endl;
//     {
//         ft::vector<int>    vect;
//         for(int i = 1; i < 11; i++) vect.push_back(i);
//         std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;

//         vect.insert(vect.end(), 12, 22);
//         std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
//         for(ft::vector<int>::iterator it = vect.begin(); it != vect.end(); it++) std::cout << "*it: " << *it << std::endl;
//     }
//     return (0);
// }

// int     main()
// {
//     {
//         std::vector<int>    vect;
//         std::vector<int>    vect0(20, 50);

//         for (int i = 1; i < 11; i++)    vect.push_back(i);
//         std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
//         vect.assign(vect0.begin(), vect0.begin() + 2);
//         std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
//         for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)  std::cout << "*it: " << *it << std::endl;
//     }

//     std::cout << "---------------------" << std::endl;
//     {
//         ft::vector<int>    vect;
//         ft::vector<int>    vect0(20, 50);

//         for (int i = 1; i < 11; i++)    vect.push_back(i);
//         std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
//         vect.assign(vect0.begin(), vect0.begin() + 2);
//         std::cout << "Size: " << vect.size() << " Capacity: " << vect.capacity() << std::endl;
//         for (ft::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)  std::cout << "*it: " << *it << std::endl;
//     }

//     return (0);
// }

// int     main()
// {
//     {
//         std::vector<std::string>    vect;

//         std::vector<std::string>::iterator it =  vect.insert(vect.begin(), "22");
//         std::cout << *vect.begin() << std::endl;
//         std::cout << *it << std::endl;
//     }
//     std::cout << "----------------------" << std::endl;
//     {
//         ft::vector<std::string>    vect;

//         ft::vector<std::string>::iterator it =  vect.insert(vect.begin(), "22");
//         std::cout << *vect.begin() << std::endl;
//         std::cout << *it << std::endl;
//     }
//     return (0);
// }

// int     main()
// {
//     {
//         std::vector<int> a;
//         a.push_back(5);
//        // std::cout << " my BEFOR size org ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
//        a.push_back(9);
//        //std::cout << " my BEFOR size org ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
//        a.push_back(8);
//         a.push_back(1);
//        //std::cout << " my BEFOR size org ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
//         a.push_back(7);
//         // a.push_back(10);
//         // a.push_back(90);
//         // a.reserve(a.size() + 1);
//         // a.reserve(5);
//         std::cout << " my v BEFOR size  ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
//         //std::cout << " BEFOR size my v ==>  " << a.size() << "    " << " BEFOR capasity my v ==> " << a.capacity() << std::endl;
//         std::vector<int>::iterator it =   a.begin();
//         std::vector<int>::iterator  rt =   a.erase(it  + 1, a.end() - 2);
//         std::cout << "test return ==> " <<  *rt  << std::endl;
//         std::cout << " AFTER size my v  ==>  " << a.size() << "    " << " AFTER capasity my v==> " << a.capacity() << std::endl;
//         for (it = a.begin(); it != a.end(); it++)
//         {
//           std::cout << "element my v ==> " << *it << std::endl;
//         }
//          std::cout << "test return ==> " <<  *rt  << std::endl;
//     }
//     std::cout << "**********************************" << std::endl;
//     {
//         ft::vector<int> a;
//         a.push_back(5);
//        // std::cout << " my BEFOR size org ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
//        a.push_back(9);
//        //std::cout << " my BEFOR size org ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
//        a.push_back(8);
//         a.push_back(1);
//        //std::cout << " my BEFOR size org ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
//         a.push_back(7);
//         // a.push_back(10);
//         // a.push_back(90);
//         // a.reserve(a.size() + 1);
//         // a.reserve(5);
//         std::cout << " my v BEFOR size  ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
//         //std::cout << " BEFOR size my v ==>  " << a.size() << "    " << " BEFOR capasity my v ==> " << a.capacity() << std::endl;
//         ft::vector<int>::iterator it =   a.begin();
//         ft::vector<int>::iterator  rt =   a.erase(it  + 1, a.end() - 2);
//         std::cout << "test return ==> " <<  *rt  << std::endl;
//         std::cout << " AFTER size my v  ==>  " << a.size() << "    " << " AFTER capasity my v==> " << a.capacity() << std::endl;
//         for (it = a.begin(); it != a.end(); it++)
//         {
//           std::cout << "element my v ==> " << *it << std::endl;
//         }
//          std::cout << "test return ==> " <<  *rt  << std::endl;
//     }
//     return (0);
// }

// int   main()
// {
//   {
//     std::vector<int>    vect;
//     for (int i = 1; i < 101; i++)  vect.push_back(i);

//     vect.insert(vect.begin() + 20, 100, 0);
//     for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
//     {
//       std::cout << "Vect " << it - vect.begin() << " : " << *it << std::endl;
//     }
//   }
//   std::cout << "**********************************************************" << std::endl;
//   {
//     ft::vector<int>    vect;
//     for (int i = 1; i < 101; i++)  vect.push_back(i);

//     vect.insert(vect.begin() + 20, 100, 0);
//     for (ft::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
//     {
//       std::cout << "Vect " << it - vect.begin() << " : " << *it << std::endl;
//     }
//   }
//   return (0);
// }

int     main()
{
    {
        std::vector<std::string> v1(70, "hello");
        std::vector<std::string> v(20, "string");
        // ft::vector<std::string> ft_v(20, "string");
        ft::vector<std::string>::iterator valid_it;

        v.reserve(100);
        // ft_v.reserve(100);
        valid_it = ft_v.begin();
        v.insert(v.begin() + 15, v1.begin(), v1.end());
        ft_v.insert(ft_v.begin() + 15, v1.begin(), v1.end());

        str.clear();
        ft_str.clear();
        s = v.size();
        ft_s = ft_v.size();
        c = v.capacity();
        ft_c = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            str += v[i];
        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_str += ft_v[i];
            // std::cout << "Sys: " << str.length() << std::endl;
            // std::cout << "Usr: " << ft_str.length() << std::endl;
            std::cout << "DBG CONDITION02: " << (str == ft_str) << (s == ft_s) << (c == ft_c) << (&(*valid_it) == &(*ft_v.begin())) << std::endl;
        cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*ft_v.begin())));
    }
    std::cout << "****************************************" << std::endl;
    {

    }
    return (0);
}