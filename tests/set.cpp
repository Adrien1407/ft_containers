/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:23:33 by adlancel          #+#    #+#             */
/*   Updated: 2022/10/13 17:54:11 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef USE
#define USING "STD"
#include <set>
#else
#include "set.hpp"
#define USING "FT"
#endif
#include <iostream>
#include <string>
#include <iomanip>
#include <sys/time.h>
#include "./test.hpp"

template <class T>
void print_set(NAMESPACE::set<T> &lst)
{
    if (!lst.empty())
    {
        for (typename NAMESPACE::set<T>::iterator it = lst.begin(); it != lst.end(); it++)
            std::cout << *it << '\n';
        std::cout << std::endl;
    }
    else
        std::cout << "This set is empty ... :(" << std::endl;
}
void set_constructor_test()
{
    std::cout << std::setw(30) << "set CONSTRUCTOR TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::set<char> myset;
    std::cout << "empty constructor" << std::endl;
    print_set(myset);
    char c = 'a';
    for (int i = 0; i < 5; i++)
        myset.insert(c++);
    print_set(myset);
    std::cout << "copy constructor from first set" << std::endl;
    NAMESPACE::set<char> myset2(myset);
    print_set(myset2);
    std::cout << "range constructor from second set" << std::endl;
    NAMESPACE::set<char> myset3(myset2.begin(), myset2.end());
    print_set(myset3);
    std::cout << "assignement constructor from second set" << std::endl;
    NAMESPACE::set<char> myset4 = myset2;
    print_set(myset4);
    // while (std::cin.get() != '\n')
    // {
    // }
}

void set_iterators_test()
{
    std::cout << std::setw(30) << "set ITERATORS TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::set<char> myset;
    char c = 'A';
    for (int i = 0; i < 26; i++)
        myset.insert(c++);
    NAMESPACE::set<char>::iterator it;
    for (it = myset.begin(); it != myset.end(); it++)
        std::cout << (*it) << std::endl;
    NAMESPACE::set<char>::iterator it2 = myset.begin();
    NAMESPACE::set<char>::iterator ite = myset.end();
    NAMESPACE::set<char>::reverse_iterator itr = myset.rbegin();
    NAMESPACE::set<char>::reverse_iterator itre = myset.rend();

    ite--;
    itre--;
    std::cout << "Begin = " << (*it2) << ", " << std::endl;
    std::cout << "end = " << (*ite) << ", " << std::endl;
    std::cout << "rbegin = " << (*itr) << ", " << std::endl;
    std::cout << "rend = " << (*itre) << ", " << std::endl;
    std::cout << std::endl;
    std::cout << "non const to const" << std::endl;
    NAMESPACE::set<char>::const_iterator it22 = it2;
    NAMESPACE::set<char>::const_iterator ite2 = ite;
    NAMESPACE::set<char>::const_reverse_iterator itrr = itr;
    NAMESPACE::set<char>::const_reverse_iterator itre2 = itre;

    std::cout << "const_begin = " << (*it22) << std::endl;
    std::cout << "const_end = " << (*ite2) << std::endl;
    std::cout << "const_rbegin = " << (*itrr) << std::endl;
    std::cout << "const_rend = " << (*itre2) << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}

void set_capacity_test()
{
    std::cout << std::setw(30) << "set SIZE TEST" << std::endl;
    std::cout << std::endl;
    std::cout << "we create an empty set" << std::endl;
    NAMESPACE::set<char> myset;
    char c = 'A';
    std::cout << "is set empty? " << std::endl;
    (myset.empty()) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    for (int i = 0; i < 26; i++)
        myset.insert(c++);
    print_set(myset);
    std::cout << "is set empty? " << std::endl;
    (myset.empty()) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "size = " << myset.size() << std::endl;
    std::cout << "we delete one value " << std::endl;
    myset.erase(myset.begin());
    std::cout << "new size = " << myset.size() << std::endl;
    std::cout << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}
void set_clear_test()
{
    std::cout << std::setw(30) << "set CLEAR TEST" << std::endl;
    NAMESPACE::set<std::string> myset;
    std::string str = "bonjour";
    for (int i = 0; i < 10; i++)
        myset.insert(str);
    print_set(myset);
    std::cout << "before clear, size = " << myset.size() << std::endl;
    myset.clear();
    std::cout << "after clear, size = " << myset.size() << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}
void set_insert_test()
{
    std::cout << std::setw(30) << "set INSERT TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::set<std::string> myset;
    std::string str[10] = {"adrien", "marie", "pierre", "lea", "paul", "jacques", "arthur", "chloe", "tom", "julie"};
    for (int i = 0; i < 10; i++)
        myset.insert(str[i]);
    print_set(myset);
    std::cout << "First insert method, single element added (robert)" << std::endl;
    myset.insert("robert");
    print_set(myset);
    std::cout << "second insert method, range of elements, we copy our first set with a range of iterator" << std::endl;
    NAMESPACE::set<std::string> myset2;
    myset2.insert(myset.begin(), myset.end());
    print_set(myset2);
    std::cout << "third insert method, we insert one element at a given key(begin)" << std::endl;
    NAMESPACE::set<std::string>::iterator it = myset.begin();
    myset2.insert(it, "joe");
    print_set(myset2);
    // while (std::cin.get() != '\n')
    // {
    // }
}
void set_erase_test()
{
    std::cout << std::setw(30) << "set ERASE TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::set<std::string> myset;
    std::string str[10] = {"adrien", "marie", "pierre", "lea", "paul", "jacques", "arthur", "chloe", "tom", "julie"};
    for (int i = 0; i < 10; i++)
        myset.insert(str[i]);
    print_set(myset);
    std::cout << "we erase the first value" << std::endl;
    std::cout << std::endl;
    myset.erase(myset.begin());
    print_set(myset);
    std::cout << "we erase a range of values( paul - end)" << std::endl;
    NAMESPACE::set<std::string>::iterator it = myset.find("paul");
    myset.erase(it, myset.end());
    print_set(myset);
    // while (std::cin.get() != '\n')
    // {
    // }
}
void set_swap_values_test()
{
    std::cout << std::setw(30) << "set SWAP TEST" << std::endl;
    NAMESPACE::set<std::string> myset;
    NAMESPACE::set<std::string> myset2;
    for (int i = 0; i < 10; i++)
    {
        myset.insert("bonjour");
        myset2.insert("hello");
    }
    std::cout << "first set contains :" << std::endl;

    print_set(myset);
    std::cout << "second set contains :" << std::endl;
    print_set(myset2);
    std::cout << "we swap sets" << std::endl;
    myset.swap(myset2);
    std::cout << "first set contains :" << std::endl;
    print_set(myset);
    std::cout << "we swap again with non member method" << std::endl;
    swap(myset, myset2);
    std::cout << "first set contains :" << std::endl;
    print_set(myset);

    // while (std::cin.get() != '\n')
    // {
    // }
}
void set_comparision_test()
{
    std::cout << std::setw(30) << "set COMPARISION TEST" << std::endl;
    std::cout << std::endl;
    NAMESPACE::set<char> myset;
    NAMESPACE::set<char> myset2;
    char c = 'a';
    for (int i = 0; i < 10; i++)
    {
        myset.insert(c);
        myset2.insert(c++);
    }
    print_set(myset);
    print_set(myset2);
    std::cout << "set1 = set2? ";
    (myset == myset2) ? std::cout << "sets are equal" : std::cout << "sets are not equal";
    std::cout << std::endl;
    NAMESPACE::set<char> myset3;
    for (int i = 0; i < 10; i++)
        myset3.insert(c++);
    std::cout << "we create a third set, different from first 2" << std::endl;
    print_set(myset3);
    std::cout << "set3 == set? ";
    (myset3 == myset) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "set2 != set ? ";
    (myset3 != myset) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "set3 >= set ? ";
    (myset3 >= myset) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "set3 > set ? ";
    (myset3 > myset) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "set3 <= set ? ";
    (myset3 <= myset) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << "set3 < set ? ";
    (myset3 < myset) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}

void set_performance_test()
{
    int i = 0;
    std::cout << "PERFORMANCE COMPARISION BETWEEN STD AND FT" << std::endl;
    double start = catch_time();
    NAMESPACE::set<int> myset;

    while (i < 10000000)
    {
        myset.insert(i);
        i++;
    }
    double end = catch_time() - start;

    std::cout << " timer set -> " << std::setprecision(4) << std::fixed << end << " ms" << std::endl;
}

void set_test()
{
    std::cout << std::setw(30) << "set TESTS" << std::endl;
    std::cout << std::endl;
    set_constructor_test();
    set_iterators_test();
    set_capacity_test();
    set_clear_test();
    set_insert_test();
    set_erase_test();
    set_swap_values_test();
    set_comparision_test();
    set_performance_test();
};