/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:58:27 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/21 16:48:43 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_ITERATOR_HPP
# define FT_MAP_ITERATOR_HPP

# include <utility.hpp>

namespace ft{
    
    /*
	 * map_iterator
	 */
	template <class T>
	class map_iterator{
	public:
		/*
		 * Member types
		 */
		typedef	typename T::value_type value_type;
		typedef typename T::key_compare key_compare;
		typedef value_type& reference;
		typedef value_type* pointer;
        typedef typename T::difference_type difference_type;
		typedef typename T::size_type size_type;
        typedef typename std::bidirectional_iterator_tag iterator_category;

		/*
		 * Orthodox Canonical Form
		 */
		map_iterator(void)
			: _comp(key_compare()), _node(NIL), _cache(NIL){};
		map_iterator(Node<value_type>* const node)
			: _comp(key_compare()), _node(node){
				if (node)
					this->_cache = node->content;
			};
		map_iterator(map_iterator const & src):_comp(key_compare()){*this = src;};
		~map_iterator(void){};
		map_iterator & operator=(map_iterator const & rhs){
			if (this != &rhs){
				this->_node = rhs._node;
				this->_cache = rhs._cache;
				this->_prev = rhs._prev;
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
		bool operator==(map_iterator const & rhs) const {
			if(this->_node == NIL || rhs._node == NIL)
				return !this->_node && !rhs._node;
			return *(_node->content) == *(rhs._node->content);
		};

		bool operator!=(map_iterator const & rhs) const {
			return !(*this == rhs);
		};

		/*
		 * Incrementation/Decrementation Operators
		 */
		map_iterator& operator++(){
			_prev = _node;
			if(_node == NIL)
				_node = _prev;
			else{
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
			}
			if(_node)
				_cache = _node->content;
			return *this;
		};

		map_iterator operator++(int){
			map_iterator tmp(*this);
			this->operator++();
			return tmp;
		};

		map_iterator& operator--(){
			if(_node == NIL)
				_node = _prev;
			else{
				_prev = _node;
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
			}
			if(_node)
				_cache = _node->content;
			return *this;
		};

		map_iterator operator--(int){
			map_iterator tmp(*this);
			this->operator--();
			return tmp;
		};

		Node<value_type>* curr(){ return this->_node; };
		void update(){ _node = _prev; };

	private:
		key_compare			_comp;
		Node<value_type>* 	_node;
		Node<value_type>* 	_prev;
		value_type* 		_cache;

	};

}
#endif