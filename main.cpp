
#include "vector.hpp"
#include <iostream>
#include <vector>
#include "iterator.hpp"
#include "ft_enable_if.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"


int main(void)
{
	ft::vector<int> vec(3, 100);
	std::vector<int> vec1(3, 100);
	ft::vector<int>::iterator it; 
	std::vector<int>::iterator it2; 

	it = vec.begin();
	it2 = vec1.begin();
	std::cout << *(it + 1) << std::endl; 
	std::cout << *(it2 + 1) << std::endl; 


}
