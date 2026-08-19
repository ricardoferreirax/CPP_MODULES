/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:30:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/19 13:12:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

#include <cstdlib>
#include <iostream>
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter(void)
{
	std::cout << "[ScalarConverter] Default ScalarConverter created!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "[ScalarConverter] ScalarConverter has been destroyed!" << std::endl;
}

static int	ft_is_printable(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

static int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	displayInvalidLiteral(void)
{
	std::cout << "[char]: Invalid literal." << std::endl;
	std::cout << "[int]: Invalid literal." << std::endl;
	std::cout << "[float]: Invalid literal." << std::endl;
	std::cout << "[double]: Invalid literal." << std::endl;
}

bool ScalarConverter::checkSingleCharacter(const std::string &literal)
{
	if (literal.length() != 1)
		return (false);
	if (!ft_is_printable(literal[0]))
		return (false);
	if (ft_is_digit(literal[0]))
		return (false);
	return (true);
}

static bool	displaySpecialLiteral(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (true);
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (true);
	}
	return (false);
}

static int	detectType(const std::string &literal)
{
	if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos)
		return (INT);
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
		return (FLOAT);
	return (DOUBLE);
}

static bool	isValidFloatLiteral(const std::string &literal, char *end)
{
	if (literal.find('.') == std::string::npos)
		return (false);
	if (*end != 'f')
		return (false);
	if (*(end + 1) != '\0')
		return (false);
	return (true);
}

static bool	isValidNumericLiteral(const std::string &literal, int type, char *end)
{
	if (type == FLOAT)
		return (isValidFloatLiteral(literal, end));
	if (*end != '\0')
		return (false);
	return (true);
}

static void	displayChar(double value)
{
	std::cout << "[char]: ";
	if (value < 0 || value > 255)
		std::cout << "Impossible.";
	else if (!ft_is_printable(static_cast<int>(value)))
		std::cout << "Non displayable.";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
}

static void	displayInt(double value)
{
	std::cout << "[int]: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "Impossible.";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

static void	displayFloat(double value)
{
	float	number;

	std::cout << "[float]: ";
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cout << "Impossible.";
	else
	{
		number = static_cast<float>(value);

		if (number >= std::numeric_limits<int>::min() && number <= std::numeric_limits<int>::max()
			&& number == static_cast<int>(number))
			std::cout << static_cast<int>(number) << ".0f";
		else
			std::cout << std::fixed << std::setprecision(1) << number << "f";
	}
	std::cout << std::endl;
}

static void	displayDouble(double value)
{
	std::cout << "[double]: ";
	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
		std::cout << "Impossible.";
	else if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()
		&& value == static_cast<int>(value))
		std::cout << static_cast<int>(value) << ".0";
	else
		std::cout << std::fixed << std::setprecision(1) << value;
	std::cout << std::endl;
}

static void	displayConversions(double value)
{
	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

void ScalarConverter::convert(const std::string &literal)
{
	double	value;
	char	*end;
	int		type;

	if (displaySpecialLiteral(literal))
		return ;
	if (checkSingleCharacter(literal))
	{
		value = static_cast<double>(literal[0]);
		displayConversions(value);
		return ;
	}
	type = detectType(literal);
	value = std::strtod(literal.c_str(), &end);
	if (end == literal.c_str())
	{
		displayInvalidLiteral();
		return ;
	}
	if (value != value)
	{
		displayInvalidLiteral();
		return ;
	}
	if (!isValidNumericLiteral(literal, type, end))
	{
		displayInvalidLiteral();
		return ;
	}
	displayConversions(value);
}
