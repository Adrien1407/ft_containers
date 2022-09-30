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

template <class T>
void print_vector(NAMESPACE::vector<T> a)
{
    if (a.capacity() != 0)
    {
        // std::cout << print++ << _NC << "  > ";
        std::cout << "vector contains : ";
        for (typename NAMESPACE::vector<T>::iterator it = a.begin(); it != a.end(); it++)
            std::cout << *it << ", ";
        // std::cout << "   Size of vector -> " << a.size() << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cerr << "this vector is empty ... " << std::endl;
    }
}
std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
{
    o << rhs.get();
    return o;
}

template <class T>
void vector_begin_test(NAMESPACE::vector<T> myvec)
{
    typename NAMESPACE::vector<T>::iterator it = myvec.begin();
    std::cout << "begin  = " << *it << std::endl;
}
template <class T>
void vector_end_test(NAMESPACE::vector<T> myvec)
{
    typename NAMESPACE::vector<T>::iterator it = myvec.end();
    std::cout << "end    = " << *--it << std::endl;
}
template <class T>
void vector_rbegin_test(NAMESPACE::vector<T> myvec)
{
    typename NAMESPACE::vector<T>::reverse_iterator it = myvec.rbegin();
    std::cout << "rbegin = " << *it << std::endl;
}
template <class T>
void vector_rend_test(NAMESPACE::vector<T> myvec)
{
    typename NAMESPACE::vector<T>::reverse_iterator it = myvec.rend();
    std::cout << "rend   = " << *--it << std::endl;
}
// template <class T>
// void vector_relationals_test()
// {
//     NAMESPACE::vector<int> my_vec_int_1(10, 10);
//     NAMESPACE::vector<int> my_vec_int_2(9, 10);
//     NAMESPACE::vector<int> my_vec_int_3(my_vec_int_1);

//     NAMESPACE::vector<double> my_vec_double_1(3.14116, 20);
//     NAMESPACE::vector<double> my_vec_double_2(3.13333, 20;
//     NAMESPACE::vector<double> my_vec_double_3;(my_vec_double_2)

//     NAMESPACE::vector<std::string> my_vec_string_1();
//     NAMESPACE::vector<std::string> my_vec_string_2();
//     NAMESPACE::vector<Awesome> my_vec_class_1();
//     NAMESPACE::vector<Awesome> my_vec_class_2();
// }

void vector_comparision_operator()
{
    std::cout << std::endl;
    std::cout << std::setw(50) << "COMPARISION OPERATORS" << std::endl;
    std::cout << std::endl;

    NAMESPACE::vector<int> vec_int(4, 8);
    NAMESPACE::vector<double> vec_double(4, 8.00);
    // NAMESPACE::vector<std::string> vec_string(4, "bonjour");
    // NAMESPACE::vector<NAMESPACE::vector<std::string> > vec_vec_string(4, vec_string);

    NAMESPACE::vector<int>::iterator iti = vec_int.begin();
    NAMESPACE::vector<double>::iterator itd = vec_double.begin();
    // NAMESPACE::vector<std::string>::iterator its = vec_string.begin();
    // NAMESPACE::vector<NAMESPACE::vector<std::string> >::iterator itv = vec_vec_string.begin();

    std::cout << *iti << " == " << *itd << " ?";
    (*iti == *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << *iti << " != " << *itd << " ?";
    (*iti != *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << *iti << " >= " << *itd << " ?";
    (*iti >= *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << *iti << " <= " << *itd << " ?";
    (*iti <= *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << *iti << " > " << *itd << " ?";
    (*iti > *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << *iti << " < " << *itd << " ?";
    (*iti < *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "we modify left part" << std::endl;
    std::cout << std::endl;

    *iti = 2;

    std::cout << *iti << " == " << *itd << " ?";
    (*iti == *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << *iti << " != " << *itd << " ?";
    (*iti != *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << *iti << " >= " << *itd << " ?";
    (*iti >= *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << *iti << " <= " << *itd << " ?";
    (*iti <= *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << *iti << " > " << *itd << " ?";
    (*iti > *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    std::cout << *iti << " < " << *itd << " ?";
    (*iti < *itd) ? std::cout << " yes" : std::cout << " no";
    std::cout << std::endl;

    // std::cout << "string comparision" << std::endl;

    // std::cout << *its << " == " << *itv << " ?";
    // (*its == *itv) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << *its << " != " << *itv << " ?";
    // (*its != *itv) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << *its << " >= " << *itv << " ?";
    // (*its >= *itv) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << *its << " <= " << *itv << " ?";
    // (*its <= *itv) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << *its << " > " << *itv << " ?";
    // (*its > *itv) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << *its << " < " << *itv << " ?";
    // (*its < *itv) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << std::endl;
    // std::cout << "we modify left part" << std::endl;
    // std::cout << std::endl;

    // *its = "hello";

    // std::cout << *its << " == " << *(its + 1) << " ?";
    // (*its == *(its + 1)) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << *its << " != " << *(its + 1) << " ?";
    // (*its != *(its + 1)) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << *iti << " >= " << *(its + 1) << " ?";
    // (*iti >= *(its + 1)) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << *iti << " <= " << *(its + 1) << " ?";
    // (*iti <= *(its + 1)) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << *iti << " > " << *(its + 1) << " ?";
    // (*iti > *(its + 1)) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;

    // std::cout << *iti << " < " << *(its + 1) << " ?";
    // (*iti < *(its + 1)) ? std::cout << " yes" : std::cout << " no";
    // std::cout << std::endl;
}

template <class T>
void vector_capacity_test(NAMESPACE::vector<T> myvec)
{
    std::cout << std::endl;
    std::cout << "CAPACITY/SIZE" << std::endl;
    std::cout << std::endl;
    print_vector(myvec);

    std::cout << "myvec_capacity = " << myvec.capacity() << std::endl;
    std::cout << "myvec_size = " << myvec.size() << std::endl;
    std::cout << "myvec is empty ? ";
    (myvec.empty()) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
    std::cout << std::endl;
    while (std::cin.get() != '\n')
    {
    }
    std::cout << "we delete 1 value" << std::endl;
    myvec.erase(myvec.begin());

    std::cout << "myvec_capacity = " << myvec.capacity() << std::endl;
    std::cout << "myvec_size = " << myvec.size() << std::endl;
    print_vector(myvec);
    while (std::cin.get() != '\n')
    {
    }
    for (int i = 0; i < 30; i++)
        myvec.push_back(*myvec.begin());
    print_vector(myvec);
    std::cout << "myvec_capacity = " << myvec.capacity() << std::endl;
    std::cout << "myvec_size = " << myvec.size() << std::endl;
}

// std::cout << "!=" std::endl;
// std::cout << ">=" std::endl;
// std::cout << "<=" std::endl;
// std::cout << ">" std::endl;
// std::cout << "<"  std::endl;

void vector_test()
{
    std::cout << "===============================   " << USING << "   =======================================" << std::endl;

    std::cout << std::endl;
    std::cout << std::setw(40) << "ITERATORS" << std::endl;

    // int
    {
        std::cout << std::setw(20) << "INT VECTOR" << std::endl;
        NAMESPACE::vector<int> myvec;
        for (int i = 0; i < 10; i++)
        {
            myvec.push_back(i * 4);
        }
        vector_begin_test(myvec);
        vector_end_test(myvec);
        vector_rbegin_test(myvec);
        vector_rend_test(myvec);
        vector_capacity_test(myvec);
        while (std::cin.get() != '\n')
        {
        }
    }

    // double
    {
        NAMESPACE::vector<double> myvec;
        for (int i = 0; i < 10; i++)
        {
            myvec.push_back(i + 0.002);
        }
        std::cout << std::setw(20) << "DOUBLE VECTOR" << std::endl;
        vector_begin_test(myvec);
        vector_end_test(myvec);
        vector_rbegin_test(myvec);
        vector_rend_test(myvec);
        vector_capacity_test(myvec);
        while (std::cin.get() != '\n')
        {
        }
    }
    // char
    {
        NAMESPACE::vector<char> myvec;
        for (int i = 0; i < 10; i++)
        {
            myvec.push_back('a' + 2 * i);
        }

        std::cout << std::setw(20) << "CHAR VECTOR" << std::endl;
        vector_begin_test(myvec);
        vector_end_test(myvec);
        vector_rbegin_test(myvec);
        vector_rend_test(myvec);
        vector_capacity_test(myvec);
        while (std::cin.get() != '\n')
        {
        }
    }
    // str
    {
        std::string tab[4] = {
            "bonjour",
            "le",
            "correcteur",
            "!"};

        NAMESPACE::vector<std::string> myvec;
        for (int i = 0; i < 4; i++)
        {
            myvec.push_back(tab[i]);
        }

        std::cout << std::setw(20) << "STRING VECTOR" << std::endl;
        vector_begin_test(myvec);
        vector_end_test(myvec);
        vector_rbegin_test(myvec);
        vector_rend_test(myvec);
        vector_capacity_test(myvec);
        while (std::cin.get() != '\n')
        {
        }
    }
    // class
    {
        std::cout << std::setw(20) << "CLASS VECTOR" << std::endl;
        int i = 0;
        NAMESPACE::vector<Awesome> myvec(10);
        for (NAMESPACE::vector<Awesome>::iterator it = myvec.begin(); it != myvec.end(); it++)
        {
            *it = Awesome(i++);
        }
        vector_begin_test(myvec);
        vector_end_test(myvec);
        vector_rbegin_test(myvec);
        vector_rend_test(myvec);
        vector_capacity_test(myvec);
        while (std::cin.get() != '\n')
        {
        }
    }
    vector_comparision_operator();
};