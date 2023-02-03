#define RED "\033[31;1m"
#define GREEN "\033[32;1m"
#define DEFAULT "\033[0m"

#include <iostream>
#include <vector>

typedef struct color_s 
{
    int r;
    int g;
    int b;

    } color;
int main(void)
{
    std::vector<color> my_vectorr;
    color one;

    one.b = 25;
    my_vectorr.push_back(one);
    std::cout << my_vectorr.begin()->b << std::endl;
    one.b = 2;
    my_vectorr.begin()->b = 10;
    std::cout << my_vectorr.begin()->b << std::endl;
	std::cout << my_vectorr.size() << std::endl;
    return (0);
}
