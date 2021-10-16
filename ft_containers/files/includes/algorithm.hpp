/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:38:45 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/15 18:17:07 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHM_HPP
# define FT_ALGORITHM_HPP

namespace ft{

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(
									InputIterator1 first1,
									InputIterator1 last1,
									InputIterator2 first2,
									InputIterator2 last2
								)
	{
		while (first1 != last1) {
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}


	template <class InputIterator1, class InputIterator2>
	bool equal	(
					InputIterator1 first1,
					InputIterator1 last1,
					InputIterator2 first2
				)
	{
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
}

#endif
