/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:53:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/20 09:26:52 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm : public Form
{

	RobotomyRequestForm(void);
public:
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	~RobotomyRequestForm(void);
	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

	void execute(Bureaucrat const & executor) const;
};

#endif
