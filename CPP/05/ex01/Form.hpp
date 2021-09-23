/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:53:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/19 17:43:33 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{

	Form(void);
public:
	Form(std::string name, int ex_grade, int sign_grade);
	Form(Form const & src);
	~Form(void);
	Form & operator=(Form const & rhs);

	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getStatus() const;
	void beSigned(Bureaucrat *bur);

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

	class IsSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	std::string const	_name;
	int			const	_sign_grade;
	int			const	_exec_grade;
	bool				_signed;
};

std::ostream & operator<<(std::ostream &o, Form const &rhs);

#endif
