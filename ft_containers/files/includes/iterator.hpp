/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:00:07 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/09 19:32:42 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP
# include <iostream>
# include <utility.hpp>
namespace ft{

	/*
	 * BIDIRECTIONAL_ITERATOR
	 */
	template <typename P, class C>
	class bidirectional_iterator{
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
		bidirectional_iterator(void){};
		bidirectional_iterator(P const ptr) : _ptr(ptr){};
		bidirectional_iterator(bidirectional_iterator const & src){*this = src;};
		~bidirectional_iterator(void){};
		bidirectional_iterator & operator=(bidirectional_iterator const & rhs){
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
		 * Incrementation/Decrementation Operators
		 */
		bidirectional_iterator& operator++(){
			this->_ptr++;
			return *this;
		};

		bidirectional_iterator operator++(int){
			bidirectional_iterator tmp(*this);
			this->_ptr++;
			return tmp;
		};

		bidirectional_iterator& operator--(){
			this->_ptr--;
			return *this;
		};

		bidirectional_iterator operator--(int){
			bidirectional_iterator tmp(*this);
			this->_ptr--;
			return tmp;
		};

		/*
		 * Getter
		 */
		pointer get_ptr() const { return this->_ptr; };
	private:
		pointer _ptr;

	};

	/*
	 * TREE_ITERATOR
	 */
	template <typename K, class C>
	class tree_iterator{
	public:
		/*
		 * Member types
		 */
		typedef	C value_type;
		typedef K key_compare;
		typedef value_type& reference;
		typedef value_type* pointer;

		/*
		 * Orthodox Canonical Form
		 */
		tree_iterator(void)
			: _comp(key_compare()), _node(NIL), _cache(NIL){};
		tree_iterator(Node<value_type>* const node)
			: _comp(key_compare()), _node(node){
				if (node)
					this->_cache = node->content;
			};
		tree_iterator(tree_iterator const & src):_comp(key_compare()){*this = src;};
		~tree_iterator(void){};
		tree_iterator & operator=(tree_iterator const & rhs){
			if (this != &rhs){
				this->_node = rhs._node;
				this->_cache = rhs._cache;
			}
			return *this;
		};

		/*
		 * Dereference Operators
		 */
		reference operator*() const {
			return *(_node->content);
		};

		pointer operator->() const {
			return &(operator*());
		};

		/*
		 * Relational Operators
		 */
		bool operator==(tree_iterator const & rhs) const {
			if(this->_node == NIL || rhs._node == NIL)
				return !this->_node && !rhs._node;
			return _node->content == rhs._node->content;
		};

		bool operator!=(tree_iterator const & rhs) const {
			return !(*this == rhs);
		};

		/*
		 * Incrementation/Decrementation Operators
		 */
		tree_iterator& operator++(){
			if(_node && _node->child[RIGHT] == NIL){
				_node = _node->parent;
			}
			else if (_node && _node->child[RIGHT]
			&& _comp(_cache->first, _node->child[RIGHT]->content->first)){
				_node = _node->child[RIGHT];
			}
			while(_node && !_comp(_cache->first, _node->content->first)){
				_node = _node->parent;
			}
			while(_node && _node->child[LEFT]
			&& _comp(_cache->first, _node->child[LEFT]->content->first)){
				_node = _node->child[LEFT];
			}
			if(_node)
				_cache = _node->content;
			return *this;
		};

		tree_iterator operator++(int){
			tree_iterator tmp(*this);
			this->operator++();
			return tmp;
		};

		tree_iterator& operator--(){
			if(_node && _node->child[LEFT] == NIL){
				_node = _node->parent;
			}
			else if (_node && _node->child[LEFT]
			&& _comp(_node->child[LEFT]->content->first, _cache->first)){
				_node = _node->child[LEFT];
			}
			while(_node && !_comp(_node->content->first, _cache->first)){
				_node = _node->parent;
			}
			while(_node && _node->child[RIGHT]
			&& _comp(_node->child[RIGHT]->content->first, _cache->first)){
				_node = _node->child[RIGHT];
			}
			if(_node)
				_cache = _node->content;
			return *this;
		};

		tree_iterator operator--(int){
			tree_iterator tmp(*this);
			this->operator--();
			return tmp;
		};

	private:
		key_compare			_comp;
		Node<value_type>* 	_node;
		value_type* 		_cache;

	};

	/*
	 * RANDOM_ACCESSL_ITERATOR
	 */
	template <typename P, class C>
	class random_access_iterator : public bidirectional_iterator<P,C>{
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

}

#endif
