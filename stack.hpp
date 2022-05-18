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
    template <class T, class Container = ft::vector<T>>

    class Stack
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

    private:
    public:
        // constructor
        explicit stack(const container_type &ctnr = container_type()){

        };
        bool empty() const {

        };
        size_type size() const {

        };
        value_type &top(){

        };
        const value_type &top() const {

        };
        void push(const value_type &val){

        };
        void pop(){

        };
        // relational iterators

        template <class T, class Container>
        bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs){

        };
        template <class T, class Container>
        bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs){

        };
        template <class T, class Container>
        bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs){

        };
        template <class T, class Container>
        bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs){

        };
        template <class T, class Container>
        bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs){

        };
        template <class T, class Container>
        bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs){

        };
    };
}

#endif