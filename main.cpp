
#include "vector.hpp"
#include <iostream>
#include <vector>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"


int main(void)
{
    ft::vector<int> vec;
    ft::vector<int> vec1(vec);
    
    std::cout << sizeof(vec) << std::endl; 
    std::cout << sizeof(vec1) << std::endl; 


}