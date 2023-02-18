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
            for(int i = 0; i < nb; i++)
            {
                curr = va_arg(args, U);
                v1[i] = curr;
                v2[i] = curr;
            }
            va_end(args);
        }

        ~TestVector() { }
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

        /*---------------------------capacity----------------------*/
        void    size_and_capacity() 
        {
            test_head("size()");
            assert(v1.size(), v2.size());
            test_head("capacity()");
            assert(v1.capacity(), v2.capacity());
        }
        /*---------------------------------------------------------*/
        
        /*----------------Modifiers--------------------------------*/
        // push_back
        void push_back() 
        {
            test_head("********push_back()******");
            v1.push_back(*(this->v1.begin()));
            v2.push_back(*(this->v2.begin()));
            this->size_and_capacity();
            this->iteration();
            v1.push_back(*(this->v1.end() - 1)); 
            v2.push_back(*(this->v2.end() - 1));
            this->iteration();
            this->size_and_capacity();
        }

        // pop_back()
        void    pop_back()
        {
            test_head("***pop_back()***");
            std::cout << "BEFORE\n";
            this->iteration();
            v1.pop_back();
            v2.pop_back();
            std::cout << "AFTER\n";
            this->iteration();
            this->size_and_capacity();
            std::cout << "BEFORE\n";
            this->iteration();
            this->v1.pop_back();
            this->v2.pop_back();
            std::cout << "AFTER\n";
            this->iteration();
            this->size_and_capacity();
        }
    
        template <typename V>
        void    insert(V val)
        {
            std::cout << "BEFORE\n";
            this->iteration();
            this->size_and_capacity();
            std::cout << "AFTER\n";
            v1.insert(v1.begin(), val);
            v2.insert(v2.begin(), val);
            this->iteration();
            this->size_and_capacity();
            // v1.insert(v1.end(), val);
            // v2.insert(v2.end(), val);
            this->iteration();
            this->size_and_capacity();
            // std::cout << "Test : " << *(v2.end() - (v2.size() / 2 - 1))  << "\n";
            // std::cout << "Test2 : " << *(v1.end() - (v1.size() / 2 - 1))  << "\n";
            // std::cout << "Test21 : " << (v2.end() - (v2.size() / 2 - 1)) - v2.begin() << "\n";
            // std::cout << "Test22 : " << (v1.end() - (v1.size() / 2 - 1)) -v1.begin()  << "\n";
            v1.insert(v1.begin() - (v1.size() / 2 - 1), val);
            v2.insert(v2.begin() - (v2.size() / 2 - 1), val);
            this->iteration();
        }
        template <typename V>
        void    insert2(V val)
        {
            std::cout << "BEFORE\n";
            this->iteration();
            this->size_and_capacity();
            std::cout << "AFTER\n";
            v1.insert(v1.begin(), 0, val);
            v2.insert(v2.begin(), 0, val);
            this->iteration();
            this->size_and_capacity();
            v1.insert(v1.end(), 3, val);
            v2.insert(v2.end(), 3, val);
            this->iteration();
            this->size_and_capacity();
            v1.insert(v1.end() - (v1.size() / 2), 8, val);
            v2.insert(v2.end() - (v2.size() / 2), 8, val);
            this->iteration();
            this->size_and_capacity();
        }

        template <typename InputIterator>
        void    insert3(InputIterator val)
        {
            std::cout << "BEFORE\n";
            this->iteration();
            this->size_and_capacity();
            std::cout << "AFTER\n";
            v1.insert(v1.begin(), val.begin(), val.end());
            v2.insert(v2.begin(), val.begin(), val.end());
            this->iteration();
            this->size_and_capacity();
            v1.insert(v1.end(), val.begin(), val.end());
            v2.insert(v2.end(), val.begin(), val.end());
            this->iteration();
            this->size_and_capacity();
            v1.insert(v1.end() - (v1.size() / 2), val.begin(), val.end());
            v2.insert(v2.end() - (v2.size() / 2), val.begin(), val.end());
            this->iteration();
            this->size_and_capacity();
        }

        /*---------------------------------------------------------*/

        // trigger tests
        template <typename ARGS>
        void    run(ARGS& val)
        {
            std::cout << "Test start...\n";
            this->constructor();
            this->iteration();
            this->push_back();
            this->pop_back();
            //this->insert2(val[1]);
            //this->insert3(val);
            std::cout << "***************************************************************************************************************\n\n";
        }

};

#endif