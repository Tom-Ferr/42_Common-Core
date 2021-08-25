/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:41:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/19 14:36:20 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
public:
	Brain(void);
	Brain(Brain const & rhs);
	~Brain(void);
	Brain & operator=(Brain const & rhs);


	std::string* _ideas;

};

# endif
