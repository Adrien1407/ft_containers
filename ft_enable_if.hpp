#ifndef FT_ENABLE_IF_HPP
#define FT_ENABLE_IF_HPP

# include "./iterator.hpp"
# include <sstream>

static	class ft_nullptr_t
	{
		private:
			void operator& () const;

		public:
			template <class T>
				operator T* () const { return 0;}
			template <class C, class T> 
				operator T C::* () const { return 0;}
	} ft_nullptr_t = {};

namespace ft
{

	template<bool C, class T = void> 
		struct enable_if {};
	template<class T>
		struct enable_if<true, T> 
		{ 
			typedef T type;
		};

	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type ret = 0;
		while (first != last)
		{
			first++;
			ret++;
		}
		return ret;
		
	};

	template<class T>
	std::string to_string(T obj)
	{
		std::ostringstream ss;
		ss << obj;
		return (ss.str());
	}

}
#endif