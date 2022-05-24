/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:10:26 by adlancel          #+#    #+#             */
/*   Updated: 2022/05/18 14:17:21 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
    template <typename T>
    class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
    {
    public:
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
        typedef T *pointer;
        typedef T &reference;

    private:
        pointer _elem;

    public:
        random_access_iterator()
            : _elem(0){}; // ctor

        random_access_iterator(pointer ptr)
            : _elem(ptr){};

        random_access_iterator(random_access_iterator<T> const &cpy)
            : _elem(cpy._elem){};

        virtual ~random_access_iterator(){};

        random_access_iterator &operator=(random_access_iterator<T> const &cpy)
        {
            if (this != &cpy)
                _elem = cpy._elem;
            return (*this);
        };
        // relationnal operators

        pointer operator->()
        {
            return (_elem);
        };

        reference operator*()
        {
            return (*_elem);
        };
        bool operator<(const random_access_iterator &src) const
        {
            return (_elem < src._elem);
        };
        bool operator>(const random_access_iterator &src) const
        {
            return (_elem > src._elem);
        };
        bool operator>=(const random_access_iterator &src) const
        {
            return (_elem >= src._elem);
        };
        bool operator<=(const random_access_iterator &src) const
        {
            return (_elem <= src._elem);
        };
        bool operator!=(const random_access_iterator &src) const
        {
            return (_elem != src._elem);
        };
        bool operator==(const random_access_iterator &src) const
        {
            return (_elem == src._elem);
        };
    };
}
#endif