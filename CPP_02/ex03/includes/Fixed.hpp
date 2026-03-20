/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:26:10 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/20 13:12:12 by rmedeiro         ###   ########.fr       */
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
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &src);
	~Fixed(void);

	int toInt(void) const;
	float toFloat(void) const;

	bool operator>(const Fixed &src) const;
	bool operator<(const Fixed &src) const;
	bool operator>=(const Fixed &src) const;
	bool operator<=(const Fixed &src) const;
	bool operator==(const Fixed &src) const;
	bool operator!=(const Fixed &src) const;

	Fixed operator+(const Fixed &src) const;
	Fixed operator-(const Fixed &src) const;
	Fixed operator*(const Fixed &src) const;
	Fixed operator/(const Fixed &src) const;

	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed const &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif