/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:37:49 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/15 14:01:25 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_HPP
# define LITERAL_HPP

#include <exception>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <limits>
#include <string>
#include <cmath>

typedef enum 	LiteralType {
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
	ERROR = -1
}				LiteralType;

class Literal
{
	private:
		std::string			_definition;
		size_t				_precision;
		bool				_def_is_out_of_int;
		bool				_def_is_pseudo_litteral;
		int					_int_value;
		char				_char_value;
		float				_float_value;
		double				_double_value;

		class	_DefNotLiteralException;
		class	_DefExceedLimitsException;

		void		_convert(std::string const&);
		LiteralType	_checkDefinitionType(std::string const&);

		int		_defFromInt(std::string const&);
		int		_defFromChar(std::string const&);
		int		_defFromFloat(std::string const&);
		int		_defFromDouble(std::string const&);

		void	_printInt(void) const;
		void	_printChar(void) const;
		void	_printFloat(void) const;
		void	_printDouble(void) const;
	public:
		Literal(void);
		Literal(Literal const&);
		Literal(std::string const&);

		~Literal(void);
		
		Literal &operator = (Literal const&);
	
	//	Methods

		void	displayLiteral(void) const;
};

class Literal::_DefNotLiteralException: public std::exception
{
	char const *what() const throw();
};

class Literal::_DefExceedLimitsException: public std::exception
{
	char const *what() const throw();
};

#endif