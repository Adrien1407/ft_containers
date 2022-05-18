/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:09:03 by adlancel          #+#    #+#             */
/*   Updated: 2022/05/18 16:44:50 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
    template <typename T>
    class reverse_iterator
        : public iterator<typename iterator_traits<_Iterator>::iterator_category,
                          typename iterator_traits<_Iterator>::value_type,
                          typename iterator_traits<_Iterator>::difference_type,
                          typename iterator_traits<_Iterator>::pointer,
                          typename iterator_traits<_Iterator>::reference>
    {
    protected:
        _Iterator current;
        typedef iterator_traits<_Iterator> __traits_type;

    public:
        typedef _Iterator iterator_type;
        typedef typename __traits_type::difference_type difference_type;
        typedef typename __traits_type::pointer pointer;
        typedef typename __traits_type::reference reference;

        reverse_iterator() : current() {}

        explicit reverse_iterator(iterator_type __x) : current(__x) {}
        reverse_iterator(const reverse_iterator &__x) : current(__x.current) {}
        template <typename _Iter>
        reverse_iterator(const reverse_iterator<_Iter> &__x) : current(__x.base()) {}
        iterator_type base() const
        {
            return current;
        }
        reference operator*() const
        {
            _Iterator __tmp = current;
            return *--__tmp;
        }
        pointer operator->() const
        {
            return &(operator*());
        }
        reverse_iterator &operator++()
        {
            --current;
            return *this;
        }
        reverse_iterator operator++(int)
        {
            reverse_iterator __tmp = *this;
            --current;
            return __tmp;
        }
        reverse_iterator &operator--()
        {
            ++current;
            return *this;
        }
        reverse_iterator operator--(int)
        {
            reverse_iterator __tmp = *this;
            ++current;
            return __tmp;
        }
        reverse_iterator operator+(difference_type __n) const
        {
            return reverse_iterator(current - __n);
        }
        reverse_iterator &operator+=(difference_type __n)
        {
            current -= __n;
            return *this;
        }
        reverse_iterator operator-(difference_type __n) const
        {
            return reverse_iterator(current + __n);
        }
        reverse_iterator &operator-=(difference_type __n)
        {
            current += __n;
            return *this;
        }
        reference operator[](difference_type __n) const
        {
            return *(*this + __n);
        }
    };

}
#endif