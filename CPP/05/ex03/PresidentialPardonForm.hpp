/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:53:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/19 18:40:41 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm : public Form
{

	PresidentialPardonForm(void);
public:
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	~PresidentialPardonForm(void);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

	void execute(Bureaucrat const & executor) const;
};

#endif
