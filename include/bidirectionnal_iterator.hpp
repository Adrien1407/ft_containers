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

#include <iostream>
#include "iterator.hpp"
#include "ft_enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"
#include "RBtree.hpp"

namespace ft
{

    template <typename T, class N>
    class bidirectionnal_iterator : public iterator<ft::bidirectional_iterator_tag, T>
    {
    public:
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef const T &const_reference;
        typedef const T *const_pointer;
        typedef typename bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef N node_type;
        typedef N *node_ptr;

    private:
        node_ptr _ptr;
        node_ptr _root;
        node_ptr _null;

    public:
        // constructors
        bidirectional_iterator() : _ptr(ft_nullptr_t), _root(ft_nullptr_t), _nill(ft_nullptr_t){};
        bidirectional_iterator(const bidirectional_iterator &cpy) : _ptr(cpy._ptr), _root(cpy._root), _nill(cpy._nill){};
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
        bool operator==(const bidirectional_iterator &lhs)
        {
            return _ptr == lhs._ptr;
        }
        bool operator!=(const bidirectional_iterator &lhs)
        {
            return _ptr != lhs._ptr;
        }
        // comparision
        template <class Iter1, class Iter2>
        friend bool operator==(ft::bidirectional_iterator<Iter1, Node<Iter1>> const &lhs, ft::bidirectional_iterator<Iter2, Node<Iter2>> const &rhs);

        template <class Iter1, class Iter2>
        friend bool operator!=(ft::bidirectional_iterator<Iter1, Node<Iter1>> const &lhs, ft::bidirectional_iterator<Iter2, Node<Iter2>> const &rhs);

    private:
        node_ptr next(node_ptr node)
        {
            if (node->right != _null)
                return (min(node->right));
            node_ptr n = node->parent;
            while (n != NULL &&node = n->right)
            {
                node = n;
                n = n->parent;
            }
            if (y == NULL)
                return _null;
            return (n);
        }
        node_ptr previous(node_ptr node)
        {
            if (node->left != _null)
                return (max(node->left));
            node_ptr n = node->parent;
            while (n != NULL && node == n->left)
            {
                node = n;
                n = n->parent;
            }
            return (n);
        }
    };
    template <class Iter1, class Iter2>
    bool operator==(ft::bidirectionnal_iterator<Iter1, Node<Iter1>> const &lhs, ft::bidirectionnal_iterator<Iter2, Node<Iter2>> const &rhs)
    {
        return (lhs._ptr == rhs._ptr);
    };
    template <class Iter1, class Iter2>
    bool operator!=(ft::bidirectionnal_iterator<Iter1, Node<Iter1>> const &lhs, ft::bidirectionnal_iterator<Iter2, Node<Iter2>> const &rhs)
    {
        return (lhs._ptr != rhs._ptr);
    };
}