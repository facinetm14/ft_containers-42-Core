/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_iterator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:02:26 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/05 00:02:26 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.hpp"
#include "../vector/reverse_iterator.hpp"
#include <vector>

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

    //-----------------test constructors------------------
	std::reverse_iterator<std::vector<int>::iterator> it_std(numbers.end());
	std::reverse_iterator<std::vector<int>::iterator> end_std(numbers.begin());
	ft::reverse_iterator<std::vector<int> > it_ft(&numbers[4]);
    test_head("pre-incrementation");
	while(it_std != end_std)
	{
		assert(*it_std, *it_ft);
		it_std++;
        it_ft++;
	}
	test_foot();
}