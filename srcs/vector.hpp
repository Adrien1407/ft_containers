/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:43:13 by adlancel          #+#    #+#             */
/*   Updated: 2022/06/20 17:10:51 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "iterator.hpp"
#include "utils.hpp"
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
			// std::cout << "constructor1 \n";
		};

		explicit vector(size_type n, const T &val = T(),
						const allocator_type &alloc = allocator_type()) : _alloc(alloc), _capacity(n), _size_container(n)
		{
			// std::cout << "constructor2 \n";

			_ptr = _alloc.allocate(_capacity);
			for (size_t i = 0; i < n; i++)
			{
				_alloc.construct(&_ptr[i], val);
			}
		};
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr_t) : _alloc(alloc)
		{
			// std::cout << "constructor3 \n";

			difference_type n = ft::distance(first, last);
			_ptr = _alloc.allocate(n);
			_capacity = n;
			_size_container = 0;
			for (; first != last; first++)
				push_back(*first);
		};

		vector(vector const &x) : _alloc(allocator_type()), _ptr(0), _capacity(0), _size_container(0)
		{
			// std::cout << "constructor4 \n";

			insert(begin(), x.begin(), x.end());

		};

		vector &operator=(vector<T, allocator_type> const &x)
		{
			if (this != &x)
			{
				clear();
				insert(end(), x.begin(), x.end());
			}
			return (*this);
		};
		virtual ~vector(void)
		{
			for (size_t i = 0; i < _size_container; i++)
				_alloc.destroy(&_ptr[i]);
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
			return (reverse_iterator(end()));
		};
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		};
		reverse_iterator rend()
		{
			return (reverse_iterator(_ptr));
		};
		const_reverse_iterator rend() const
		{
			return (const__reverse_iterator(_ptr));
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
			}
			else
			{
				size_t new_capacity = 0;
				if (_capacity == 0)
					new_capacity = 1;
				else
					new_capacity = _size_container * 2;
				if (new_capacity < n)
					new_capacity = n;
				// std::cout << "call from resize()\n";
				reserve(new_capacity);
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
			// std::cout << "capacity from reserve au debut = "<< this->capacity() << std::endl;
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
				// std::cout << "capacity from reserve end = "<< this->capacity() << std::endl;
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
			difference_type n = ft::distance(first, last);
			if ((long)_capacity < n)
			{
				_alloc.deallocate(_ptr, _capacity);
				_ptr = _alloc.allocate(n);
				_capacity = n;
			}
			for (; first != last; first++)
				push_back(*first);
		};
		void assign(size_type n, const value_type &val)
		{
			clear();
			if (_capacity < n)
			{
				_alloc.deallocate(_ptr, _capacity);
				_ptr = _alloc.allocate(n);
				_capacity = n;
			}
			for (size_t i = 0; i < n; i++)
				push_back(val);
		};
		void push_back(const value_type &val)
		{
			// std::cout << "size, capacity from pushback begin = "<< this->size() << ", "<<this->capacity() << std::endl;

			if (_size_container == _capacity)
			{

				if (empty())
					reserve(1);
				else
					reserve(size() * 2);
			}
			_alloc.construct(_ptr + _size_container, val);
			_size_container++;
			// std::cout << "size, capacity from pushback end = "<< this->size() << ", "<<this->capacity() << std::endl;

		};
		void pop_back()
		{
			if (_size_container > 0)
			{
				// std::cout << "size = " << _size_container << std::endl;

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
		void insert(iterator pos, size_type count, const value_type &value)
		{
					// std::cout << "call from insert()\n";

			size_type index = pos - begin();
			if (!count)
				return;
		if (count + _size_container > _capacity)
{
			size_t new_capacity = 0;
			if (_capacity == 0)
				new_capacity = 1;
			else
				new_capacity = _size_container * 2;
			if (new_capacity < _size_container + count)
				new_capacity = _size_container + count;
			reserve(new_capacity); // (otherwhise iterator `pos` is invalidated)
}

			for (ptrdiff_t i = _size_container - 1; i >= (ptrdiff_t)index; i--)
			{
				// move elements count times to the right
				_alloc.construct(&_ptr[i + count], _ptr[i]); // copy constructor
				_alloc.destroy(&_ptr[i]);					// call destructor
			}

			for (size_type i = index; i < index + count; i++)
				_alloc.construct(&_ptr[i], value); // copy constructor

			_size_container += count;
		}
		
			// insert range (3)
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr_t)
		{

			size_type index = position - begin();
			difference_type count = ft::distance(first, last);
			if (!count)
				return;

		if (count + _size_container > _capacity)
		{
					// std::cout << "call from insert range()\n";

		size_t new_capacity = 0;
			if (_capacity == 0)
				new_capacity = 1;
			else
				new_capacity = _size_container * 2;
			if (new_capacity < _size_container + count)
				new_capacity = _size_container + count;
			reserve(new_capacity); 
		}
			for (ptrdiff_t i = _size_container - 1; i >= (ptrdiff_t)index; i--)
			{
				// move elements count times to the right
				_alloc.construct(&_ptr[i + count], _ptr[i]); // copy constructor
				_alloc.destroy(&_ptr[i]);					// call destructor
			}

			for (InputIterator ite = first; ite != last; ++ite)
				_alloc.construct(&_ptr[index++], *ite); // copy constructor

			_size_container += count;
		}
		iterator erase(iterator pos)
		{
			return (erase(pos, pos + 1));
		}

		iterator erase(iterator first, iterator last)
		{
			iterator tmp = first;

			iterator end = this->end();

			size_type deleted = ft::distance(first, last);

			while (last != end)
			{
				*first = *last;
				++first;
				++last;
			}
			while (deleted-- > 0)
				this->_alloc.destroy(&_ptr[--_size_container]);

			return (tmp);
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
			while (_size_container > 0)
				pop_back();
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
