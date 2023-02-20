/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:04:35 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/20 17:12:09 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heads/Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer Default constructor.\n";
}

Serializer::Serializer(Serializer const&)
{
	std::cout << "Serializer Copy constructor.\n";
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer Destructor.\n";
}

Serializer &Serializer::operator = (Serializer const&)
{
	std::cout << "Serializer Assignation constructor.\n";
	return (*this);
}

Data *Serializer::deserialize(uintptr_t raw_data)
{
	void	*object;
	
	object = (void *)raw_data;
	return ((Data *)object);
}

uintptr_t Serializer::serialize(Data const *pointer)
{
	void	*object;

	object = (void *)pointer;
	return (uintptr_t(object));
}