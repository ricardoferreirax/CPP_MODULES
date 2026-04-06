/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:16:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/06 22:17:03 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <string>

class Sed
{
	private:
		std::string	_fileName;
		std::string	_toReplace;
		std::string	_replaceBy;

		std::string	replaceLine(std::string line) const;

	public:
		Sed(const std::string &fileName, const std::string &toReplace,
			const std::string &replaceBy);

		void	processFile(void) const;
};

#endif