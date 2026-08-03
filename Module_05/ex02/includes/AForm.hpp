/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:26:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/03 15:27:14 by rmedeiro         ###   ########.fr       */
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
		bool _isSigned;
		const int _gradeSign;
		const int _gradeExecute;

	protected:
		virtual void executeAction(void) const = 0;

	public:
		AForm(void);
		AForm(const std::string name, int gradeSign, int gradeExecute);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm(void);

		const std::string &getName(void) const;
		bool getIsSigned(void) const;
		int	getGradeSign(void) const;
		int	getGradeExecute(void) const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif