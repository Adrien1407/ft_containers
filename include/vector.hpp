/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:43:13 by adlancel          #+#    #+#             */
/*   Updated: 2022/06/07 16:14:46 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "iterator.hpp"
#include "ft_enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename ft::random_access_iterator<T> iterator;
		typedef typename ft::random_access_iterator<const T> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef typename std::size_t size_type;

	private:
		allocator_type _alloc;
		value_type *_ptr;
		size_type _capacity;
		size_type _size_container;

	public:
		// Constructors
		explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _ptr(0), _capacity(0), _size_container(0){

		};

		explicit vector(size_type n, const T &val = T(),
						const allocator_type &alloc = allocator_type()) : _alloc(alloc), _ptr(0), _capacity(n), _size_container(n)
		{
			_ptr = _alloc.allocate(n);
			for (size_t i = 0; i < n; i++)
			{
				_alloc.construct(_ptr + i, val);
			}
		};
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr_t) : _alloc(alloc)
		{

			difference_type n = ft::distance(first, last);
			_ptr = _alloc.allocate(n);
			_capacity = n;
			for (; first != last; first++)
				push_back(*first);
		};

		vector(vector const &x) : _alloc(allocator_type()), _ptr(0), _capacity(0), _size_container(0)
		{

			*this = x;
		};

		vector &operator=(vector<T, allocator_type> const &x)
		{
			
			if (this != &x)
			{
				clear();
				assign(x.begin(), x.end());
			}
			return (*this);
		};
		virtual ~vector(void)
		{

			clear();
			if (_capacity > 0)
				_alloc.deallocate(_ptr, _capacity);
		};
		// ITERATORS
		iterator begin()
		{
			return (iterator(_ptr));
		};
		const_iterator begin() const
		{
			return (const_iterator(_ptr));
		};

		iterator end()
		{
			return (iterator(_ptr + _size_container));
		};
		const_iterator end() const
		{
			return (const_iterator(_ptr + _size_container));
		};
		reverse_iterator rbegin()
		{
			return (reverse_iterator(end() - 1));
		};
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end() - 1));
		};
		reverse_iterator rend()
		{
			return (reverse_iterator(_ptr - 1));
		};
		const_reverse_iterator rend() const
		{
			return (const__reverse_iterator(_ptr - 1));
		};

		// capacity
		size_type size() const
		{
			return (_size_container);
		};
		size_type max_size() const
		{
			return (Allocator().max_size());
		};

		// void resize(std::size_t n, T val = T())
		// {

		// 	if (n == size())
		// 		return;

		// 	if (n > max_size())
		// 		throw(std::length_error("ft::vector::resize"));
		// 	if (n < size())
		// 	{
		// 		for (size_t i = n; i < _size_container; i++)
		// 		{
		// 			_alloc.destroy(_ptr + i);
		// 		}
		// 		_capacity = n;
		// 	}
		// 	else
		// 		insert(end(), n - this->size(), val);
		// };

		void resize(size_type n, value_type val = value_type())
		{
			if (n == size())
			{
				return;
			
			}
			if (n > max_size())
				throw(std::length_error("ft::vector::resize"));
			else if (n < size())
			{

				for (size_type i = n; i < _size_container; i++)
					_alloc.destroy(_ptr + i);
				_capacity = n;
			}
			else
			{

				reserve(n);
				for (size_type i = _size_container; i < n; i++)
					_alloc.construct(_ptr + i, val);
			}
			_size_container = n;
		};
		size_type capacity() const
		{
			return (_capacity);
		}
		bool empty() const
		{
			return (size() == 0);
		};

		void reserve(size_type n)
		{

			if (n > max_size())
				throw(std::length_error("vector::reserve"));
			if (n != 0 && n > _capacity)
			{
				value_type *tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _size_container; i++)
					_alloc.construct(&tmp[i], _ptr[i]);
				for (size_type i = 0; i < _size_container; i++)
					_alloc.destroy(&_ptr[i]);
				_alloc.deallocate(_ptr, _capacity);
				_capacity = n;
				_ptr = tmp;
			}
		};

		// Element Access
		reference operator[](size_type n)
		{
			return (_ptr[n]);
		};
		const_reference operator[](size_type n) const
		{
			return (_ptr[n]);
		};
		reference at(size_type n)
		{
			if (n >= size())
				throw(std::out_of_range("ft::vector::at"));
			else
				return (_ptr[n]);
		};
		const_reference at(size_type n) const
		{
			if (n >= size())
				throw(std::out_of_range("ft::vector::at"));
			else
				return (_ptr[n]);
		};

		reference front()
		{
			return (_ptr[0]);
		};
		const_reference front() const
		{
			return (_ptr[0]);
		};
		reference back()
		{
			return (_ptr[_size_container - 1]);
		};
		const_reference back() const
		{
			return (_ptr[_size_container - 1]);
		};
		// Modifiers

		template <class InputIterator>

		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr_t)
		{
			clear();
			if (_capacity)
				_alloc.deallocate(_ptr, _capacity);
			_size_container = 0;
			difference_type n = ft::distance(first, last);
			if (n > 0)
				_ptr = _alloc.allocate(n);
			_capacity = n;
			for (; first != last; first++)
				push_back(*first);
		};
		void assign(size_type n, const value_type &val)
		{
			clear();
			if (_capacity)
				_alloc.deallocate(_ptr, _capacity);
			_size_container = 0;
			if (n > 0)
				_ptr = _alloc.allocate(n);
			_capacity = n;
			for (size_t i = 0; i < n; i++)
				push_back(val);
		};
		void push_back(const value_type &val)
		{
			if (_size_container == _capacity)
			{
				if (empty())
					reserve(1);
				else
					reserve(size() * 2);
			}
			_alloc.construct(_ptr + _size_container, val);
			_size_container++;
		};
		void pop_back()
		{
			if (_size_container)
			{
				_alloc.destroy(_ptr + (_size_container - 1));
				_size_container--;
			}
		};
		iterator insert(iterator position, const value_type &val)
		{
			difference_type index = position - begin();
			insert(position, 1, val);
			return begin() + index;
		}

		void insert(iterator position, size_t n, const value_type &val)
		{
			difference_type index = position - begin();
			if (n + _size_container > _capacity)
			{
				size_t new_capacity = (2 * _capacity > n + _size_container) ? _size_container * 2 : n + _size_container;
				if (new_capacity > max_size())
					throw(std::length_error("vector::reserve"));
				else
				{
					value_type *prev_ptr = _ptr;
					size_type prev_size = _size_container;
					size_type prev_cap = _capacity;
					_ptr = _alloc.allocate(new_capacity);
					_capacity = new_capacity;
					difference_type i = 0;
					for (; i < index; i++)
						_alloc.construct(_ptr + i, *(prev_ptr + i));
					size_type j = i;
					for (size_t z = 0; z < n; z++)
					{
						_alloc.construct(_ptr + i, val);
						i++;
					}
					for (; j < prev_size; j++)
					{
						_alloc.construct(_ptr + i, *(prev_ptr + j));
						i++;
					}
					_alloc.deallocate(prev_ptr, prev_cap);
					_size_container += n;
				}
			}
			else
			{

				if (position == end())
				{
					for (size_t i = 0; i < n; i++)
						push_back(val);
				}
				else
				{
					difference_type ending = _size_container - 1;
					while (ending > index)
					{
						_alloc.construct(_ptr + n + ending, *(_ptr + ending));
						ending--;
					}
					_alloc.construct(_ptr + n + ending, *(_ptr + ending));
					size_t i = index;
					for (size_t z = 0; z < n; z++)
					{
						_alloc.construct(_ptr + i, val);
						i++;
					}
					_size_container += n;
				}
			}
		}

		// insert range (3)
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr_t)
		{
			size_type n = ft::distance(first, last);
			difference_type index = position - begin();
			if (n + _size_container > _capacity)
			{
				size_t new_capacity = (2 * _capacity > n + _size_container) ? _size_container * 2 : n + _size_container;
				if (new_capacity > max_size())
					throw(std::length_error("vector::reserve"));
				else
				{
					value_type *prev_ptr = _ptr;
					std::size_t prev_size = _size_container;
					std::size_t prev_capacity = _capacity;
					_ptr = _alloc.allocate(new_capacity);
					_capacity = new_capacity;
					difference_type i = 0;
					for (; i < index; i++)
						_alloc.construct(_ptr + i, *(prev_ptr + i));
					size_type z = i;
					for (; first != last; first++)
					{
						_alloc.construct(_ptr + (i++), *first);
					}
					for (; z < prev_size; z++)
					{
						_alloc.construct(_ptr + i, *(prev_ptr + z));
						i++;
					}
					_alloc.deallocate(prev_ptr, prev_capacity);
					_size_container += n;
				}
			}
			else
			{
				if (position == end())
				{
					for (; first != last; first++)
						push_back(*first);
				}
				else
				{
					difference_type i = index;
					difference_type ending = _size_container - 1;

					while (ending > index)
					{
						_alloc.construct(_ptr + ending + n, *(_ptr + ending));
						ending--;
					}
					_alloc.construct(_ptr + ending + n, *(_ptr + ending));
					i = index;
					for (; first != last; first++)
					{
						_alloc.construct(_ptr + (i++), *first);
					}
					_size_container += n;
				}
			}
		}

		iterator erase(iterator pos)
		{
			if (empty() || pos == end())
				return end();
			iterator it = begin();
			while (it != pos)
				it++;
			_alloc.destroy(&(*it));
			pointer tmp = &(*(it++));
			pointer ret = tmp;
			while (it != end())
			{
				_alloc.construct(tmp, *it);
				tmp = &(*(it++));
			}
			pop_back(); // destroy the last
			return iterator(ret);
		}

		iterator erase(iterator first, iterator last)
		{
			size_t nb = ft::distance(first, last);
			if (empty())
				return end();
			iterator it = begin();
			while (it != first)
				it++;
			iterator start = it;
			iterator dest = it;
			while (it != last && it != end())
				_alloc.destroy(&(*(it++)));
			while (it != end())
				_alloc.construct(&(*(start++)), *(it++));
			for (size_t i = 0; i < nb; i++)
				pop_back();
			return (dest);
		}

		void swap(vector &x)
		{
			pointer tmp_ptr = _ptr;
			allocator_type tmp_allocator_type = _alloc;
			size_t tmp_capacity = _capacity;
			size_t tmp_size_container = _size_container;

			_alloc = x._alloc;
			_ptr = x._ptr;
			_capacity = x._capacity;
			_size_container = x._size_container;

			x._alloc = tmp_allocator_type;
			x._ptr = tmp_ptr;
			x._capacity = tmp_capacity;
			x._size_container = tmp_size_container;
		}

		void clear()
		{
			for (iterator it = this->begin(); it != this->end(); ++it)
				_alloc.destroy(&(*it));
			_size_container = 0;
		};

		// Allocator
		allocator_type get_allocator() const
		{
			return (_alloc);
		};
	};

	template <class T, class Allocator>
	bool operator==(const ft::vector<T, Allocator> &x, const ft::vector<T, Allocator> &y)
	{
		return (x.size() == y.size() && std::equal(x.begin(), x.end(), y.begin()));
	};

	template <class T, class Allocator>
	bool operator!=(const ft::vector<T, Allocator> &x, const ft::vector<T, Allocator> &y)
	{
		return !(x == y);
	};

	template <class T, class Allocator>
	bool operator<(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	};

	template <class T, class Allocator> // a<=b	->	!(b < a)
	bool operator<=(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return (!(y < x));
	};

	template <class T, class Allocator> // a>b	->  b<a
	bool operator>(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return (y < x);
	};

	template <class T, class Allocator> // a>=b	->	!(a<b)
	bool operator>=(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return (!(x < y));
	};
	template <class T, class Allocator>
	void swap(vector<T, Allocator> &x, vector<T, Allocator> &y)
	{
		x.swap(y);
	};
}
#endif
