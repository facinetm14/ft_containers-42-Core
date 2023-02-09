/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:35:44 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/06 19:35:44 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include <iostream>
# include <iomanip>
# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define DEFAULT "\033[0m"

void	test_head(std::string to_check);
void	test_foot(void);

template<typename T>
void	assert(T const & expected, T const & output)
{
	std::cout << " " << std::setw(30) <<"std::" << std::setw(10) << expected << "    ft::" << std::setw(10) << output << std::setw(10) << "  ";
	if (expected == output)
		std::cout << GREEN << "OK\n" << DEFAULT;
	else
		std::cout << RED << "KO\n" << DEFAULT;	
}

template<typename T>
void	assert_performance(T const & expected, T const & output)
{
    std::cout << " " << std::setw(30) <<"std::" << std::setw(10) << expected << "    ft::" << std::setw(10) << output << std::setw(10) << "  ";
	if (expected < output * 20)
		std::cout << GREEN << "OK\n" << DEFAULT;
	else
		std::cout << RED << "KO\n" << DEFAULT;
}

#endif
