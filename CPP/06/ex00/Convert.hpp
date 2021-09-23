/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:29:58 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/20 17:45:10 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <cfloat>
# include <climits>

class Convert
{
	Convert(void);
public:
	Convert(char* target);
	Convert(Convert const & src);
	~Convert(void);
	Convert & operator=(Convert const & rhs);

private:
	void Detect(void);
	void Cast(void);
	void NonSense(void);
	void PseudosHandler(int const & size);
	void Format(void);
	void Print(void);

	int			_i, _p;
	char		_c;
	float		_f;
	double		_d;
	std::string _s, _oi, _oc, _of, _od;
};

#endif
