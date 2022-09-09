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
#include "ft_enable_if.hpp"
#include "ft_pair.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"

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

		typedef ft::RBTree<key_type, value_type, ft::selectFirst<value_type, key_type>, key_compare> tree_type;
		class value_compare;

	private:
		allocator_type _alloc;
		key_compare _comp;
		tree_type _tree;

	public:
	};
}
#endif
