/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:43:11 by fakouyat          #+#    #+#             */
/*   Updated: 2023/01/18 10:43:11 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef T&												reference;
			typedef const T&    									const_reference;  	    
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef typename ft::random_access_iterator<T>			iterator;
			typedef const typename ft::random_access_iterator<T>	const_iterator;
			typedef typename ft::reverse_iterator<T>				reverse_iterator;
			typedef const typename ft::reverse_iterator<T>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>			difference_type;
			typedef unsigned typename ft::iterator_traits<iterator>	size_type;											
	};
}

#endif