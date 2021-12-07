/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:20 by abelarif          #+#    #+#             */
/*   Updated: 2021/12/07 11:53:46 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

namespace ft
{
    template < typename T>
    class test
    {
    private:
        /* data */
    public:
        /*
        ** Constructor00 (std::string)
        */
        // template <typename T>
        test(T t0, T t1,
        typedef std::enable_if_t< !std::is_integral<T>::value,
        std::string = std::string()>)
        {
            std::cout << "<std::string>: Constructor00 Called" << std::endl;
            std::cout << "T0(string) : " << t0 << std::endl;
            std::cout << "T1(string) : " << t1 << std::endl;
        }

        /*
        ** Constructor01 (Integral_type)
        */
        test(T t0, T t1)
        {
            std::cout << "<Integral_type>: Constructor00 Called" << std::endl;
            std::cout << "T0: " << t0 << std::endl;
            std::cout << "T1: " << t1 << std::endl;
        }

        ~test(){ std::cout << "Destructor00  Called" << std::endl;}
    };
};

#endif