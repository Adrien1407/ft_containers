
#include <iostream>
#include <vector>
#include "../include/vector.hpp"
#include "../include/iterator.hpp"
#include "../include/ft_enable_if.hpp"
#include "../include/reverse_iterator.hpp"
#include "../include/random_access_iterator.hpp"



int main()
{	//INSERT
ft::vector<int> test(3,3);
	std::cout << "\nINSERT\n";
	ft::vector<ft::vector<int> >	insert_in_me;
	// for (int i = 0; i < 15; i++)
	// {
	// 	ft::vector<int>	j(2, i);
	// 	insert_in_me.push_back(j);
	// }
	// for (size_t i = 0; i < insert_in_me.size(); i++)
	// {
	// 	for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
	// 		std::cout << insert_in_me.at(i).at(j) << ' ';
	// 	std::cout << '\n';
	// }

	ft::vector<ft::vector<int> >::iterator	tmp;
	test.assign(23, 19);
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, test);

}