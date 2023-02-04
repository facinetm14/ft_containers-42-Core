/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:53:05 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/04 21:05:47 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VECTOR_HPP
# define ITERATOR_VECTOR_HPP
# include "../iterator_trait.hpp"

namespace ft {
	
	template <typename T>
	class IteratorVector {
		public:
			typedef T 													iterator_type;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::iterator	  		iterator;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			// constructor & destructors
			IteratorVector(void): _ptr(NULL) {}
			
			IteratorVector(pointer ptr) { this->_ptr = ptr; }
			
			IteratorVector(const IteratorVector & it) { this->_ptr = it._ptr ; }
			
			IteratorVector& operator=(const IteratorVector & it) 
			{  
				if (this == &it)
					return (*this);
				this->_ptr = it._ptr ;
				return (*this);	
			}

			virtual ~IteratorVector(void) {}
			
			// comparaison operators
			bool operator==(const IteratorVector & it2) const { return this->_ptr == it2._ptr; }
			
			bool operator!=(const IteratorVector & it2) const { return this->_ptr != it2._ptr; }
			
			bool operator<=(const IteratorVector & it2) const { return this->_ptr <= it2._ptr; }
			
			bool operator>=(const IteratorVector & it2) const { return this->_ptr >= it2._ptr; }
			
			bool operator<(const IteratorVector & it2) const { return this->_ptr < it2._ptr; }
			
			bool operator>(const IteratorVector & it2) const { return this->_ptr >= it2._ptr; }

			// reference and dereference
			reference operator*(void) { return *(this->_ptr); }
			
			pointer operator->(void) { return &(this->operator*()); }
			
			// incrementation and decrement (pre/post)
			IteratorVector& operator++(void) 
			{
				_ptr++;
				return (*this);
			}
			
			IteratorVector operator++(int)
			{
				IteratorVector tmp(*this);
				_ptr++;
				return (tmp);
			}

			IteratorVector& operator--(void) 
			{
				_ptr--;
				return (*this);
			}
			
			IteratorVector operator--(int)
			{
				IteratorVector tmp(*this);
				_ptr--;
				return (tmp);
			}

			IteratorVector operator+(difference_type n) const
			{
				IteratorVector tmp(_ptr + n);
				return tmp;
			}
			
			IteratorVector operator-(difference_type n) const
			{
				IteratorVector tmp(_ptr - n);
				return tmp;
			}

			reference operator[](difference_type n) const
			{
				return *(_ptr + n);
			}
			
			IteratorVector& operator+=(difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			
			IteratorVector& operator-=(difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			
			pointer base() const { return _ptr; }
			
		private:
			pointer _ptr;
	};
}

template<typename T>
typename ft::IteratorVector<T>::difference_type
operator-( 
		   	const typename ft::IteratorVector<T> & it,
		   	const typename ft::IteratorVector<T> & it2
		 )
{
	return (it.base() - it2.base());
}
template<typename T>
typename ft::IteratorVector<T>
operator+( 
			const typename ft::IteratorVector<T>::difference_type & n,
		   	const typename ft::IteratorVector<T> & it
		 )
{
	ft::IteratorVector<T> new_it(it.base() + n);
	return (new_it);
}

#endif