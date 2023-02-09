/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:26:37 by fakouyat          #+#    #+#             */
/*   Updated: 2023/02/04 23:26:37 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "../iterator_traits.hpp"

namespace ft {
    template<typename T>
    class reverse_iterator {

        public:
			typedef T 												    iterator_type;
			typedef typename ft::iterator_traits<T>::value_type		    value_type;
			typedef typename ft::iterator_traits<T>::difference_type    difference_type;
            typedef typename ft::iterator_traits<T>::iterator_category  iterator_category;
			typedef typename ft::iterator_traits<T>::pointer		    pointer;
			typedef typename ft::iterator_traits<T>::reference  		reference;

            // constructors & destructor
            reverse_iterator(): _base() {}
        
            reverse_iterator(iterator_type it_base): _base(it_base - 1) {}
            
            reverse_iterator(const reverse_iterator<T> & it): _base(it._base) {}
            
            reverse_iterator & operator=(const reverse_iterator<T> & it)
            {
                if (this == &it)
					return (*this);
				_base = it._base ;
				return (*this);	
            }

            virtual ~reverse_iterator() {}

            // arithmetic operators
            reverse_iterator operator++(int) 
            {
                reverse_iterator it = *this;
                _base--;
                return it;
            }

            reverse_iterator & operator++() 
            {
                _base--;
                return *(this);
            }

            reverse_iterator operator--(int) 
            {
                reverse_iterator it(*this);
                _base++;
                return it;
            }

            reverse_iterator & operator--() 
            {
                _base++;
                return *(this);
            }
            
            reverse_iterator operator+=(difference_type n)
            {
                _base -= n;
                return (*this);
            }

            reverse_iterator operator-=(difference_type n)
            {
                _base += n;
                return (*this);
            }
            
            reverse_iterator operator+(difference_type n) const 
            { 
                reverse_iterator<T> new_it(_base - n);
                return new_it;
            }

            reverse_iterator operator-(difference_type n) const 
            { 
                reverse_iterator<T> new_it(_base + n);
                return new_it;
            }

            reference operator[] (difference_type n) const { return *(_base - n); }
            // base iterator
            iterator_type base(void) const { return _base; }

            // reference & dereference
            reference operator*(void) const { return *(_base) ; }

            iterator_type operator->() const { return &(operator*()); }

            // comparaisons operators 
            bool operator==(const reverse_iterator<T> & it) { return _base == it._base; }
            
            bool operator!=(const reverse_iterator<T> & it) { return _base != it._base; }
            
            bool operator<=(const reverse_iterator<T> & it) { return _base >= it._base; }
            
            bool operator>=(const reverse_iterator<T> & it) { return _base <= it._base; }
            
            bool operator>(const reverse_iterator<T> & it) { return _base < it._base; }
            
            bool operator<(const reverse_iterator<T> & it) { return _base > it._base; }

        private:
            iterator_type _base;
    };
}

// non-members operators overloading

template<typename T>
typename ft::reverse_iterator<T>::difference_type
operator-( 
		   	const typename ft::reverse_iterator<T> & it,
		   	const typename ft::reverse_iterator<T> & it2
		 )
{
	return (it2.base() - it.base());
}
template<typename T>
typename ft::reverse_iterator<T>
operator+( 
			const typename ft::reverse_iterator<T>::difference_type & n,
		   	const typename ft::reverse_iterator<T> & it
		 )
{
	ft::reverse_iterator<T> new_it(it.base() - n);
	return (new_it);
}

#endif