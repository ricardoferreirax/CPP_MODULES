/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:50:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/24 10:24:44 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class	Base
{
	public:
		virtual ~Base(void);
};

class	A : public	Base
{
};

class	B : public	Base
{
};

class	C : public	Base
{
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
