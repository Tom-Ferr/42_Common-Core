/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 23:36:15 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/18 15:36:47 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITY_HPP
# define FT_UTILITY_HPP

# define NIL 	nullptr
# define RED 	true
# define BLACK 	false
# define LEFT 	1
# define RIGHT 	0

namespace ft{

	/*
	 * PAIR
	 */
	template<typename T1, typename T2>
	struct pair{

		/*
		 * Member types
		 */
		typedef T1 first_type;
		typedef T2 second_type;

		/*
		 * Member Functions
		 */
		pair() : first(), second(){};
		template< class U1, class U2 >
		pair( const pair<U1, U2>& pr )
			: first(pr.first), second(pr.second){};
		pair (const first_type& a, const second_type& b)
			: first(a), second(b){};


		/*
		 * Member Variables
		 */
		first_type first;
		second_type second;
	};

	/*
	 * Relational Operators
	 */
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return lhs.first==rhs.first && lhs.second==rhs.second;
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(lhs==rhs);
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(rhs<lhs);
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return rhs<lhs;
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(lhs<rhs);
	}

	/*
	 * MAKE PAIR
	 */
	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y){
		return pair<T1,T2>(x,y);
	}

	/*
	 * NODE
	 */
	template<typename T>
	struct Node{
		Node(T* val = NIL) :
		 parent(NIL), content(val), color(RED){
			child[0] = NIL;
			child[1] = NIL;
		};
		Node<T> operator=(Node<T> const & rhs){
			if (this != &rhs){
				this->parent = rhs.parent;
				this->content = rhs.content;
				this->child[0] = rhs.child[0];
				this->child[1] = rhs.child[1];
				this->color = rhs.color;
			}
			return *this;
		};

		Node<T>* 				parent;
		Node<T>* 				child[2];
		T* 						content;
		bool  					color;
	};
}

#endif
