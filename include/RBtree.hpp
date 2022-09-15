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
#include "bidirectional_iterator.hpp"
#include "ft_enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"

// Rules That Every Red-Black Tree Follows:
// 1 - Every node has a color either red or black.
// 2 - The _root of the tree is always black.
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
    struct Node
    {
        T data;
        Color color;
        Node *left;
        Node *right;
        Node *parent;

        Node(T data, Node *parent, Node *left, Node *right, Color color) : data(data), parent(parent), left(left), right(right), color(color) {}
    };

    template <class Key, class T, class get_key_from_val, class Compare = std::less<Key>, class Alloc = std::allocator<Node<T> > >
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

    private:
        node_ptr _root;
        node_ptr _TNULL;
        key_compare _comp;
        allocator_type _alloc;
        size_type _size;

    public:
        RBtree(allocator_type alloc = allocator_type()) : _root(NULL), _TNULL(NULL), _comp(key_compare()), _alloc(alloc), _size(0)
        {
            _TNULL = alloc.allocate(1);
            _alloc.construct(_TNULL, node_type(value_type(), NULL, NULL, NULL, BLACK));
            _root = _TNULL;
        }
        virtual ~RBtree()
        {
            clear(_root);
            _root = _TNULL;
            _alloc.destroy(_TNULL);
            _alloc.deallocate(_TNULL, 1);
        }
        void clear(node_ptr const &node)
        {
            if (node == _TNULL)
                return; // stop of recursive
            clear(node->left);
            clear(node->right);

            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
            _size--;
        }
        void initializeNode(node_ptr node, node_ptr parent)
        {
            node->data = 0;
            node->parent = parent;
            node->left = ft_nullptr_t;
            node->right = ft_nullptr_t;
            node->color = 0;
        }
        void insertFix(node_ptr k)
        {
            node_ptr u;
            while (k->parent->color == 1)
            {
                if (k->parent == k->parent->parent->right)
                {
                    u = k->parent->parent->left;
                    if (u->color == 1)
                    {
                        u->color = 0;
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        k = k->parent->parent;
                    }
                    else
                    {
                        if (k == k->parent->left)
                        {
                            k = k->parent;
                            rightRotate(k);
                        }
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        leftRotate(k->parent->parent);
                    }
                }
                else
                {
                    u = k->parent->parent->right;

                    if (u->color == 1)
                    {
                        u->color = 0;
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        k = k->parent->parent;
                    }
                    else
                    {
                        if (k == k->parent->right)
                        {
                            k = k->parent;
                            leftRotate(k);
                        }
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        rightRotate(k->parent->parent);
                    }
                }
                if (k == _root)
                {
                    break;
                }
            }
            _root->color = 0;
        }
        void deleteFix(node_ptr x)
        {
            node_ptr s;
            while (x != _root && x->color == 0)
            {
                if (x == x->parent->left)
                {
                    s = x->parent->right;
                    if (s->color == 1)
                    {
                        s->color = 0;
                        x->parent->color = 1;
                        leftRotate(x->parent);
                        s = x->parent->right;
                    }

                    if (s->left->color == 0 && s->right->color == 0)
                    {
                        s->color = 1;
                        x = x->parent;
                    }
                    else
                    {
                        if (s->right->color == 0)
                        {
                            s->left->color = 0;
                            s->color = 1;
                            rightRotate(s);
                            s = x->parent->right;
                        }

                        s->color = x->parent->color;
                        x->parent->color = 0;
                        s->right->color = 0;
                        leftRotate(x->parent);
                        x = _root;
                    }
                }
                else
                {
                    s = x->parent->left;
                    if (s->color == 1)
                    {
                        s->color = 0;
                        x->parent->color = 1;
                        rightRotate(x->parent);
                        s = x->parent->left;
                    }

                    if (s->right->color == 0 && s->right->color == 0)
                    {
                        s->color = 1;
                        x = x->parent;
                    }
                    else
                    {
                        if (s->left->color == 0)
                        {
                            s->right->color = 0;
                            s->color = 1;
                            leftRotate(s);
                            s = x->parent->left;
                        }

                        s->color = x->parent->color;
                        x->parent->color = 0;
                        s->left->color = 0;
                        rightRotate(x->parent);
                        x = _root;
                    }
                }
            }
            x->color = 0;
        }
        void leftRotate(node_ptr x)
        {
            node_ptr y = x->right;
            x->right = y->left;
            if (y->left != _TNULL)
            {
                y->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == ft_nullptr_t)
            {
                this->_root = y;
            }
            else if (x == x->parent->left)
            {
                x->parent->left = y;
            }
            else
            {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }
        void rightRotate(node_ptr x)
        {
            node_ptr y = x->left;
            x->left = y->right;
            if (y->right != _TNULL)
            {
                y->right->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == ft_nullptr_t)
            {
                this->_root = y;
            }
            else if (x == x->parent->right)
            {
                x->parent->right = y;
            }
            else
            {
                x->parent->left = y;
            }
            y->right = x;
            x->parent = y;
        }
        void insert(const value_type &value)
        {
            node_ptr node;
            node->parent = ft_nullptr_t;
            node->data = value;
            node->left = _TNULL;
            node->right = _TNULL;
            node->color = 1;

            node_ptr y = ft_nullptr_t;
            node_ptr x = this->_root;

            while (x != _TNULL)
            {
                y = x;
                if (node->data < x->data)
                {
                    x = x->left;
                }
                else
                {
                    x = x->right;
                }
            }

            node->parent = y;
            if (y == ft_nullptr_t)
            {
                _root = node;
            }
            else if (node->data < y->data)
            {
                y->left = node;
            }
            else
            {
                y->right = node;
            }

            if (node->parent == ft_nullptr_t)
            {
                node->color = 0;
                return;
            }

            if (node->parent->parent == ft_nullptr_t)
            {
                return;
            }

            insertFix(node);
        }
    };

}
#endif