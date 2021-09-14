/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:29:58 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/11 11:30:59 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

typedef struct Data
{
	int			_i;
	char		_c;
	float		_f;
	double		_d;
	std::string _s, _oi, _oc, _of, _od;
} 	Data;

#endif
