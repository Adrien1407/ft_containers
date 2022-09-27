#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>
#include <memory>
#include "iterator.hpp"
#include "bidirectional_iterator.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"
#include "utils.hpp"

// 0 - Rules That Every RED-Black Tre00000000000000000000e Follows:
// 1 - Every node has a color either RED or black.
// 2 - The _root of the tree is always black.
// 3 - There are no two adjacent red nodes (A red node cannot have a red parent or red child).
// 4 - Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
// 5 - All leaf nodes are black nodes.

namespace ft
{
    template <class Key, class T, class selectFirst, class Compare = std::less<Key>, class Alloc = std::allocator<Node<T> > >
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
        RBtree(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _comp(comp), _alloc(alloc), _size(0)
        {
            _TNULL = _alloc.allocate(1);
            _alloc.construct(_TNULL, node_type(value_type(), NULL, NULL, NULL, BLACK));
            _root = _TNULL;
        }
        virtual ~RBtree()
        {
            clear_h(_root);
            _alloc.destroy(_TNULL);
            _alloc.deallocate(_TNULL, 1);
        }
        
        size_type get_size() const
        {
            return (this->_size);
        }
        node_ptr get_end() const
        {
            return (this->_TNULL);
        }
        node_ptr get_root() const
        {
            return (this->_root);
        }
        size_type max_size() const
        {
            return (_alloc.max_size());
        }
        node_ptr min(void) const
        {
            return min(_root);
        }

        node_ptr min(node_ptr node) const
        {
            if (node == _TNULL)
                return _root;
            while (node->left != _TNULL)
                node = node->left;
            return node;
        }

        node_ptr max(void) const
        {
            return max(_root);
        }

        node_ptr max(node_ptr node) const
        {
            if (node == _TNULL)
                return _root;
            while (node->right != _TNULL)
                node = node->right;
            return node;
        }
        node_ptr get_TNULL() const
        {
            return this->_TNULL;
        }
        void clear_h(node_ptr const &node)
        {
            clear(node);
            this->_root = _TNULL;
        }
        void clear(node_ptr const &node)
        {
            if (node == _TNULL)
                return;
            clear(node->left);
            clear(node->right);
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
            _size--;
        }
        void insertFix(node_ptr node)
        {
            node_ptr tmp;
            while (node->parent->color == RED)
            {
                if (node->parent == node->parent->parent->right)
                {
                    tmp = node->parent->parent->left;
                    if (tmp->color == RED)
                    {
                        tmp->color = BLACK;
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        node = node->parent->parent;
                    }
                    else
                    {
                        if (node == node->parent->left)
                        {
                            node = node->parent;
                            rightRotate(node);
                        }
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        leftRotate(node->parent->parent);
                    }
                }
                else
                {
                    tmp = node->parent->parent->right;

                    if (tmp->color == RED)
                    {
                        tmp->color = BLACK;
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        node = node->parent->parent;
                    }
                    else
                    {
                        if (node == node->parent->right)
                        {
                            node = node->parent;
                            leftRotate(node);
                        }
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        rightRotate(node->parent->parent);
                    }
                }
                if (node == _root)
                {
                    break;
                }
            }
            _root->color = BLACK;
        }
        void swap(RBtree &x)
		{
			std::swap(this->_root, x._root);
			std::swap(this->_TNULL, x._TNULL);
			std::swap(this->_size, x._size);
		}
    bool deleteNode(key_type key)
        {
            return (this->erase(key));

        }
        void deleteFix(node_ptr x)
        {
            node_ptr s;
            while (x != _root && x->color == BLACK)
            {
                if (x == x->parent->left)
                {
                    s = x->parent->right;
                    if (s->color == RED)
                    {
                        s->color = BLACK;
                        x->parent->color = RED;
                        leftRotate(x->parent);
                        s = x->parent->right;
                    }

                    if (s->left->color == BLACK && s->right->color == BLACK)
                    {
                        s->color = RED;
                        x = x->parent;
                    }
                    else
                    {
                        if (s->right->color == BLACK)
                        {
                            s->left->color = BLACK;
                            s->color = RED;
                            rightRotate(s);
                            s = x->parent->right;
                        }

                        s->color = x->parent->color;
                        x->parent->color = BLACK;
                        s->right->color = BLACK;
                        leftRotate(x->parent);
                        x = _root;
                    }
                }
                else
                {
                    s = x->parent->left;
                    if (s->color == RED)
                    {
                        s->color = BLACK;
                        x->parent->color = RED;
                        rightRotate(x->parent);
                        s = x->parent->left;
                    }

                    if (s->right->color == RED && s->right->color == RED)
                    {
                        s->color = BLACK;
                        x = x->parent;
                    }
                    else
                    {
                        if (s->left->color == RED)
                        {
                            s->right->color = RED;
                            s->color = BLACK;
                            leftRotate(s);
                            s = x->parent->left;
                        }

                        s->color = x->parent->color;
                        x->parent->color = RED;
                        s->left->color = RED;
                        rightRotate(x->parent);
                        x = _root;
                    }
                }
            }
            x->color = BLACK;
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
        node_ptr insert(const value_type &value)
        {
            node_ptr node;
            node = _alloc.allocate(1);
            _alloc.construct(node, node_type(value, ft_nullptr_t, _TNULL, _TNULL, RED));
            node_ptr y = ft_nullptr_t;
            node_ptr x = this->_root;

            while (x != _TNULL)
            {
                y = x;
                if (_comp(selectFirst()(node->data), selectFirst()(x->data)))
                    x = x->left;
                else if (_comp(selectFirst()(x->data), selectFirst()(node->data)))
                    x = x->right;
                else
                {
                    _alloc.destroy(node);
                    _alloc.deallocate(node, 1);
                    return (_TNULL);
                }
            }
            node->parent = y;
            if (y == ft_nullptr_t)
                _root = node;
            else if (_comp(selectFirst()(node->data), selectFirst()(y->data))) // place the new node at it's right placement
                y->left = node;
            else
                y->right = node;
            this->_size++;

            if (y == ft_nullptr_t)
            {
                node->color = BLACK;
                return (_root);
            }
            if (node->parent->parent == ft_nullptr_t)
                return (node);
            insertFix(node);
            return (node);
        }
        node_ptr search(node_ptr node, const key_type &key) const
        {
            if (node == _TNULL)
                return _TNULL;
            if (key == selectFirst()(node->data))
                return node;
            if (_comp(key, selectFirst()(node->data)))
                return (search(node->left, key));
            else
                return (search(node->right, key));
        }
        node_ptr search(const key_type &key) const
        {
            return search(_root, key);
        }
        void rbTransplant(node_ptr u, node_ptr v) // replaces u by v
        {
            if (u->parent == ft_nullptr_t)
                _root = v;
            else if (u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            v->parent = u->parent;
        }
        bool erase(key_type key)
        {
            node_ptr z, x, y;

            z = search(key);
            if (z == _TNULL)
                return false;

            y = z; // y saves the suppressed node's placement
            Color y_og_color = y->color;
            if (z->left == _TNULL) // z only had 1 child whitch is the right one so so it get's replaced by it's child
            {
                x = z->right; // x saves the right child's branch
                rbTransplant(z, z->right);
            }
            else if (z->right == _TNULL) // mirror case
            {
                x = z->left;
                rbTransplant(z, z->left);
            }
            else // suppressed node had 2 children and is replaced by the minimum of it's right branch
            {
                y = min(z->right); // search for the minimum in the right child's branch
                y_og_color = y->color;
                x = y->right;       // x saves the minimum's right branch
                if (y->parent == z) // the minimum is z->right
                    x->parent = y;
                else
                {
                    rbTransplant(y, y->right); // replaces the minimum by it's right branch
                    y->right = z->right;       // set the new z's right side
                    y->right->parent = y;
                }
                rbTransplant(z, y); // replace z by the correct value whitch is y and maintain the tree as a good search tree
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
            }
            _alloc.destroy(z);
            _alloc.deallocate(z, 1);
            _size--;
            if (y_og_color == BLACK) // fix the lost black color on x
                fixDelete(x);
            return true;
        }
        // fix the rb tree modified by the delete operation
        void fixDelete(node_ptr x)
        {
            node_ptr w;

            while (x != this->_root && x->color == BLACK)
            {
                if (x == x->parent->left) // if x is the left child
                {
                    w = x->parent->right; // w is x's right brother
                    if (w->color == RED)
                    {
                        w->color = BLACK;
                        x->parent->color = RED;
                        leftRotate(x->parent); // new parent is w, old parent p became w's left child, p is still x's parent and x->parent->right bacame old w->left
                        w = x->parent->right;
                    }

                    if (w->left->color == BLACK && w->right->color == BLACK)
                    {
                        w->color = RED;
                        x = x->parent;
                    }
                    else // at least one child is RED
                    {
                        if (w->right->color == BLACK) // left child is RED
                        {
                            w->left->color = BLACK;
                            w->color = RED;
                            rightRotate(w);
                            w = x->parent->right;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->right->color = BLACK;
                        leftRotate(x->parent);
                        x = _root;
                    }
                }
                else // mirror case
                {
                    w = x->parent->left;
                    if (w->color == RED)
                    {
                        w->color = BLACK;
                        x->parent->color = RED;
                        rightRotate(x->parent);
                        w = x->parent->left;
                    }

                    if (w->left->color == BLACK && w->right->color == BLACK)
                    {
                        w->color = RED;
                        x = x->parent;
                    }
                    else
                    {
                        if (w->left->color == BLACK)
                        {
                            w->right->color = BLACK;
                            w->color = RED;
                            leftRotate(w);
                            w = x->parent->left;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->left->color = BLACK;
                        rightRotate(x->parent);
                        x = _root;
                    }
                }
            }
            x->color = BLACK; // root always is black
        }
    };

}
#endif