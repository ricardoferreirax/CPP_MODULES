/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:19:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/28 14:36:24 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
		
	public:
		AAnimal(void);
		AAnimal(const AAnimal &src);
		AAnimal &operator=(const AAnimal &src);
		virtual ~AAnimal(void);

		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
		// we can't create an object from an abstract class and we can create a pointer 
		// or reference to an abstract class, but we cannot instantiate it directly, is forbidden.
};

#endif
