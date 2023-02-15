/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:50:05 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/15 14:24:15 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heads/Literal.hpp"

Literal::Literal(void): _definition(""), _precision(1), _def_is_out_of_int(false) ,_def_is_pseudo_litteral(false), _int_value(0), _char_value(0), _float_value(0.0f), _double_value(0.0)
{
	// std::cout << "Literal Default constructor.\n";
}

Literal::Literal(Literal const &to_copy)
{
	// std::cout << "Literal Copy constructor.\n";
	*this = to_copy;
}

Literal::Literal(std::string const &definition): _definition(definition), _def_is_out_of_int(false) ,_def_is_pseudo_litteral(false), _int_value(0), _char_value(0), _float_value(0.0f), _double_value(0.0)
{
	if (definition.empty())
	{
		std::cout << "Input is empty.\n";
		return ;
	}
	this->_precision = 1;
	try {
		this->_convert(definition);
	} catch (std::exception &error) {
		std::cout << definition << ": " << error.what();
	}
}

Literal::~Literal(void)
{
	// std::cout << "Literal Destructor.\n";
}

Literal &Literal::operator = (Literal const &to_set_to)
{
	// std::cout << "Literal Assignation constructor.\n";
	this->_convert(to_set_to._definition);
	return (*this);
}

//	Methods

void Literal::displayLiteral(void) const
{
	std::cout << "\t----\n";
	this->_printChar();
	this->_printInt();
	this->_printFloat();
	this->_printDouble();
}

   /*----------------*/
  /*	 PRIVATE	*/
 /*----------------*/

static bool 		isPseudoLiteral(std::string const &definition);
static LiteralType	returnPseudoLiteralType(std::string const &definition);

 
void Literal::_convert(std::string const &definition)
{
	LiteralType	definition_type;

	this->_def_is_pseudo_litteral = false;
	definition_type = this->_checkDefinitionType(definition);
	switch (definition_type) {
		case INT:
			std::cout << "INT DEF\n";
			this->_defFromInt(definition);
			break ;

		case CHAR:
			std::cout << "CHAR DEF\n";
			this->_defFromChar(definition);
			break ;

		case FLOAT:
			std::cout << "FLOAT DEF\n";
			this->_defFromFloat(definition);
			break ;

		case DOUBLE:
			std::cout << "DOUBLE DEF\n";
			this->_defFromDouble(definition);
			break ;

		default:
			throw _DefNotLiteralException();
	}
}

char const *Literal::_DefNotLiteralException::what() const throw()
{
	return ("Invalid value. Must be: Int, Char, Float or Double.\n");
}

char const *Literal::_DefExceedLimitsException::what() const throw()
{
	return ("Invalide value. Input value exceeds literal limit range.\n");
}

LiteralType Literal::_checkDefinitionType(std::string const &definition)
{
	size_t		index = -1;
	char const	*definition_data = definition.data();

	if (*definition_data == '\0')
		return (CHAR);
	if (definition.length() == 1 && !std::isdigit(*definition_data))
		return (CHAR);
	if (isPseudoLiteral(definition) == true)
	{
		this->_def_is_pseudo_litteral = true;
		return (returnPseudoLiteralType(definition));
	}
	if (*definition_data == '-' || *definition_data == '+')
		index += 1;
	while (definition_data[++index] != '\0')
		if (!std::isdigit(definition_data[index]))
			break ;
	if (definition_data[index] == '\0')
		return (INT);
	if (definition_data[index] != '.')
		throw _DefNotLiteralException();
	while (definition_data[++index] != '\0')
		if (!std::isdigit(definition_data[index]))
			break ;
	if (definition_data[index] == '\0')
		return (DOUBLE);
	if (definition_data[index] == 'f' && index == (definition.length() - 1))
		return (FLOAT);
	throw _DefNotLiteralException();
}


static bool isPseudoLiteral(std::string const &definition)
{
	size_t	_signed = 0;
	size_t	length_of_def = definition.length();

	if (length_of_def > 5 && length_of_def < 3)
		return (false);
	if (definition.data()[0] == '+' || definition.data()[0] == '-')
		_signed = 1;
	if (length_of_def - _signed == 4 && definition.data()[length_of_def - 1] == 'f')
		length_of_def -= 2;
	if (!_signed && definition.compare(0, length_of_def, "nan") == 0)
		return (true);
	if (_signed && definition.compare(1, length_of_def, "inf") == 0)
		return (true);
	return (false);
}

static LiteralType returnPseudoLiteralType(std::string const &definition)
{
	if (definition.compare(1, 4, "inff") == 0)
		return (FLOAT);
	if (definition.compare(0, 4, "nanf") == 0)
		return (FLOAT);
	return (DOUBLE);
}

/*		DEFINITION CONVERSION		*/

int	Literal::_defFromInt(std::string const &definition)
{
	long int	definition_value = 0;

	definition_value = std::strtol(definition.data(), NULL, 10);
	if (definition_value > INT_MAX || definition_value < INT_MIN)
		throw _DefExceedLimitsException();
	this->_int_value = int(definition_value);
	this->_char_value = char(definition_value);
	this->_double_value = double(definition_value);
	this->_float_value = float(definition_value);
	return (0);
}

int	Literal::_defFromChar(std::string const &definition)
{
	char	definition_value = 0;

	definition_value = *definition.data();
	this->_int_value = int(definition_value);
	this->_char_value = definition_value;
	this->_double_value = double(definition_value);
	this->_float_value = float(definition_value);
	return (0);
}

int	Literal::_defFromFloat(std::string const &definition)
{
	float		definition_value = 0;
	
	definition_value = (float)std::strtod(definition.data(), NULL);
	if (definition_value == std::numeric_limits<float>::max())
		throw _DefExceedLimitsException();
	if (definition_value > INT_MAX || definition_value < INT_MIN)
		this->_def_is_out_of_int = 1;
	this->_precision = definition.length() - definition.find('.') - 2;
	this->_int_value = int(round(definition_value));
	this->_char_value = this->_int_value;
	this->_float_value = definition_value;
	this->_double_value = double(definition_value);
	return (0);
}

int	Literal::_defFromDouble(std::string const &definition)
{
	double	definition_value = 0;

	definition_value = std::strtod(definition.data(), NULL);
	if (definition_value == std::numeric_limits<double>::max())
		throw _DefExceedLimitsException();
	if (definition_value > INT_MAX || definition_value < INT_MIN)
		this->_def_is_out_of_int = 1;
	this->_precision = definition.length() - definition.find('.') - 1;
	this->_int_value = int(round(definition_value));
	this->_char_value = this->_int_value;
	this->_float_value = float(definition_value);
	this->_double_value = definition_value;
	return (0);
}

/*		PRINT MEMBER FUNCTIONS		*/

void Literal::_printChar(void) const
{
	std::cout << "Char:\t";
	if (std::isprint(this->_char_value))
		std::cout << '\'' << this->_char_value << '\'';
	else if (this->_def_is_pseudo_litteral == true || this->_def_is_out_of_int == true)
		std::cout << "impossible conversion";
	else
		std::cout << "unprintable";
	std::cout << ";\n";
}

void Literal::_printInt(void) const
{
	std::cout << "Int:\t";
	if (this->_def_is_pseudo_litteral == true || this->_def_is_out_of_int == true)
		std::cout << "impossible conversion";
	else
		std::cout << this->_int_value;
	std::cout << ";\n";
}

void Literal::_printFloat(void) const
{
	std::ostringstream	buffer;
	double				decimal_part;
	double				fractionnal_part;

	std::cout << "Float:\t";
	if (this->_def_is_pseudo_litteral == true) { std::cout << this->_float_value << "f;\n"; return ; }
	buffer.setf(std::ios::fixed, std::ios::floatfield);
	buffer.setf(std::ios::showpoint);
	buffer << std::setprecision(7);
	if (this->_precision < 7)
		buffer << std::setprecision(this->_precision);
	fractionnal_part = std::modf(this->_float_value, &decimal_part);
	if (fractionnal_part == 0)
		buffer << std::setprecision(1);
	buffer << this->_float_value;
	std::cout << buffer.str() << "f;\n";
}

void Literal::_printDouble(void) const
{
	std::ostringstream	buffer;
	double				decimal_part;
	double				fractionnal_part;

	std::cout << "Double:\t";
	if (this->_def_is_pseudo_litteral == true) { std::cout << this->_double_value << ";\n"; return ; }
	buffer.setf(std::ios::fixed, std::ios::floatfield);
	buffer.setf(std::ios::showpoint);
	buffer << std::setprecision(15);
	if (this->_precision < 15)
		buffer << std::setprecision(this->_precision);
	fractionnal_part = std::modf(this->_double_value, &decimal_part);
	if (fractionnal_part == 0)
		buffer << std::setprecision(1);
	buffer << this->_double_value;
	std::cout << buffer.str() << ";\n";
}
