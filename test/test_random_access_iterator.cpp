/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_random_access_iterator.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:32:41 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/04 21:08:31 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/random_access_iterator.hpp"
#include "../header.hpp"
#include <vector>

// for testing it-> 
typedef struct s_full_name {
			std::string f_name;
			std::string l_name;
}					full_name;

int main() 
{
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(6);
	numbers.push_back(3);
	numbers.push_back(2);
	std::vector<int>::iterator it(numbers.begin());
	ft::random_access_iterator<std::vector<int> > it2(&numbers[0]);
	//--------------testing it.base() ---------------------
	test_head("base()");
	assert(*(it.base()), *(it2.base()));
	test_foot();

	//-------------- testing pre-incrementation ---------------
	test_head("pre-incrementation");
	while(it != numbers.end())
	{
		assert(*it, *it2);
		it++;
		it2++;
	}
	test_foot();

	//-----------------testing pre-decrementation----------------
	test_head("pre-decrementation");*
	--it; --it2;
	while(it >= numbers.begin())
	{
		assert(*it, *it2);
		it--;
		it2--;
	}
	test_foot();

	//-----------------testing post-incrementation----------------
	test_head("post-incrementation");
	++it; ++it2;
	while (it != numbers.end())
	{
		assert(*it, *it2);
		++it;
		++it2;
	}
	test_foot();

	//-----------------testing post-decrementation----------------
	test_head("post-decrementation");
	--it; --it2;
	while (it >= numbers.begin())
	{
		assert(*it, *it2);
		--it;
		--it2;
	}
	test_foot();
	
	//-----------------testing operator += ----------------
	test_head("operator +=");
	++it; ++it2;
	while (it != numbers.end())
	{
		assert(*it, *it2);
		it += 1;
		it2 += 1;
	}
	test_foot();
	
	//-----------------testing operator -= -----------------
	--it; --it2;
	test_head("operator -=");
	while (it >= numbers.begin())
	{
		assert(*it, *it2);
		--it;
		--it2;
	}
	test_foot();
	
	//-----------------testing operator -> ------------------
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
		ft::random_access_iterator<std::vector<full_name> > it2(&students[0]);
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
	test_foot();
	
	/*-----------------testing operator comparaison ----------------*/
	{
		std::vector<int> v1;
		v1.push_back(2);
		v1.push_back(12);
		v1.push_back(21);
		v1.push_back(123);
		v1.push_back(9);
		std::vector<int>::iterator it1_std = v1.begin();
		std::vector<int>::iterator it2_std = v1.begin() + 2;
		ft::random_access_iterator<std::vector<int> > it1_ft(&v1[0]);
		ft::random_access_iterator<std::vector<int> > it2_ft(&v1[2]);
		test_head("operator comparaison it + 0 and it + 2 ");
		assert(((it1_std == it2_std) ? 1 : 0), ((it1_ft == it2_ft) ? 1 : 0));
		assert(((it1_std <= it2_std) ? 1 : 0), ((it1_ft <= it2_ft) ? 1 : 0));
		assert(((it1_std >= it2_std) ? 1 : 0), ((it1_ft >= it2_ft) ? 1 : 0));
		assert(((it1_std > it2_std) ? 1 : 0), ((it1_ft > it2_ft) ? 1 : 0));
		assert(((it1_std < it2_std) ? 1 : 0), ((it1_ft < it2_ft) ? 1 : 0));
		test_foot();
	
		test_head("operator +");
		assert((it2_std - it1_std), (it2_ft- it1_ft));
		assert(*(it1_std + 2), *(it1_ft + 2));
		assert(*(it2_std - 2), *(it2_ft - 2));
		assert(*(2 + it2_std), *(2 + it2_ft));
		test_foot();
	
		const std::vector<int>::iterator const_it1_std = it1_std;
		const std::vector<int>::iterator const_it2_std = it2_std;
		const ft::random_access_iterator<std::vector<int> > const_it1_ft = it1_ft;
		const ft::random_access_iterator<std::vector<int> > const_it2_ft = it2_ft;
		test_head("operator comparaison it + 0 and it + 2 for const");
		assert(((const_it1_std == const_it2_std) ? 1 : 0), ((const_it1_ft == const_it2_ft) ? 1 : 0));
		assert((const_it2_std - const_it1_std), (const_it2_ft - const_it1_ft));
		test_foot();
	
	}
	return (0);
}