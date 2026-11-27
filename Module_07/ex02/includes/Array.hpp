/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:42:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/27 11:24:50 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T> class Array
{
	private:
		T *_array; // pointer to first element 
		unsigned int _length; // nbr elements in array

	public:
		Array(void)
		{
			std::cout << "[Default] create an empty array object!" << std::endl;
			this->_array = NULL;
			this->_length = 0;
		}

		Array(unsigned int n)
		{
			std::cout << "[Parameterized] create an array of " << n << " elements of type T!" << std::endl;
			this->_length = n;
			if (this->_length > 0)
				this->_array = new T[n](); // memory for n elements of type T -> initialize them to default values
			else
				this->_array = NULL; // if n is 0 ->array is empty ->set pointer to NULL
		}
	
		Array(const Array &other)
		{
			std::cout << "[Copy] create an array from another array object!" << std::endl;
			this->_length = other._length;
			this->_array = NULL;
			if (this->_length > 0)
			{
				this->_array = new T[this->_length]; // memory for new array of same length as other array
				for (unsigned int i = 0; i < this->_length; i++)
					this->_array[i] = other._array[i];
			}
		}
	
		Array &operator=(const Array &other)
		{
			T *tmp;
		
			std::cout << "[Assignment] Assign of another array to this array!" << std::endl;
			if (this != &other)
			{
				tmp = NULL;
				if (other._length > 0)
				{
					tmp = new T[other._length];
					for (unsigned int i = 0; i < other._length; i++)
						tmp[i] = other._array[i];
				}
				delete[] this->_array; // delete old array to avoid memory leak
				this->_array = tmp;
				this->_length = other._length;
			}
			return (*this);
		}
	
		~Array(void)
		{
			delete[] this->_array;
			std::cout << "[Destructor] Memory deleted!" << std::endl;
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
