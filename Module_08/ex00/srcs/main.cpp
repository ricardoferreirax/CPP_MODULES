/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:15:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/20 10:15:33 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nbrs;

    nbrs.push_back(10);
    nbrs.push_back(20);
    nbrs.push_back(30);
    std::cout << nbrs[0] << std::endl;
    std::cout << nbrs[1] << std::endl;
    std::cout << nbrs[2] << std::endl;
    return (0);
}
