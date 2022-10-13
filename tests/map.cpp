/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:55:48 by adlancel          #+#    #+#             */
/*   Updated: 2022/10/13 18:03:55 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef USE
#define USING "STD"
#include <map>
#else
#include "map.hpp"
#define USING "FT"
#endif
#include <iostream>
#include <string>
#include <iomanip>
#include <sys/time.h>
#include "./test.hpp"

template <class Key, class T>
void print_map(NAMESPACE::map<Key, T> &lst)
{
    if (!lst.empty())
    {
        for (typename NAMESPACE::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
            std::cout << it->first << " ~> " << it->second << '\n';
        std::cout << std::endl;
    }
    else
        std::cout << "This map is empty ... :(" << std::endl;
}
void map_constructor_test()
{
    std::cout << std::setw(30) << "MAP CONSTRUCTOR TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::map<int, char> mymap;
    std::cout << "empty constructor" << std::endl;
    print_map(mymap);
    char c = 'a';
    for (int i = 0; i < 5; i++)
        mymap.insert(NAMESPACE::make_pair(i, c++));
    print_map(mymap);
    std::cout << "copy constructor from first map" << std::endl;
    NAMESPACE::map<int, char> mymap2(mymap);
    print_map(mymap2);
    std::cout << "range constructor from second map" << std::endl;
    NAMESPACE::map<int, char> mymap3(mymap2.begin(), mymap2.end());
    print_map(mymap3);
    std::cout << "assignement constructor from second map" << std::endl;
    NAMESPACE::map<int, char> mymap4 = mymap2;
    print_map(mymap4);
    // while (std::cin.get() != '\n')
    // {
    // }
}

void map_iterators_test()
{
    std::cout << std::setw(30) << "MAP ITERATORS TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::map<int, char> mymap;
    char c = 'A';
    for (int i = 0; i < 26; i++)
        mymap.insert(NAMESPACE::make_pair(i, c++));
    NAMESPACE::map<int, char>::iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++)
        std::cout << (*it).first << ", " << (*it).second << std::endl;
    NAMESPACE::map<int, char>::iterator it2 = mymap.begin();
    NAMESPACE::map<int, char>::iterator ite = mymap.end();
    NAMESPACE::map<int, char>::reverse_iterator itr = mymap.rbegin();
    NAMESPACE::map<int, char>::reverse_iterator itre = mymap.rend();

    ite--;
    itre--;
    std::cout << "Begin = " << (*it2).first << ", " << (*it2).second << std::endl;
    std::cout << "end = " << (*ite).first << ", " << (*ite).second << std::endl;
    std::cout << "rbegin = " << (*itr).first << ", " << (*itr).second << std::endl;
    std::cout << "rend = " << (*itre).first << ", " << (*itre).second << std::endl;
    std::cout << std::endl;
    std::cout << "non const to const" << std::endl;
    NAMESPACE::map<int, char>::const_iterator it22 = it2;
    NAMESPACE::map<int, char>::const_iterator ite2 = ite;
    NAMESPACE::map<int, char>::const_reverse_iterator itrr = itr;
    NAMESPACE::map<int, char>::const_reverse_iterator itre2 = itre;

    std::cout << "const_begin = " << (*it22).first << ", " << (*it22).second << std::endl;
    std::cout << "const_end = " << (*ite2).first << ", " << (*ite2).second << std::endl;
    std::cout << "const_rbegin = " << (*itrr).first << ", " << (*itrr).second << std::endl;
    std::cout << "const_rend = " << (*itre2).first << ", " << (*itre2).second << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}

void map_access_op_test()
{
    std::cout << std::setw(30) << "MAP OPERATOR[] TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::map<int, char> mymap;
    char c = 'A';
    for (int i = 0; i < 26; i++)
        mymap.insert(NAMESPACE::make_pair(i, c++));
    print_map(mymap);
    std::cout << "we try to access and change value of mymap[1] (B)" << std::endl;
    mymap[1] = '&';
    print_map(mymap);
    // while (std::cin.get() != '\n')
    // {
    // }
}

void map_capacity_test()
{
    std::cout << std::setw(30) << "MAP SIZE TEST" << std::endl;
    std::cout << std::endl;
    std::cout << "we create an empty map" << std::endl;
    NAMESPACE::map<int, char> mymap;
    char c = 'A';
    std::cout << "is map empty? " << std::endl;
    (mymap.empty()) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    for (int i = 0; i < 26; i++)
        mymap.insert(NAMESPACE::make_pair(i, c++));
    print_map(mymap);
    std::cout << "is map empty? " << std::endl;
    (mymap.empty()) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "size = " << mymap.size() << std::endl;
    std::cout << "we delete one value " << std::endl;
    mymap.erase(mymap.begin());
    std::cout << "new size = " << mymap.size() << std::endl;
    std::cout << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}
void map_clear_test()
{
    std::cout << std::setw(30) << "MAP CLEAR TEST" << std::endl;
    NAMESPACE::map<int, std::string> mymap;
    std::string str = "bonjour";
    for (int i = 0; i < 10; i++)
        mymap.insert(NAMESPACE::make_pair(i, str));
    print_map(mymap);
    std::cout << "before clear, size = " << mymap.size() << std::endl;
    mymap.clear();
    std::cout << "after clear, size = " << mymap.size() << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}
void map_insert_test()
{
    std::cout << std::setw(30) << "MAP INSERT TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::map<int, std::string> mymap;
    std::string str[10] = {"adrien", "marie", "pierre", "lea", "paul", "jacques", "arthur", "chloe", "tom", "julie"};
    for (int i = 0; i < 10; i++)
        mymap.insert(NAMESPACE::make_pair(i * 2 + 1, str[i]));
    print_map(mymap);
    std::cout << "First insert method, single element added (robert)" << std::endl;
    mymap.insert(NAMESPACE::make_pair(10, "robert"));
    print_map(mymap);
    std::cout << "second insert method, range of elements, we copy our first map with a range of iterator" << std::endl;
    NAMESPACE::map<int, std::string> mymap2;
    mymap2.insert(mymap.begin(), mymap.end());
    print_map(mymap2);
    std::cout << "third insert method, we insert one element at a given key(begin)" << std::endl;
    NAMESPACE::map<int, std::string>::iterator it = mymap.begin();
    mymap2.insert(it, NAMESPACE::make_pair<int, std::string>(0, "joe"));
    print_map(mymap2);
    // while (std::cin.get() != '\n')
    // {
    // }
}
void map_erase_test()
{
    std::cout << std::setw(30) << "MAP ERASE TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::map<int, std::string> mymap;
    std::string str[10] = {"adrien", "marie", "pierre", "lea", "paul", "jacques", "arthur", "chloe", "tom", "julie"};
    for (int i = 0; i < 10; i++)
        mymap.insert(NAMESPACE::make_pair(i * 2 + 1, str[i]));
    print_map(mymap);
    std::cout << "we erase the first value" << std::endl;
    std::cout << std::endl;
    mymap.erase(mymap.begin());
    print_map(mymap);
    std::cout << "we erase a range of values(11 - end)" << std::endl;
    NAMESPACE::map<int, std::string>::iterator it = mymap.find(11);
    mymap.erase(it, mymap.end());
    print_map(mymap);
    // while (std::cin.get() != '\n')
    // {
    // }
}
void map_swap_values_test()
{
    std::cout << std::setw(30) << "MAP SWAP TEST" << std::endl;
    NAMESPACE::map<int, std::string> mymap;
    NAMESPACE::map<int, std::string> mymap2;
    for (int i = 0; i < 10; i++)
    {
        mymap.insert(NAMESPACE::make_pair(i * 2 + 1, "bonjour"));
        mymap2.insert(NAMESPACE::make_pair(i, "hello"));
    }
    std::cout << "first map contains :" << std::endl;

    print_map(mymap);
    std::cout << "second map contains :" << std::endl;
    print_map(mymap2);
    std::cout << "we swap maps" << std::endl;
    mymap.swap(mymap2);
    std::cout << "first map contains :" << std::endl;
    print_map(mymap);
    std::cout << "we swap again with non member method" << std::endl;
    swap(mymap, mymap2);
    std::cout << "first map contains :" << std::endl;
    print_map(mymap);

    // while (std::cin.get() != '\n')
    // {
    // }
}
void map_comparision_test()
{
    std::cout << std::setw(30) << "MAP COMPARISION TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::map<int, char> mymap;
    NAMESPACE::map<int, char> mymap2;
    char c = 'a';
    for (int i = 0; i < 10; i++)
    {
        mymap.insert(NAMESPACE::make_pair(i, c));
        mymap2.insert(NAMESPACE::make_pair(i, c++));
    }
    print_map(mymap);
    print_map(mymap2);
    std::cout << "map1 = map2? ";
    (mymap == mymap2) ? std::cout << "maps are equal" : std::cout << "maps are not equal";
    std::cout << std::endl;
    NAMESPACE::map<int, char> mymap3;
    for (int i = 0; i < 10; i++)
        mymap3.insert(NAMESPACE::make_pair(i, c++));
    std::cout << "we create a third map, different from first 2" << std::endl;
    print_map(mymap3);
    std::cout << "map3 == map? ";
    (mymap3 == mymap) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "map2 != map ? ";
    (mymap3 != mymap) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "map3 >= map ? ";
    (mymap3 >= mymap) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "map3 > map ? ";
    (mymap3 > mymap) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "map3 <= map ? ";
    (mymap3 <= mymap) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "map3 < map ? ";
    (mymap3 < mymap) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}

void map_performance_test()
{
    int i = 0;
    std::cout << "PERFORMANCE COMPARISION BETWEEN STD AND FT" << std::endl;
    // struct timeval time;
    // gettimeofday(&time, NULL);
    double start = catch_time();
    // std::cout << start << std::endl;

    NAMESPACE::map<int, int> mymap;

    while (i < 10000000)
    {
        mymap.insert(NAMESPACE::make_pair(i, i * 2));
        i++;
    }
    double end = catch_time() - start;

    std::cout << " timer map -> " << std::setprecision(4) << std::fixed << end << " ms" << std::endl;
}

void map_test()
{
    std::cout << std::setw(30) << "MAP TESTS" << std::endl;
    std::cout << std::endl;
    map_constructor_test();
    map_iterators_test();
    map_access_op_test();
    map_capacity_test();
    map_clear_test();
    map_insert_test();
    map_erase_test();
    map_swap_values_test();
    map_comparision_test();
    map_performance_test();
}