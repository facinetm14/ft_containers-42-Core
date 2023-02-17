#include "test/header.hpp"
#include <string>


int main(void)
{
    TestVector<int> test1(5, 0, 39, 8, 31, 3, 4);
    test1.run();
    TestVector<std::string> test2(3, "", "Bonjour", "Bien", "COOL");
    test2.run();
    return (0);
}
