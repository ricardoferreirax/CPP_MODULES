/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:25:16 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/02/05 22:24:37 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>

class Sed
{
	private:
		std::string _searchString;
		std::string _replaceString;
		std::string _inputFilename;
		std::string _outputFilename;
	public:
		Sed(char *inputFilename, char *searchString, char *replaceString);
		const std::string& getSearchString(void) const;
		const std::string& getReplaceString(void) const;
		const std::string& getInputFilename(void) const;
		const std::string& getOutputFilename(void) const;
		void processFile(void) const; 
};

#endif