/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:30:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/19 22:40:54 by rmedeiro         ###   ########.fr       */
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

// Checks whether a numeric value represents a printable ASCII character. Printable ASCII characters are in the range 32 to 126.
// Values below 32 are control characters and are not normally printable. Value 127 is also not a printable ASCII character.
// Returns: true -> printable character | false -> non-printable character
static bool	isPrintable(int value)
{
	return (value >= 32 && value <= 126);
}

// Checks whether a character is a decimal digit.
static bool	isDigit(char value)
{
	return (value >= '0' && value <= '9');
}

// Prints the result used when the input does not represent a valid literal. That means that the original input itself could not be
// recognized as a valid char, int, float, double, or required pseudo-literal.
// Since the input itself is invalid, none of the four scalar conversions can be performed.
static void	printInvalid(void)
{
	std::cout << "[char]: invalid literal" << std::endl;
	std::cout << "[int]: invalid literal" << std::endl;
	std::cout << "[float]: invalid literal" << std::endl;
	std::cout << "[double]: invalid literal" << std::endl;
}

// Detects and displays the special floating-point pseudo-literals.
// nan / nanf: means "not a number". It represents an undefined or invalid floating-point result.
// +inf / +inff: means "positive infinity". It represents a value that is larger than the maximum representable floating-point number.
// -inf / -inff: means "negative infinity". It represents a value that is smaller than the minimum representable floating-point number.
// These values cannot be meaningfully converted to char or int, so those conversions are reported as impossible.
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
	else // if the input does not match any of the recognized pseudo-literals
		return (false); // return false to indicate that normal conversion should proceed.
	std::cout << "[char]: impossible" << std::endl;
	std::cout << "[int]: impossible" << std::endl;
	std::cout << "[float]: " << floatValue << std::endl;
	std::cout << "[double]: " << doubleValue << std::endl;
	return (true); // return true to indicate that a floating-point pseudo-literal was recognized and printed.
}

// Checks whether the input should be interpreted as a single character literal.
// Rules: 1. contain exactly one character | 2. be printable | 3. not be a decimal digit.
// The digit check is important because "7" should represent the integer value 7, not the ASCII character '7'.
bool	ScalarConverter::checkSingleCharacter(const std::string &literal)
{
	if (literal.length() != 1) // if the length of the string is not exactly 1, it cannot be a single character literal
		return (false);
	if (!isPrintable(literal[0])) // if the single character is not printable, it cannot be treated as a valid single character literal
		return (false);
	if (isDigit(literal[0])) // if the single character is a digit, it should be treated as an integer literal, not a character literal
		return (false);
	return (true);
}

// Determines the numeric type from the textual form of the literal. The function only classifies the syntax.
// Rules: no '.' and no 'f' -> INT | last character is 'f' -> FLOAT | otherwise -> DOUBLE
static int	findLiteralType(const std::string &literal)
{
	if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos) // if there's no decimal point and no 'f', it's an integer literal
		return (INT);
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f') // if the last character is 'f', it's a float literal
		return (FLOAT);
	return (DOUBLE); // if it has a decimal point and doesn't end with 'f', it's a double literal
}


// Performs the final syntax validation after std::strtod() has parsed the numeric part of the input.
// std::strtod() receives a pointer named "end". After parsing, "end" points to the first character that was not consumed.
// Example: input: "42.0f" -> std::strtod() parses "42.0" -> end points to 'f'.
// For a FLOAT: the literal must contain '.', end must point to 'f', and the character after 'f' must be '\0'.;
// For INT and DOUBLE: std::strtod() must consume the complete string, so end must point directly to the null terminator '\0'.
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
		return (true); //
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

// Prints the integer conversion. Before casting, the function verifies that the value fits inside the range of the int.
// If the value overflows, the conversion is impossible.
static void	printInt(double value)
{
	std::cout << "[int]: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
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
	if (converted >= std::numeric_limits<int>::min() && converted <= std::numeric_limits<int>::max()
		&& converted == static_cast<int>(converted))
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
	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()
		&& value == static_cast<int>(value))
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
