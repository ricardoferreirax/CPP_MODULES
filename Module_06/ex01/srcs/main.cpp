/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:10:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/08 18:22:43 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>

int	main(void)
{
	Data data;
	Data *ptr;
	uintptr_t raw;

	data.name = "Ricky";
	data.age = 25;
	data.score = 42.5;

	ptr = &data;

	std::cout << "Original pointer : " << ptr << std::endl;
	raw = Serializer::serialize(ptr);
	std::cout << "Serialized value : " << raw << std::endl;

	return (0);
}
