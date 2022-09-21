#include "../include/RBtree.hpp"
#include "../include/map.hpp"

#define NAMESPACE ft

using namespace NAMESPACE;

template <class Key, class T>
void print(map<Key, T> &lst)
{
    for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}

int main()
{
    ft::pair<int, std::string> my_pair(8, "salut");
    ft::map<int, std::string> test;
    ft::map<int, std::string>::iterator it;

    test.insert(my_pair);
    test.insert(ft::pair<int, std::string>(-4, "bar"));
    test.insert(ft::pair<int, std::string>(2, "machin"));
    test.insert(ft::pair<int, std::string>(3, "foo"));
    test.insert(ft::pair<int, std::string>(746, "Marcel"));
    test.insert(ft::pair<int, std::string>(1, "truc"));
    it = test.begin();
    std::cout << '\n';
    while (it != test.end())
    {
        // cout << "start of while\n";
        std::cout << it->first << ", " << it->second << '\n';
        it++;
        // 		cout << "iterator incremented\n";

        // #ifndef STD
        // 		cout << it.getPointer() << '\n';
        // 		cout << test.end().getPointer() << '\n';
        // #endif
    }
    std::cout << "End of display loop\n";
}
