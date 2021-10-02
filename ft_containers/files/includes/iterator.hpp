/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:00:07 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/02 18:48:04 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP
# include <iostream>
namespace ft{
	/*
	 * NORMAL_ITERATOR
	 */
	template <typename P, class C>
	class normal_iterator{
	public:
		/*
		 * Member types
		 */
		typedef typename C::value_type value_type;
		typedef typename C::size_type size_type;
		typedef typename C::difference_type difference_type;
		typedef typename C::reference reference;
		typedef P pointer;


		normal_iterator(void){};
		normal_iterator(P const ptr) : _ptr(ptr){};
		normal_iterator(normal_iterator const & src){*this = src;};
		~normal_iterator(void){};
		normal_iterator & operator=(normal_iterator const & rhs){
			if (this != &rhs){
				this->_ptr = rhs.get_ptr();
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
		 * Relational Operators
		 */
		bool operator==(normal_iterator const & rhs) const {
			return this->_ptr == rhs.get_ptr();
		};

		bool operator!=(normal_iterator const & rhs) const {
			return !(*this == rhs);
		};

		bool operator<(normal_iterator const & rhs) const {
			return this->_ptr < rhs.get_ptr();
		};

		bool operator<=(normal_iterator const & rhs) const {
			return !(rhs < *this);
		};

		bool operator>(normal_iterator const & rhs) const {
			return rhs < *this;
		};

		bool operator>=(normal_iterator const & rhs) const {
			return !(*this < rhs);
		};

		/*
		 * Arithmetic Operators
		 */
		normal_iterator operator+(size_type d) const{
			normal_iterator tmp(this->_ptr + d);
			return tmp;
		};

		normal_iterator& operator+=(size_type d){
			this->_ptr += d;
			return *this;
		};

		normal_iterator operator-(size_type d) const{
			normal_iterator tmp(this->_ptr - d);
			return tmp;
		};

		normal_iterator& operator-=(size_type d){
			this->_ptr -= d;
			return *this;
		};
		//difference operator
		difference_type operator-(normal_iterator const & rhs) const {
			return this->_ptr - rhs.get_ptr();
		};

		/*
		 * Incrementation/Decrementation Operators
		 */
		normal_iterator& operator++(){
			this->_ptr++;
			return *this;
		};

		normal_iterator operator++(int){
			normal_iterator tmp(*this);
			this->_ptr++;
			return tmp;
		};

		normal_iterator& operator--(){
			this->_ptr--;
			return *this;
		};

		normal_iterator operator--(int){
			normal_iterator tmp(*this);
			this->_ptr--;
			return tmp;
		};

		/*
		 * Offset Operator
		 */
		reference operator[](size_type i){
			return this->_ptr[i];
		}

		/*
		 * Getter
		 */
		pointer get_ptr() const { return this->_ptr; };
	private:
		pointer _ptr;

	};


	/*
 	 * REVERSE_ITERATOR
 	 */
	template <class Iter>
	class reverse_iterator{
	public:
		/*
		 * Member types
		 */
		typedef Iter iterator_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::size_type size_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::difference_type difference_type;

		/*
		 * Orthodox Canonical Form
		 */
		reverse_iterator(void){};

		explicit reverse_iterator( iterator_type it ) : _it(it){};

		~reverse_iterator(void){};

		reverse_iterator( const reverse_iterator<Iter>& src ){*this = src;};

		reverse_iterator & operator=(reverse_iterator const & rhs){
			if (this != &rhs){
				this->_it = rhs.base();
			}
			return *this;
		};

		/*
		 * Dereference Operators
		 */
		reference operator*() const {
			return *(this->_it);
		};

		pointer operator->() const {
			return &(operator*());
		};

		/*
		 * Relational Operators
		 */
		bool operator==(reverse_iterator const & rhs) const {
			return this->_it == rhs.base();
		};

		bool operator!=(reverse_iterator const & rhs) const {
			return !(*this == rhs);
		};

		bool operator<(reverse_iterator const & rhs) const {
			return this->it < rhs.base();
		};

		bool operator<=(reverse_iterator const & rhs) const {
			return !(rhs < *this);
		};

		bool operator>(reverse_iterator const & rhs) const {
			return rhs < *this;
		};

		bool operator>=(reverse_iterator const & rhs) const {
			return !(*this < rhs);
		};

		/*
		 * Arithmetic Operators
		 */
		reverse_iterator operator+(size_type d){
			reverse_iterator tmp(this->_it - d);
			return tmp;
		};

		reverse_iterator operator-(size_type d){
			reverse_iterator tmp(this->_it + d);
			return tmp;
		};
		//difference operator
		difference_type operator-(reverse_iterator const & rhs) const {
			return rhs.base() - this->it;
		};

		/*
		 * Incrementation/Decrementation Operators
		 */
		reverse_iterator& operator++(){
			this->_it--;
			return *this;
		};

		reverse_iterator operator++(int){
			reverse_iterator tmp(*this);
			this->_it--;
			return tmp;
		};

		reverse_iterator& operator--(){
			this->_it++;
			return *this;
		};

		reverse_iterator operator--(int){
			reverse_iterator tmp(*this);
			this->_it++;
			return tmp;
		};

		/*
		 * Offset Operator
		 */
		reference operator[](size_type i){
			return this->_it[-i];
		}

		/*
		 * Getter
		 */
		iterator_type base(void) const { return this->_it ;}
	private:
		iterator_type _it;

	};

}

#endif
