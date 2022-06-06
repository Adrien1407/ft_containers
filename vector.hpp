/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:43:13 by adlancel          #+#    #+#             */
/*   Updated: 2022/06/06 16:26:11 by adlancel         ###   ########.fr       */
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
//#include "reverse_iterator.hpp"

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
				explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _ptr(0), _capacity(0), _size_container(0)
			{
			};

				explicit vector(size_type n, const T &val = T(),
						const allocator_type &alloc = allocator_type()) : _alloc(alloc), _ptr(0), _capacity(n),  _size_container(n)
			{
				_ptr = _alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
				{
					_alloc.construct(_ptr + i, val);
				}
			};
				template <class InputIterator>
				vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr_t) : _alloc(alloc){
				difference_type n = ft::distance(first, last);
				_ptr  = _alloc.allocate(n);
				_capacity = n;
						for (; first != last; first++)
								push_back(*first);
				};


				vector(const vector &x) : _alloc(allocator_type()), _ptr(0), _capacity(0), _size_container(0)
			{
				*this = x;
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
					return (iterator(_ptr) + _size_container);
				};
				const_iterator end() const
				{
					return (const_iterator(_ptr) + _size_container);
				};
				reverse_iterator rbegin()
				{
					return (reverse_iterator(_ptr) + _size_container);
				};
				const_reverse_iterator rbegin() const
				{
					return (const_reverse_iterator(_ptr) + _size_container);
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
				size_type max_size() const {
					return (Allocator().max_size());
				};
				void resize(size_type n, value_type val = value_type()){
					if (n == size())
						return ;
					if (n < size())
					{
						for (size_type i = 0; i < n; i++)
						{
							_alloc.destroy(_ptr + i);
						}
						_capacity = n;
					}
					else if (n > max_size())
						throw(std::length_error("ft::vector::resize"));
					else
					{
						reserve(n);
						for(size_type i = _size_container; i < n; i++)
							_alloc.construct(_ptr + i, val);
					}
				};
				size_type capacity() const
				{
					return (_capacity);
				};
				bool empty() const
				{
					return (size() == 0);
				};

				void reserve(size_type n){
					if (n > max_size())
						throw (std::length_error("ft::vector::reserve")); 
					else if (n > _capacity)
					{
						value_type	*prev_ptr = _ptr;
						std::size_t	prev_size = _size_container;
						std::size_t	prev_capacity = _capacity;
						_ptr = _alloc.allocate(n);
						_capacity = n;
						for (size_t i = 0; i < prev_size; i++)
							_alloc.construct(_ptr + i, *(prev_ptr + i));
						_alloc.deallocate(prev_ptr, prev_capacity);
					}

				};

				// Element Access
				reference operator[](size_type n){
					return (_ptr[n]);
				};
				const_reference operator[](size_type n) const {
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


					void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr_t) {
						clear();
						if (_capacity)
							_alloc.deallocate(_ptr, _capacity);
						_size_container = 0;

						difference_type n = ft::distance(first, last);
						_ptr = _alloc.allocate(n);
						_capacity = n;
						for(; first != last; first++)
						{
							_alloc.construct(_ptr + first, first.value_type());
							_size_container++;
						}
					};

				// void assign(size_type n, const value_type &val){

				// };
				void push_back(const value_type &val){
					if(_size_container == _capacity)
					{
						if (empty())
							reserve(1);
						else
							reserve(size() * 2);
					}
					_alloc.construct(_ptr + _size_container, val);
					_size_container++;
				};
				void pop_back(){
					if (_size_container)
					{
						_alloc.destroy(_ptr + (_size_container - 1));
						_size_container--;
					}
				};

					/*			iterator insert(iterator position, const value_type &val){

								};
								void insert(iterator position, size_type n, const value_type &val){

								};
								template <class InputIterator>
								void insert(iterator position, InputIterator first, InputIterator last){

								};
								iterator erase(iterator position){

								};
								iterator erase(iterator first, iterator last){

								};
								iterator erase(iterator position){

								};
								iterator erase(iterator first, iterator last){

								};
								void swap(vector &x){

								};
								*/
				void clear(){
					for(iterator it = this->begin(); it != this->end(); it++)
						_alloc.destroy(&(*it));
					_size_container = 0;
				};

				// Allocator
				allocator_type get_allocator() const {
					return (_alloc);
				};

		};
	// relationnal operators
	template <class T, class Alloc>
		bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			if (lhs.size() == rhs.size())
			{
				typename ft::vector<T>::const_iterator it1 = lhs.begin();
				typename ft::vector<T>::const_iterator it2 = rhs.begin();

				while (it1 != lhs.end())
				{
					if (it2 == rhs.end() || *it1 != *it2)
						return (false);
					it1++;
					it2++;
				}
			}
			return (true);
		};
	template <class T, class Alloc>
		bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (lhs != rhs);
		};
	template <class T, class Alloc>
		bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (lhs < rhs);
		};
	template <class T, class Alloc>
		bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (lhs <= rhs);
		};
	template <class T, class Alloc>
		bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (lhs > rhs);
		};
	template <class T, class Alloc>
		bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (lhs >= rhs);
		};
	// // SWAP
	// template <class T, class Alloc>
	// 	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y){

	// 	};

}
#endif
