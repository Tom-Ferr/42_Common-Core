/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:47:19 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/15 18:16:59 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_HPP
# define FT_EXCEPTION_HPP
# include <exception>

namespace ft{

	class out_of_range : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
}

#endif
