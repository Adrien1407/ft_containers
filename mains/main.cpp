
#include <iostream>
#include <vector>
#include "../include/vector.hpp"
#include "../include/iterator.hpp"
#include "../include/ft_enable_if.hpp"
#include "../include/reverse_iterator.hpp"
#include "../include/random_access_iterator.hpp"

// int main(void)
// {

// 	{
// 		ft::vector<int> vec2(3, 100);
// 		std::cout << "capacity = " << vec2.capacity() << std::endl;
// 			for (ft::vector<int>::iterator it4 = vec2.begin(); it4 != vec2.end(); it4++)
// 			std::cout << "before, ft = " << *it4 << std::endl;
// 		std::cout << "add 4 two times " << std::endl;
// 		vec2.insert(vec2.end(), 100, 4);
// 		for (ft::vector<int>::iterator it5 = vec2.begin(); it5 != vec2.end(); it5++)
// 			std::cout << "after, ft = " << *it5 << std::endl;
// 	}
// 	{
// 		std::vector<int> vec2(3, 100);
// 	for (std::vector<int>::iterator it4 = vec2.begin(); it4 != vec2.end(); it4++)
// 			std::cout << "before, vector = " << *it4 << std::endl;
// 		std::cout << "add 4 two times " << std::endl;
// 		vec2.insert(vec2.end(), 100, 4);
// 		for (std::vector<int>::iterator it5 = vec2.begin(); it5 != vec2.end(); it5++)
// 			std::cout << "after, vector = " << *it5 << std::endl;
// 	}
// }


// int main ()
// {
//   ft::vector<int> myvector (5);  // 5 default-constructed ints

//   int i=0;

//   ft::vector<int>::reverse_iterator rit = myvector.rbegin();
// std::cout << *rit << std::endl

//   for (; rit!= myvector.rend(); ++rit)
//     *rit = ++i;

//   std::cout << "myvector contains:";
//   for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }


int main ()
{
 {

 ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

 // myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
 // it = myvector.begin();

  // ft::vector<int> anothervector (2,400);
  // myvector.insert (it+2,anothervector.begin(),anothervector.end());

  // int myarray [] = { 501,502,503 };
  // myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
 } 
 {

 std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert(it , 200 );

 // myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
 // it = myvector.begin();

  // std::vector<int> anothervector (2,400);
  // myvector.insert (it+2,anothervector.begin(),anothervector.end());

  // int myarray [] = { 501,502,503 };
  // myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "mector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
 }
  return 0;
}
