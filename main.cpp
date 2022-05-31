
#include "vector.hpp"
#include <iostream>
#include <vector>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"


int main(void)
{
	ft::vector<int> vec(3, 100);
	std::vector<int> vec1(3, 100);
	ft::vector<int>::iterator it; 

	it = vec.begin();
	std::cout << *(it + 1) << std::endl; 


}
