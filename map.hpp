/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:41:47 by adlancel          #+#    #+#             */
/*   Updated: 2022/05/18 13:46:51 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

namespace ft
{
	class map
	{
	private:
	public:
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()){

		};
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()){

		};
		map(const map &x){

		};
		~map(){

		};
		map &operator=(const map &x){

		};

	public:
		iterator begin(){

		};
		const_iterator begin() const {

		};
	};
}
#endif
