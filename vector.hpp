/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:43:13 by adlancel          #+#    #+#             */
/*   Updated: 2022/05/18 16:52:23 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "iterator.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
    template <class T, class Allocator = std::allocator<T>>
    class vector
    {
    public:
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::random_access_iterator<T> iterator;
        typedef typename ft::const_iterator const_iterator;
        typedef typename ft::reverse_iterator reverse_iterator;
        typedef typename ft::const_reverse_iterator const_reverse_iterator;
        typedef typename ft::difference_type difference_type;
        typedef typename ft::size_type size_type;

    private:
        allocator_type _alloc;
        value_type *_ptr;
        size_type _capacity;
        size_type _size_container;

    public:
        // Constructors
        explicit vector(const allocator_type &alloc = allocator_type()){

        };

        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type()){

        };
        template <class InputIterator>
        vector(InputIterator first, InputIterator last,
               const allocator_type &alloc = allocator_type()){

        };
        vector(const vector &x){

        };

        // ITERATORS
        iterator begin()
        {
            return (iterator(_ptr));
        };
        const_iterator begin() const
        {
            return (const_iterator(_ptr));
        };
        iterator end()
        {
            return (iterator(_ptr) + _size_container);
        };
        const_iterator end() const
        {
            return (const_iterator(_ptr) + _size_container);
        };
        reverse_iterator rbegin()
        {
            return (reverse_iterator(_ptr) + _size_container);
        };
        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(_ptr) + _size_container);
        };
        reverse_iterator rend()
        {
            return (reverse_iterator(_ptr));
        };
        const_reverse_iterator rend() const
        {
            return (const__reverse_iterator(_ptr));
        };

        // capacity
        size_type size() const
        {
            return (_size_container);
        };
        size_type max_size() const {

        };
        void resize(size_type n, value_type val = value_type()){

        };
        size_type capacity() const
        {
            return (_capacity);
        };
        bool empty() const
        {
            return (size() == 0 ? true : false);
        };
        void reserve(size_type n){

        };
        // Element Access
        reference operator[](size_type n){

        };
        const_reference operator[](size_type n) const {

        };
        reference at(size_type n)
        {
            if (n >= size())
                throw(std::out_of_range("ft::vecotr::at")));
            else
                return ((*this)[n]);
        };
        const_reference at(size_type n) const
        {
            if (n >= size())
                throw(std::out_of_range("ft::vecotr::at")));
            else
                return ((*this)[n]);
        };
        reference front()
        {
            return ((*this)[0]);
        };
        const_reference front() const
        {
            return ((*this)[0]);
        };
        reference back()
        {
            return ((*this)[_size_container - 1]);
        };
        const_reference back() const
        {
            return ((*this)[_size_container - 1]);
        };
        // Modifiers

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last){

        };

        void assign(size_type n, const value_type &val){

        };
        void push_back(const value_type &val){

        };
        void pop_back(){

        };
        iterator insert(iterator position, const value_type &val){

        };
        void insert(iterator position, size_type n, const value_type &val){

        };
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last){

        };
        iterator erase(iterator position){

        };
        iterator erase(iterator first, iterator last){

        };
        iterator erase(iterator position){

        };
        iterator erase(iterator first, iterator last){

        };
        void swap(vector &x){

        };
        void clear(){

        };
        // Allocator
        allocator_type get_allocator() const {

        };
        // relationnal operators
        template <class T, class Alloc>
        bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            if (lhs.size() == rhs.size())
                if (lhs.begin() == rhs.begin())
                    if (lhs.end() == rhs.end())
                        return (true);
            return (false);
        };
        template <class T, class Alloc>
        bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            return (lhs != rhs ? true : false);
        };
        template <class T, class Alloc>
        bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            return (lhs < rhs ? true : false);
        };
        template <class T, class Alloc>
        bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            return (lhs <= rhs ? true : false);
        };
        template <class T, class Alloc>
        bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            return (lhs > rhs ? true : false);
        };
        template <class T, class Alloc>
        bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            return (lhs >= rhs ? true : false);
        };
        // SWAP
        template <class T, class Alloc>
        void swap(vector<T, Alloc> &x, vector<T, Alloc> &y){

        };
    };
}
#endif