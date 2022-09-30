#include "../include/RBtree.hpp"
#include "../include/map.hpp"
#include "../include/vector.hpp"
#include "../include/stack.hpp"
#include <map>
#include <vector>
#include <stack>

#define _NC "\033[0;0m"
#define _RED "\033[0;31m"
#define _GREEN "\033[0;32m"
#define _YELLOW "\033[0;33m"
#define _BLUE "\033[0;34m"
#define _PURPLE "\033[0;95m"
#define _CYAN "\033[0;36m"
#define _WHITE "\033[0;37m"

template <class Key, class T>
void print_map(ft::map<Key, T> &lst)
{
  // int count = 0;
  if (!lst.empty())
  {
    std::cout << _PURPLE << "Print: \n";
    for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
    {
      std::cout << it->first << " ~> " << it->second << '\n';
      // count++;
      // if (count == 3)
      // break;
    }
    std::cout << _NC << std::endl;
  }
  else
    std::cout << _RED << "This map is empty ... :(" << _NC << std::endl;
}
template <class Key, class T>
void print_map_std(std::map<Key, T> &lst)
{
  // int count = 0;
  if (!lst.empty())
  {
    std::cout << _PURPLE << "Print: \n";
    for (typename std::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
    {
      std::cout << it->first << " ~> " << it->second << '\n';
      // count++;
      // if (count == 3)
      // break;
    }
    std::cout << _NC << std::endl;
  }
  else
    std::cout << _RED << "This map is empty ... :(" << _NC << std::endl;
}
template <class T>
void	print(std::vector<std::vector<T> >& lst)
{
	for (std::vector<vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (std::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(ft::vector<T>& lst)
{
	for (ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}
template <class T>
void  vector_test_iterators(std::vector<T>)
{

};

int main ()
{
  //different types of std::vector<> 
  std::vector<int> vec_std_int;
  std::vector<char> vec_std_char;
  std::vector<std::string> vec_std_string;
  std::vector<std::vector<int> > vec_std_vec_int;
  std::vector<std::vector<std::string> > vec_std_vec_str;

  //different types of ft::vector<> 
  ft::vector<int> vec_ft_int;
  ft::vector<char> vec_ft_char;
  ft::vector<std::string> vec_ft_string;
  ft::vector<ft::vector<int> > vec_ft_vec_int;
  ft::vector<ft::vector<std::string> > vec_ft_vec_str;



  vector_std_test_iterators();
  vector_ft_test_iterators();
  
  return 0;

}

















