/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:41:47 by adlancel          #+#    #+#             */
/*   Updated: 2022/05/18 13:46:51 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"
#include "utils.hpp"

namespace ft
{
	template <class T, class Key>
	struct get_key : public std::unary_function<T, Key>
	{
		const Key &operator()(const T &x) const
		{
			return (x.first);
		}
	};
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef Node<value_type> node_type;
		typedef node_type *node_ptr;
		typedef typename ft::bidirectional_iterator<value_type, node_type> iterator;
		typedef typename ft::bidirectional_iterator<const value_type, const node_type> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef typename std::size_t size_type;

		typedef ft::RBtree<key_type, value_type, ft::selectFirst<value_type, key_type>, key_compare> tree_type;

	private:
		class value_compare
		{
		protected:
			Compare comp;

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			value_compare() : comp(Compare()) {}

			bool operator()(const value_type &lhs, const value_type &rhs) const
			{
				return comp(lhs.first, rhs.first);
			};
		};

	protected:
		allocator_type _alloc;
		key_compare _comp;
		tree_type _tree;
		value_compare _value_compare;

	public:
		map();
		explicit map(const Compare &comp = key_compare(), const Allocator &alloc = Allocator()) : _alloc(alloc), _key_compare(comp){};
		template <class InputIt>
		map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator()) : _alloc(alloc), _key_compare(comp), _value_compare(value_compare()), _tree()
		{
			insert(first, last);
		}
		map(const map &other) : _alloc(other._alloc), _key_compare(other._key_compare),
								_value_compare(other._value_compare)
		{
			insert(other.begin(), other.end());
		}
		virtual ~map(){};

		map &operator=(const map &other)
		{
			if (this != &cpy)
			{
				clear();
				_alloc = cpy._alloc;
				_comp = cpy._comp;
				this->insert(cpy.begin(), cpy.end());
			}
			return (*this);
		};
		allocator_type get_allocator() const
		{
			return _alloc;
		}
		iterator begin()
		{
			return iterator(_tree.get_root(), _tree._min(), _tree.get_end());
		};
		const_iterator begin() const;
		{
			return const_iterator(_tree.get_root(), _tree._min(), _tree.get_end());
		};

		iterator end()
		{
			return iterator(_tree.get_root(), _tree.get_end(), _tree.get_end());
		};
		const_iterator end() const
		{
			return (const_iterator(_tree.get_root(), _tree.get_end(), _tree.get_end()));
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
			return (reverse_iterator(end()));
		};
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(end()));
		};
		bool empty() const
		{
			return (_tree.size() == 0);
		};
		size_type size() const
		{
			return (_tree.size());
		};
		size_type max_size() const
		{
			return (_alloc.max_size());
		};
		void clear()
		{
			_tree.clear();
		}
		ft::pair<iterator, bool> insert(const value_type &value)
		{
			return (_tree.insert(value));
		}

		iterator insert(iterator hint, const value_type &value)
		{
			(void)hint;
			return insert(value).first;
		};
		template <class InputIt>
		void insert(InputIt first, InputIt last)
		{
			for (; first != last; ++first)
				_tree.insert_node(*first);
			return;
		};
		iterator erase(iterator pos)
		{
			this->erase((*pos).first);
		};
		iterator erase(iterator first, iterator last)
		{
			while (first != last)
				this->erase((*(first++)).first);
		};
		size_type erase(const Key &key)
		{
			if (_tree->erase(key))
				return 1;
			return 0;
		};
		void swap(map &other)
		{
			std::swap(_alloc, x._alloc);
			std::swap(_key_compare, x._key_compare);
			std::swap(_value_compare, x._value_compare);
			_tree.swap(x._tree);
		};
		size_type count(const Key &key) const
		{
			const_iterator beg = this->begin();
			const_iterator end = this->end();

			while (beg != end)
			{
				if ((*(beg++)).first == k)
					return (1);
			}
			return (0);
		};
		iterator find(const Key &key)
				{
			node_ptr tmp = _tree._search_node(k);
			if (tmp == _tree.get_end())
				return (end());
			return iterator(tmp, _tree.get_root(), _tree.get_end());
		};
		
		const_iterator find(const Key &key) const;
		ft::pair<iterator, iterator> equal_range(const Key &key);
		ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const;
		iterator lower_bound(const Key &key);
		const_iterator lower_bound(const Key &key) const;
		iterator upper_bound(const Key &key);
		const_iterator upper_bound(const Key &key) const;
		key_compare key_comp() const;
	};
}
#endif
