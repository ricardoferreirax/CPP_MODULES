/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:43:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 20:45:56 by rmedeiro         ###   ########.fr       */
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

	public:
		AForm(void);
		AForm(const std::string name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm(void);

		const std::string &getName(void) const;
		int	getSignGrade(void) const;
		int	getExecuteGrade(void) const;
		bool isSigned(void) const;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		
		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;
		virtual void processForm(void) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
