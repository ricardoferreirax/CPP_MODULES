/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:58:12 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/12 22:57:44 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		const std::string &getName(void) const;
		int	getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);

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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif



/*
 * Custom exception that inherits from std::exception.
 *
 * GradeTooLowException is a derived class of std::exception. By inheriting from std::exception, 
 * our custom exception becomes part of the standard C++ exception hierarchy and can be treated 
 * as a std::exception. This is useful because different custom exceptions, such as
 * GradeTooHighException and GradeTooLowException, can all be handled through the same base class:
 * catch (const std::exception &e)
 *
 * -------------------------------------------------------------------------
 *
 * The declaration: class GradeTooLowException : public std::exception , means that GradeTooLowException 
 * publicly inherits from std::exception. std::exception is the base class and GradeTooLowException is 
 * the derived class. The derived class inherits the interface provided by std::exception and can
 * provide its own implementation of its virtual functions. GradeTooLowException is an std::exception.
 * Because of this relationship, an object of GradeTooLowException can be referred to through a reference 
 * to std::exception.
 *
 * -------------------------------------------------------------------------
 *
 * what() is the function used to obtain a description of the error. The declaration is:
 * virtual const char *what(void) const throw();
 * "throw()" is the C++98 exception specification. It means that what() promises not to throw another exception.
 * This is particularly appropriate for what(), because this function is normally called while the program is already 
 * handling an exception. Its purpose is simply to provide information about the current error.
 *
 * Polymorphism means that the same interface can produce different behavior depending on the real type 
 * of the object. In this exercise, runtime polymorphism is used through the virtual what() function. 
 * std::exception already declares what() as a virtual member function.
 * The derived exception can provide a more specific error message while still being handled as a generic 
 * std::exception. For example:
 *
 *     try
 *     {
 *         throw GradeTooLowException();
 *     }
 *     catch (const std::exception &e)
 *     {
 *         std::cerr << e.what() << std::endl;
 *     }
 *
 * The object that is actually thrown is: GradeTooLowException, but the catch block receives it through:
 * const std::exception &e. Therefore, the reference has the base type std::exception, while the real
 * object is still a GradeTooLowException. Because what() is virtual, C++ checks the real type of the object 
 * at runtime and calls: GradeTooLowException::what(), instead of the generic: std::exception::what().
 * This behavior is called runtime polymorphism.
 *
 * -------------------------------------------------------------------------
 *
 *  const std::exception &e, has the static type std::exception, but the object referred to by "e" can
 * actually be a GradeTooLowException. Since what() is virtual, calling: e.what(), executes the correct 
 * derived implementation. This is important because otherwise catching different exceptions through
 * std::exception would lose their specific error messages.
 *
 * -------------------------------------------------------------------------
 *
 * The exception is caught using: catch (const std::exception &e).
 * Catching by reference is important because it preserves the real type of the exception and 
 * therefore preserves polymorphic behavior.
 * Catching by value could create a copy of only the std::exception part of the object.
 * Using a reference also avoids an unnecessary copy of the exception object.
 * The reference is const because the catch block only needs to inspect the
 * exception and should not modify it.
 */