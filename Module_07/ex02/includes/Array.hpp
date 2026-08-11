/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:42:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/11 17:18:58 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T> class Array
{
	private:
		T *_array;
		unsigned int _length;

	public:
		Array(void)
		{
			std::cout << "[Array] Default constructor!" << std::endl;
			this->_array = NULL;
			this->_length = 0;
		}

		Array(unsigned int n)
		{
			std::cout << "[Array] Parameter constructor!" << std::endl;
			this->_length = n;
			if (this->_length > 0)
				this->_array = new T[n]();
			else
				this->_array = NULL;
		}
		
		~Array(void)
		{
			delete[] this->_array;
			std::cout << "[Array] Destructor!" << std::endl;
		}
};

#endif