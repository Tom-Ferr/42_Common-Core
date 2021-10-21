/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:18:27 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/21 00:36:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR
# define FT_REVERSE_ITERATOR

# include <iterator_traits.hpp>

namespace ft{
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
		typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iter>::pointer pointer;
		typedef typename ft::iterator_traits<Iter>::reference reference;
		typedef typename ft::iterator_traits<Iter>::value_type value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
		typedef typename Iter::size_type size_type;

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
		 * Incrementation/Decrementation Operators
		 */
		reverse_iterator& operator++(){
			if(_it.curr())
				this->_it--;
			return *this;
		};

		reverse_iterator operator++(int){
			reverse_iterator tmp(*this);
			if(_it.curr())
				this->_it--;
			return tmp;
		};

		reverse_iterator& operator--(){
			if(typeid( iterator_category) == typeid(std::bidirectional_iterator_tag)
			&& _it.curr() == NIL)
				_it.update();
			else
				this->_it++;
			return *this;
		};

		reverse_iterator operator--(int){
			reverse_iterator tmp(*this);
			if(typeid( iterator_category) == typeid(std::bidirectional_iterator_tag)
			&& _it.curr() == NIL)
				_it.update();
			else
				this->_it++;
			return tmp;
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
};

#endif