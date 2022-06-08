
#include <iostream>
#include <vector>
#include "../include/vector.hpp"
#include "../include/iterator.hpp"
#include "../include/ft_enable_if.hpp"
#include "../include/reverse_iterator.hpp"
#include "../include/random_access_iterator.hpp"

int main(void)
{

	{
		ft::vector<int> vec2(3, 100);
		std::cout << "capacity = " << vec2.capacity() << std::endl;
			for (ft::vector<int>::iterator it4 = vec2.begin(); it4 != vec2.end(); it4++)
			std::cout << "before, ft = " << *it4 << std::endl;
		std::cout << "add 4 two times " << std::endl;
		vec2.insert(vec2.end(), 100, 4);
		for (ft::vector<int>::iterator it5 = vec2.begin(); it5 != vec2.end(); it5++)
			std::cout << "after, ft = " << *it5 << std::endl;
	}
	{
		std::vector<int> vec2(3, 100);
	for (std::vector<int>::iterator it4 = vec2.begin(); it4 != vec2.end(); it4++)
			std::cout << "before, vector = " << *it4 << std::endl;
		std::cout << "add 4 two times " << std::endl;
		vec2.insert(vec2.end(), 100, 4);
		for (std::vector<int>::iterator it5 = vec2.begin(); it5 != vec2.end(); it5++)
			std::cout << "after, vector = " << *it5 << std::endl;
	}
}
