/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/15 14:27:59 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "heads/Literal.hpp"

int	main(int argc, const char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please, provide a single argument\n";
		return (1);
	}
	std::string	definition = argv[1];
	Literal literal(definition);

	literal.displayLiteral();
}