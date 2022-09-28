#ifdef USE
#define USING "STD"
#include <vector>
#else
#include "vector.hpp"
#define USING "FT"
#endif
#include <iostream>

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
std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
{
    o << rhs.get();
    return o;
}

template <class T>
void vector_begin_test(NAMESPACE::vector<T> myvec)
{
    typename NAMESPACE::vector<T>::iterator it = myvec.begin();
    std::cout << "begin = " << *it << std::endl;
}
template <class T>
void vector_end_test(NAMESPACE::vector<T> myvec)
{
    typename NAMESPACE::vector<T>::iterator it = myvec.end();
    std::cout << "end -1  = " << *--it << std::endl;
}
template <class T>
void vector_rbegin_test(NAMESPACE::vector<T> myvec)
{
    typename NAMESPACE::vector<T>::reverse_iterator it = myvec.rbegin();
    std::cout << "rbegin  = " << *it << std::endl;
}
template <class T>
void vector_rend_test(NAMESPACE::vector<T> myvec)
{
    typename NAMESPACE::vector<T>::reverse_iterator it = myvec.rend();
    std::cout << "rend  = " << *--it << std::endl;
}

void vector_test()
{
    std::cout << USING << std::endl;

    // int
    {
        NAMESPACE::vector<int> myvec(3, 3);
        vector_begin_test(myvec);
        vector_end_test(myvec);
        vector_rbegin_test(myvec);
        vector_rend_test(myvec);
        //        	while (std::cin.get() != '\n') {}
    }
    // double
    {
        NAMESPACE::vector<double> myvec(3, 3.14);
        vector_begin_test(myvec);
        vector_end_test(myvec);
        vector_rbegin_test(myvec);
        vector_rend_test(myvec);
    }
    // char
    {
        NAMESPACE::vector<char> myvec(3, 'a');
        vector_begin_test(myvec);
        vector_end_test(myvec);
        vector_rbegin_test(myvec);
        vector_rend_test(myvec);
    }
    // str
    {
        NAMESPACE::vector<std::string> myvec(3, "bonjour");
        vector_begin_test(myvec);
        vector_end_test(myvec);
        vector_rbegin_test(myvec);
        vector_rend_test(myvec);
    }
    // class
    {
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
    }
};