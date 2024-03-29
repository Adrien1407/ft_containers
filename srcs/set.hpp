/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:41:47 by adlancel          #+#    #+#             */
/*   Updated: 2022/10/13 17:46:44 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include "iterator.hpp"
#include "random_access_iterator.hpp"
#include "RBtree.hpp"

#include "reverse_iterator.hpp"
#include "utils.hpp"

namespace ft
{
    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set
    {
    public:
        typedef T key_type;
        typedef T value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef Alloc allocator_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef Node<value_type> node_type;
        typedef node_type *node_ptr;
        typedef typename ft::bidirectional_iterator<const value_type, const node_type> iterator;
        typedef typename ft::bidirectional_iterator<const value_type, const node_type> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename std::size_t size_type;

        typedef ft::RBtree<key_type, value_type, ft::_selectFirst<value_type, key_type>, key_compare, Alloc> tree_type;

    protected:
        allocator_type _alloc;
        key_compare _key_compare;
        tree_type _tree;
        value_compare _value_compare;

    public:
        explicit set(const Compare &comp = key_compare(), const Alloc &alloc = Alloc()) : _alloc(alloc), _key_compare(comp), _tree(){};
        template <class InputIt>
        set(InputIt first, InputIt last, const Compare &comp = Compare(), const Alloc &alloc = Alloc()) : _alloc(alloc), _key_compare(comp), _tree()
        {
            insert(first, last);
        }
        set(const set &other) : _alloc(other._alloc), _key_compare(other._key_compare),
                                _value_compare(other._value_compare)
        {

            insert(other.begin(), other.end());
        }

        virtual ~set(){};

        set &operator=(const set &other)
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
        value_type &operator[](const value_type &k)
        {
            node_ptr val = _tree.search(k);

            if (val != _tree.get_end())
                return (val->data.second);
            else
            {
                _tree.insert(value_type(k, value_type())); // insert returns a pair an first element of pair is an it
                val = _tree.search(k);
                return (val->data.second);
            }
        }
        allocator_type get_allocator() const
        {
            return _alloc;
        }
        iterator begin()
        {
            return iterator(_tree.get_root(), _tree.min(), _tree.get_end());
        };
        const_iterator begin() const
        {
            return const_iterator(_tree.get_root(), _tree.min(), _tree.get_end());
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
            return (reverse_iterator(begin()));
        };
        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(begin()));
        };
        bool empty() const
        {
            return (_tree.get_size() == 0);
        };
        size_type size() const
        {
            return (_tree.get_size());
        };
        size_type max_size() const
        {
            return (_tree.max_size());
        };
        void clear()
        {
            _tree.clear_h(_tree.get_root());
        }
        ft::pair<iterator, bool> insert(const value_type &value)
        {
            iterator it = find(value);
            if (it != end())
            {
                return (ft::pair<iterator, bool>(it, false));
            }
            else
            {
                _tree.insert(value);
                it = find(value);
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
                insert(*first);
            return;
        };
        void erase(iterator pos)
        {
            this->erase((*pos));
        };
        void erase(iterator first, iterator last)
        {
            while (first != last)
            {
                this->erase((*(first++)));
            }
        };
        size_type erase(const value_type &k)
        {
            if (_tree.deleteNode(k) == true)
                return 1;
            return 0;
        };
        void swap(set &other)
        {
            _tree.swap(other._tree);
        };
        size_type count(const value_type &key) const
        {
            const_iterator beg = this->begin();
            const_iterator end = this->end();

            while (beg != end)
            {
                if ((*(beg++)) == key)
                    return (1);
            }
            return (0);
        };
        iterator find(const value_type &key)
        {
            node_ptr tmp = _tree.search(key);
            if (tmp == _tree.get_end())
                return (end());
            return iterator(_tree.get_root(), tmp, _tree.get_end());
        };
        const_iterator find(const value_type &key) const
        {
            node_ptr tmp = _tree.search(key);
            if (tmp == _tree.get_end())
                return (end());
            return const_iterator(_tree.get_root(), tmp, _tree.get_end());
        };

        ft::pair<iterator, iterator> equal_range(const value_type &key)
        {
            return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
        }
        ft::pair<const_iterator, const_iterator> equal_range(const value_type &key) const
        {
            return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
        }

        iterator lower_bound(const value_type &k)
        {
            iterator beg = this->begin();
            iterator end = this->end();

            while (beg != end)
            {
                if (_key_compare((*beg), k) == false)
                    break;
                beg++;
            }
            return (beg);
        }

        const_iterator lower_bound(const value_type &k) const
        {
            const_iterator beg = this->begin();
            const_iterator end = this->end();

            while (beg != end)
            {
                if (_key_compare((*beg), k) == false)
                    break;
                beg++;
            }
            return (beg);
        }

        iterator upper_bound(const value_type &key)
        {
            iterator beg = this->begin();
            iterator end = this->end();

            while (beg != end)
            {
                if (_key_compare(key, (*beg)))
                    break;
                beg++;
            }
            return (beg);
        }
        const_iterator upper_bound(const value_type &key) const
        {
            const_iterator beg = this->begin();
            const_iterator end = this->end();

            while (beg != end)
            {
                if (_key_compare(key, (*beg)))
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
            return this->_key_compare;
        }
    };
    template <class T, class Compare, class Alloc>
    void swap(ft::set<T, Compare, Alloc> &lhs,
              ft::set<T, Compare, Alloc> &rhs)
    {
        lhs.swap(rhs);
    }
    template <class T, class Compare, class Alloc>
    bool operator==(const ft::set<T, Compare, Alloc> &lhs,
                    const ft::set<T, Compare, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        return std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <class T, class Compare, class Alloc>
    bool operator!=(const ft::set<T, Compare, Alloc> &lhs,
                    const ft::set<T, Compare, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Compare, class Alloc>
    bool operator<(const ft::set<T, Compare, Alloc> &lhs,
                   const ft::set<T, Compare, Alloc> &rhs)
    {
        return ft::lexicographical_compare(
            lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Compare, class Alloc>
    bool operator<=(const ft::set<T, Compare, Alloc> &lhs,
                    const ft::set<T, Compare, Alloc> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T, class Compare, class Alloc>
    bool operator>(const ft::set<T, Compare, Alloc> &lhs,
                   const ft::set<T, Compare, Alloc> &rhs)
    {
        return rhs < lhs;
    }

    template <class T, class Compare, class Alloc>
    bool operator>=(const ft::set<T, Compare, Alloc> &lhs,
                    const ft::set<T, Compare, Alloc> &rhs)
    {
        return !(lhs < rhs);
    };
}
#endif
