/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:21:03 by adlancel          #+#    #+#             */
/*   Updated: 2022/09/16 09:21:08 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <sstream>
#include "./iterator.hpp"

namespace ft
{
    enum Color
    {
        BLACK,
        RED
    };
    template <typename T>
    struct Node
    {
        T data;
        Node *parent;
        Node *left;
        Node *right;
        Color color;

        Node(T data, Node *parent, Node *left, Node *right, Color color) : data(data), parent(parent), left(left), right(right), color(color) {}
        ~Node(){};
    };
    template <class Input, class Output>
    struct selectFirst : public std::unary_function<Input, Output>
    {
        const Output &operator()(const Input &x) const
        {
            return x.first;
        }
    };
    template <class Input, class Output>
    struct _selectFirst : public std::unary_function<Input, Output>
    {
        const Output &operator()(const Input &x) const
        {
            return x;
        }
    };

    template <class Input, class Output>
    struct selectKey : public std::unary_function<Input, Output>
    {
        const Output &operator()(const Input &x) const
        {
            return (x);
        }
    };

    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        // member variables
        first_type first;
        second_type second;

        // members functions
        pair() : first(first_type()), second(second_type()){}; // default(1)
        template <class U, class V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second){};       // copy(2)
        pair(const first_type &a, const second_type &b) : first(a), second(b){}; // initialization(3)

        pair &operator=(const pair &pr)
        {
            if (*this == pr)
                return *this;
            this->first = pr.first;
            this->second = pr.second;
            return *this;
        }
    };
    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }

    // relational operators
    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs < rhs);
    }
    template <class T, T v>
    struct integral_constant
    {
        static const T value = v;
        typedef T value_type;
        typedef integral_constant<T, v> type;
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;
    // DEFAULT TEMPLATE -> RETURN FALSE
    template <class T>
    struct is_integral : public false_type
    {
    };

    // after, all type overloads the structure

    template <>
    struct is_integral<bool> : public true_type
    {
    };
    template <>
    struct is_integral<char> : public true_type
    {
    };
    template <>
    struct is_integral<wchar_t> : public true_type
    {
    };
    template <>
    struct is_integral<signed char> : public true_type
    {
    };
    template <>
    struct is_integral<short int> : public true_type
    {
    };
    template <>
    struct is_integral<int> : public true_type
    {
    };
    template <>
    struct is_integral<long int> : public true_type
    {
    };
    template <>
    struct is_integral<long long int> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned char> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned short int> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned int> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned long int> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned long long int> : public true_type
    {
    };

    template <>
    struct is_integral<const bool> : public true_type
    {
    };
    template <>
    struct is_integral<const char> : public true_type
    {
    };
    template <>
    struct is_integral<const wchar_t> : public true_type
    {
    };
    template <>
    struct is_integral<const signed char> : public true_type
    {
    };
    template <>
    struct is_integral<const short int> : public true_type
    {
    };
    template <>
    struct is_integral<const int> : public true_type
    {
    };
    template <>
    struct is_integral<const long int> : public true_type
    {
    };
    template <>
    struct is_integral<const long long int> : public true_type
    {
    };
    template <>
    struct is_integral<const unsigned char> : public true_type
    {
    };
    template <>
    struct is_integral<const unsigned short int> : public true_type
    {
    };
    template <>
    struct is_integral<const unsigned int> : public true_type
    {
    };
    template <>
    struct is_integral<const unsigned long int> : public true_type
    {
    };
    template <>
    struct is_integral<const unsigned long long int> : public true_type
    {
    };
    template <bool C, class T = void>
    struct enable_if
    {
    };
    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
    distance(InputIterator first, InputIterator last)
    {
        typename iterator_traits<InputIterator>::difference_type ret = 0;
        while (first != last)
        {
            first++;
            ret++;
        }
        return ret;
    };
    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                 InputIt2 first2, InputIt2 last2)
    {
        for (; (first1 != last1) && (first2 != last2);
             ++first1, (void)++first2)
        {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template <class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                 InputIt2 first2, InputIt2 last2,
                                 Compare comp)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
        {
            if (comp(*first1, *first2))
                return true;
            if (comp(*first2, *first1))
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }
};
template <class T>
std::string to_string(T obj)
{
    std::ostringstream ss;
    ss << obj;
    return (ss.str());
}
static class ft_nullptr_t
{
private:
    void operator&() const;

public:
    template <class T>
    operator T *() const { return 0; }
    template <class C, class T>
    operator T C::*() const { return 0; }
} ft_nullptr_t = {};

#endif