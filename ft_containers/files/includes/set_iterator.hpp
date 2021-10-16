/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:58:27 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/15 18:16:23 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_ITERATOR_HPP
# define FT_SET_ITERATOR_HPP
# include <utility.hpp>
namespace ft{
    
    /*
	 * set_iterator
	 */
	template <typename K, class C>
	class set_iterator{
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
		set_iterator(void)
			: _comp(key_compare()), _node(NIL), _cache(NIL){};
		set_iterator(Node<value_type>* const node)
			: _comp(key_compare()), _node(node){
				if (node)
					this->_cache = node->content;
			};
		set_iterator(set_iterator const & src):_comp(key_compare()){*this = src;};
		~set_iterator(void){};
		set_iterator & operator=(set_iterator const & rhs){
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
		bool operator==(set_iterator const & rhs) const {
			if(this->_node == NIL || rhs._node == NIL)
				return !this->_node && !rhs._node;
			return _node->content == rhs._node->content;
		};

		bool operator!=(set_iterator const & rhs) const {
			return !(*this == rhs);
		};

		/*
		 * Incrementation/Decrementation Operators
		 */
		set_iterator& operator++(){
			if(_node && _node->child[RIGHT] == NIL){
				_node = _node->parent;
			}
			else if (_node && _node->child[RIGHT]
			&& _comp(_cache, _node->child[RIGHT]->content)){
				_node = _node->child[RIGHT];
			}
			while(_node && !_comp(_cache, _node->content)){
				_node = _node->parent;
			}
			while(_node && _node->child[LEFT]
			&& _comp(_cache, _node->child[LEFT]->content)){
				_node = _node->child[LEFT];
			}
			if(_node)
				_cache = _node->content;
			return *this;
		};

		set_iterator operator++(int){
			set_iterator tmp(*this);
			this->operator++();
			return tmp;
		};

		set_iterator& operator--(){
			if(_node && _node->child[LEFT] == NIL){
				_node = _node->parent;
			}
			else if (_node && _node->child[LEFT]
			&& _comp(_node->child[LEFT]->content, _cache)){
				_node = _node->child[LEFT];
			}
			while(_node && !_comp(_node->content, _cache)){
				_node = _node->parent;
			}
			while(_node && _node->child[RIGHT]
			&& _comp(_node->child[RIGHT]->content, _cache)){
				_node = _node->child[RIGHT];
			}
			if(_node)
				_cache = _node->content;
			return *this;
		};

		set_iterator operator--(int){
			set_iterator tmp(*this);
			this->operator--();
			return tmp;
		};

	private:
		key_compare			_comp;
		Node<value_type>* 	_node;
		value_type* 		_cache;

	};

}
#endif