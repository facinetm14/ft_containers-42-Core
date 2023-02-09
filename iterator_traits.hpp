/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:38:40 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/08 14:30:15 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAIT_HPP
# define ITERATOR_TRAIT_HPP
# include <iostream>
# include <cstddef>

namespace  ft {
	
	struct input_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag : public input_iterator_tag {};
	struct random_access_iterator_tag : public forward_iterator_tag {};
	struct output_iterator_tag : public bidirectional_iterator_tag {};

	template <typename Iterator>
	struct iterator_traits {
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::pointer 				pointer;
		typedef typename Iterator::reference			reference;
	};
	
	template <typename T>
	struct iterator_traits<T*> {
		typedef T 									value_type;
		typedef ptrdiff_t 							difference_type;
		typedef random_access_iterator_tag			iterator_category;
		typedef T* 									pointer;
		typedef T& 									reference;
	};

	template <typename T>
	struct iterator_traits<const T*> {
		typedef T 									value_type;
		typedef ptrdiff_t 							difference_type;
		typedef random_access_iterator_tag			iterator_category;
		typedef const T* 							pointer;
		typedef const T& 							reference;
	};
	
	template <class Category, class T, class Distance = ptrdiff_t,
				class Pointer = T*, class Reference = T&>
	class Iterator {
		
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef	Pointer 	pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};
	
}

#endif
