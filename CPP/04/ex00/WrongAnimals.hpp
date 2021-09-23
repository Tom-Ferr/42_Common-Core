/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimals.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:41:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 12:23:42 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & rhs);
	~WrongAnimal(void);
	WrongAnimal & operator=(WrongAnimal const & rhs);

protected:
	std::string _type;
public:
	void makeSound(void) const;
	std::string getType(void) const;

};

class WrongDog : public WrongAnimal
{
public:
	WrongDog(void);
	WrongDog(WrongDog const & rhs);
	~WrongDog(void);
	WrongDog & operator=(WrongDog const & rhs);
	void makeSound(void) const;

};

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat const & rhs);
	~WrongCat(void);
	WrongCat & operator=(WrongCat const & rhs);
	void makeSound(void) const;
};

# endif
