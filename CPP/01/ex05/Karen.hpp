/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:02:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 16:48:05 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

class Karen
{
public:
	Karen(void);
	~Karen(void);

	void complain( std::string level );


private:
	void debug( void ) const;
	void info( void ) const;
	void warning( void ) const;
	void error( void ) const;
	typedef void (Karen::*funcs)(void) const;

};

#endif
