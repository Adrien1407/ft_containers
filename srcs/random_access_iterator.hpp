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

#include <cstddef>
#include <iostream>

namespace ft
{
	template <class T>
	class random_access_iterator
	{
	public:
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef const T *const_pointer;
		typedef const T &const_reference;
		typedef std::random_access_iterator_tag iterator_category;

		random_access_iterator() : _ptr(NULL) {}
		random_access_iterator(pointer ptr) : _ptr(ptr) {}
		random_access_iterator(random_access_iterator const &lhs) : _ptr(lhs._ptr) {}
		random_access_iterator &operator=(random_access_iterator const &lhs)
		{
			if (this == &lhs)
				return (*this);
			_ptr = lhs._ptr;
			return (*this);
		}
		virtual ~random_access_iterator() {}

		// Overload called when trying to copy construct a const_iterator
		// based on an iterator
		operator random_access_iterator<value_type const>() const
		{
			return random_access_iterator<value_type const>(_ptr);
		}
		pointer base() const
		{
			return (_ptr);
		};
		const_reference operator*() const
		{
			return (*_ptr);
		}

		const_pointer operator->() const
		{
			return (_ptr);
		}

		reference operator*()
		{
			return (*_ptr);
		}

		pointer operator->()
		{
			return (_ptr);
		}

		random_access_iterator &operator++()
		{
			_ptr++;
			return (*this);
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator<T> tmp(*this);
			_ptr++;
			return (tmp);
		}

		random_access_iterator &operator--()
		{
			_ptr--;
			return (*this);
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator<T> tmp(*this);
			_ptr--;
			return (tmp);
		}

		random_access_iterator operator+(difference_type n) const
		{
			return (random_access_iterator<T>(_ptr + n));
		}

		random_access_iterator operator-(difference_type n) const
		{
			return (random_access_iterator<T>(_ptr - n));
		}

		difference_type operator-(random_access_iterator const &lhs) const
		{
			return (_ptr - lhs._ptr);
		}

		random_access_iterator &operator+=(difference_type n)
		{
			_ptr += n;
			return (*this);
		}

		random_access_iterator &operator-=(difference_type n)
		{
			_ptr -= n;
			return (*this);
		}

		reference operator[](difference_type n) const
		{
			return *(_ptr + n);
		}

	protected:
		pointer _ptr;
	};

	template <class Iterator>
	bool operator==(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iterator> const &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!=(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iterator> const &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iterator> const &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iterator> const &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<=(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iterator> const &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	bool operator>=(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iterator> const &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator, class Iter>
	bool operator==(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iter> const &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator, class Iter>
	bool operator!=(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iter> const &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator, class Iter>
	bool operator<(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iter> const &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator, class Iter>
	bool operator>(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iter> const &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator, class Iter>
	bool operator<=(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iter> const &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator, class Iter>
	bool operator>=(ft::random_access_iterator<Iterator> const &lhs, ft::random_access_iterator<Iter> const &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	ft::random_access_iterator<Iterator> operator+(typename ft::random_access_iterator<Iterator>::difference_type n, ft::random_access_iterator<Iterator> const &lhs)
	{
		return (lhs + n);
	}
}

#endif