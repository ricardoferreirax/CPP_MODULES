/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:22:04 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/07/28 17:43:06 by rmedeiro         ###   ########.fr       */
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
		bool _isSigned;
		const int _gradeSign;
		const int _gradeExecute;

	public:
		Form(void);
		Form(const std::string name, int gradeSign, int gradeExecute);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form(void);

		const std::string &getName(void) const;
		bool getIsSigned(void) const;
		int	getGradeSign(void) const;
		int	getGradeExecute(void) const;

		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
