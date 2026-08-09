/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 17:41:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 22:04:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <exception>
# include <ostream>
# include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		void drawTree(std::ostream &out) const;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm(void);

		const std::string &getTarget(void) const;

		class OutputFileException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		virtual void processForm(void) const;
};

#endif
