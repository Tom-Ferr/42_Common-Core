/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:47:03 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/11 11:25:42 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
	return ret;
}

Data* deserialize(uintptr_t raw)
{
	Data* ret = reinterpret_cast<Data*>(raw);
	return ret;
}

int main() {

	Data* ptr = new Data;

	std::cout << "before serialization: " << ptr << std::endl;
	uintptr_t raw = serialize(ptr);
	std::cout << "after serialization: " << raw << std::endl;
	Data* ptr2 = deserialize(raw);
	std::cout << "after deserialization: " << ptr2 << std::endl;

	delete ptr2;

	return 0;
}
