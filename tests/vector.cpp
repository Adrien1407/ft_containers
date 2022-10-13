/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:55:57 by adlancel          #+#    #+#             */
/*   Updated: 2022/10/13 18:04:07 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef USE
#define USING "STD"
#include <vector>
#else
#include "vector.hpp"
#define USING "FT"
#endif
#include <iostream>
#include <string>
#include <iomanip>
#include <sys/time.h>
#include "./test.hpp"

class Awesome
{

public:
    Awesome(void) : _n(42) {} // should not happen too oNSen or else there is a wrong use of allocator (which calls the copy constructor)
    Awesome(int n) : _n(n)
    {
        (void)n;
    }
    Awesome(Awesome const &rhs) : _n(42) { *this = rhs; }
    virtual ~Awesome(void) {}

    Awesome &operator=(Awesome const &rhs)
    {
        this->_n = rhs._n;
        return (*this);
    }
    bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
    bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
    bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
    bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
    bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
    bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
    void operator+=(int rhs) { _n += rhs; }
    int get(void) const { return this->_n; }

private:
    int _n;
};
// std::cout << ""<<std::endl;

template <class T>
void print(NAMESPACE::vector<T> &lst)
{
    std::cout << "vector contains : ";
    for (typename NAMESPACE::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}

void vector_constructor_test()
{
    std::cout << std::setw(30) << "CONSTRUCTOR TESTS" << std::endl;
    std::cout << std::endl;
    std::cout << "first vector initialized with no values" << std::endl;
    NAMESPACE::vector<int> vec;
    std::cout << "capacity = " << vec.capacity() << std::endl;
    std::cout << "size = " << vec.size() << std::endl;
    print(vec);
    std::cout << std::endl;
    std::cout << "second vector initialized with 10 values" << std::endl;
    NAMESPACE::vector<int> vec2(10, 10);
    std::cout << "capacity = " << vec2.capacity() << std::endl;
    std::cout << "size = " << vec2.size() << std::endl;
    print(vec2);
    std::cout << std::endl;
    std::cout << "third vector initialized by copying vector2" << std::endl;
    NAMESPACE::vector<int> vec3(vec2);
    std::cout << "capacity = " << vec3.capacity() << std::endl;
    std::cout << "size = " << vec3.size() << std::endl;
    print(vec3);
    std::cout << std::endl;
    std::cout << "fourth vector initialized by range(7)" << std::endl;
    NAMESPACE::vector<int> vec4(vec2.begin() + 3, vec2.end());
    std::cout << "capacity = " << vec4.capacity() << std::endl;
    std::cout << "size = " << vec4.size() << std::endl;
    print(vec4);
    std::cout << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}

void vector_iterators_test()
{
    std::cout << std::setw(30) << "ITERATOR TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    std::cout << "we push 100 values in our vector " << std::endl;
    for (int i = 0; i < 100; i++)
        vec.push_back((i * 3) - (i + 2) + (i / 2));
    std::cout << "capacity = " << vec.capacity() << std::endl;
    std::cout << "size = " << vec.size() << std::endl;
    std::cout << std::endl;
    std::cout << "begin = " << *vec.begin() << std::endl;
    std::cout << "end = " << *vec.end() << std::endl;
    std::cout << "rbegin = " << *vec.rbegin() << std::endl;
    std::cout << "rend = " << *vec.rend() << std::endl;
    std::cout << std::endl;
    std::cout << "we insert 9999 as begin value " << std::endl;
    vec.insert(vec.begin(), 9999);
    std::cout << "new begin = " << *vec.begin() << std::endl;

    std::cout << "we print in reverse mode with reverse iterators" << std::endl
              << std::endl;
    for (NAMESPACE::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
        std::cout << *it << ", ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(30) << "COMPARISION ITERATORS" << std::endl;
    std::cout << std::endl;
    std::cout << vec[0] << " == " << vec[1] << " ? ";
    (vec[0] == vec[1]) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << vec[0] << " != " << vec[1] << " ? ";
    (vec[0] != vec[1]) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << vec[0] << " >= " << vec[1] << " ? ";
    (vec[0] >= vec[1]) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << vec[0] << " > " << vec[1] << " ? ";
    (vec[0] > vec[1]) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << vec[0] << " <= " << vec[1] << " ? ";
    (vec[0] <= vec[1]) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << vec[0] << " < " << vec[1] << " ? ";
    (vec[0] < vec[1]) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_at_test()
{
    std::cout << std::setw(30) << "AT TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    for (int i = 0; i < 100; i++)
        vec.push_back(i * 3);
    print(vec);
    std::cout << "vec.at(1) = " << vec.at(1) << std::endl;
    std::cout << "vec.at(99) = " << vec.at(99) << std::endl;
    std::cout << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_access_op_test()
{
    std::cout << std::setw(30) << " OPERATOR[] TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    for (int i = 0; i < 100; i++)
        vec.push_back(i * 3);
    print(vec);
    std::cout << "vec[0] = " << vec[0] << std::endl;
    std::cout << "vec[2] = " << vec[2] << std::endl;
    std::cout << "vec[99] = " << vec[99] << std::endl;
    std::cout << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_front_test()
{
    std::cout << std::setw(30) << "FRONT TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    for (int i = 0; i < 100; i++)
        vec.push_back(i * 3);
    print(vec);
    std::cout << "vec.front() = " << vec.front() << std::endl;
    std::cout << "we insert new front value(99) " << std::endl;
    vec.insert(vec.begin(), 99);
    print(vec);

    std::cout << "new vec.front() = " << vec.front() << std::endl;
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}

void vector_back_test()
{
    std::cout << std::setw(30) << "BACK TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    for (int i = 0; i < 100; i++)
        vec.push_back(i * 3);
    print(vec);
    std::cout << "vec.back() = " << vec.back() << std::endl;
    std::cout << "we insert new back value(99) " << std::endl;
    vec.insert(vec.end(), 99);
    print(vec);

    std::cout << "new vec.back() = " << vec.back() << std::endl;
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_capacity_test()
{
    std::cout << std::setw(30) << "CAPACITY TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(i * 3);
        std::cout << "capacity = " << vec.capacity() << std::endl;
        std::cout << "size = " << vec.size() << std::endl;
    }
    std::cout << "we insert 100 values" << std::endl;
    vec.insert(vec.begin(), 100, 100);
    std::cout << "capacity = " << vec.capacity() << std::endl;
    std::cout << "size = " << vec.size() << std::endl;
    std::cout << std::endl;
    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_clear_test()
{
    std::cout << std::setw(30) << "CLEAR TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    for (int i = 0; i < 20; i++)
        vec.push_back(i * 3);
    print(vec);
    std::cout << "capacity = " << vec.capacity() << std::endl;
    std::cout << "size = " << vec.size() << std::endl
              << std::endl;
    std::cout << "we clear vec" << std::endl;
    vec.clear();
    print(vec);
    std::cout << "capacity = " << vec.capacity() << std::endl;
    std::cout << "size = " << vec.size() << std::endl;
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_insert_test()
{
    std::cout << std::setw(30) << "INSERT TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    NAMESPACE::vector<int> vec2;
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(i * 3);
        vec2.push_back(i * 3);
    }
    print(vec);
    std::cout << "we insert one value (10 at begin)" << std::endl
              << std::endl;
    vec.insert(vec.begin(), 10);
    print(vec);
    std::cout << std::endl;
    std::cout << "we insert 100 values at end" << std::endl
              << std::endl;
    vec.insert(vec.end(), 100, 100);
    print(vec);
    std::cout << std::endl;
    std::cout << "we insert a range at position 20" << std::endl
              << std::endl;
    vec.insert(vec.begin() + 20, vec2.begin(), vec2.end());
    print(vec);

    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_erase_test()
{
    std::cout << std::setw(30) << "ERASE TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    for (int i = 0; i < 20; i++)
        vec.push_back(i * 4);
    print(vec);
    std::cout << std::endl;
    std::cout << "we erase last value" << std::endl
              << std::endl;
    vec.erase(vec.end() - 1);
    print(vec);
    std::cout << std::endl;
    std::cout << "we erase 10 first value" << std::endl;
    for (int i = 0; i < 10; i++)
        vec.erase(vec.begin());
    print(vec);
    std::cout << std::endl;
    std::cout << "we erase second value" << std::endl;
    vec.erase(vec.begin() + 1);
    print(vec);
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_push_back_test()
{
    std::cout << std::setw(30) << "PUSHBACK TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    std::cout << "we push back 20 values" << std::endl;
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(i * 3);
        print(vec);
    }
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_pop_back_test()
{
    std::cout << std::setw(30) << "POPBACK TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    std::cout << "we push back 20 values" << std::endl;
    for (int i = 0; i < 20; i++)
        vec.push_back(i * 3);
    print(vec);
    std::cout << std::endl;
    std::cout << "we pop back 10 last values" << std::endl;
    for (int i = 0; i < 10; i++)
        vec.pop_back();
    print(vec);
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_resize_test()
{
    std::cout << std::setw(30) << "RESIZE TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    std::cout << "size = " << vec.size() << std::endl;
    std::cout << "we resize the vector to 20" << std::endl;
    vec.resize(20);
    std::cout << "size = " << vec.size() << std::endl;
    std::cout << "capacity = " << vec.capacity() << std::endl;
    std::cout << "we resize the vector to 1" << std::endl;
    vec.resize(1);
    std::cout << "size = " << vec.size() << std::endl;
    std::cout << "capacity = " << vec.capacity() << std::endl;
    std::cout << std::endl;

    try
    {
        vec.resize(vec.max_size() + 12);
    }
    catch (const std::exception &e)
    {
        std::cerr << "exception : " << e.what() << std::endl;
    }
    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_reserve_test()
{
    std::cout << std::setw(30) << "RESERVE TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;

    try
    {
        vec.reserve(vec.max_size() + 12);
    }
    catch (const std::exception &e)
    {
        std::cerr << "exception : " << e.what() << std::endl;
    }
    // while (std::cin.get() != '\n')
    // {
    // }
}

void vector_swap_values_test()
{
    std::cout << std::setw(30) << "SWAP VALUES TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    NAMESPACE::vector<int> vec2;
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(i * 3);
        vec2.push_back(i * i + 2);
    }
    print(vec);
    print(vec2);
    std::cout << std::endl;
    std::cout << "we swap vec with vec2" << std::endl;
    vec.swap(vec2);
    print(vec);
    print(vec2);
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_swap_vec_test()
{
    std::cout << std::setw(30) << "NON MEMBER SWAP VECTOR TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    NAMESPACE::vector<int> vec2;
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(i * 3 + 2);
        vec2.push_back(i * i * i + 5);
    }
    print(vec);
    print(vec2);
    std::cout << "we swap vec and vec2" << std::endl;
    swap(vec, vec2);
    print(vec);
    print(vec2);
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}
void vector_comparision_test()
{
    std::cout << std::setw(30) << "COMPARISION TESTS" << std::endl;
    std::cout << std::endl;
    NAMESPACE::vector<int> vec;
    NAMESPACE::vector<int> vec2;
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(i * 3 + 2);
        vec2.push_back(i * i * i + 5);
    }
    print(vec);
    print(vec2);
    std::cout << "vec == vec2? ";
    (vec == vec2) ? std::cout << "vectors are equal" : std::cout << "vector are not equal";
    std::cout << std::endl;
    NAMESPACE::vector<int> vec3;
    for (int i = 0; i < 20; i++)
        vec3.push_back(i * i * i + 5);
    std::cout << "we create a third vector, identical to second" << std::endl;
    print(vec3);
    std::cout << "vec2 == vec3? ";
    (vec2 == vec3) ? std::cout << "vectors are equal" : std::cout << "vector are not equal";
    std::cout << "we modify third vector first value" << std::endl;
    vec3[0] = 4;
    print(vec3);
    std::cout << std::endl;
    std::cout << "vec2 != vec3 ? ";
    (vec2 != vec3) ? std::cout << "vectors not equal" : std::cout << "vectors equal";
    std::cout << std::endl;
    std::cout << "vec2 >= vec3 ? ";
    (vec2 >= vec3) ? std::cout << "vec2 superior to vec3" : std::cout << "vec2 not superior to vec3";
    std::cout << std::endl;
    std::cout << "vec2 > vec3 ? ";
    (vec2 > vec3) ? std::cout << "vec2 strictly superior to vec3" : std::cout << "vec2 not strictly superior to vec3";
    std::cout << std::endl;
    std::cout << "vec2 <= vec3 ? ";
    (vec2 <= vec3) ? std::cout << "vec2 inferior to vec3" : std::cout << "vec2 not inferior to vec3";
    std::cout << std::endl;
    std::cout << "vec2 < vec3 ? ";
    (vec2 < vec3) ? std::cout << "vec2 strictly inferior to vec3" : std::cout << "vec2 not strictly inferior to vec3";
    std::cout << std::endl;

    // while (std::cin.get() != '\n')
    // {
    // }
}

void performance_test()
{
    int i = 0;
    std::cout << "PERFORMANCE COMPARISION BETWEEN STD AND FT" << std::endl;
    double start = catch_time();
    NAMESPACE::vector<int> myvec;
    while (i < 10000000)
    {
        myvec.push_back(i * 2);
        i++;
    }
    double end = catch_time() - start;
    std::cout << " timer map -> " << std::setprecision(4) << std::fixed << end << " ms" << std::endl;
}

void vector_test()
{
    vector_constructor_test();
    vector_iterators_test();
    vector_at_test();
    vector_access_op_test();
    vector_front_test();
    vector_back_test();
    vector_capacity_test();
    vector_clear_test();
    vector_insert_test();
    vector_erase_test();
    vector_push_back_test();
    vector_pop_back_test();
    vector_resize_test();
    vector_reserve_test();
    vector_swap_values_test();
    vector_swap_vec_test();
    vector_comparision_test();
    performance_test();
};
