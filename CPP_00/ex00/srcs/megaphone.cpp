/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 06:22:51 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/13 12:34:15 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++)
    {
        for (size_t j = 0; argv[i][j]; j++)
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
        if (i < argc - 1)
            std::cout << ' ';
    }
    std::cout << std::endl;
    return (0);
}
