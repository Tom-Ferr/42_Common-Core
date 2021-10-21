/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:28:18 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/21 17:15:13 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iterator.hpp>
# include <algorithm.hpp>
# include <exception.hpp>
# include <type_traits.hpp>
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
		typedef ft::random_access_iterator<vector> iterator;
		typedef ft::random_access_iterator<vector> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		/*
		 * Orthodox Canonical Form
		 */

		// constructors
		explicit vector (const allocator_type & alloc = allocator_type())
			: _Data(nullptr), _Alloc(alloc), _size(0), _capacity(0){};

		explicit vector (size_type n, const value_type & val = value_type(),
			const allocator_type & alloc = allocator_type())
			:  _Data(nullptr), _Alloc(alloc){
				this->assign(n, val);
			};

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
			const allocator_type & alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0)
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
					this->_Alloc.construct(&_Data[i], rhs[i]);
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
						this->_Alloc.construct(&heir[i], _Data[i]);
					}
					else
						this->_Alloc.construct(&heir[i], val);
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
   		void assign (InputIterator first, InputIterator last,
		   typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0){
			if (this->_Data)
				this->_Alloc.deallocate(this->_Data, this->_capacity);
			this->_size = last - first;
			this->_capacity = this->size();
			this->_Data = this->_Alloc.allocate(_capacity);
			for (size_type i = 0; i < this->size(); i++, first++) {
				this->_Alloc.construct(&_Data[i], *first);
			}
		};
		void assign (size_type n, const value_type& val){
			if (this->_Data)
				this->_Alloc.deallocate(this->_Data, this->_capacity);
			this->_size = n;
			this->_capacity = n;
			this->_Data = this->_Alloc.allocate(_capacity);
			for (size_type i = 0; i < this->size(); i++) {
				this->_Alloc.construct(&_Data[i], val);
			}
		};
		void push_back (const value_type& val){
			this->check_capacity();
			this->_Alloc.construct(_Data + this->size(), val);
			this->_size++;
		};
		void pop_back(){
			if (this->size() > 0)
			this->_Alloc.destroy(_Data + this->size() - 1);
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
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last){
			typedef typename is_integral<InputIterator>::type Integral;
			insert_dispatch(position, first, last, Integral());
		};
		iterator erase (iterator position){
			size_type p = position - begin();
			position = begin() + p;
			this->_Alloc.destroy(&(*position));
			for (iterator it = position; it != end() - 1; it++) {
				*it = *(it + 1);
			}
			this->_size--;
			return position;
		};
		iterator erase (iterator first, iterator last){
			iterator it = first;
			for (iterator from = last; from != end() && it != last; from++, it++) {
				this->_Alloc.destroy(&(*it));
				*it = *from;
			}
			this->_size -= last - first;
			return first;
		};
		void swap(vector & other){
			value_type* tmp = this->_Data;
			this->_Data = other._Data;
			other._Data = tmp;
			size_type s_tmp = this->size();
			this->_size = other._size;
			other._size = s_tmp;
			s_tmp = this->capacity();
			this->_capacity = other._capacity;
			other._capacity = s_tmp;

		};
		void clear(){
			if (this->_Data)
				this->_Alloc.deallocate(this->_Data, this->_capacity);
			this->_Data = nullptr;
			this->_size = 0;
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
				this->_Alloc.construct(&tmp[i], _Data[i]);
			}
			this->_Alloc.deallocate(this->_Data, this->capacity());
			this->_Data = tmp;
			this->_capacity *= m;
		}

		void check_capacity(size_type n = 1){
			if (this->size() + n >= this->capacity())
				realloc(this->size() + n);
		};

		template <class InputIterator>
    	void insert_dispatch (iterator position, InputIterator first, InputIterator last, typename ft::true_type){
			insert_fil(position, first, last);
		}
		template <class InputIterator>
    	void insert_dispatch (iterator position, InputIterator first, InputIterator last, typename ft::false_type){
			insert_range(position, first, last);
		}

		void insert_fil (iterator position, size_type n, const value_type& val){
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
    	void insert_range (iterator position, InputIterator first, InputIterator last){
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
			this->_size += n;
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
		if(lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
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
