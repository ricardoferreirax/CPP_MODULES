/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:19:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/26 14:01:09 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

// Abstract Class Rules:

// * Must have at least one pure virtual function: virtual void func() = 0;
// * If it not have 'virtual', it's not abstract.
// * Without (= 0), it's a normal function, so class is not abstract.
// * We can't create an object from an abstract class.
// * We can create a pointer or reference to an abstract class.
// * But we cannot instantiate it directly: AAnimal a; or new AAnimal(); is forbidden.

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
};

#endif
