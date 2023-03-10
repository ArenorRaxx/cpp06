/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:01:26 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/20 17:15:20 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>
#include <stdint.h>

typedef struct	Data
{
	int			index;
	std::string	name;
	struct Data	*next;
}				Data;

uintptr_t	serialize(Data *pointer);
Data		*deserialize(uintptr_t raw_data);

#endif