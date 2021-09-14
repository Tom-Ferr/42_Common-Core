/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:36:49 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/03 15:49:19 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
# define MATERIA_HPP

# include <iostream>
# include "Character.hpp"

class ICharacter;

class AMateria
{
public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(AMateria const & rhs);
	virtual ~AMateria(void);
	AMateria & operator=(AMateria const & rhs);
protected:
	std::string _type;
public:
	std::string const & getType(void) const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice const & rhs);
	~Ice(void);
	Ice & operator=(Ice const & rhs);

	AMateria* clone() const;
	void use(ICharacter& target);
};

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(Cure const & rhs);
	~Cure(void);
	Cure & operator=(Cure const & rhs);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
