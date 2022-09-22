#include "../include/RBtree.hpp"
#include "../include/map.hpp"
#include <map>
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

int main ()
{
  ft::map<char,int> mymap;
  
  std::map<char,int> mymap2;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  mymap2['x'] = 100;
  mymap2['y'] = 200;
  mymap2['z'] = 300;
  ft::map<char,int>::reverse_iterator rit;
   rit=mymap.rbegin();
   std::cout << rit->first << " => " << rit->second << '\n';

  std::map<char,int>::reverse_iterator rit2;
   rit2=mymap2.rbegin();
   
    std::cout << rit2->first << " => " << rit2->second << '\n';


	// for (ft::map<char,int>::const_reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); it++)
  //   std::cout << it->first << " => " << it->second << '\n';

	// ft::map<char, int>::const_reverse_iterator it = mymap.rbegin();
	// ft::map<char, int>::const_reverse_iterator ti = mymap.rend();

	// it++;
	// ++it;
	// it--;
	// --it;

	// ti--;
	// --ti;
	// ++ti;
	// ti++;

	// ti = it;

	// ft::map<char, int>::reverse_iterator end = mymap.rend();
	// while(it != end)
	// {
  //   	std::cout << it->first << " => " << it->second << '\n';
	// 	it++;
	// }


  return 0;
}
