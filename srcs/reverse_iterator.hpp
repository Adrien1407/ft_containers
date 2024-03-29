/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:09:03 by adlancel          #+#    #+#             */
/*   Updated: 2022/06/09 17:32:04 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    protected:
        Iterator _ptr;

    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        typedef typename iterator_traits<Iterator>::reference reference;
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;

        reverse_iterator(void) : _ptr() {}
        explicit reverse_iterator(Iterator it) : _ptr(it) {}
        template <class U>
        reverse_iterator(reverse_iterator<U> const &other) : _ptr(other.base()){};

        virtual ~reverse_iterator(void){};
        template <class U>
        reverse_iterator &operator=(reverse_iterator<U> const &other)
        {
            _ptr = other.base();
            return (*this);
        }

        // getter
        iterator_type base(void) const
        {
            return _ptr;
        }

        // Deferencement
        reference operator*() const
        {
            Iterator tmp = _ptr;
            return (*--tmp);
        }
        // ->
        pointer operator->() const
        {
            return &(this->operator*());
        }

        // operator[]
        reference operator[](difference_type op) const
        {
            return base()[-op - 1];
        }

        // increments
        reverse_iterator &operator++(void)
        {
            _ptr--;
            return (*this);
        };
        reverse_iterator operator++(int)
        {
            reverse_iterator old = *this;
            _ptr--;
            return (old);
        }
        reverse_iterator &operator--(void)
        {
            _ptr++;
            return (*this);
        };
        reverse_iterator operator--(int)
        {
            reverse_iterator old = *this;
            _ptr++;
            return (old);
        }

        // +/-
        reverse_iterator operator+(difference_type op) const { return (reverse_iterator<iterator_type>(_ptr - op)); }
        reverse_iterator operator-(difference_type op) const { return (reverse_iterator<iterator_type>(_ptr + op)); }
        difference_type operator+(const Iterator &src) const { return (_ptr - src._ptr); }
        difference_type operator-(const Iterator &src) const { return (_ptr + src._ptr); }

        //+= -= operators
        reverse_iterator &operator+=(difference_type op)
        {
            _ptr -= op;
            return (*this);
        }
        reverse_iterator &operator-=(difference_type op)
        {
            _ptr += op;
            return (*this);
        }

        difference_type _comp(const reverse_iterator<Iterator> rhs) const
        {
            return (rhs.base() - this->_ptr);
        }
    };

    // Non member functions : comparaison operators overloads
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
    {
        return (rev_it + n);
    }

    template <class Iter1, class Iter2>
    reverse_iterator<Iter1> operator+(typename reverse_iterator<Iter1>::difference_type n, const reverse_iterator<Iter2> &rev_it)
    {
        return (rev_it + n);
    }

    /*                -                 */
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs._comp(rhs));
    }

    template <class Iterator, class Iter>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iter> &rhs)
    {
        return (lhs._comp(rhs));
    }
} // ft
#endif