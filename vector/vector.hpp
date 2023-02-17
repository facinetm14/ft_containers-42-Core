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
	template< class T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef T&														reference;
			typedef const T&    											const_reference;  	    
			typedef T*														pointer;
			typedef const T*												const_pointer;
			typedef typename ft::random_access_iterator<value_type>			iterator;
			typedef typename ft::random_access_iterator<const value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const iterator>			const_reverse_iterator;
			typedef ptrdiff_t												difference_type;
			typedef size_t													size_type;	
			
			// constructors & destructors 
			explicit vector(const allocator_type alloc = allocator_type()):
					_size(0), _capacity(0), _ptr(), _alloc(alloc), _begin(_ptr) {}

			explicit vector(size_type n, const value_type& val = value_type(), 
							const allocator_type & alloc = allocator_type()):
					_size(n), _capacity(n), _alloc(alloc), _ptr(NULL)
			{
				_ptr = _alloc.allocate(_capacity);
				_begin = _ptr;
				size_t i = 0, j = n;	
				while (i < j)
				{
					_alloc.construct(_ptr + i, val);
					_alloc.construct(_ptr + j - 1, val);
					i++;
					j--;
				}
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			{
				if (first == last)
					return ;
				_size = last - first;
				_capacity = _size;
				_ptr = _alloc.allocate(_capacity);
				_begin = _ptr;
				size_t i = 0, j = _size;
				while (i < j)
				{
					_alloc.construct(_ptr + i, *first);
					_alloc.construct(_ptr + j - 1, *(last - 1));
					i++; first++;
					j--; last--;
				}
				
			}

			vector(const vector & v):
				_size(v._size), _capacity(v._capacity), _alloc(v._alloc), 
				_ptr(_alloc.allocate(_capacity))
			{
				size_t i = 0, j = _capacity;	
				while (i < j)
				{
					_alloc.construct(_ptr + i, *(v._pt + i));
					_alloc.construct(_ptr + j - 1, *(v._pt + j - 1));
					i++;
					j--;
				}
				_begin = _ptr;
			}

			~vector() {}

			//iterators
			iterator		begin() { return iterator(_begin); }
			const_iterator	begin() const { return const_iterator(_begin); }

			iterator		end() { return iterator(_begin + _size); }
			const_iterator	end() const { return const_iterator(_begin + _size); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

			reverse_iterator rend() { return reverse_iterator(begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			// elements access
			reference operator[] (size_type n) { return *(_ptr + n); }
			const_reference operator[] (size_type n) const { return *(_ptr + n); }

			reference front() { return *_begin; }
			const_reference front() const { return *_begin; };

			reference back() { return *(_begin + _size - 1); }
			const_reference back() const { return *(_begin + _size - 1); };

			reference at (size_type n) { return *(_begin + n); };
			const_reference at (size_type n) const { return *(_begin + n); };
			
			// capacity
			size_type	size() const { return _size; }

			size_type	capacity() const { return _capacity; }

			size_type	max_size() const { return _alloc.max_size(); }

			bool empty() const { return _size == 0; }

			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					_alloc.destroy(_ptr + n);
					_size = n;
					return ;
				}
				if (n == _size)
					return;
				if (n > _capacity)
					this->re_allocate(n, val, 2 * _capacity);
				_size = n;
			}

			void	reserve(size_type n) 
			{
				if (n > this->max_size())
					throw std::exception();
				if (n > _capacity)
					this->re_allocate(n, value_type(), n);
			}

			// modifiers

			/********************TODO!!!****************/
			template <class InputIterator>
			void	assign (InputIterator first, InputIterator last) 
			{

			}

			void	assign(size_type, const value_type & val)
			{

			}
			/*------------------------------------------------*/

			void	push_back (const value_type& val)
			{
				if (_size + 1 <= _capacity)
					*(_ptr + _size) = val;
				else
				{
					this->re_allocate(_size + 1, val, 2 * _capacity);
					_begin = _ptr;
				}
				_size += 1;
			}

			void	pop_back() 
			{
				_alloc.destroy(_ptr + _size - 1);
				_alloc.construct(_ptr + _size - 1, value_type());
				_size -= 1;
			}

			void	insert (iterator position, size_type n, const value_type& val)
			{
				if (n <= 0)
					return ;
				pointer tmp = _ptr;
				size_type pos = position - this->begin(), i = 0, j = pos, z = 0;
				for (auto i = 0; i < n; i++)
				{
					if (_size + i + 1 > _capacity)
						_capacity *= 2;
				}
				_size += n;
				_ptr = _alloc.allocate(_capacity);
				while(i < j)
				{
					*(_ptr + i) = *(tmp + i);
					*(_ptr + j - 1) = *(tmp + j - 1);
					i++; j--;
				}
				while (z < n)
				{
					*(_ptr + pos + z) = val;
					z++;
				}
				j = _capacity;
				while (z < j)
				{
					if (z < _size)
						*(_ptr + z) = *(tmp + (z - n));
					if (j > _size)
						_alloc.construct(_ptr + j - 1, value_type());
					z++; j--;
				}
				_begin = _ptr;
				_alloc.destroy(tmp);
				_alloc.deallocate(tmp, _capacity);
			}
		
			iterator	insert(iterator position, const value_type& val)
			{
				pointer tmp = _ptr;
				size_type pos = position - this->begin(), i = 0, j = pos, old_capacity = _capacity;
				if (_size + 1 > _capacity)
					_capacity *= 2;
				_size += 1;
				_ptr = _alloc.allocate(_capacity);
				while(i < j)
				{
					*(_ptr + i) = *(tmp + i);
					*(_ptr + j - 1) = *(tmp + j - 1);
					i++; j--;
				}
				*(_ptr + pos) = val;
				i = pos + 1; j = _capacity;
				while (i < j)
				{
					if (i < _size)
						*(_ptr + i) = *(tmp + (i - 1));
					if (j > _size)
						_alloc.construct(_ptr + j - 1, value_type());
					i++; j--;
				}
				_begin = _ptr;
				_alloc.destroy(tmp);
				_alloc.deallocate(tmp, old_capacity);
				return iterator(_ptr + pos);
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				size_type n = last - first;
				pointer tmp = _ptr;
				size_type pos = position - this->begin(), i = 0, j = pos, z = 0;
				for (auto i = n; i > 0; i--)
				{
					if (_size + i > _capacity)
					{
						_capacity *= 2;
						break ;
					}
				}
				_size += n;
				_ptr = _alloc.allocate(_capacity);
				while(i < j)
				{
					*(_ptr + i) = *(tmp + i);
					*(_ptr + j - 1) = *(tmp + j - 1);
					i++; j--;
				}
				while (first != last)
				{
					*(_ptr + pos + z) = *first;
					z++;
					first++;
				}
				i = pos + z; j = _capacity;
				while (i < j)
				{
					if (z < _size)
						*(_ptr + z) = *(tmp + (z - n));
					if (j > _size)
						_alloc.construct(_ptr + j - 1, value_type());
					z++; j--;
				}
				_begin = _ptr;
				_alloc.destroy(tmp);
				_alloc.deallocate(tmp, _capacity);
			}
			// allocator
			allocator_type get_allocator() const { return _alloc; }

			private:
				size_type		_size;
				size_type		_capacity;
				pointer			_begin;
				allocator_type	_alloc;
				pointer 		_ptr;

			private:

				//just a helper for rellocating and updating.
				void	re_allocate(size_type n, const value_type val, size_type new_capacity)
				{
					pointer tmp = _ptr;
					_ptr = _alloc.allocate(new_capacity);
					size_type i = 0, j = n;
					while (i < new_capacity)
					{
						if (i < _size)
							*(_ptr + i) = *(tmp + i);
						if (j > _size)
							_alloc.construct(_ptr + j - 1, val);
						i++;
						j--;
					}
					_alloc.destroy(tmp);
					_alloc.deallocate(tmp, _capacity);
					_capacity = new_capacity;
				}
	};
}

#endif