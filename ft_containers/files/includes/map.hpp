/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:28:18 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/06 00:24:00 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include <iterator.hpp>
# include <algorithm.hpp>
# include <exception.hpp>
# include <memory>

# define NIL 	nullptr
# define RED 	true
# define BLACK 	false
# define LEFT 	1
# define RIGHT 	0

namespace ft {


	template<typename Key, typename T, class Compare = less<Key>,
		class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
	public:

		/*
		 * Member types
		 */
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::bidirectional_iterator<pointer, value_type> iterator;
		typedef ft::bidirectional_iterator<const_pointer, value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		/*
		 * Orthodox Canonical Form
		 */

		// constructors
		explicit map	(
							const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()
						) : _comp(comp), _Alloc(alloc), _size(0), _root(NIL){};

		template <class InputIterator>
		map (	InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()
			) : _comp(comp), _Alloc(alloc), _size(0), _root(NIL)
		{
			insert(first, last);
		};
		//destructor
		~map(void) { this->clear() };
		//copy constructor
		map (const map & src) { *this = src };
		//assign operator
		map & operator=(const map & rhs){
			if(this != &rhs){
				this->_root = rhs._root;
				this->_size = rhs._size;
				this->_comp = rhs._comp;
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

		bool empty() const { return this->_size == 0; };

		/*
		 * Element access
		 */
		mapped_type& operator[] (const key_type& k){
			pair<iterator, bool> pr = insert(make_pair(k, mapped_type()))
			return pr->first->second;
		};

		/*
		 * Modifiers
		 */
		pair<iterator,bool> insert (const value_type& val){
			value_type* new_val = this->_Alloc.allocate(1);
			*new_val = val;
			Node* node = new Node(new_val);
			iterator it = sprout(node);
			bool ret = it == new_val;
			if(ret)
				this->_size++;
			return ft::make_pair(it, ret);
		};

		iterator insert (iterator position, const value_type& val){
			// value_type* new_val = this->_Alloc.allocate(1);
			// *new_val = val;
			// Node* node = new Node(new_val);
			// iterator it = sprout(node);
			// bool done = it == new_val;
			// if(done)
			// 	this->_size++;
			// return it;
		};
		// template <class InputIterator>
 		// void insert (InputIterator first, InputIterator last){
		// 	new_val = this->_Alloc.allocate(1);
		// 	*new_val = val;
		// 	Node* node = new Node(new_val);
		//
		// 	this->_size++;
		// };
		iterator erase (iterator position){

		};

		size_type erase (const key_type& k){
			
		};

		iterator erase (iterator first, iterator last){

		};

		void clear(){

		};

		void swap(map& other){
			map<key_type, mapped_type> tmp(*this);
			*this = other;
			other = tmp;
		};

		/*
		 * Allocator
		 */
		allocator_type get_allocator() const{ return this->_Alloc; };

		/*
		 * Operations
		 */
		iterator find(const key_type& k){
			Node* seed = _root;
			bool c;
			while (seed){
				if (k == seed->content->first)
					return iterator(seed->content);
				if ((c = _comp(k, seed->content->first))){
					seed = seed->child[c];
				}
			}
			return end();
		};

		size_type count (const key_type& k) const{
			return !(find(k) == end());
		};

		iterator lower_bound (const key_type& k){
			iterator it;
			for(it = begin(); it != end(); it++){
				if (!(k < it->content->first))
					break;
			}
			return it;
		};

		const_iterator lower_bound (const key_type& k) const{
			return const_iterator(lower_bound(k));
		};

		iterator upper_bound (const key_type& k){
			iterator it = lower_bound(k);
			if(it != end() && it->content == k)
				it++;
			return it;
		};

		const_iterator upper_bound (const key_type& k) const{
			return const_iterator(upper_bound(k));
		};

		pair<iterator,iterator> equal_range (const key_type& k){
			return make_pair(lower_bound(k), upper_bound(k));
		};

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
			return make_pair(lower_bound(k), upper_bound(k));
		};

		/*
		 * Observers
		 */
		key_compare key_comp() const{ return _comp; };

	protected:
		/*
		 * Protected Methods
		 */
		//Red-Black tree
		void rotation(node* y, const bool& side){
			bool other = side+1 % 2;
			value_type* tmp = y->parent->parent;
			if(tmp){
				for (int i = 0; i < 2; i++) {
					if (tmp->child[i] == y->parent)
					tmp->child[i] = y; break;
				}
			}
			else
				this->_root = y;
			y->parent->child[other] = y->child[side];
			y->child[side] = y->parent;
			y->parent = tmp;
			y->child[side].parent = y;
			recolor(y, RED)
		};

		void double_rotation(node* z, const bool& side){
			bool other = side+1 % 2;
			z->child[other].parent = z->parent;
			z->parent.child[side] = z->child[other];
			z->parent = z.child[other];
			z->parent.child[side] = z;
			rotation(z->parent, other);
		};

		void recolor(Node* seed, const bool& clr){
			bool k = false;
			for(Node* node : seed->child){
				node->color = clr
			}
			if(seed->parent){
				seed->color = clr+1 % 2;
				if (seed->parent->child[k] != seed)
					k++;
				check_conflict(seed->parent, k);
			}
			else
				seed->color = BLACK;
		};

		void check_conflict(Node* mid, const bool& k){
			bool c = false;
			if (mid->color == BLACK)
				return;
			if (mid->parent->child[c] == mid)
				c++;
			if (mid->parent->child[c] && mid->parent->child[c]->color)
				return (recolor(mid->parent, BLACK), );
			if (c == k)
				rotation(mid, k);
			else
				double_rotation(mid, k);
			check_conflict(mid->parent, c);
		};

		iterator sprout(Node* new_node){
			Node* seed = _root;
			bool k;
			if(new_node->color == BLACK)
				return	(_root = new_node, iterator(_root->content));
			while (seed){
				if (new_node->content->first == seed->content->first)
					return iterator(seed->content);
				if ((k = _comp(new_node->content->first, seed->content->first))){
					new_node->parent = seed;
					seed = seed->child[k];
				}
			}
			seed = new_node;
			check_conflict(seed->parent, k)
			return iterator(seed->content);
		};
		//Aux methods
		template <typename T>
		void swap_aux(T& a, T& b){
			T tmp;
			tmp = a;
			a = b;
			b = tmp;
		};

		/*
		 * Attributes
		 */
		struct Node{
			Node(value_type* val = NIL) :
			content(val), parent(NIL), color(ft::map::empty()), child({NIL, NIL}){};

			Node* 		parent;
 			Node* 		child[2];
 			value_type* content;
			bool  		color;
 		};

		Node*			_root;
		size_type 		_size;
		key_compare		_comp;
		allocator_type 	_Alloc;
	};

	/*
	 * Non-member function overloads
	 */
	template <typename T, class Alloc>
	bool operator==(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};
	template <typename T, class Alloc>
	bool operator!=(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		return !(lhs == rhs);
	};
	template <typename T, class Alloc>
	bool operator< (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};
	template <typename T, class Alloc>
	bool operator<=(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		return !(rhs < lhs);
	};
	template <typename T, class Alloc>
	bool operator> (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		return rhs < lhs;
	};
	template <typename T, class Alloc>
	bool operator>=(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		return !(lhs < rhs);
	};

	template <class T, class Alloc>
  	void swap (map<T,Alloc>& x, map<T,Alloc>& y){ x.swap(y); };
};
#endif
