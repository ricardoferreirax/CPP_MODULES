/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 17:38:36 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/07 17:39:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;

	protected:
		virtual void executeForm(void) const = 0;

	public:
		AForm(void);
		AForm(const std::string name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm(void);

		const std::string &getName(void) const;
		bool isSigned(void) const;
		int	getSignGrade(void) const;
		int	getExecuteGrade(void) const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
