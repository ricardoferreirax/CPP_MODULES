/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:04:31 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/08 21:04:41 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

#include <cstdlib>
#include <ctime>

int	main(void)
{
	Base	*ptr;

	std::srand(std::time(NULL));
	ptr = generate();

	delete ptr;

	return (0);
}
