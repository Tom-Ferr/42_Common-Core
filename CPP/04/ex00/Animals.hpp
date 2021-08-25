/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:41:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/19 14:32:17 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
public:
	Animal(void);
	Animal(Animal const & rhs);
	virtual ~Animal(void);
	Animal & operator=(Animal const & rhs);

protected:
	std::string _type;
public:
	virtual void makeSound(void) const;
	std::string getType(void) const;

};

class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const & rhs);
	~Dog(void);
	Dog & operator=(Dog const & rhs);
	virtual void makeSound(void) const;

};

class Cat : public Animal
{
public:
	Cat(void);
	Cat(Cat const & rhs);
	~Cat(void);
	Cat & operator=(Cat const & rhs);
	virtual void makeSound(void) const;
};

# endif
