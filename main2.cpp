#include "test/header.hpp"
#include <string>


int main(void)
{
    //TestVector<int> test1(5, 0, 39, 8, 31, 3, 4);
    //test1.run();
    //test1.insert2(100);
    TestVector<std::string> test2(3, "", "Bonjour", "Bien", "COOL");
    std::vector<std::string> args;
    args.push_back("42 WOB");
    args.push_back("42 BERLIN");
    args.push_back("ANDROID");
    //std::cout << "CAP" << args.capacity();
    //return (0);
    //test2.run(args);
    test2.insert("KOUYATE");
    return (0);
}
