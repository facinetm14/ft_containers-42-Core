#define RED "\033[31;1m"
#define GREEN "\033[32;1m"
#define DEFAULT "\033[0m"

#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> my_vector(5);
	std::cout << my_vector.size() << std::endl;
    return (0);
}
