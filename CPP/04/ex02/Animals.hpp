/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:41:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 20:23:15 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMALS_HPP
# define AANIMALS_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
public:
	AAnimal(void);
	AAnimal(AAnimal const & rhs);
	virtual ~AAnimal(void);
	AAnimal & operator=(AAnimal const & rhs);

protected:
	std::string _type;
public:
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;

};

class Dog : public AAnimal
{
public:
	Dog(void);
	Dog(Dog const & rhs);
	virtual ~Dog(void);
	Dog & operator=(Dog const & rhs);
	virtual void makeSound(void) const;

	Brain* getBrain(void) const;
	std::string mindReader(void) const;

private:
	Brain* _brain;

};

class Cat : public AAnimal
{
public:
	Cat(void);
	Cat(Cat const & rhs);
	virtual ~Cat(void);
	Cat & operator=(Cat const & rhs);
	virtual void makeSound(void) const;

	Brain* getBrain(void) const;
	std::string mindReader(void) const;

private:
	Brain* _brain;
};

# endif
