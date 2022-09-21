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
#include "RBtree.hpp"
#include "utils.hpp"

namespace ft
{
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
		key_compare _key_compare;
		tree_type _tree;
		value_compare _value_compare;

	public:
		explicit map(const Compare &comp = key_compare(), const Alloc &alloc = Alloc()) : _alloc(alloc), _key_compare(comp){};
		template <class InputIt>
		map(InputIt first, InputIt last, const Compare &comp = Compare(), const Alloc &alloc = Alloc()) : _alloc(alloc), _key_compare(comp), _value_compare(value_compare()), _tree()
		{
			insert(first, last);
		}
		map(const map &other) : _alloc(other._alloc), key_compare(other._key_compare),
								_value_compare(other._value_compare)
		{
			insert(other.begin(), other.end());
		}
		virtual ~map(){};

		map &operator=(const map &other)
		{
			if (this != &other)
			{
				clear();
				_alloc = other._alloc;
				_key_compare = other._key_compare;
				this->insert(other.begin(), other.end());
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
		const_iterator begin() const
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
			iterator it = find(value.first);
			if (it != end())
			{
				return (ft::pair<iterator, bool>(it, false));
			}
			else
			{
				_tree.insert(value);
				it = find(value.first);
				return (ft::pair<iterator, bool>(it, true));
			}
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
			std::swap(_alloc, other._alloc);
			std::swap(_key_compare, other._key_compare);
			std::swap(_value_compare, other._value_compare);
			_tree.swap(other._tree);
		};
		size_type count(const Key &key) const
		{
			const_iterator beg = this->begin();
			const_iterator end = this->end();

			while (beg != end)
			{
				if ((*(beg++)).first == key)
					return (1);
			}
			return (0);
		};
		iterator find(const Key &key)
		{
			node_ptr tmp = _tree.search(key);
			if (tmp == _tree.get_end())
				return (end());
			return iterator(tmp, _tree.get_root(), _tree.get_end());
		};
		iterator find(const Key &key) const
		{
			node_ptr tmp = _tree.search(key);
			if (tmp == _tree.get_end())
				return (end());
			return const_iterator(tmp, _tree.get_root(), _tree.get_end());
		};

		ft::pair<iterator, iterator> equal_range(const Key &key)
		{
			return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
		}
		ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const
		{
			return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
		}
		iterator lower_bound(const Key &key)
		{
			iterator beg = this->begin();
			iterator end = this->end();

			while (beg != end)
			{
				if (_key_compare((*beg).first, key) == false)
					break;
				beg++;
			}
			return (beg);
		};
		const_iterator lower_bound(const Key &key) const
		{
			iterator beg = this->begin();
			iterator end = this->end();

			while (beg != end)
			{
				if (_key_compare((*beg).first, key) == false)
					break;
				beg++;
			}
			return (beg);
		};
		iterator upper_bound(const Key &key)
		{
			iterator beg = this->begin();
			iterator end = this->end();

			while (beg != end)
			{
				if (_key_compare((*beg).first, key))
					break;
				beg++;
			}
			return (beg);
		}
		const_iterator upper_bound(const Key &key) const
		{
			iterator beg = this->begin();
			iterator end = this->end();

			while (beg != end)
			{
				if (_key_compare((*beg).first, key))
					break;
				beg++;
			}
			return (beg);
		};
		key_compare key_comp() const
		{
			return this->_key_compare;
		}

		value_compare value_comp() const
		{
			return this->_value_compare;
		}
	};
}
#endif
