/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iteratorVector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:32:41 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/03 02:36:06 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/IteratorVector.hpp"
#include "../header.hpp"
#include <vector>

/* for testing it-> */
typedef struct s_full_name {
			std::string f_name;
			std::string l_name;
}					full_name;

void	test_head(std::string to_check)
{
	std::cout << "------------------------------------------------------------------------------------------------------------- \n";
	std::cout << "           Testing " << to_check << "                    \n";
	std::cout << "------------------------------------------------------------------------------------------------------------- \n";
}

void	test_foot(void)
{
	std::cout << "______________________________________________________________________________________________________________\n";
}

template<typename T>
void	assert(T const & expected, T const & output)
{
	std::cout << " " << std::setw(30) <<"ft::IteratorVector<T> " << std::setw(10) << expected << " std::vector<T> " << std::setw(10) << output << std::setw(10) << "  ";
	if (expected == output)
		std::cout << GREEN << "OK\n" << DEFAULT;
	else
		std::cout << RED << "KO\n" << DEFAULT;	
}

int main() 
{
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(6);
	numbers.push_back(3);
	numbers.push_back(2);
	std::vector<int>::iterator it(numbers.begin());
	ft::IteratorVector<std::vector<int> > it2(&numbers[0]);
	/*--------------testing it.base() --------------*/
	test_head("base()");
	assert(*(it.base()), *(it2.base()));
	test_foot();
	/*-------------- testing pre-incrementation --------------*/
	test_head("pre-incrementation");
	while(it != numbers.end())
	{
		assert(*it, *it2);
		it++;
		it2++;
	}
	test_foot();
	/*-----------------testing pre-decrementation----------------*/
	test_head("pre-decrementation");*
	--it; --it2;
	while(it >= numbers.begin())
	{
		assert(*it, *it2);
		it--;
		it2--;
	}
	test_foot();
	/*-----------------testing post-incrementation----------------*/
	test_head("post-incrementation");
	++it; ++it2;
	while (it != numbers.end())
	{
		assert(*it, *it2);
		++it;
		++it2;
	}
	test_foot();
	/*-----------------testing post-decrementation----------------*/
	test_head("post-decrementation");
	--it; --it2;
	while (it >= numbers.begin())
	{
		assert(*it, *it2);
		--it;
		--it2;
	}
	test_foot();
	/*-----------------testing operator += ----------------*/
	test_head("operator +=");
	++it; ++it2;
	while (it != numbers.end())
	{
		assert(*it, *it2);
		it += 1;
		it2 += 1;
	}
	test_foot();
	/*-----------------testing operator -= ----------------*/
	--it; --it2;
	test_head("operator -=");
	while (it >= numbers.begin())
	{
		assert(*it, *it2);
		--it;
		--it2;
	}
	test_foot();
	/*-----------------testing operator -> ----------------*/
	{
		test_head("operator ->");
		std::vector<full_name> students;
		full_name fakouyat;
		fakouyat.f_name = "Facinet";
		fakouyat.l_name = "KOUYATE";
		students.push_back(fakouyat);
		full_name bangus;
		bangus.f_name = "Alseny";
		bangus.l_name = "BANGOURA";
		students.push_back(bangus);
		full_name soul;
		soul.f_name = "Souleymane";
		soul.l_name = "DIALLO";
		students.push_back(soul);
		std::vector<full_name>::iterator it = students.begin();
		ft::IteratorVector<std::vector<full_name> > it2(&students[0]);
		while (it != students.end())
		{
			assert(it->f_name, it2->f_name);
			assert(it->l_name, it2->l_name);
			it++;
			it2++;
		}
		test_foot();
	}
	/*-----------------testing dereference operator *it ----------------*/
	it += 2; ++it2;
	test_head("operator *it = n");
	*it = -100;
	*it2 = -100;
	assert(*it, *it2);
	*it += 200;
	*it2 += 200;
	assert(*it, *it2);
	*it -= 20;
	*it2 -= 20;
	assert(*it, *it2);
	*it++;
	*it2++;
	assert(*it, *it2);
	// *it--;
	// *it2--;
	// assert(*it, *it2);
	test_foot();
	return (0);
}