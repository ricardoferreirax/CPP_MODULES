/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:14:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/08 19:55:46 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

class Data
{
	private:
		std::string	_name;
		int	_age;

	public:
		Data(void);
		Data(const std::string name, int age);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data(void);

		const std::string &getName(void) const;
		int	getAge(void) const;

		void setName(const std::string &name);
		void setAge(int age);
};

#endif
