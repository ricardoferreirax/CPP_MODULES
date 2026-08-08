/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:03:01 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/08 16:09:34 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

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

bool ScalarConverter::isSpecialLiteral(const std::string &str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "[char]: NaN has no char value." << std::endl;
		std::cout << "[int]: NaN has no int value." << std::endl;
		std::cout << "[float]: Not a Number." << std::endl;
		std::cout << "[double]: Not a Number." << std::endl;
		return (true);
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "[char]: No char value." << std::endl;
		std::cout << "[int]: No int value." << std::endl;
		std::cout << "[float]: Negative infinity." << std::endl;
		std::cout << "[double]: Negative infinity." << std::endl;
		return (true);
	}
	if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
	{
		std::cout << "[char]: No char value." << std::endl;
		std::cout << "[int]: No int value." << std::endl;
		std::cout << "[float]: Positive infinity." << std::endl;
		std::cout << "[double]: Positive infinity." << std::endl;
		return (true);
	}
	return (false);
}

void ScalarConverter::displayChar(double value)
{
	std::cout << "[char]: ";
	if (value < 0 || value > 255)
	{
		std::cout << "No char value." << std::endl;
		return ;
	}
	if (!ft_is_printable(static_cast<int>(value)))
	{
		std::cout << "Non displayable." << std::endl;
		return ;
	}
	std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::displayInt(double value)
{
	std::cout << "[int]: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << "No int value." << std::endl;
		return ;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	double	value;
	char	*end;

	if (checkSingleCharacter(literal))
	{
		value = static_cast<double>(literal[0]);
		displayChar(value);
		displayInt(value);
		return ;
	}
	if (isSpecialLiteral(literal))
		return ;
	value = std::strtod(literal.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0')
		end++;
	if (*end != '\0')
	{
		displayInvalidLiteral();
		return ;
	}
	displayChar(value);
	displayInt(value);
}


// static void	displayConversions(double value)
// {
// 	std::cout << "[char]: ";
// 	if (value < 0 || value > 127)
// 		std::cout << "No char value.";
// 	else if (value < 32 || value > 126)
// 		std::cout << "Non displayable.";
// 	else
// 		std::cout << "'" << static_cast<char>(value) << "'";
// 	std::cout << std::endl;

// 	std::cout << "[int]: ";
// 	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
// 		std::cout << "No int value.";
// 	else
// 		std::cout << static_cast<int>(value);
// 	std::cout << std::endl;

// 	std::cout << "[float]: ";
// 	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
// 		std::cout << "No float value.";
// 	else
// 		std::cout << static_cast<float>(value) << "f";
// 	std::cout << std::endl;

// 	std::cout << "[double]: ";
// 	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
// 		std::cout << "No double value.";
// 	else
// 		std::cout << value;
// 	std::cout << std::endl;
// }

// void ScalarConverter::convert(const std::string &literal)
// {
// 	double	value;
// 	char	*end;

// 	if (checkSingleCharacter(literal))
// 	{
// 		value = static_cast<double>(literal[0]);
// 		displayConversions(value);
// 		return ;
// 	}
// 	if (isSpecialLiteral(literal))
// 		return ;
// 	value = std::strtod(literal.c_str(), &end);
// 	if (*end == 'f' && *(end + 1) == '\0')
// 		end++;
// 	if (*end != '\0')
// 	{
// 		displayInvalidLiteral();
// 		return ;
// 	}
// 	displayConversions(value);
// }

