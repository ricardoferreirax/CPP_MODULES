/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:26:10 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/16 19:18:55 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string> 

class Fixed
{
  private:
	int _rawValue;
	static const int _fractBits;

  public:
	Fixed(void);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &src);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif
