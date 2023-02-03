/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_trait.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:38:40 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/02 23:12:15 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAIT_HPP
# define ITERATOR_TRAIT_HPP
# include <iostream>
# include <cstddef>

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};



namespace  ft
{
	template <typename T>
	struct iterator_traits {
		typedef typename T::value_type			value_type;
		typedef typename T::difference_type		difference_type;
		typedef typename T::iterator			iterator;
		typedef typename T::pointer 			pointer;
		typedef typename T::reference			reference;
	};
	
	template <typename T>
	struct iterator_traits<T*> {
		typedef T 							value_type;
		typedef ptrdiff_t 					difference_type;
		typedef random_access_iterator_tag	iterator;
		typedef T* 							pointer;
		typedef T& 							reference;
	};

	template <typename T>
	struct iterator_traits<const T*> {
		typedef T 							value_type;
		typedef ptrdiff_t 					difference_type;
		typedef random_access_iterator_tag	iterator;
		typedef const T* 					pointer;
		typedef const T& 					reference;
	};
}

#endif
