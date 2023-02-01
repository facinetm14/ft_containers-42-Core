/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator_trait.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:38:40 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/01 18:51:02 by fakouyat         ###   ########.fr       */
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
	template <class T>
	struct iterator_traits {
		typedef typename T::value_type			value_type;
		typedef typename T::difference_type		difference_type;
		typedef typename T::iterator_category	iterator_category;
		typedef typename T::pointer 			pointer;
		typedef typename T::reference			reference;
	};
	
	template <class T>
	struct iterator_traits<T*> {
		typedef T 							value_type;
		typedef ptrdiff_t 					difference_type;
		typedef random_access_iterator_tag	iterator_category;
		typedef T* 							pointer;
		typedef T& 							reference;
	};

	template <class T>
	struct iterator_traits<const T*> {
		typedef T 							value_type;
		typedef ptrdiff_t 					difference_type;
		typedef random_access_iterator_tag	iterator_category;
		typedef const T* 							pointer;
		typedef const T& 							reference;
	};
}

#endif
