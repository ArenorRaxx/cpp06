/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/13 17:07:05 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "heads/Literal.hpp"

int	main(int argc, const char **argv)
{
	(void)argc;
	std::string	definition = argv[1];
	Literal literal(definition);

	literal.displayLiteral();
}