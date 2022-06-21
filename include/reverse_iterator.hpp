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
	template <class iterator>
		class reverse_iterator
		{
			public:
				typedef iterator iterator_type;
				typedef typename iterator_traits<iterator>::iterator_category iterator_category;
				typedef typename iterator_traits<iterator>::value_type value_type;
				typedef typename iterator_traits<iterator>::difference_type difference_type;
				typedef typename iterator_traits<iterator>::pointer pointer;
				typedef typename iterator_traits<iterator>::reference reference;

			protected:
				iterator_type _elem;

			public:
				reverse_iterator() : _elem() {}
				explicit reverse_iterator(iterator_type __x) : _elem(__x) {};
				reverse_iterator(const reverse_iterator &__x) : _elem(__x._elem) {};
				template <typename _Iter>
					reverse_iterator(const reverse_iterator<_Iter> &__x) : _elem(__x._elem) {};

				virtual ~reverse_iterator(){};
				
				template <typename _Iter>
				reverse_iterator &operator=(reverse_iterator<_Iter> const &cpy)
					{
						_elem = cpy._elem;
						return *this;
					};
				iterator_type base() const
				{
					return _elem;
				}
				reference operator*() const
				{
					iterator __tmp = _elem;
					return *__tmp;
				}
				pointer operator->() const
				{
					return &(operator*());
				}
				reverse_iterator &operator++()
				{
					_elem--;
					return *this;
				}
				reverse_iterator operator++(int)
				{
					reverse_iterator __tmp = *this;
					_elem--;
					return __tmp;
				}
				reverse_iterator &operator--()
				{
					_elem++;
					return *this;
				}
				reverse_iterator operator--(int)
				{
					reverse_iterator __tmp = *this;
					_elem++;
					return __tmp;
				}
				reverse_iterator operator+(difference_type __n) 
				{
				return reverse_iterator<iterator_type>(_elem - __n);
				}
				reverse_iterator &operator+=(difference_type __n) 
				{
					_elem -= __n;
					return *this;
				}
				reverse_iterator operator-(difference_type __n) 
				{
				return reverse_iterator<iterator_type>(_elem + __n);
				}
				reverse_iterator &operator-=(difference_type __n)
				{
					_elem += __n;
					return *this;
				}
				reference operator[](difference_type __n) const
				{
					return *(*this + __n);
				}
		};
	template <class iterator>
		bool operator<(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs)
		{
			return (lhs.base() > rhs.base());
		};
	template <class iterator>
		bool operator>(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs)
		{
			return (lhs.base() < rhs.base());
		};
	template <class iterator>
		bool operator>=(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs)
		{
			return (lhs.base() <= rhs.base());
		};
	template <class iterator>
		bool operator<=(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs)
		{
			return (lhs.base() >= rhs.base());
		};
	template <class iterator>
		bool operator!=(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs)
		{
			return (lhs.base() != rhs.base());
		};
	template <class iterator>
		bool operator==(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs)
		{
			return (lhs.base() == rhs.base());
		};
	template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
    {
        return (rev_it + n);
    };

    template <class Iter1, class Iter2>
    reverse_iterator<Iter1> operator+(typename reverse_iterator<Iter1>::difference_type n, const reverse_iterator<Iter2> &rev_it)
    {
        return (rev_it + n);
    };

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return ((rhs.base() - lhs.base()));
    };

    template <class Iterator1, class Iterator2>
    typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return ((rhs.base() - lhs.base()));
    };
}
#endif
