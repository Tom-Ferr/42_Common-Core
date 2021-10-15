/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:28:18 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/14 16:22:12 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iterator.hpp>
# include <algorithm.hpp>
# include <exception.hpp>
# include <memory>

namespace ft {
	template<typename T, class Allocator = std::allocator<T> >
	class vector
	{
	public:

		/*
		 * Member types
		 */
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::random_access_iterator<pointer, vector> iterator;
		typedef ft::random_access_iterator<const_pointer, vector> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		/*
		 * Orthodox Canonical Form
		 */

		// constructors
		// vector (void)
		// 	: _Alloc(allocator_type()), _Data(nullptr), _size(0), _capacity(2){};

		explicit vector (const allocator_type & alloc = allocator_type())
			: _Data(nullptr), _Alloc(alloc), _size(0), _capacity(0){};

		explicit vector (size_type n, const value_type & val = value_type(),
			const allocator_type & alloc = allocator_type())
			:  _Data(nullptr), _Alloc(alloc){
				this->assign(n, val);
			};

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
			const allocator_type & alloc = allocator_type())
				:  _Data(nullptr), _Alloc(alloc){
					this->assign(first, last);
			};
		//destructor
		~vector(void){this->_Alloc.deallocate(this->_Data, this->_capacity);};
		//copy constructor
		vector (const vector & src)
			:  _Data(nullptr), _Alloc(allocator_type()), _capacity(0){ *this = src; };
		//assign operator
		vector & operator=(const vector & rhs){
			if (this != &rhs){
				if(this->capacity() < rhs.size()){
					this->_Alloc.deallocate(this->_Data, this->capacity());
					this->_Data = this->_Alloc.allocate(rhs.size());
					this->_capacity = rhs.size();
				}
				for (size_type i = 0; i < rhs.size(); i++){
					this->_Data[i] = rhs[i];
				}
				this->_size = rhs.size();
			}
			return *this;
		};

		/*
		 * Iterators
		 */
		iterator begin(){ return iterator(this->_Data); };

		const_iterator begin() const{ return const_iterator(this->_Data); };

		iterator end(){ return iterator(this->_Data + this->size()); };

		const_iterator end() const{ return const_iterator(this->_Data + this->size()); };

		reverse_iterator rbegin(){
			return reverse_iterator(end() - 1);
		};
		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(end() - 1);
		};
		reverse_iterator rend(){
			return reverse_iterator(begin() - 1);
		};
		const_reverse_iterator rend() const{
			return const_reverse_iterator(begin() - 1);
		};

		/*
		 * Capacity
		 */
		size_type size() const { return this->_size; };

		size_type max_size() const{ return -1ul / sizeof(value_type);};

		void resize (size_type n, value_type val = value_type()){
			if (n > size()){
				value_type* heir = this->_Alloc.allocate(n);
				for (size_type i = 0; i < n; i++){
					if(i < size()){
						heir[i] = _Data[i];
					}
					else
						heir[i] = val;
				}
				this->_Alloc.deallocate(this->_Data, capacity());
				this->_Data = heir;
				this->_size = n;
				this->_capacity = n;
			}
			else
				this->_size = n;
		};

		size_type capacity() const { return this->_capacity; };

		bool empty() const { return this->_size == 0; };

		void reserve (size_type n){
			if (n > this->capacity())
				realloc(n);
		};

		/*
		 * Element access
		 */
		reference operator[](size_type n){ return this->_Data[n]; };

		const_reference operator[](size_type n) const{ return this->_Data[n]; };

		reference at (size_type n){
			if (n >= this->size())
				throw ft::out_of_range();
			return this->_Data[n];
		};
		const_reference at (size_type n) const{
			if (n >= this->size())
				throw ft::out_of_range();
			return this->_Data[n];
		};
		reference front(){ return *begin(); };

		const_reference front() const{ return *begin(); };

		reference back(){ return *(end() - 1); };

		const_reference back() const{ return *(end() - 1); };

		value_type* data(){ return this->_Data; };

		const value_type* data() const{ return this->_Data; };

		/*
		 * Modifiers
		 */
		template <class InputIterator>
   		void assign (InputIterator first, InputIterator last){
			if (this->_Data)
				this->_Alloc.deallocate(this->_Data, this->_capacity);
			this->_size = last - first;
			this->_capacity = this->size();
			this->_Data = this->_Alloc.allocate(_capacity);
			for (size_type i = 0; i < this->size(); i++) {
				this->_Data[i] = *first++;
			}
		};
		void assign (size_type n, const value_type& val){
			if (this->_Data)
				this->_Alloc.deallocate(this->_Data, this->_capacity);
			this->_size = n;
			this->_capacity = n;
			this->_Data = this->_Alloc.allocate(_capacity);
			for (size_type i = 0; i < this->size(); i++) {
				this->_Data[i] = val;
			}
		};
		void push_back (const value_type& val){
			this->check_capacity();
			*(this->_Data + this->size()) = val;
			this->_size++;
		};
		void pop_back(){
			if (this->size() > 0)
				this->_size--;
		};
		iterator insert (iterator position, const value_type& val){
			size_type p = position - begin();
			this->check_capacity();
			iterator it;
			position = begin() + p;
			for (it = end(); it != position; it--) {
				*it = *(it - 1);
			}
			*it = val;
			this->_size++;
			return it;
		};
		void insert (iterator position, size_type n, const value_type& val){
			if(n == 0)
				return ; 
			size_type p = position - begin();
			this->check_capacity(n);
			position = begin() + p;
			for (iterator it = end(); it != position; it--) {
				*(it + n - 1) = *(it - 1);
			}
			for (size_type i = n; i; i--, position++) {
				*position = val;
			}
			this->_size += n;
		};
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last){
			size_type p = position - begin();
			size_t n = last - first;
			this->check_capacity(last - first);
			position = begin() + p;
			for (iterator it = end(); it != position; it--) {
				*(it + n) = *(it - 1);
			}
			for (iterator it = position; first != last; it++, first++) {
				*it = *first;
			}
			this->_size += n + 1;
		};
		iterator erase (iterator position){
			for (iterator it = position; it != end(); it++) {
				*it = *(it + 1);
			}
			this->_Alloc.destroy(*position);
			this->size--;
			return ++position;
		};
		iterator erase (iterator first, iterator last){
			iterator it = first;
			for (iterator from = ++last; from != end() && it != last; from++, it++) {
				*it = *from;
			}
			this->size -= last - first;
			return it;
		};
		void swap(vector & other){
			if(other.size() < this->size()){
				other.swap(*this);
				return ;
			}
			check_capacity(other.size() - this->size());
			iterator ts = this->begin();
			value_type tmp;
			for (iterator it = other.begin(); it != other.end(); it++) {
				tmp = *ts;
				*ts = *it;
				*it = tmp;
				ts++;
			};
		};
		void clear(){
			if (this->_Data)
				this->_Alloc.deallocate(this->_Data, this->_capacity);
			this->_Alloc = nullptr;
			this->size = 0;
		};

		/*
		 * Allocator
		 */
		allocator_type get_allocator() const{ return this->_Alloc; };

	protected:
		/*
		 * Protected Methods
		 */
		void realloc(size_type n){
			size_type m = 1;
			if(this->capacity() == 0)
				this->_capacity = 1;
			while (n > this->capacity() * m)
				m++;
			value_type* tmp = this->_Alloc.allocate(this->capacity() * m);
			for (size_type i = 0; i < this->size(); i++) {
				tmp[i] = this->_Data[i];
			}
			this->_Alloc.deallocate(this->_Data, this->capacity());
			this->_Data = tmp;
			this->_capacity *= m;
		}

		void check_capacity(size_type n = 1){
			if (this->size() + n >= this->capacity())
				realloc(this->size() + n);
		};

		/*
		 * Attributes
		 */
		value_type* _Data;
		allocator_type _Alloc;
		size_type _size, _capacity;
	};

	/*
	 * Non-member function overloads
	 */
	template <typename T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};
	template <typename T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(lhs == rhs);
	};
	template <typename T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};
	template <typename T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(rhs < lhs);
	};
	template <typename T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return rhs < lhs;
	};
	template <typename T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(lhs < rhs);
	};

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){ x.swap(y); };
}
#endif
