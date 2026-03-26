/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:30:44 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/26 14:17:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
		
	public:
		Cat(void);
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		~Cat(void);

		void makeSound(void) const;
		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
};

#endif
