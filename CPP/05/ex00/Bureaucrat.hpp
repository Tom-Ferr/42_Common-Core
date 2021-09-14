/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:53:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/04 15:18:28 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);
	Bureaucrat & operator=(Bureaucrat const & rhs);

	std::string getName() const;
	int getGrade() const;
	void inGrade();
	void deGrade();

private:
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	std::string _name;
	int			_grade;
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
