/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:41:51 by adlancel          #+#    #+#             */
/*   Updated: 2022/05/18 13:46:54 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

    protected:
        Container c;

    public:
        // constructor
        explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {}
        stack(const stack &other) : c(other.c) {}
        virtual ~stack(){};
        bool empty() const
        {
            return (c.empty());
        };
        size_type size() const
        {
            return (c.size());
        };
        value_type &top()
        {
            return (c.back());
        };
        const value_type &top() const
        {
            return (c.back());
        };
        void push(const value_type &val)
        {
            c.push_back(val);
        };
        void pop()
        {
            c.pop_back();
        };
        // relational iterators
        template <class Ts, class ctn>
        friend bool operator==(const stack<Ts, ctn> &lhs, const stack<Ts, ctn> &rhs);
        template <class Ts, class ctn>
        friend bool operator!=(const stack<Ts, ctn> &lhs, const stack<Ts, ctn> &rhs);
        template <class Ts, class ctn>
        friend bool operator<(const stack<Ts, ctn> &lhs, const stack<Ts, ctn> &rhs);
        template <class Ts, class ctn>
        friend bool operator<=(const stack<Ts, ctn> &lhs, const stack<Ts, ctn> &rhs);
        template <class Ts, class ctn>
        friend bool operator>(const stack<Ts, ctn> &lhs, const stack<Ts, ctn> &rhs);
        template <class Ts, class ctn>
        friend bool operator>=(const stack<Ts, ctn> &lhs, const stack<Ts, ctn> &rhs);
    };
    template <class T, class Container>
    bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return (lhs.c == rhs.c);
    };
    template <class T, class Container>
    bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return (lhs.c != rhs.c);
    };
    template <class T, class Container>
    bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return (lhs.c < rhs.c);
    };
    template <class T, class Container>
    bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return (lhs.c <= rhs.c);
    };
    template <class T, class Container>
    bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return (lhs.c > rhs.c);
    };
    template <class T, class Container>
    bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return (lhs.c >= rhs.c);
    };

}

#endif