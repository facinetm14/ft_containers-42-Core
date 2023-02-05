/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:52:37 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/05 17:01:33 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP
# include <iostream>
# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define DEFAULT "\033[0m"
# include <iomanip>

void	test_head(std::string to_check)
{
	std::cout << "------------------------------------------------------------------------------------------------------------- \n";
	std::cout << "           Testing " << to_check << "                    \n";
	std::cout << "------------------------------------------------------------------------------------------------------------- \n";
}

void	test_foot(void)
{
	std::cout << "______________________________________________________________________________________________________________\n\n";
}

template<typename T>
void	assert(T const & expected, T const & output)
{
	std::cout << " " << std::setw(30) <<"std::it<T> " << std::setw(10) << expected << "    ft::it<T> " << std::setw(10) << output << std::setw(10) << "  ";
	if (expected == output)
		std::cout << GREEN << "OK\n" << DEFAULT;
	else
		std::cout << RED << "KO\n" << DEFAULT;	
}

#endif