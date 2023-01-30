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

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef T			value_type;
			typedef Alloc		allocator_type;
			typedef T&			reference;
			typedef const T&    const_reference;  	    
			typedef T*			pointer;
			typedef const T*	const_pointer;
			typedef iterator
	};
}

#endif