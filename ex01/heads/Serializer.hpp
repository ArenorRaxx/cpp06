/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:59:11 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/20 17:15:16 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:

	//	Constructors

		Serializer(void);
		Serializer(Serializer const&);
		
		~Serializer(void);

	//	Operators

		Serializer &operator = (Serializer const&);

	public:
	
	//	Methods

static	Data		*deserialize(uintptr_t const);
static	uintptr_t	serialize(Data const*);
};

#endif