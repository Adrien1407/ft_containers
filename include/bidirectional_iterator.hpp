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
        bidirectional_iterator(node_ptr root, node_ptr base, node_ptr end) : _ptr(base), _null(end), _root(root){};
        // destructors
        virtual ~bidirectional_iterator(){};

        bidirectional_iterator &operator=(bidirectional_iterator const &cpy)
        {
            if (this != &cpy)
            {
                _ptr = cpy._ptr;
                _root = cpy._root;
                _null = cpy._null;
            }
            return (*this);
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
        pointer operator->()
        {
            return (&_ptr->data);
        }
        const_pointer operator->() const
        {
            return (&_ptr->data);
        }
        // increment and decrement
        bidirectional_iterator &operator++(void)
        {
            if (_ptr != _null)
                _ptr = next(_ptr);
            return (*this);
        }
        bidirectional_iterator &operator++(int)
        {
            bidirectional_iterator old(*this);
            this->operator++();
            return (old);
        }
        bidirectional_iterator &operator--(void)
        {
            if (_ptr != _null)
                _ptr = previous(_ptr);
            return (*this);
        }
        bidirectional_iterator &operator--(int)
        {
            bidirectional_iterator old(*this);
            this->operator--();
            return (old);
        }

        // comparision
        bool operator==(const bidirectional_iterator &lhs) const { return _ptr == lhs._ptr; }
        bool operator!=(const bidirectional_iterator &lhs) const { return _ptr != lhs._ptr; }

    private:
        node_ptr successor(node_ptr x)
        {
            if (x->right != _null)
            {
                return min(x->right);
            }

            node_ptr y = x->parent;
            while (y != _null && x == y->right)
            {
                x = y;
                y = y->parent;
            }
            return y;
        }

        node_ptr predecessor(node_ptr x)
        {
            if (x->left != _null)
            {
                return max(x->left);
            }

            node_ptr y = x->parent;
            while (y != _null && x == y->left)
            {
                x = y;
                y = y->parent;
            }

            return y;
        }
        node_ptr minimum(node_ptr node)
        {
            while (node->left != _null)
            {
                node = node->left;
            }
            return node;
        }

        node_ptr maximum(node_ptr node)
        {
            while (node->right != _null)
            {
                node = node->right;
            }
            return node;
        }
    };
    template <class Iter1, class Iter2>
    bool operator==(ft::bidirectional_iterator<Iter1, ft::Node<Iter1> > const &lhs, ft::bidirectional_iterator<Iter2, ft::Node<Iter2> > const &rhs)
    {
        return (lhs._ptr == rhs._ptr);
    }

    template <class Iter1, class Iter2>
    bool operator!=(ft::bidirectional_iterator<Iter1, ft::Node<Iter1> > const &lhs, ft::bidirectional_iterator<Iter2, ft::Node<Iter2> > const &rhs)
    {
        return (lhs._ptr != rhs._ptr);
    }
}