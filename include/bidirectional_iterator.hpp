/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectionnal_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:34:14 by adlancel          #+#    #+#             */
/*   Updated: 2022/09/06 15:34:15 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BIDIRECTIONNAL_ITERATOR_HPP
#define BIDIRECTIONNAL_ITERATOR_HPP

#include "iterator.hpp"
#include "RBtree.hpp"
#include "utils.hpp"

namespace ft
{
    template <typename T, class N>
    class bidirectional_iterator : public iterator<ft::bidirectional_iterator_tag, T>
    {
    public:
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef const T &const_reference;
        typedef const T *const_pointer;
        typedef typename ft::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef N node_type;
        typedef N *node_ptr;

    private:
        node_ptr _ptr;
        node_ptr _root;
        node_ptr _null;

    public:
        // constructors
        bidirectional_iterator() : _ptr(ft_nullptr_t), _root(ft_nullptr_t), _null(ft_nullptr_t){};
        bidirectional_iterator(const bidirectional_iterator &cpy) : _ptr(cpy._ptr), _root(cpy._root), _null(cpy._null){};
        bidirectional_iterator(node_ptr root, node_ptr base, node_ptr end) : _ptr(base), _root(root), _null(end){};
        // destructors
         ~bidirectional_iterator(){};

        bidirectional_iterator &operator=(bidirectional_iterator const &cpy)
        {
            if (this != &cpy)
            {

                        std::cout << "here\n";

                _ptr = cpy._ptr;
                _root = cpy._root;
                _null = cpy._null;
            }
            return (*this);
        }
        operator bidirectional_iterator<value_type const, node_type const>() const
        {

            return bidirectional_iterator<value_type const, node_type const>(_root, _ptr, _null);
        }
        // access
        reference operator*()
        {
            return (_ptr->data);
        }
        const_reference operator*() const
        {
            return (_ptr->data);
        }
  		pointer operator->() { return &(operator*()); }

        const_pointer operator->() const
        {
            return (&_ptr->data);
        }
        // increment and decrement
        bidirectional_iterator &operator++(void)
        {
            if (_ptr != _null)
                _ptr = successor(_ptr);
            return (*this);
        }
        bidirectional_iterator operator++(int)
        {

            bidirectional_iterator old(*this);
            this->operator++();
            return (old);
        }
        bidirectional_iterator &operator--()
        {
            if (_ptr == _null)
                _ptr = max(_root);
            else
                _ptr = predecessor(_ptr);
            return (*this);
        }
        bidirectional_iterator operator--(int)
        {
            bidirectional_iterator tmp(*this);
            operator--();
            return tmp;
        }
        // comparision
        bool operator==(const bidirectional_iterator &lhs) const { return _ptr == lhs._ptr; }
        bool operator!=(const bidirectional_iterator &lhs) const { return _ptr != lhs._ptr; }

    protected:
        node_ptr successor(node_ptr x)
        {
            if (x->right != _null)
                return min(x->right);
            node_ptr y = x->parent;
            while (y != NULL && x == y->right)
            {
                x = y;
                y = y->parent;
            }
            if (y == NULL)
                return _null;
            return y;
        }

        node_ptr predecessor(node_ptr x)
        {
            if (x->left != _null)
                return max(x->left);
            node_ptr y = x->parent;
            while (y != _null && x == y->left)
            {
                x = y;
                y = y->parent;
            }
            return y;
        }
        node_ptr min(node_ptr node)
        {
            while (node->left != _null)
                node = node->left;
            return node;
        }

        node_ptr max(node_ptr node)
        {
            while (node->right != _null)
                node = node->right;
            return node;
        }
    };
    template <class Iter1, class Iter2>
    bool operator==(bidirectional_iterator<Iter1, Node<Iter1> > const &lhs, bidirectional_iterator<Iter2, Node<Iter2> > const &rhs)
    {
        return (lhs._ptr == rhs._ptr);
    }

    template <class Iter1, class Iter2>
    bool operator!=(bidirectional_iterator<Iter1, Node<Iter1> > const &lhs, bidirectional_iterator<Iter2, Node<Iter2> > const &rhs)
    {
        return (lhs._ptr != rhs._ptr);
    }
}
#endif