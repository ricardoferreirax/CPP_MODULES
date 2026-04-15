/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:47:22 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/15 22:43:23 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int _fixedPointNbr;
	static const int _fractBits;

  public:
	Fixed(void);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &src);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif