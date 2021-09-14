/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:53:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/09 10:55:43 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCRETIONFORM_HPP
# define SHRUBBERYCRETIONFORM_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{

public:
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(Form const & src);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

	void execute(Bureaucrat const & executor) const;
};

#endif
