/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:53:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/20 09:22:37 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{

	Form(void);
public:
	Form(std::string name, std::string target, int ex_grade, int sign_grade);
	Form(Form const & src);
	virtual ~Form(void);
	Form & operator=(Form const & rhs);

	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getStatus() const;
	std::string getTaget() const;
	void beSigned(Bureaucrat const & bur);
	virtual void execute(Bureaucrat const & executor) const = 0;

protected:
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

	class IsSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class IsNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	std::string const	_name, _target;
	int			const	_sign_grade, _exec_grade;
	bool				_signed;
};

std::ostream & operator<<(std::ostream &o, Form const &rhs);

#endif
