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
	ft::reverse_iterator<ft::random_access_iterator<std::vector<int> > > it_ft(&numbers[4]);
    test_head("pre-incrementation");
	while(it_std != end_std)
	{
		assert(*it_std, *it_ft);
		it_std++;
        it_ft++;
	}
	test_foot();

    // ---------------test pre-decrementation---------------------------------
    {
        std::reverse_iterator<std::vector<int>::iterator> it_std(numbers.end());
	    std::reverse_iterator<std::vector<int>::iterator> end_std(numbers.begin() + 1);
        ft::reverse_iterator<ft::random_access_iterator<std::vector<int> > > end_ft(&numbers[0]);
        test_head("pre-decrementation");
        while (end_std != it_std)
        {
            assert(*end_std, *end_ft);
            end_std--;
            end_ft--;
        }
        test_foot();
    }

    //-------------- test numeric operators -------------------------------------
    test_head("operators it +/- n");
    {
        std::reverse_iterator<std::vector<int>::iterator> it_std(numbers.end());
        ft::reverse_iterator<ft::random_access_iterator<std::vector<int> > > it_ft(&numbers[4]);
        assert(*(it_std + 2), *(it_ft + 2));
        it_std += 2; it_ft += 2;
        assert(*it_std, *it_ft);
        assert(*(it_std - 2), *(it_ft - 2));
        it_std -= 2; it_ft -= 2;
        assert(*it_std, *it_ft);
    }
    test_foot();

    //---------------- test operator [] -----------------------
    {
		test_head("operator []");
        std::reverse_iterator<std::vector<int>::iterator> it_std(numbers.end());
        ft::reverse_iterator<ft::random_access_iterator<std::vector<int> > > it_ft(&numbers[4]);
		assert(it_std[0], it_ft[0]);
		test_foot();
    }

	{
		std::reverse_iterator<std::vector<int>::iterator> it1_std(numbers.end());
		std::reverse_iterator<std::vector<int>::iterator> it2_std(numbers.end() + 2);
 		ft::reverse_iterator<ft::random_access_iterator<std::vector<int> > > it1_ft(&numbers[4]);
 		ft::reverse_iterator<ft::random_access_iterator<std::vector<int> > > it2_ft(&numbers[4] + 2);
		test_head("operator comparaison it + 0 and it + 2 ");
		assert(((it1_std == it2_std) ? 1 : 0), ((it1_ft == it2_ft) ? 1 : 0));
		assert(((it1_std != it1_std) ? 1 : 0), ((it1_ft != it1_ft) ? 1 : 0));
		assert(((it1_std <= it2_std) ? 1 : 0), ((it1_ft <= it2_ft) ? 1 : 0));
		assert(((it1_std >= it2_std) ? 1 : 0), ((it1_ft >= it2_ft) ? 1 : 0));
		assert(((it1_std > it2_std) ? 1 : 0), ((it1_ft > it2_ft) ? 1 : 0));
		assert(((it1_std < it2_std) ? 1 : 0), ((it1_ft < it2_ft) ? 1 : 0));
		test_foot();
	}

    // --------------- test operator -> ------------------------
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
		std::reverse_iterator<std::vector<full_name>::iterator> it_std(students.end());
	    std::reverse_iterator<std::vector<full_name>::iterator> end_std(students.begin());
	    ft::reverse_iterator<ft::random_access_iterator<std::vector<full_name> > > it_ft(&students[2]);
		while (it_std != end_std)
		{
			assert(it_std->f_name, it_ft->f_name);
			assert(it_std->l_name, it_ft->l_name);
			it_std++;
			it_ft++;
		}
		test_foot();

		//------------------testing operator +/- n ---------------------------
		{
			std::reverse_iterator<std::vector<int>::iterator> it1_std(numbers.end());
			std::reverse_iterator<std::vector<int>::iterator> it2_std(numbers.end() + 2);
			ft::reverse_iterator<ft::random_access_iterator<std::vector<int> > > it1_ft(&numbers[4]);
			ft::reverse_iterator<ft::random_access_iterator<std::vector<int> > > it2_ft(&numbers[4] + 2);
			test_head("operator + n and it - it2");
			assert((it2_std - it1_std), (it2_ft- it1_ft));
			assert(*(it1_std + 2), *(it1_ft + 2));
			assert(*(it2_std - 2), *(it2_ft - 2));
			assert(*(2 + it2_std), *(2 + it2_ft));
			test_foot();
		}
	}


}


