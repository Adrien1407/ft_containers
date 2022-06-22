

#include "../include/vector.hpp"
#include <iostream>
#include <vector>
#include "../include/iterator.hpp"
#include "../include/ft_enable_if.hpp"
#include "../include/reverse_iterator.hpp"
#include "../include/random_access_iterator.hpp"

class Awesome {

	public:

		Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; } //should not happen too often or else there is a wrong use of allocator (which calls the copy constructor)
		Awesome( int n ) : _n( n ) { std::cout << "Int constructor" << std::endl; (void)n; }
		Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
		virtual ~Awesome(void) {}

		Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		void operator+=(int rhs){ _n += rhs; }
		int get( void ) const { return this->_n; }

	private:

		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template <class T>
void	print_vector(ft::vector<T> &test)
{
	typename ft::vector<T>::iterator		beg = test.begin();
	typename ft::vector<T>::iterator		end = test.end();
	std::cout << "size : " << test.size() << ", capacity : " << test.capacity() << std::endl;
	for (typename ft::vector<T>::iterator it = beg; it != end; it++)
	{
		std::cout << *it << " ";
		if (((it - beg) % 10 == 9) && it > beg)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}
template <class T>
void	insert_tests()
{
	std::cout << std::endl << "INSERT TESTS" << std::endl;
	ft::vector<T> test(1, 1);
//	ft::vector<T> test2(5, 5);

	test.insert(test.begin(), 200, 12);
	// print_vector<T>(test);
	test.insert(test.begin() + 12, 200, 30);
	// print_vector<T>(test);
	test.insert(test.end(), 12, 50);
	// print_vector<T>(test);
	test.insert(test.end() - 1, 0, 60);
	// print_vector<T>(test);
	test.insert(test.end() - 1, 1, 70);
	// print_vector<T>(test);
//	test.insert(test.begin() + 412, test2.begin(), test2.end());
	// print_vector<T>(test);
//	test.insert(test.begin() + 6, test2.begin(), test2.end());
	// print_vector<T>(test);
//	test.insert(test.end(), test2.begin(), test2.end());
	// print_vector<T>(test);
}

int main()
{
	insert_tests<Awesome>();
}

