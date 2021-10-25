/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:28:18 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/25 09:51:13 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_HPP
# define FT_SET_HPP

# include <iterator.hpp>
# include <algorithm.hpp>
# include <exception.hpp>
# include <memory>

namespace ft {

	template<typename T, class Compare = std::less<T>,
		class Allocator = std::allocator<T> >
	class set
	{
	public:

		/*
		 * Member types
		 */
		typedef T key_type;
		typedef T value_type;
		typedef Compare key_compare;
		typedef Compare value_compare;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::set_iterator< ft::set<key_type> > iterator;
		typedef ft::set_iterator< ft::set<key_type> > const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename Allocator::template rebind< Node<value_type> >::other a_node;

		/*
		 * Orthodox Canonical Form
		 */

		// constructors
		explicit set	(
							const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()
						) : _root(NIL), _size(0), _comp(comp), _Alloc(alloc){};

		template <class InputIterator>
		set (	InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()
			) :  _root(NIL), _size(0), _comp(comp), _Alloc(alloc){ insert(first, last); };
		// destructor
		~set(void) { this->clear(); };
		//copy constructor
		set (const set & src) : _root(NIL), _size(0){ *this = src; };
		//assign operator
		set & operator=(const set & rhs){
			if(this != &rhs){
				if(this->_root)
					this->clear();
				this->_comp = rhs._comp;
				this->insert(rhs.begin(), rhs.end());
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

		const_iterator begin() const{
			Node<value_type>* b = _root;
			if(!empty()){
				while (b->child[LEFT])
					b = b->child[LEFT];
			}
			return const_iterator(b);
		};

		iterator end(){
			Node<value_type>* b = _root;
			if(!empty()){
				while (b->child[RIGHT])
					b = b->child[RIGHT];
			}
			return ++iterator(b);
		};

		const_iterator end() const{
			Node<value_type>* b = _root;
			if(!empty()){
				while (b->child[RIGHT])
					b = b->child[RIGHT];
			}
			return ++iterator(b); 
		};

		reverse_iterator rbegin(){
			Node<value_type>* b = _root;
			if(!empty()){
				while (b->child[RIGHT])
					b = b->child[RIGHT];
			}
			return reverse_iterator(b);
		};
		const_reverse_iterator rbegin() const{
			Node<value_type>* b = _root;
			if(!empty()){
				while (b->child[RIGHT])
					b = b->child[RIGHT];
			}
			return const_reverse_iterator(b);
		};
		reverse_iterator rend(){
			return reverse_iterator(--begin());
		};
		const_reverse_iterator rend() const{
			return const_reverse_iterator(--begin());
		};

		/*
		 * Capacity
		 */
		size_type size() const { return this->_size; };

		size_type max_size() const{ return -1ul / (sizeof(Node<value_type>) - sizeof(value_type*)); };

		bool empty() const { return this->_size == 0; };


		/*
		 * Modifiers
		 */
		pair<iterator,bool> insert (const value_type& val){
			value_type* new_val = this->_Alloc.allocate(1);
			this->_Alloc.construct(new_val, val);
			Node<value_type>* node = this->n_Alloc.allocate(1);
			this->n_Alloc.construct(node, new_val);
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
			Node<value_type>* node = this->n_Alloc.allocate(1);
			this->n_Alloc.construct(node, new_val);
			Node<value_type>* hint = _root;
			for (; position != end(); position++){
				if (!_comp(*position, *(node->content))){
					hint = position.curr();
					break;
				}
			}
			 
			iterator it = this->sprout(node, hint);
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
				Node<value_type>* node = this->n_Alloc.allocate(1);
				this->n_Alloc.construct(node, new_val);
				iterator it = this->sprout(node, _root);
				bool ret = (&(*it) == new_val);
				if(ret)
					this->_size++;
				else
					this->node_deallocate(node);
			}
		};

		void erase (iterator position){
			if (delete_node(*position))
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
				if (delete_node(*target))
					this->_size--;
			}
		};
		//
		void clear(){
			erase(begin(), end());
		};

		void swap(set& other){
			set<key_type> tmp(*this);
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
		iterator find(const key_type& k) const {
			Node<value_type>* seed = _root;
			bool c;
			while (seed){
				if (k == *(seed->content))
					return iterator(seed);
				c = _comp(k, *(seed->content));
				seed = seed->child[c];
			}
			return end();
		};

		size_type count (const key_type& k) const{
			return !(find(k) == end());
		};

		iterator lower_bound (const key_type& k){
			iterator it;
			for(it = begin(); it != end(); it++){
				if ((k <= *it))
					break;
			}
			return it;
		};

		const_iterator lower_bound (const key_type& k) const{
			return const_iterator(lower_bound(k));
		};

		iterator upper_bound (const key_type& k){
			iterator it = lower_bound(k);
			if(it != end() && *it == k)
				it++;
			return it;
		};

		const_iterator upper_bound (const key_type& k) const{
			return const_iterator(upper_bound(k));
		};

		pair<iterator,iterator> equal_range (const key_type& k){
			return ft::make_pair(lower_bound(k), upper_bound(k));
		};

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		};

		/*
		 * Observers
		 */
		key_compare key_comp() const{ return _comp; };

		value_compare value_comp() const { return value_compare(_comp); };

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
			z->child[other] = z->parent->child[side];
			if (z->child[other])
				z->child[other]->parent = z;
			z->parent->child[side] = z;
			rotation(z->parent, other);
			recolor(z->parent, RED);
		};

		//Insertion
		void recolor(Node<value_type>* seed, const bool& clr){
			bool k = RIGHT;
			seed->child[RIGHT]->color = clr;
			seed->child[LEFT]->color = clr;
			if(seed->parent){
				seed->color = !clr;
				if (seed->parent->child[k] != seed)
					k = LEFT;
				if(seed->color == RED)
					check_conflict(seed->parent, k);
			}
			else
				seed->color = BLACK;
		};

		void check_conflict(Node<value_type>* mid, const bool& k){
			bool c = RIGHT;
			if (mid == NIL || mid->color == BLACK)
				return;
			if (mid->parent->child[c] != mid)
				c = LEFT;
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
				if (*(new_node->content) == *(seed->content))
					return iterator(seed);
				k = _comp(*(new_node->content), *(seed->content));
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
				if (*(seed->content) == key)
					break;
				side = _comp(key, *(seed->content));
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
				else if(del->child[RIGHT] == NIL){
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
					Node<value_type> 	tmp;
					while(del->child[LEFT] || del->child[RIGHT]){
						heir = del->child[RIGHT];
						while (heir->child[LEFT])
							heir = heir->child[LEFT];
						tmp = *heir;
						transplant(del, heir);
						estate(del, heir);
						if(tmp.parent == del){
							del->parent = heir;
							heir->child[RIGHT] = del;
						}
						else{
							del->parent = tmp.parent;
							del->parent->child[LEFT] = del;
						}
						if(heir->child[RIGHT])
							heir->child[RIGHT]->parent = heir;
						if(heir->child[LEFT])
							heir->child[LEFT]->parent = heir;
						if(del->child[RIGHT])
							del->child[RIGHT]->parent = del;
						if(del->child[LEFT])
							del->child[LEFT]->parent = del;
					}
					seed = del->parent;
					if (seed->child[LEFT] == del){
						seed->child[LEFT] = NIL;
						side = LEFT;
					}
					else{
						seed->child[RIGHT] = NIL;
						side = RIGHT;
					}
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
			this->n_Alloc.destroy(node);
			this->n_Alloc.deallocate(node, 1);
		}

		/*
		 * Attributes
		 */

		Node<value_type>*	_root;
		size_type 			_size;
		key_compare			_comp;
		allocator_type 		_Alloc;
		a_node 				n_Alloc;
	};

	/*
	 * Non-member function overloads
	 */
	template <class T, class Compare, class Alloc>
	bool operator==(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs){
		if(lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	};
	template <class T, class Compare, class Alloc>
	bool operator!=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs){
		return !(lhs == rhs);
	};
	template <class T, class Compare, class Alloc>
	bool operator< (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};
	template <class T, class Compare, class Alloc>
	bool operator<=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs){
		return !(rhs < lhs);
	};
	template <class T, class Compare, class Alloc>
	bool operator> (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs){
		return rhs < lhs;
	};
	template <class T, class Compare, class Alloc>
	bool operator>=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs){
		return !(lhs < rhs);
	};

	template <class T, class Compare, class Alloc>
  	void swap (const set<T,Compare,Alloc>& x, const set<T,Compare,Alloc>& y){ x.swap(y); };
};
#endif
