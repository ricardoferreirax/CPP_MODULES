/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:10:41 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/11/24 10:07:28 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

// serializer class mustnt be instantiated->its constructor is private cause class 
// only provides static methods->we never need to create a serializer object to call serialize() or deserialize().
Serializer::Serializer(void)
{
	std::cout << "[Serializer] Default Serializer created!" << std::endl;
}

// serializer objects should never be created or copied->since class has no attributes->there is no data to copy.
Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "[Serializer] Serializer has been destroyed!" << std::endl;
}

// serialize() receives a pointer to Data object->Data *ptr means ptr contains memory address of a Data object.
// if a Data object is stored at address 0x7ffd12345678->ptr contains that address.
// reinterpret_cast<uintptr_t>(ptr) reinterprets the pointer value as an unsigned int capable of storing a memory address.
// uintptr_t is an unsigned int type designed to be large enough to store a pointer value.
// The Data object itself is NOT converted, copied, moved or modified. Only the numerical representation of its memory address is returned.
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// deserialize() performs opposite operation->it receives a uintptr_t containing int representation of address that was previously obtained from serialize().
// reinterpret_cast<Data *>(raw) reinterprets that int value as a pointer to Data->function returns Data * because original value before serialization was 
// also a Data pointer->we want to recover a pointer that points to the same Data object.
// No new Data object is created here and no memory is allocated. We are simply recovering the original memory address.
Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

// goal of Serializer is to demonstrate how a pointer can be converted into an int representation and then converted back into original pointer. 
// we are not serializing or converting the contents of Data structure itself->values stored inside Data are never copied or transformed by Serializer.
// when create a Data object, that object occupies a certain location in memory->if we write "Data *ptr = &car", ptr is a pointer to Data and stores 
// memory address where car object is located->this explains why serialize() receives a Data *ptr.
// we dont want to receive Data object itself, we want its pointer because we want to convert memory address into an int representation.
//
// serialize() returns a uintptr_t->uintptr_t is an unsigned int that is capable of representing a pointer value as an int. 
// a normal int shouldnt be used cause an int isnt large enough to hold representation of a memory address->storing a pointer value in an int could lose part 
// of address->uintptr_t exists for situations where we need an unsigned int capable of holding a pointer value.
// reinterpret_cast<uintptr_t>(ptr) is a cast intended for conversions where we ask compiler to reinterpret a value as another type->it converts Data pointer 
// into its int representation->if ptr represents an address such as 0x7ffd12345678->returned uintptr_t contains an int representation corresponding to that 
// pointer value->Data object remains exactly where it was in memory and nothing inside object is modified.
// after serialization->we have an int representation of pointer. 
//
//                 reinterpret_cast<uintptr_t>
//    Data *  -----------------------------------> uintptr_t
//                 
// we want now to recover original pointer->this is the purpose of deserialize()->receives a uintptr_t cause that is exactly the type produced by serialize(). 
// it performs opposite conversion using reinterpret_cast<Data *>(raw).
// deserialize() returns Data * cause value we originally serialized was also a Data *. 
// 
// we started with a pointer to a Data object->temporarily represented that pointer as an int->and now want to recover a pointer to that same Data object. 
// return type is Data *, not Data cause deserialize() doesnt create or return a new Data object->it only reconstructs pointer value.
