/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 23:36:15 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/03 00:16:11 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		pair (const pair<first_type,second_type>& pr){*this = pr};
		pair (const first_type& a, const second_type& b)
			: first(a), second(b){};
		pair & operator=(const pair & rhs){
			if(this != &rhs){
				first = rhs.first;
				second = rhs.second;
			}
			return(*this)
		}

		/*
		 * Member Variables
		 */
		T1 first;
		T2 second;
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
}
