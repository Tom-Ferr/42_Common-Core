/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:47:19 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/02 18:00:10 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP
# include <exception>

namespace ft{

	class out_of_range : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
}

#endif
