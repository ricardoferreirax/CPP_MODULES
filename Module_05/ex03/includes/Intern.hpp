/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:10:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/05 17:57:31 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <exception>
# include <string>

class AForm;

class Intern
{
	private:
		AForm *createShrubbery(const std::string &target) const;
		AForm *createRobotomy(const std::string &target) const;
		AForm *createPresidential(const std::string &target) const;

	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern(void);

		AForm *makeForm(const std::string &formName, const std::string &target) const;

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

#endif
