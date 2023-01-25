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

template<class T, typename U>
class vector {
    private:
        T* _arr;
    public:
        size_t _size;
        size_t _capacity;
        vector(int n): _arr(new T[n]), _size(n), _capacity(n) {};
        ~vector(void){};
        vector(vector )
        size_t size() { return this->_size; };
        size_t capacity() { return this->_capacity; };


};

#endif