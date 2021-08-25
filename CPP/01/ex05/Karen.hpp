/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:02:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/16 23:02:53 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

class Karen{

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:

	Karen(void);
	~Karen(void);

	void complain( std::string level );

	typedef void (Karen::*funcPtr)(void);

};

#endif
