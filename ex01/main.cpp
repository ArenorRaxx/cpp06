/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/15 16:21:27 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include "heads/Data.hpp"

int	main(void)
{
	Data	data;
	Data	next_data;
	Data	*new_data = &data;
	Data	*retrieved_data;

	data.index = 0;
	data.name = "Data";
	data.next =	&next_data;
	next_data.index = 1;
	next_data.name = "Next data";
	next_data.next = NULL;

	std::cout << "\t----\n";

	uintptr_t raw_data = serialize(new_data);
	std::cout << "Serialized data: " << raw_data << ";\n";

	std::cout << "\t----\n";
	
	retrieved_data = deserialize(raw_data);
	std::cout << "Index:\t" << retrieved_data->index << ";\n";
	std::cout << "Name: " << data.name << ";\n";
	std::cout << "Next data name: " << data.next->name << ";\n";
	std::cout << "Next data index: " << data.next->index << ";\n";

}

uintptr_t	serialize(Data *pointer)
{
	void	*object;

	object = (void *)pointer;
	return (uintptr_t(object));
}

Data	*deserialize(uintptr_t raw_data)
{
	void	*object;

	object = (void *)raw_data;
	return ((Data *)object);
}