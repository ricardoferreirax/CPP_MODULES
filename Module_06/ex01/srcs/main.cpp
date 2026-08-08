/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:10:45 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/08 18:15:35 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main(void)
{
    Data data;

    data.name = "Ricky";
    data.age = 25;
    data.score = 42.5;

    // Serializer::serialize(&data);

    return (0);
}
