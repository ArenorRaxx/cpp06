/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/15 18:00:17 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include "heads/A.hpp"
#include "heads/B.hpp"
#include "heads/C.hpp"
#include "heads/Base.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int	main(void)
{
	Base	*new_instance = generate();
	srand((uintptr_t)(void*)new_instance);	
	delete	new_instance;

	for (int i = 0; i < 3; i++)
	{
		new_instance = generate();
		identify(new_instance);
		delete new_instance;
	}
	
	Base	&ref_instance = *generate();
	
	identify(ref_instance);

	delete &ref_instance;
}

Base *generate(void)
{
	int		random_index = rand() % 3;
	Base	*instance_array[3] = {new A, new B, new C};

	switch (random_index){
		case 0:
			delete instance_array[1];
			delete instance_array[2];
			break ;
		case 1:
			delete instance_array[0];
			delete instance_array[2];
			break ;
		case 2:
			delete instance_array[0];
			delete instance_array[1];
			break ;
	}

	return (instance_array[random_index]);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Class A, derived from Base.\n";
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Class B, derived from Base.\n";
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Class C, derived from Base.\n";
}

void identify(Base &p)
{
	if (dynamic_cast<A*>(&p) != NULL)
		std::cout << "Class A, derived from Base.\n";
	if (dynamic_cast<B*>(&p) != NULL)
		std::cout << "Class B, derived from Base.\n";
	if (dynamic_cast<C*>(&p) != NULL)
		std::cout << "Class C, derived from Base.\n";
}
