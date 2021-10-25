/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 09:14:15 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/23 22:28:10 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP
# include <vector.hpp>

namespace ft{

	template< typename T, class Parent = ft::vector<T> >
	class stack{

	public:

		/*
		 * Member types
		 */
		typedef T value_type;
		typedef Parent container_type;
		typedef size_t size_type;

		/*
		 * Member functions
		 */
		explicit stack(const container_type& ctnr = container_type()) : c(ctnr){};

		bool empty() const { return c.empty(); };

		size_type size() const { return c.size(); };

		value_type& top() { return c.back(); };

		const value_type& top() const { return c.back(); };

		void push(const value_type& val) { c.push_back(val); };

		void pop() { c.pop_back(); };
		
		/*
		 * Friends
		 */
		template <class T2, class Container>
		friend bool operator==(const stack<T2,Container>& lhs, const stack<T2,Container>& rhs);
		template <class T2, class Container>
		friend bool operator< (const stack<T2,Container>& lhs, const stack<T2,Container>& rhs);

	protected:
		container_type c;
	};

	/*
	 * Relational Operators
	 */
	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return lhs.c == rhs.c;
	};

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return !(lhs == rhs);
	};

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return lhs.c < rhs.c ;
	};

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return !(rhs < lhs) ;
	};

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return rhs < lhs ;
	};

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return !(lhs < rhs) ;
	};
}


#endif
