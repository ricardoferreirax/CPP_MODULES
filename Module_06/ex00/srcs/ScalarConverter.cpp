/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:30:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/23 17:48:36 by rmedeiro         ###   ########.fr       */
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

static bool	isPrintable(int value)
{
	return (value >= 32 && value <= 126);
}

static bool	isDigit(char value)
{
	return (value >= '0' && value <= '9');
}

static bool	isValidNumericChar(char c)
{
	return (isDigit(c) || c == '.' || c == '+' || c == '-' || c == 'f' || c == 'e' || c == 'E');
}

static void	printInvalid(void)
{
	std::cout << "[char]: invalid literal" << std::endl;
	std::cout << "[int]: invalid literal" << std::endl;
	std::cout << "[float]: invalid literal" << std::endl;
	std::cout << "[double]: invalid literal" << std::endl;
}

// nan / nanf: means "not a number"->represents an undefined or invalid floating-point result
// +inf / +inff: means "positive infinity"->represents a value that is larger than max representable floating-point nbr
// -inf / -inff: means "negative infinity"->represents a value that is smaller than min representable floating-point nbr
// These values cant be converted to char or int->those conversions are reported as impossible.
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

// rules: contain exactly one char | be printable | not be a decimal digit.
// The digit check is important because "7" should represent the integer value 7, not the ASCII character '7'.
bool	ScalarConverter::checkSingleCharacter(const std::string &literal)
{
	if (literal.length() != 1) // len of string isnt 1->it cant be a single char literal
		return (false);
	if (!isPrintable(literal[0])) // single char is not printable->cant be a valid single char literal
		return (false);
	if (isDigit(literal[0])) // single char is a digit->should be an int literal, not a char literal
		return (false);
	return (true);
}

// detects numeric type based on the literal's format.
// int->no decimal point and no 'f' | float->ends with 'f' | double->has decimal point and does not end with 'f'
static int	findLiteralType(const std::string &literal)
{
	if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos
		&& literal.find('e') == std::string::npos && literal.find('E') == std::string::npos)
		return (INT);
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
		return (FLOAT);
	return (DOUBLE);
}

// final validation after std::strtod() has parsed numeric part of input (end points to 1st char that was not consumed)
// input: "42.0f" -> std::strtod() parses "42.0" -> end points to 'f'.
static bool	hasValidSyntax(const std::string &literal, int type, char *end)
{
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isValidNumericChar(literal[i]))
			return (false);
		if ((literal[i] == '+' || literal[i] == '-') && i > 0 && literal[i - 1] != 'e' && literal[i - 1] != 'E')
			return (false); // '+' or '-' can only appear at beginning or after 'e'/'E'
	}
	if (type == FLOAT)
	{
		if (*end != 'f')
			return (false); // theres no 'f' after parsed nbr ->not a valid float
		if (*(end + 1) != '\0')
			return (false); // theres another char after 'f'->not valid float
		return (true);
	}
	return (*end == '\0'); // std::strtod() must consume string for int/double->end must point to '\0'
}

static void	printChar(char value, bool possible)
{
	std::cout << "char: ";
	if (!possible)
		std::cout << "impossible";
	else if (!isPrintable(static_cast<unsigned char>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << value << "'"; // char is printable->print it in single quotes to indicate its a char literal
	std::cout << std::endl;
}

static void	printInt(int value, bool possible)
{
	std::cout << "int: ";
	if (!possible)
		std::cout << "impossible";
	else
		std::cout << value; // if is possible->print int value directly
	std::cout << std::endl;
}

static void	printFloat(float value)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

static void convertChar(char value)
{
	printChar(value, true);
	printInt(static_cast<int>(value), true);
	printFloat(static_cast<float>(value));
	printDouble(static_cast<double>(value));
}

static void	convertInt(int value)
{
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) // int value is outside range of char->print impossible
		printChar(0, false);
	else
		printChar(static_cast<char>(value), true); // int value is within range of char->cast to char and print it
	printInt(value, true);
	printFloat(static_cast<float>(value));
	printDouble(static_cast<double>(value));
}

static void	convertFloat(float value)
{
	if (value != value || value < std::numeric_limits<char>::min() 
		|| value >= static_cast<float>(std::numeric_limits<char>::max()) + 1.0f) // float value is NaN or outside range of char->print impossible
		printChar(0, false);
	else
		printChar(static_cast<char>(value), true); // float value is within range of char->cast to char and print it
	if (value != value || static_cast<double>(value) < std::numeric_limits<int>::min()
		|| static_cast<double>(value) >= static_cast<double>(std::numeric_limits<int>::max()) + 1.0) // float value is NaN or outside range of int->print impossible
		printInt(0, false);
	else
		printInt(static_cast<int>(value), true);
	printFloat(value);
	printDouble(static_cast<double>(value));
}

static void	convertDouble(double value)
{
	if (value != value || value < std::numeric_limits<char>::min()
		|| value >= static_cast<double>(std::numeric_limits<char>::max()) + 1.0)
		printChar(0, false);
	else
		printChar(static_cast<char>(value), true);
	if (value != value || value < std::numeric_limits<int>::min()
		|| value >= static_cast<double>(std::numeric_limits<int>::max()) + 1.0)
		printInt(0, false);
	else
		printInt(static_cast<int>(value), true);
	if (value != value || value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		printFloat(static_cast<float>(value));
	printDouble(value);
}

void ScalarConverter::convert(const std::string &literal)
{
	double value;
	char  *end;
	int    type;

	if (printPseudoLiteral(literal))
		return ;
	if (checkSingleCharacter(literal))
	{
		convertChar(literal[0]);
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
	if (value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity())
	{
		printInvalid();
		return ;
	}
	if (type == INT)
	{
		if (value < std::numeric_limits<int>::min() || value >= static_cast<double>(std::numeric_limits<int>::max()) + 1.0)
		{
			printInvalid();
			return ;
		}
		convertInt(static_cast<int>(value));
	}
	else if (type == FLOAT)
	{
		if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
		{
			printInvalid();
			return ;
		}
		convertFloat(static_cast<float>(value));
	}
	else
		convertDouble(value);
}

// The goal of the ScalarConverter class is to receive a string containing the representation of a C++ scalar literal, detect what 
// kind of literal it represents, convert it into the corresponding numeric value, and then display its equivalent value as char, int, 
// float and double. The class itself does not need to store any data. Its only responsibility is to perform conversions.
// First, the input arrives as a std::string. Even if we write: ./convert 42, the program initially receives  "42" as text. The program must determine what
// that text represents. The supported scalar types are: char, int, float, double and there are special floating-point pseudo-literals: nanf / nan, +inff / +inf 
// and -inff / -inf. These values are treated separately because they do not behave like normal numeric values. If input is one of these pseudo-literals, the 
// float and double representations are printed directly and the normal conversion process stops. If the input is not a pseudo-literal, the program checks whether 
// it represents a single character. 
// A one-character input such as: 'a' is treated as a char, but a digit such as: 7 must not be treated as the character '7'. It represents the integer 
// value 7. For that reason, the character check verifies that the input contains exactly one printable character and that this character is not a decimal digit.
//
// For numeric literals, the program identifies the expected type from the syntax of the string. The type detection only classifies the textual representation. 
// The actual numeric parsing is performed using std::strtod(). std::strtod() converts a string into a double and also provides an "end" pointer. This pointer is 
// extremely useful for validation because it points to the first character that was not consumed by the conversion. For example: "42.0f" <- end (points to 'f').
// strtod() converts the "42.0" part and stops when it reaches 'f'. This allows the program to check that a float literal ends with exactly one 'f' and has
// no unexpected characters after it. For an int or double literal, the complete string should be consumed, so "end" must point to the null terminator '\0'.
// This validation prevents malformed literals from being accepted as valid values. Examples: "42.0" <- end (points to '\0') | "42abc" <- end (points to 'a'). 
// Once the input has been successfully parsed, the same numeric value is used to display the four required scalar representations.
//
// The char conversion has an additional distinction between "impossible" and "Non displayable". "impossible" means that the numeric value cannot be represented 
// as the char type being used. "Non displayable" means that the conversion itself is possible, but the resulting character is not printable. Printable ASCII 
// characters are normally in the range 32 to 126.
//
// Float and double outputs also need special formatting. Whole numeric values should normally be displayed with a decimal part: 42.0f or 42.0.
// Therefore, the program checks whether the converted floating-point value is mathematically equal to its integer representation. If it is, ".0f" or ".0"
// is added to the output. Fractional values are printed using floating-point formatting. Care must be taken with std::fixed and std::setprecision(), because with 
// fixed notation the precision represents the number of digits after the decimal point.
//
//  input string -> pseudo-literal check -> character detection -> numeric type detection -> std::strtod() -> syntax validation -> scalar casts -> char / int / float / double
//
