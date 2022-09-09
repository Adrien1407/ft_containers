/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:56:08 by adlancel          #+#    #+#             */
/*   Updated: 2022/09/06 14:56:13 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <memory>
#include "iterator.hpp"
#include "ft_enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"

// Rules That Every Red-Black Tree Follows:
// 1 - Every node has a color either red or black.
// 2 - The root of the tree is always black.
// 3 - There are no two adjacent red nodes (A red node cannot have a red parent or red child).
// 4 - Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
// 5 - All leaf nodes are black nodes.

namespace ft
{
    enum Color
    {
        BLACK,
        RED
    };
    template <typename T>
    class Node
    {
    private:
        T data;
        Color color;
        Node *left;
        Node *right;
        Node *parent;

    public:
        Node(T data, Node *parent, Node *left, Node *right, Color color) : data(data), parent(parent), left(left), right(right), color(color) {}
    };

    template <class Key, class T, class get_key_from_val, class Compare = std::less<Key>, class Alloc = std::allocator<Node<T>>>
    class RBtree
    {
    public:
        typedef T value_type;
        typedef Key key_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef Node<value_type> node_type;
        typedef Node<value_type> *node_ptr;
        typedef std::size_t size_type;

        ~RBtree();

    private:
        node_ptr _root;
        node_ptr _end;
        key_compare _comp;
        allocator_type _alloc;
        size_type _size;

    public:
        RBtree(allocator_type alloc = allocator_type()) : _root(NULL), _end(NULL), _comp(key_compare()), _alloc(alloc), _size(0)
        {
            _end = alloc.allocate(1);
            _alloc.construct(_end, node_type(value_type(), NULL, NULL, NULL, BLACK));
            _root = _end;
        }
        virtual ~RBTree()
        {
            clear(_root);
            _root = _end;
            _alloc.destroy(_end);
            _alloc.deallocate(_end, 1);
        }
        void clear(node_ptr const &node)
        {
            if (node == _end)
                return; // stop of recursive
            clear(node->left);
            clear(node->right);

            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
            _size--;
        }
    };
}
#endif