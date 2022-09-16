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
		explicit map(const Compare &comp,
					 const Allocator &alloc = Allocator());
		template <class InputIt>
		map(InputIt first, InputIt last,
			const Compare &comp = Compare(),
			const Allocator &alloc = Allocator());
		~map();
		map &operator=(const map &other);

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		std::pair<iterator, bool> insert(const value_type &value);
		iterator insert(iterator hint, const value_type &value);
		template <class InputIt>
		void insert(InputIt first, InputIt last);
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		size_type erase(const Key &key);
		void swap(map &other);
		size_type count(const Key &key) const;
		iterator find(const Key &key);
		const_iterator find(const Key &key) const;
		std::pair<iterator, iterator> equal_range(const Key &key);
		std::pair<const_iterator, const_iterator> equal_range(const Key &key) const;
		iterator lower_bound(const Key &key);
		const_iterator lower_bound(const Key &key) const;
		iterator upper_bound(const Key &key);
		const_iterator upper_bound(const Key &key) const;
		key_compare key_comp() const;

		void clear();
	};
}
#endif
