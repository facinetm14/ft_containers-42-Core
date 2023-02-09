/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:53:05 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/04 21:05:47 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VECTOR_HPP
# define ITERATOR_VECTOR_HPP
# include "../iterator_traits.hpp"

namespace ft {
	
	template <typename T>
	class random_access_iterator : ft::Iterator<ft::random_access_iterator_tag, T> {

		public:
			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::reference			reference;

			// constructor & destructors
			random_access_iterator(void): _ptr() {}
			
			random_access_iterator(pointer ptr): _ptr(ptr) {}
			
			random_access_iterator(const random_access_iterator & it): _ptr(it._ptr) {}
			
			random_access_iterator& operator=(const random_access_iterator & it) 
			{  
				if (this == &it)
					return (*this);
				this->_ptr = it._ptr ;
				return (*this);	
			}

			virtual ~random_access_iterator(void) {}
			
			// comparaison operators
			bool operator==(const random_access_iterator & it2) const { return this->_ptr == it2._ptr; }
			
			bool operator!=(const random_access_iterator & it2) const { return this->_ptr != it2._ptr; }
			
			bool operator<=(const random_access_iterator & it2) const { return this->_ptr <= it2._ptr; }
			
			bool operator>=(const random_access_iterator & it2) const { return this->_ptr >= it2._ptr; }
			
			bool operator<(const random_access_iterator & it2) const { return this->_ptr < it2._ptr; }
			
			bool operator>(const random_access_iterator & it2) const { return this->_ptr >= it2._ptr; }

			// reference and dereference
			reference operator*(void) const { return *(this->_ptr); }
			//reference operator*(void) const { return *(this->_ptr); }
			
			pointer operator->(void) { return &(this->operator*()); }
			//const pointer operator->(void) const { return &(this->operator*()); }
			
			// incrementation and decrement (pre/post)
			random_access_iterator& operator++(void) 
			{
				_ptr++;
				return (*this);
			}
			
			random_access_iterator operator++(int)
			{
				random_access_iterator tmp(*this);
				_ptr++;
				return (tmp);
			}

			random_access_iterator& operator--(void) 
			{
				_ptr--;
				return (*this);
			}
			
			random_access_iterator operator--(int)
			{
				random_access_iterator tmp(*this);
				_ptr--;
				return (tmp);
			}

			random_access_iterator operator+(difference_type n) const
			{
				random_access_iterator tmp(_ptr + n);
				return tmp;
			}
			
			random_access_iterator operator-(difference_type n) const
			{
				random_access_iterator tmp(_ptr - n);
				return tmp;
			}

			reference operator[](difference_type n) { return *(_ptr + n); }
			
			random_access_iterator& operator+=(difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			
			random_access_iterator& operator-=(difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			
			pointer base() const { return _ptr; }
			
		protected:
			pointer _ptr;
	};
}

// non members functions (relationals)

template<typename T>
typename ft::random_access_iterator<T>::difference_type
operator-( 
		   	const typename ft::random_access_iterator<T> & it,
		   	const typename ft::random_access_iterator<T> & it2
		 )
{
	return (it.base() - it2.base());
}
template<typename T>
typename ft::random_access_iterator<T>
operator+( 
			const typename ft::random_access_iterator<T>::difference_type & n,
		   	const typename ft::random_access_iterator<T> & it
		 )
{
	ft::random_access_iterator<T> new_it(it.base() + n);
	return (new_it);
}

#endif