
#include "vector.hpp"
#include <iostream>
#include <vector>
#include "iterator.hpp"
#include "ft_enable_if.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"


int main(void)
{
	std::vector<int> vec(3, 100);
	std::vector<int>::iterator it;
	it = vec.begin();
	std::cout << *(it + 1) << std::endl;
}
