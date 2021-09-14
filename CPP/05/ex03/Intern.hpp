/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:53:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/10 00:45:14 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(Intern const & src);
	~Intern(void);
	Intern & operator=(Intern const & rhs);

	Form* makeForm(std::string const & name, std::string const & target);
private:
	class InternException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

};

#endif
