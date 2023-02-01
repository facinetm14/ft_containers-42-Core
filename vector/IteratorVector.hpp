/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:53:05 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/01 19:11:25 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VECTOR_HPP
# define ITERATOR_VECTOR_HPP
# include "../iterator_trait.hpp"

namespace ft {
	template <typename T, class Container>
	class IteratorVector {
		protected:
		public:
			typedef T 												iterator_type;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::difference_type		difference_type;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::pointer				pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
			pointer _ptr; // just for test, should not be public

			IteratorVector(void): _ptr(NULL) {}
			IteratorVector(IteratorVector const & it) { *this = it ; }
			IteratorVector& operator=(IteratorVector const & it): _ptr(it._ptr) {}
	};
}
#endif