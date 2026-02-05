/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:25:16 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/05 23:03:46 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>

class Sed
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
		std::string _outputFilename;
	public:
		Sed(const char *filename, const char *s1, const char *s2);
		const std::string& getFilename(void) const;
		const std::string& getS1(void) const;
		const std::string& getS2(void) const;
		const std::string& getOutputFilename(void) const;
		int processFile(void) const;
};

#endif