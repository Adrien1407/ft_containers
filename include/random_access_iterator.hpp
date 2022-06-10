/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:10:26 by adlancel          #+#    #+#             */
/*   Updated: 2022/05/31 17:22:24 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <typename T>
		class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
		/*	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
			typedef T *pointer;
			typedef T &reference;
*/
		typedef T value_type;
		typedef T &reference;
		typedef T *pointer;
		typedef const T &const_reference;
		typedef const T *const_pointer;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;
		typedef typename ft::random_access_iterator_tag iterator_category;
		
		private:
			pointer _elem;

		public:
			random_access_iterator() : _elem(0){};
			random_access_iterator(pointer ptr) : _elem(ptr){};
			random_access_iterator(const random_access_iterator<T> &cpy) : _elem(cpy._elem){};
			virtual ~random_access_iterator(){};

			random_access_iterator &operator=(random_access_iterator<T> const &cpy)
			{
				if (this != &cpy)
					_elem = cpy._elem;
				return (*this);
			};
			
			operator random_access_iterator<T const>() const
			{
				return random_access_iterator<T const>(_elem);
			};

			pointer base() const
			{
				return (_elem);
			};
			pointer operator->()
			{
				return (_elem);
			};

			reference operator*()
			{
				return (*_elem);
			};

			// relationnal operators

			bool operator<(const random_access_iterator &src) const
			{
				return (_elem < src._elem);
			};
			bool operator>(const random_access_iterator &src) const
			{
				return (_elem > src._elem);
			};
			bool operator>=(const random_access_iterator &src) const
			{
				return (_elem >= src._elem);
			};
			bool operator<=(const random_access_iterator &src) const
			{
				return (_elem <= src._elem);
			};
			bool operator!=(const random_access_iterator &src) const
			{
				return (_elem != src._elem);
			};
			bool operator==(const random_access_iterator &src) const
			{
				return (_elem == src._elem);
			};

			random_access_iterator operator+(difference_type _n)
			{
				return (_elem + _n);
			};
			random_access_iterator operator-(difference_type _n)
			{
				return (_elem - _n);
			};
			random_access_iterator operator++(int)
			{
				random_access_iterator tmp = *this;
				_elem++;
				return (tmp);
			};
			random_access_iterator &operator++()
			{
				_elem++;
				return (*this);
			};
			random_access_iterator operator--(int)
			{
				random_access_iterator tmp = *this;
				_elem--;
				return (tmp);
			};		
			random_access_iterator &operator--()
			{
				_elem--;
				return (*this);
			};
			random_access_iterator &operator-=(difference_type n)
			{
				_elem -= n;
				return (*this);
			};
			random_access_iterator &operator+=(difference_type n)
			{
				_elem += n;
				return (*this);
			};
			random_access_iterator &operator[](difference_type n) const
			{
				return (_elem[n]);
			};
	};
	template <class T>
		ft::random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &rhs)
		{
			return (rhs + n);
		};
	template <class T, class U>
		ptrdiff_t operator-(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
		{
			return (lhs.base() - rhs.base());
		};
	template <class it1, class it2>
		bool operator==(const random_access_iterator<it1> &lhs, const random_access_iterator<it2> &rhs)
		{
			return (lhs._elem == rhs._elem);
		};
	template <class it1, class it2>
		bool operator!=(const random_access_iterator<it1> &lhs, const random_access_iterator<it2> &rhs)
		{
			return (lhs._elem != rhs._elem);
		};
	template <class it1, class it2>
		bool operator>=(const random_access_iterator<it1> &lhs, const random_access_iterator<it2> &rhs)
		{
			return (lhs._elem >= rhs._elem);
		};
	template <class it1, class it2>
		bool operator<=(const random_access_iterator<it1> &lhs, const random_access_iterator<it2> &rhs)
		{
			return (lhs._elem <= rhs._elem);
		};
	template <class it1, class it2>
		bool operator<(const random_access_iterator<it1> &lhs, const random_access_iterator<it2> &rhs)
		{
			return (lhs._elem < rhs._elem);
		};
	template <class it1, class it2>
		bool operator>(const random_access_iterator<it1> &lhs, const random_access_iterator<it2> &rhs)
		{
			return (lhs._elem > rhs._elem);
		};
}
#endif
