/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:01:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/07 19:04:11 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
# include <string>
#include <limits>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter(void);

		static bool	checkSingleCharacter(const std::string &literal);
		static bool	isPseudoLiteral(const std::string &literal);

		static void	displayChar(double value);
		static void	displayInt(double value);
		static void	displayFloat(double value);
		static void	displayDouble(double value);

	public:
		static void	convert(const std::string &literal);
};

#endif
