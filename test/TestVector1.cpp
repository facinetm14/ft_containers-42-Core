/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:46:33 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/06 19:46:33 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <chrono>
#include "utils.hpp"
#include <vector>
#include "../vector/vector.hpp"

int     main()
{
    // ---------------- testing constructors & iterators ------------------------
    {
        test_head("constructors");
        {
            std::vector<int> v;
            ft::vector<int> v1;
            assert(v.size(), v1.size());
        }
        {
            auto start = std::chrono::steady_clock::now();
            std::vector<int> v(10000);
            auto end = std::chrono::steady_clock::now();
            auto std_benchmark = std::chrono::duration_cast<std::chrono::nanoseconds>\
                                (end - start).count();
            auto start1 = std::chrono::steady_clock::now();
            ft::vector<int> v1(10000);
            auto end1 = std::chrono::steady_clock::now();
            auto ft_benchmark = std::chrono::duration_cast<std::chrono::nanoseconds>\
                                (end1 - start1).count();
            assert(v.size(), v1.size());
            test_head("benchmark st vs ft [ms]");
            assert_performance(std_benchmark, ft_benchmark);
        }

        {
            std::vector<int> v(5);
            ft::vector<int> v1(5);

            ft::vector<int>::reverse_iterator re_it1(v1.rbegin());
            std::vector<int>::reverse_iterator re_it(v.rbegin());
            std::vector<int>::reverse_iterator re_end(v.rend());

            ft::vector<int>::iterator it1(v1.begin());
            std::vector<int>::iterator it(v.begin());

            v1[0] = 2,  v[0] = 2;
            v1[1] = 20; v[1] = 20;
            v1[2] = 52;  v[2] = 52;
            v1[3] = 8;  v[3] = 8;
            v1[4] = 10; v[4] = 10;
            
            // iteration
            test_head("iteration std::vector vs ft::vector");
            while (it1 != v1.end())
            {
                assert(*it, *it1);
                it++;
                it1++;
            }

            // reverse iteration
            test_head("reverse_iteration std::vector vs ft::vector");
            while (re_it != re_end)
            {
                assert(*re_it, *re_it1);
                re_it++;
                re_it1++;
            }

            // iteration benchmark
            auto start = std::chrono::steady_clock::now();
            std::vector<int>::iterator iter = v.begin();
            while (iter != v.end())
                iter++;
            auto end = std::chrono::steady_clock::now();
            auto std_benchmark = std::chrono::duration_cast<std::chrono::nanoseconds>\
                                (end - start).count();
            auto start1 = std::chrono::steady_clock::now();
            ft::vector<int>::iterator iter_ft = v1.begin();
            while (iter_ft != v1.end())
                iter_ft++;
            auto end1 = std::chrono::steady_clock::now();
            auto ft_benchmark = std::chrono::duration_cast<std::chrono::nanoseconds>\
                                (end1 - start1).count();
            test_head("benchmark st vs ft [ms]");
            assert_performance(std_benchmark, ft_benchmark);
            test_foot();

            //--------------------elements acces methods -----------------------------
            std::cout << "Elements access methods\n";
            test_head("front()");
            assert(v.front(), v1.front());
            test_head("back()");
            assert(v.back(), v1.back());
            test_head("at(n) n = 3, 1, -1");
            assert(v.at(3), v1.at(3));
            assert(v.at(1), v1.at(1));
            //assert(v.at(-1), v.at(-1));
            //assert(v.at(v.size()), v1.at(v1.size()));
            test_foot();

            //------------------testing capacity methods ----------------------------------------
            std::cout << "Capacity methods\n";
            test_head("!empty()");
            assert(!v.empty() ? 1 : 0 , !v1.empty() ? 1 : 0);
            test_head("max_size()");
            assert(v.max_size(), v1.max_size());
            test_head("resize()");
            v.resize(3);
            v1.resize(3);
            assert(v.size(), v1.size());
            assert(v.capacity(), v1.capacity());
            assert(v[0], v1[0]);
            assert(v[1], v1[1]);
            assert(v[2], v1[2]);
            v.resize(3);
            v1.resize(3);
            assert(v.size(), v1.size());
            assert(v.capacity(), v1.capacity());
            assert(v[0], v1[0]);
            assert(v[1], v1[1]);
            assert(v[2], v1[2]);
            v.resize(3);
            v1.resize(3);
            v.resize(4);
            v1.resize(4);
            assert(v.size(), v1.size());
            assert(v.capacity(), v1.capacity());
            assert(v[0], v1[0]);
            assert(v[1], v1[1]);
            assert(v[2], v1[2]);
            v.resize(5);
            v1.resize(5);
            assert(v.size(), v1.size());
            assert(v.capacity(), v1.capacity());
            assert(v[0], v1[0]);
            assert(v[1], v1[1]);
            assert(v[2], v1[2]);
            auto start_resize = std::chrono::steady_clock::now();
            v.resize(6);
            auto end_resize = std::chrono::steady_clock::now();
            auto time_std = std::chrono::duration_cast<std::chrono::nanoseconds>\
                            (end_resize - start_resize).count();
            auto start_resize_ft = std::chrono::steady_clock::now();
            v1.resize(6);
            auto end_resize_ft = std::chrono::steady_clock::now();
            auto time_ft = std::chrono::duration_cast<std::chrono::nanoseconds>\
                            (end_resize_ft - start_resize_ft).count();
            test_head("resize() performance");
            assert_performance(time_std, time_ft);
            test_foot();
            assert(v.size(), v1.size());
            assert(v.capacity(), v1.capacity());
            assert(v[0], v1[0]);
            assert(v[1], v1[1]);
            assert(v[2], v1[2]);
            test_head("reserve()");
            v.reserve(12);
            v1.reserve(12);
            assert(v.size(), v1.size());
            assert(v.capacity(), v1.capacity());
            assert(v[0], v1[0]);
            assert(v[1], v1[1]);
            assert(v[2], v1[2]);
            test_foot();
            //-----------------Testing modifiers methods----------------------
            test_head("assign");
            v.assign(2, 200);
            v1.assign(2, 200);
            assert(v[0], v1[0]);
            assert(v[1], v1[1]);
            assert(v[2], v1[2]);
            assert(v[3], v1[3]);
            assert(v[4], v1[4]);
        }
    }


    return (0);
}