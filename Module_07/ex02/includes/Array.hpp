/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:42:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/27 10:54:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

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
	
		Array(const Array &other)
		{
			std::cout << "[Array] Copy constructor!" << std::endl;
			this->_length = other._length;
			this->_array = NULL;
			if (this->_length > 0)
			{
				this->_array = new T[this->_length];
				try
				{
					for (unsigned int i = 0; i < this->_length; i++)
						this->_array[i] = other._array[i];
				}
				catch (...)
				{
					delete[] this->_array;
					throw;
				}
			}
		}
	
		Array &operator=(const Array &other)
		{
			T *tmp;
		
			std::cout << "[Array] Assignment operator!" << std::endl;
			if (this != &other)
			{
				tmp = NULL;
				if (other._length > 0)
				{
					tmp = new T[other._length];
					try
					{
						for (unsigned int i = 0; i < other._length; i++)
							tmp[i] = other._array[i];
					}
					catch (...)
					{
						delete[] tmp;
						throw;
					}
				}
				delete[] this->_array;
				this->_array = tmp;
				this->_length = other._length;
			}
			return (*this);
		}
	
		~Array(void)
		{
			delete[] this->_array;
			std::cout << "[Array] Destructor!" << std::endl;
		}
	
		class InvalidIndexException : public std::exception
		{
			public:
			virtual const char *what(void) const throw()
			{
				return ("Array index is out of bounds!");
			}
		};
	
		T &operator[](unsigned int index)
		{
			if (index >= this->_length)
				throw InvalidIndexException();
			return (this->_array[index]);
		}
	
		const T &operator[](unsigned int index) const
		{
			if (index >= this->_length)
				throw InvalidIndexException();
			return (this->_array[index]);
		}
	
		unsigned int size(void) const
		{
			return (this->_length);
		}
};

#endif
