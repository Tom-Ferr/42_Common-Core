/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:28:18 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/09 01:02:43 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include <iterator.hpp>
# include <algorithm.hpp>
# include <exception.hpp>
# include <memory>

namespace ft {

	template<typename Key, typename T, class Compare = std::less<Key>,
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
		typedef ft::tree_iterator<key_compare, value_type> iterator;
		typedef ft::tree_iterator<key_compare, value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename Allocator::template rebind<value_type>::other a_node;

		/*
		 * Orthodox Canonical Form
		 */

		// constructors
		explicit map	(
							const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()
						) : _root(NIL), _size(0), _comp(comp), _Alloc(alloc){};

		// template <class InputIterator>
		// map (	InputIterator first, InputIterator last,
		// 		const key_compare& comp = key_compare(),
		// 		const allocator_type& alloc = allocator_type()
		// 	) : _comp(comp), _Alloc(alloc), _size(0), _root(NIL)
		// {
		// 	insert(first, last);
		// };
		//destructor
		// ~map(void) { this->clear(); };
		//copy constructor
		map (const map & src) { *this = src; };
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
		iterator begin(){
			Node<value_type>* b = _root;
			while (b->child[LEFT])
				b = b->child[LEFT];
			return iterator(b);
		};

		const_iterator begin() const{ return const_iterator(this->_Data); };

		iterator end(){
			Node<value_type>* e = _root;
			while (e->child[RIGHT])
				e = e->child[RIGHT];
			return iterator(e);
		};

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
			pair<iterator, bool> pr = insert(ft::make_pair(k, mapped_type()));
			return pr.first->second;
		};

		/*
		 * Modifiers
		 */
		pair<iterator,bool> insert (const value_type& val){
			value_type* new_val = this->_Alloc.allocate(1);
			this->_Alloc.construct(new_val, val);
			Node<value_type>* node = new Node<value_type>(new_val);
			iterator it = sprout(node);
			bool ret = (&(*it) == new_val);
			if(ret)
				this->_size++;
			return ft::make_pair(it, ret);
		};

		// iterator insert (iterator position, const value_type& val){
		//
		// };
		template <class InputIterator>
 		// void insert (InputIterator first, InputIterator last){
		//
		// };
		// iterator erase (iterator position){
		//
		// };
		//
		// size_type erase (const key_type& k){
		//
		// };
		//
		// iterator erase (iterator first, iterator last){
		//
		// };
		//
		// void clear(){
		//
		// };

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
			Node<value_type>* seed = _root;
			bool c;
			while (seed){
				if (k == seed->content->first)
					return iterator(seed);
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
		void rotation(Node<value_type>* y, const bool& side){
			bool other = !side;
			Node<value_type>* tmp = y->parent->parent;
			if(tmp){
				for (int i = 0; i < 2; i++) {
					if (tmp->child[i] == y->parent){
						tmp->child[i] = y;
						break;
					}
				}
			}
			else
				this->_root = y;
			y->parent->child[other] = y->child[side];
			y->child[side] = y->parent;
			y->parent = tmp;
			y->child[side]->parent = y;
			recolor(y, RED);
		};

		void double_rotation(Node<value_type>* z, const bool& side){
			bool other = !side;
			z->child[other]->parent = z->parent;
			z->parent->child[side] = z->child[other];
			z->parent = z->child[other];
			z->parent->child[side] = z;
			z->child[other] = NIL;
			rotation(z->parent, other);
		};

		void recolor(Node<value_type>* seed, const bool& clr){
			bool k = false;
			for(int i = 0; i < 2; i++){
				seed->child[i]->color = clr;
			}
			if(seed->parent){
				seed->color = !clr;
				if (seed->parent->child[k] != seed)
					k = true;
				if(seed->color == RED)
					check_conflict(seed->parent, k);
			}
			else
				seed->color = BLACK;
		};

		void check_conflict(Node<value_type>* mid, const bool& k){
			bool c = false;
			if (mid == NIL || mid->color == BLACK)
				return;
			if (mid->parent->child[c] != mid)
				c = true;
			if (mid->parent->child[!c] && mid->parent->child[!c]->color){
				recolor(mid->parent, BLACK);
				return ;
			}
			if (c == k)
				rotation(mid, !k);
			else
				double_rotation(mid, c);
			if(mid->color == RED)
				check_conflict(mid->parent, c);
		};

		iterator sprout(Node<value_type>* new_node){
			Node<value_type>* seed = _root;
			bool k;
			if((new_node->color = !this->empty()) == BLACK)
				return	(_root = new_node, iterator(_root));
			while (seed){
				if (new_node->content->first == seed->content->first)
					return iterator(seed);
				k = _comp(new_node->content->first, seed->content->first);
				new_node->parent = seed;
				seed = seed->child[k];

			}
			seed = new_node;
			seed->parent->child[k] = new_node;
			if (seed->parent->parent)
				check_conflict(seed->parent, k);
			return iterator(seed);
		};

		/*
		 * Attributes
		 */

		Node<value_type>*	_root;
		size_type 			_size;
		key_compare			_comp;
		allocator_type 		_Alloc;
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
