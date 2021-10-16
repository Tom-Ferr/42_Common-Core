/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:00:07 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/15 18:45:27 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR
# define FT_RANDOM_ACCESS_ITERATOR
namespace ft{

	/*
	 * RANDOM_ACCESSL_ITERATOR
	 */
	template <typename P, class C>
	class random_access_iterator{
	public:
		/*
		 * Member types
		 */
		typedef typename C::value_type value_type;
		typedef typename C::size_type size_type;
		typedef typename C::difference_type difference_type;
		typedef typename C::reference reference;
		typedef P pointer;

		/*
		 * Orthodox Canonical Form
		 */
		random_access_iterator(void){};
		random_access_iterator(P const ptr) : _ptr(ptr){};
		random_access_iterator(random_access_iterator const & src){*this = src;};
		~random_access_iterator(void){};
		random_access_iterator & operator=(random_access_iterator const & rhs){
			if (this != &rhs){
				this->_ptr = rhs._ptr;
			}
			return *this;
		};

		/*
		 * Dereference Operators
		 */
		reference operator*() const {
			return *(this->_ptr);
		};

		pointer operator->() const {
			return &(operator*());
		};

		/*
		 * Incrementation/Decrementation Operators
		 */
		random_access_iterator& operator++(){
			this->_ptr++;
			return *this;
		};

		random_access_iterator operator++(int){
			random_access_iterator tmp(*this);
			this->_ptr++;
			return tmp;
		};

		random_access_iterator& operator--(){
			this->_ptr--;
			return *this;
		};

		random_access_iterator operator--(int){
			random_access_iterator tmp(*this);
			this->_ptr--;
			return tmp;
		};

		/*
		 * Relational Operators
		 */
		bool operator==(random_access_iterator const & rhs) const {
			return this->_ptr == rhs._ptr;
		};

		bool operator!=(random_access_iterator const & rhs) const {
			return !(*this == rhs);
		};

		bool operator<(random_access_iterator const & rhs) const {
			return this->_ptr < rhs._ptr;
		};

		bool operator<=(random_access_iterator const & rhs) const {
			return !(rhs < *this);
		};

		bool operator>(random_access_iterator const & rhs) const {
			return rhs < *this;
		};

		bool operator>=(random_access_iterator const & rhs) const {
			return !(*this < rhs);
		};

		/*
		 * Arithmetic Operators
		 */
		random_access_iterator operator+(size_type d) const{
			random_access_iterator tmp(this->_ptr + d);
			return tmp;
		};

		random_access_iterator& operator+=(size_type d){
			this->_ptr += d;
			return *this;
		};

		random_access_iterator operator-(size_type d) const{
			random_access_iterator tmp(this->_ptr - d);
			return tmp;
		};

		random_access_iterator& operator-=(size_type d){
			this->_ptr -= d;
			return *this;
		};
		//difference operator
		difference_type operator-(random_access_iterator const & rhs) const {
			return this->_ptr - rhs._ptr;
		};

		/*
		 * Offset Operator
		 */
		reference operator[](size_type i){
			return this->_ptr[i];
		}

	private:
		pointer _ptr;

	};

}

#endif
