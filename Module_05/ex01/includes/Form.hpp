/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:47:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/09 22:48:23 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;

	public:
		Form(void);
		Form(const std::string name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

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

		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
