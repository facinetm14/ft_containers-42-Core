#ifndef TEST_VECTOR_HPP
# define TEST_VECTOR_HPP
# include "../vector/vector.hpp"
# include <cstdarg>
# include <vector>
# include <string>
# include "header.hpp"

template <typename T>
class TestVector {

    private:
        std::vector<T> v1;
        ft::vector<T>  v2;

    public:
        template<typename U>
        TestVector(int nb, U type, ...)
        {
            v1 = std::vector<T>(nb);
            v2 = ft::vector<T>(nb);
            std::va_list args;
            U curr;
            va_start(args, type);
            (void)type;

            for(int i = 0; i < nb; i++)
            {
                curr = va_arg(args, U);
                v1[i] = curr;
                v2[i] = curr;
            }
            va_end(args);
        }

        // construction size
        void constructor() 
        {
            test_head("construction size");
            assert(v1.size(), v2.size());
            test_head("range constructor");
            typename std::vector<T> v1_clone(v1.begin(), v1.end());
            typename ft::vector<T> v2_clone(v2.begin(), v2.end());
            typename std::vector<T>::iterator it1(v1_clone.begin());
            typename ft::vector<T>::iterator it(v2_clone.begin());
            while (it1 != v1_clone.end())
            {
                assert(*it, *it1);
                it++;
                it1++;
            }
            test_foot();
        }

        // iteration
        void    iteration()
        {
            typename std::vector<T>::reverse_iterator re_it(v1.rbegin());
            typename std::vector<T>::reverse_iterator re_end(v1.rend());
            typename ft::vector<T>::reverse_iterator re_it1(v2.rbegin());

            typename ft::vector<T>::iterator it1(v2.begin());
            typename std::vector<T>::iterator it(v1.begin());

            test_head("iteration std::vector vs ft::vector");
            while (it1 != v2.end())
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
            test_foot();
        }

        // trigger tests
        void    run()
        {
            std::cout << "Test start...\n";
            this->constructor();
            this->iteration();
            std::cout << "***************************************************************************************************************\n\n";
        }

};

#endif