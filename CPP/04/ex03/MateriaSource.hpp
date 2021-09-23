/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:36:49 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/18 11:31:36 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "Materia.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	~MateriaSource(void);
	MateriaSource & operator=(MateriaSource const & rhs);

private:
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
	private:
		AMateria* _inventory[4];
};

#endif
