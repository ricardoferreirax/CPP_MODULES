/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:30:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/23 22:40:05 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

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
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

// check and print special floating-point literals
// nan->Not a Number | +inf->Positive infinity | -inf->Negative infinity
// these values cant be converted to char or int.
static bool	printPseudoLiteral(const std::string &literal)
{
	std::string floatValue;
	std::string doubleValue;
	
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
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << floatValue << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
	return (true);
}

// string must has one char | that char must be printable | it must not be a digit.
// digits are excluded because "7" should be treated as int 7, not as ascii char '7'.
bool ScalarConverter::checkSingleChar(const std::string &literal)
{
	if (literal.length() != 1)
		return (false);
	if (!isPrintable(literal[0]))
		return (false);
	if (isDigit(literal[0]))
		return (false);
	return (true);
}

// identify numeric type from literal format.
// INT: no decimal point, float suffix or exponent.
// FLOAT: literal ends with 'f'.
// DOUBLE: decimal values and scientific notation without 'f' suffix.
//
// "42.5f"   -> FLOAT
// "1e3f"    -> FLOAT
// "42.5"    -> DOUBLE
// "1e3"     -> DOUBLE
static int	findLiteralType(const std::string &literal)
{
	if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos
		&& literal.find('e') == std::string::npos && literal.find('E') == std::string::npos)
		return (INT);
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
		return (FLOAT); // ends with 'f'->FLOAT
	return (DOUBLE);
}

// literal->original input string | type-> type detected by findLiteralType() | end-> pointer returned by strtod().
// strtod() converts numeric part of string->updates 'end' to point to first char that wasnt consumed during conversion.
//
// literal = "42.5"->strtod() converts 42.5->end points to '\0', the end of the string.
// literal = "42.5f"->strtod() converts 42.5->end points to 'f'.
static bool	hasValidSyntax(const std::string &literal, int type, char *end)
{
	for (size_t i = 0; i < literal.length(); i++) // iterate through each char in original input string
	{
		if (!isValidNumericChar(literal[i]))
			return (false); // reject chars that are not digits, '.', '+', '-', 'f', 'e', or 'E'.
		if ((literal[i] == '+' || literal[i] == '-') && i > 0 
			&& literal[i - 1] != 'e' && literal[i - 1] != 'E') // '+' or '-' can only appear at start of string or after 'e' or 'E'.
			return (false);
	}
	if (type == FLOAT)
		return (*end == 'f' && *(end + 1) == '\0'); // floats must end with 'f' and nothing else after it.
	return (*end == '\0'); // for int/double->strtod() must consume entire string->end point to '\0'.
}

// convert a numeric value into a formatted string.
// controls how float and double values are displayed w/out changing their stored values.
// value-> Number to format. | precision > Number of decimal places to display.
//
// value = 42.500000 ->precision = 6 ->after removing zeros ->"42.5"
// 
// If result ends with '.' ->append '0'.
// "42.000000" -> "42." -> "42.0"
static std::string formatNumber(double value, int precision)
{
	std::ostringstream stream;
	std::string res; // formatted nbr as string

	if (value != 0.0 && value < 0.000001 && value > -0.000001) // value is very small but not exactly zero
		precision = 10;
	stream << std::fixed << std::setprecision(precision) << value; // convert value to string with fixed-point notation
	res = stream.str(); // extract formatted string from stream
	while (res.find('.') != std::string::npos && res[res.length() - 1] == '0')
		res.erase(res.length() - 1); // rmv zeros after decimal point
	if (res[res.length() - 1] == '.')
		res += '0'; // all decimal digits were removed->append '0' to ensure at least one decimal place is displayed
	return (res);
}

static void	printChar(char value, bool possible)
{
	std::cout << "char: ";
	if (!possible)
		std::cout << "impossible";
	else if (!isPrintable(static_cast<unsigned char>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << value << "'";
	std::cout << std::endl;
}

static void	printInt(int value, bool possible)
{
	std::cout << "int: ";
	if (!possible)
		std::cout << "impossible";
	else
		std::cout << value;
	std::cout << std::endl;
}

static void	printFloat(float value)
{
	std::cout << "float: " << formatNumber(value, 6) << "f" << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "double: " << formatNumber(value, 15) << std::endl;
}

static void	printOverflow(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: overflow" << std::endl;
	std::cout << "float: overflow" << std::endl;
	std::cout << "double: overflow" << std::endl;
}

// check if a double can safely become an int.
// casting a floating-point value outside int range can cause undefined behavior.
// we must check limits before static_cast<int>().
static bool	canConvertToInt(double value)
{
	if (value != value) // NaN cant be converted safely to int
		return (false);
	if (value < std::numeric_limits<int>::min())
		return (false);
	if (value >= static_cast<double>(std::numeric_limits<int>::max()) + 1.0)
		return (false); // reject values at or above int_max + 1.0
	return (true);
}

// check if a double can safely become a char.
// on systems with signed 8-bit char: min = -128 and max = 127
static bool	canConvertToChar(double value)
{
	if (value != value)
		return (false);
	if (value < std::numeric_limits<char>::min())
		return (false);
	if (value >= static_cast<double>(std::numeric_limits<char>::max()) + 1.0)
		return (false);
	return (true);
}

// convert a char to all four scalar types->the original value is already a char.
// value = 'A'->ASCII value of 'A' = 65.
// char-> 'A' | int-> 65 | float-> 65.0f | double-> 65.0
// static_cast converts original char value to requested numeric type.
static void	convertChar(char value)
{
	printChar(value, true);
	printInt(static_cast<int>(value), true);
	printFloat(static_cast<float>(value));
	printDouble(static_cast<double>(value));
}

// convert an int to all four scalar types.
// value = 42 | char-> '*' | int-> 42 | float-> 42.0f | double-> 42.0
// before casting int to char->check if int fits inside char range->if not, print "impossible" for char.
static void	convertInt(int value)
{
	if (!canConvertToChar(value))
		printChar(0, false);
	else
		printChar(static_cast<char>(value), true);
	printInt(value, true);
	printFloat(static_cast<float>(value));
	printDouble(static_cast<double>(value));
}

// convert a float to all four scalar types.
// value = 42.5f | char-> '*' | int-> 42 | float-> 42.5f | double-> 42.5
// floating-point to int conversion->truncate fractional part->42.5f becomes 42
// before casting float to char or int->check if float fits inside char or int range
static void	convertFloat(float value)
{
	if (!canConvertToChar(value))
		printChar(0, false);
	else
		printChar(static_cast<char>(value), true);
	if (!canConvertToInt(value))
		std::cout << "int: overflow" << std::endl;
	else
		printInt(static_cast<int>(value), true);
	printFloat(value);
	printDouble(static_cast<double>(value));
}

// convert a double to all four scalar types.
// value = 42.5 | char-> '*' | int-> 42 | float-> 42.5f | double-> 42.5
// before casting double to char or int->check if double fits inside char or int range
static void	convertDouble(double value)
{
	if (!canConvertToChar(value))
		printChar(0, false);
	else
		printChar(static_cast<char>(value), true);
	if (!canConvertToInt(value))
		std::cout << "int: overflow" << std::endl;
	else
		printInt(static_cast<int>(value), true);
	if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
		std::cout << "float: overflow" << std::endl;
	else
		printFloat(static_cast<float>(value));
	printDouble(value);
}


// 1) check nan, nanf, +inf, -inf->if recognized, print all four representations
// 2) check if string has one printable char that is not a digit.
//    literal = "a" ->convertChar('a') prints: char: 'a' | int: 97 | float: 97.0f | double: 97.0
// 3) determine if literal represents an int, float or double.
// 4) parse nbrs->strtod() converts numeric part of input string into a double.
//    literal.c_str(): returns a pointer to a string.
//    &end: allows strtod() to update pointer with position where parsing stopped.
// 5) check if strtod() consumed entire string->if not, print "impossible" for all types.
// 6) check if double value is infinity->if so, print "overflow" for all types.
//    when a numeric value exceeds double range->strtod() returns +/-infinity.
// 7) convert double to int, float and char->print all four representations.
//    strtol() converts string to long int->check if long int fits inside int range->if not, print "overflow" for int.
// 8) convert parsed double to float->check if float fits inside float range->if not, print "overflow" for float.
void ScalarConverter::convert(const std::string &literal)
{
	char   *end;
	double	value;
	int		type;
	char   *intEnd;
	long	intNbr;
	float	floatNbr;

	if (printPseudoLiteral(literal))
		return ;
	if (checkSingleChar(literal))
	{
		convertChar(literal[0]);
		return ;
	}
	type = findLiteralType(literal);
	value = std::strtod(literal.c_str(), &end);
	if (end == literal.c_str() || value != value || !hasValidSyntax(literal, type, end))
	{
		printInvalid();
		return ;
	}
	if (value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity())
	{
		printOverflow();
		return ;
	}
	if (type == INT)
	{
		intNbr = std::strtol(literal.c_str(), &intEnd, 10); // convert string to long int
		if (*intEnd == '\0' && intNbr >= std::numeric_limits<int>::min() && intNbr <= std::numeric_limits<int>::max())
			convertInt(static_cast<int>(intNbr));
		else
			convertDouble(value); // if strtol() fails or long int is out of int range->treat as double
	}
	else if (type == FLOAT)
	{
		floatNbr = static_cast<float>(value); // convert and rounds value to float precision
		if (floatNbr == std::numeric_limits<float>::infinity() || floatNbr == -std::numeric_limits<float>::infinity())
			convertDouble(value); // if float conversion overflows->treat as double
		else
			convertFloat(floatNbr); // if float conversion is successful->print all four representations
	}
	else
		convertDouble(value);
}
