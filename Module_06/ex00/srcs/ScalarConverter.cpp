/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:30:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/19 21:30:22 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter(void)
{
	
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
	
}

// Checks if an ASCII value represents a printable character. Printable characters occupy the range from 32 (' ') to 126 ('~').
static bool	isPrintable(int value)
{
	return (value >= 32 && value <= 126);
}

// Checks whether a character is a decimal digit.
static bool	isDigit(char value)
{
	return (value >= '0' && value <= '9');
}

static void	printInvalid(void)
{
	std::cout << "[char]: invalid literal" << std::endl;
	std::cout << "[int]: invalid literal" << std::endl;
	std::cout << "[float]: invalid literal" << std::endl;
	std::cout << "[double]: invalid literal" << std::endl;
}

// Detects and prints the floating-point pseudo-literals. The C++ language defines special values that are not ordinary numbers:
// nan -> Not a Number | +inf -> Positive infinity | -inf -> Negative infinity. Their float versions simply add the 'f' suffix.
// These values cannot be converted into meaningful char or int values, so those conversions are reported as impossible.
static bool	printPseudoLiteral(const std::string &literal)
{
	std::string	floatValue;
	std::string	doubleValue;

	if (literal == "nan" || literal == "nanf")
	{
		floatValue = "nanf";
		doubleValue = "nan";
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		floatValue = "-inff";
		doubleValue = "-inf";
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		floatValue = "+inff";
		doubleValue = "+inf";
	}
	else
		return (false);
	std::cout << "[char]: impossible" << std::endl;
	std::cout << "[int]: impossible" << std::endl;
	std::cout << "[float]: " << floatValue << std::endl;
	std::cout << "[double]: " << doubleValue << std::endl;

	return (true);
}

// Detects whether the input represents a single character literal. A valid character input must: - contain exactly one character,
// be printable and not be a digit.
bool	ScalarConverter::checkSingleCharacter(const std::string &literal)
{
	if (literal.length() != 1)
		return (false);
	if (!isPrintable(literal[0]))
		return (false);
	if (isDigit(literal[0]))
		return (false);
	return (true);
}

// Determines which numeric type the input represents. Rules: no '.' and no 'f' -> INT | ends with 'f' -> FLOAT | otherwise -> DOUBLE
// This function only classifies the literal. The actual numeric conversion is performed later with std::strtod().
static int	findLiteralType(const std::string &literal)
{
	if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos) // if there's no decimal point and no 'f', it's an integer literal
		return (INT);
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f') // if the last character is 'f', it's a float literal
		return (FLOAT);
	return (DOUBLE); // if it has a decimal point and doesn't end with 'f', it's a double literal
}

// Validates the syntax of a float literal after parsing. std::strtod() stops reading at the first invalid character.
// For a float, the remaining character must be exactly 'f', and nothing is allowed after it.
static bool	hasValidSyntax(const std::string &literal, int type, char *end)
{
	if (type == FLOAT)
	{
		if (literal.find('.') == std::string::npos) // if there's no decimal point, it's not a valid float literal
			return (false);
		if (*end != 'f') // if the character after the parsed number is not 'f', it's not a valid float literal
			return (false);
		if (*(end + 1) != '\0') // if there's any character after 'f', it's not a valid float literal
			return (false);
		return (true);
	}
	return (*end == '\0'); // for INT and DOUBLE, the entire string must be consumed by std::strtod(), so *end should point to the null terminator.
}

// Prints the character conversion. The numeric value is cast to char using static_cast<char>().
// Three situations: impossible -> outside the valid char range | Non displayable -> valid ASCII but not printable | printable -> displayed between single quotes
static void	printChar(double value)
{
	std::cout << "[char]: ";
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "impossible";
	else if (!isPrintable(static_cast<int>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
}

static void	printInt(double value)
{
	std::cout << "[int]: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

static bool	isWholeFloat(float value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		return (false);
	return (value == static_cast<int>(value));
}

static bool	isWholeDouble(double value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		return (false);
	return (value == static_cast<int>(value));
}

static void	printFloat(double value)
{
	float	converted;

	std::cout << "[float]: ";
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	converted = static_cast<float>(value);
	if (isWholeFloat(converted))
		std::cout << static_cast<int>(converted) << ".0f";
	else
		std::cout << std::fixed << std::setprecision(1) << converted << "f";
	std::cout << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "[double]: ";
	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isWholeDouble(value))
		std::cout << static_cast<int>(value) << ".0";
	else
		std::cout << std::fixed << std::setprecision(1) << value;
	std::cout << std::endl;
}

static void	printAllConversions(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void	ScalarConverter::convert(const std::string &literal)
{
	double	value;
	char	*end;
	int		type;

	if (printPseudoLiteral(literal))
		return ;
	if (checkSingleCharacter(literal))
	{
		printAllConversions(static_cast<double>(literal[0]));
		return ;
	}
	type = findLiteralType(literal);
	value = std::strtod(literal.c_str(), &end);
	if (end == literal.c_str() || value != value)
	{
		printInvalid();
		return ;
	}
	if (!hasValidSyntax(literal, type, end))
	{
		printInvalid();
		return ;
	}
	printAllConversions(value);
}
