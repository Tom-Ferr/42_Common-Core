/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:28:18 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/16 16:28:02 by tde-cama         ###   ########.fr       */
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
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::map_iterator<key_compare, value_type> iterator;
		typedef ft::map_iterator<key_compare, value_type> const_iterator;
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

		template <class InputIterator>
		map (	InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()
			) : _comp(comp), _Alloc(alloc), _size(0), _root(NIL) { insert(first, last); };
		// destructor
		~map(void) { this->clear(); };
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
			if(!empty()){
				while (b->child[LEFT])
					b = b->child[LEFT];
			}
			return iterator(b);
		};

		const_iterator begin() const{ return const_iterator(begin()); };

		iterator end(){ return iterator(); };

		const_iterator end() const{ return const_iterator(); };

		reverse_iterator rbegin(){
			Node<value_type>* b = _root;
			if(!empty()){
				while (b->child[RIGHT])
					b = b->child[RIGHT];
			}
			return reverse_iterator(b);
		};
		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(rbegin());
		};
		reverse_iterator rend(){
			return reverse_iterator();
		};
		const_reverse_iterator rend() const{
			return const_reverse_iterator();
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
			iterator it = this->sprout(node, _root);
			bool ret = (&(*it) == new_val);
			if(ret)
				this->_size++;
			else
				this->node_deallocate(node);
			return ft::make_pair(it, ret);
		};

		iterator insert (iterator position, const value_type& val){
			value_type* new_val = this->_Alloc.allocate(1);
			this->_Alloc.construct(new_val, val);
			Node<value_type>* node = new Node<value_type>(new_val);
			Node<value_type> hint = Node<value_type>(&(*position));
			iterator it = this->sprout(node, &hint);
			bool ret = (&(*it) == new_val);
			if(ret)
				this->_size++;
			else
				this->node_deallocate(node);
			return it;
		};
		
		template <class InputIterator>
 		void insert (InputIterator first, InputIterator last){
			for (; first != last; first++){
				value_type* new_val = this->_Alloc.allocate(1);
				this->_Alloc.construct(new_val, *first);
				Node<value_type>* node = new Node<value_type>(new_val);
				iterator it = this->sprout(node, _root);
				bool ret = (&(*it) == new_val);
				if(ret)
					this->_size++;
				else
					this->node_deallocate(node);
			}
		};

		void erase (iterator position){
			if (delete_node(position->first))
				this->_size--;
		};
		
		size_type erase (const key_type& k){
			if (delete_node(k)){
				this->_size--;
				return 1;
			}
			return 0;
		};
		//
		void erase (iterator first, iterator last){
			iterator next, target;
			for (next = first; next != last;){
				target = next;
				next++;
				if (delete_node(target->first))
					this->_size--;
			}
		};
		//
		void clear(){
			erase(begin(), end());
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
		//Red-Black tree functions

		//rotaions
		void rotation(Node<value_type>* y, const bool& side){
			bool other = !side;
			Node<value_type>* tmp = y->parent->parent;
			if(tmp){
				if (tmp->child[RIGHT] == y->parent)
					tmp->child[RIGHT] = y;
				else
					tmp->child[LEFT] = y;
			}
			else{

				this->_root = y;
			}
			y->parent->child[other] = y->child[side];
			if (y->child[side])
				y->child[side]->parent =  y->parent;
			y->child[side] = y->parent;
			y->parent = tmp;
			y->child[side]->parent = y;
		};

		void double_rotation(Node<value_type>* z, const bool& side){
			bool other = !side;
			z->child[other]->parent = z->parent;
			z->parent->child[side] = z->child[other];
			z->parent = z->child[other];
			z->parent->child[side] = z;
			z->child[other] = NIL;
			rotation(z->parent, other);
			recolor(z->parent, RED);
		};

		//Insertion
		void recolor(Node<value_type>* seed, const bool& clr){
			bool k = false;
			seed->child[RIGHT]->color = clr;
			seed->child[LEFT]->color = clr;
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
			if (c == k){
				rotation(mid, !k);
				recolor(mid, RED);
			}
			else
				double_rotation(mid, c);
			if(mid->color == RED)
				check_conflict(mid->parent, c);
		};

		iterator sprout(Node<value_type>* new_node, Node<value_type>* hint){
			Node<value_type>* seed = hint;
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

		// Delete
		void fix_cases(Node<value_type>* & seed, Node<value_type>* & db, bool const & side){
			Node<value_type>* bro = seed->child[!side];
			if (bro->color == RED){
				bro->color = BLACK;
				seed->color = RED;
				rotation(bro, side);
				bro = seed->child[!side];
			}
			if ( (bro->child[side] == NIL || bro->child[side]->color == BLACK)
			&& (bro->child[!side] == NIL || bro->child[!side]->color == BLACK) ){
				bro->color = RED;
				if (seed->color == BLACK){
					db = seed;
					seed = seed->parent;
				}
				else{
					seed->color = BLACK;
					seed = NIL;
				}
			}
			else{
				if ( bro->child[!side] == NIL || bro->child[!side]->color == BLACK ){
					bro->child[side]->color = BLACK;
					bro->color = RED;
					rotation(bro->child[side], !side);
					bro = seed->child[!side];
				}
				bro->color = seed->color;
				seed->color = BLACK;
				if (seed->parent == NIL)
					seed->color = BLACK;
				bro->child[!side]->color = BLACK;
				rotation(seed->child[!side], side);
				seed = NIL;
			}	
		};
		void fix_tree(Node<value_type>* & seed, bool const & side){
			Node<value_type>* db;
			if(seed)
				db = seed->child[side];
			while ( seed && (db == NIL || db->color == BLACK) ){
				if(db == seed->child[LEFT])
					fix_cases(seed, db, LEFT);
				else
					fix_cases(seed, db, RIGHT);
			}
			if (seed)
				seed->color = BLACK;
		};

		void transplant(Node<value_type>* & del, Node<value_type>* & heir){
			if (del->parent == NIL)
				_root = heir;
			else if (del == del->parent->child[LEFT])
				del->parent->child[LEFT] = heir;
			else
				del->parent->child[RIGHT] = heir;
			if(heir)
				heir->parent = del->parent;
		};

		void estate(Node<value_type>* & del, Node<value_type>* & heir){
			Node<value_type> 	tmp;

			tmp.child[LEFT] = heir->child[LEFT];
			tmp.child[RIGHT] = heir->child[RIGHT];
			tmp.color = heir->color;

			heir->child[LEFT] = del->child[LEFT];
			heir->child[RIGHT] = del->child[RIGHT];
			heir->color = del->color;

			del->child[LEFT] = tmp.child[LEFT];
			del->child[RIGHT] = tmp.child[RIGHT];
			del->color = tmp.color;
		};

		bool delete_node(key_type const & key){
			Node<value_type>* 	seed = _root;
			Node<value_type>* 	del;
			Node<value_type>* 	heir;
			
			bool side, o_clr;

			while (seed){
				if (seed->content->first == key)
					break;
				side = _comp(key, seed->content->first);
				seed = seed->child[side];
			}
			if (seed){
				seed = seed->parent;
				if (seed == NIL)
					del = _root;
				else
					del = seed->child[side];
				o_clr = del->color;
				if(del->child[LEFT] == NIL){
					heir = del->child[RIGHT];
					transplant(del, heir);
					if(heir){
						del->parent = heir;
						estate(del, heir);
						heir->child[RIGHT] = NIL;
						if(heir->child[LEFT])
							heir->child[LEFT]->parent = heir;
					}
				}
				else if(seed->child[RIGHT] == NIL){
					heir = del->child[LEFT];
					transplant(del, heir);
					if(heir){
						del->parent = heir;
						estate(del, heir);
						heir->child[LEFT] = NIL;
						if(heir->child[RIGHT])
							heir->child[RIGHT]->parent = heir;
					}
				}
				else{
					while(del->child[LEFT] || del->child[RIGHT]){
						heir = del->child[RIGHT];
						while (heir->child[LEFT])
							heir = heir->child[LEFT];
						transplant(del, heir);
						if(heir->parent == del)
							del->parent = heir;
						else
							del->parent = heir->parent;
						estate(del, heir);
						if(heir->child[RIGHT])
							heir->child[RIGHT]->parent = heir;
						if(heir->child[LEFT])
							heir->child[LEFT]->parent = heir;
					}
					if (del->parent->child[LEFT] == del)
						del->parent->child[LEFT] = NIL;
					else
						del->parent->child[RIGHT] = NIL;
				}
				o_clr = del->color;
				node_deallocate(del);
				if (o_clr == BLACK)
					fix_tree(seed, side);
				return true;
			}
			return false;
		};
		//end of Red-Black tree functions
		void node_deallocate(Node<value_type>* & node){
			this->_Alloc.destroy(node->content);
			this->_Alloc.deallocate(node->content, 1);
			delete node;
		}

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
