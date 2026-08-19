/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:30:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/19 23:25:44 by rmedeiro         ###   ########.fr       */
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

static bool	hasOuterSpaces(const std::string &literal)
{
	if (literal.empty()) // if the string is empty, it cannot have outer spaces
		return (false);
	if (literal[0] == ' ' || literal[literal.length() - 1] == ' ') // if the first or last character is a space, it has outer spaces
		return (true);
	return (false);
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

// Displays the char conversion. The input arrives as a double because all normal numeric literals are first converted to a 
// common numeric representation before the output conversions are displayed. First, the function checks whether the value 
// fits inside the range of the char type.
// impossible -> The value cannot be represented by char.
// Non displayable -> The value can be represented by char but does not correspond to a printable ASCII character.
// Printable character -> The value can be represented by char and corresponds to a printable ASCII character.
// static_cast<char>() performs the explicit scalar conversion from double to char.
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

// Displays the int conversion. The function checks whether the double value fits inside the valid int range.
// std::numeric_limits<int>::min() gives the smallest representable int.
// std::numeric_limits<int>::max() gives the largest representable int.
// This check is important because converting a value outside the int range would overflow.
// If the value is valid, static_cast<int>() explicitly converts it to int. Any fractional part is discarded by the conversion.
static void	printInt(double value)
{
	std::cout << "[int]: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

// Displays the float conversion. The original numeric value is stored as double, so the function first checks whether that 
// value fits inside the finite range of a float. std::numeric_limits<float>::max() represents the largest finite float.
// If the value is outside the float range, the conversion would overflow and is therefore reported as impossible.
// If it fits, static_cast<float>() performs the float conversion.  Example: 42.0 -> "42.0f" instead of: "42f".
// Fractional values are printed using the selected floating-point formatting. 
static void	printFloat(double value)
{
	float	converted;

	std::cout << "[float]: ";
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	converted = static_cast<float>(value); // conversion from double to float
	if (converted >= std::numeric_limits<int>::min() && converted <= std::numeric_limits<int>::max()
		&& converted == static_cast<int>(converted)) // if the float value is within the int range and has no fractional part
		std::cout << static_cast<int>(converted) << ".0f"; //  print it as an integer with ".0f" appended
	else // if the float value has a fractional part 
		std::cout << std::fixed << std::setprecision(1) << converted << "f"; // print it with one decimal place and append "f"
	std::cout << std::endl;
}

// Displays the double conversion. The value is already stored as double, so no additional cast is required for the double representation.
// The function still checks the double range so that overflow can be reported as impossible.
// Fractional values are printed using the selected floating-point formatting.
static void	printDouble(double value)
{
	std::cout << "[double]: ";
	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()
		&& value == static_cast<int>(value)) // if the double value is within the int range and has no fractional part
		std::cout << static_cast<int>(value) << ".0"; // print it as an integer with ".0" appended
	else // if the double value has a fractional part
		std::cout << std::fixed << std::setprecision(1) << value; // print it with one decimal place
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

	if (hasOuterSpaces(literal))
	{
		printInvalid();
		return ;
	}
	if (printPseudoLiteral(literal)) // if the input is a recognized as a pseudo-literal, print it and return
		return ;
	if (checkSingleCharacter(literal)) // if the input is a single printable non-digit character
	{
		printAllConversions(static_cast<double>(literal[0])); // convert its ASCII value to double and print all scalar representations
		return ;
	}
	type = findLiteralType(literal); // determine the numeric type based on the syntax of the literal
	value = std::strtod(literal.c_str(), &end); // convert the string to a double using std::strtod(), which also provides a pointer to the first unprocessed character
	if (end == literal.c_str() || value != value) // if std::strtod() did not consume any characters (end points to the start of the string)
	{
		printInvalid();
		return ;
	}
	if (!hasValidSyntax(literal, type, end)) // if the syntax of the literal is not valid (e.g., missing 'f' for float, extra characters after the number)
	{
		printInvalid();
		return ;
	}
	printAllConversions(value);
}
