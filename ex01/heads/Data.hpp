/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:01:26 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/15 16:17:21 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>

typedef struct	Data
{
	int			index;
	std::string	name;
	struct Data	*next;
}				Data;

uintptr_t	serialize(Data *pointer);
Data		*deserialize(uintptr_t raw_data);

#endif