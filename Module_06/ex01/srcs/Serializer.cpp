/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:10:41 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/08/20 22:13:57 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

// The Serializer class must not be instantiated. Its constructor is private because the class only provides static methods.
// We never need to create a Serializer object to call serialize() or deserialize().
Serializer::Serializer(void)
{
	std::cout << "[Serializer] Default Serializer created!" << std::endl;
}

// It is private because Serializer objects should never be created or copied. Since the class has no attributes, 
// there is no actual data to copy.
Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

// Serializer has no attributes, so there is nothing to assign. It is private because the user should not create or assign 
// Serializer objects.
Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "[Serializer] Serializer has been destroyed!" << std::endl;
}


// serialize() receives a pointer to a Data object. Data *ptr means that ptr contains the memory address of a Data object.
// For example, if a Data object is stored at address 0x7ffd12345678, ptr contains that address.
//
// reinterpret_cast<uintptr_t>(ptr) reinterprets the pointer value as an unsigned int capable of storing a memory address.
// uintptr_t is an unsigned int type designed to be large enough to store a pointer value when the implementation provides it.
//
// The Data object itself is NOT converted, copied, moved or modified. Only the numerical representation of its memory address is returned.
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// deserialize() performs the opposite operation. It receives a uintptr_t containing the integer representation of the
// address that was previously obtained from serialize().
//
// reinterpret_cast<Data *>(raw) reinterprets that int value as a pointer to Data. The function returns Data * because the original
// value before serialization was also a Data pointer. We want to recover a pointer that points to the same Data object.
//
// No new Data object is created here and no memory is allocated. We are simply recovering the original memory address.
Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}


 // The purpose of the Serializer class is to demonstrate how a pointer can be converted into an integer representation and then converted 
 // back into the original pointer. The important idea is that we are not serializing or converting the contents of the Data structure itself. 
 // The values stored inside Data, such as the brand, year and price of the car, are never copied or transformed by Serializer.
 // When we create a Data object, that object occupies a certain location in memory. If we write "Data *ptr = &car", ptr is a pointer to Data 
 // and stores the memory address where the car object is located. This explains why the serialize() function receives a Data *ptr. We do not 
 // want to receive the Data object itself, we specifically want its pointer because the exercise is about converting a memory address into an 
 // integer representation.
 //
 // serialize() returns a uintptr_t. uintptr_t is an unsigned integer type that, when available, is capable of representing a pointer value as 
 // an integer. A normal int should not be used for this purpose because there is no guarantee that an int is large enough to hold the representation 
 // of a memory address. For example, on a system where pointers are 64 bits and int is 32 bits, storing a pointer value in an int could lose part 
 // of the address. uintptr_t exists specifically for situations where we need an unsigned integer type capable of holding a pointer value.
 //
 // Inside serialize(), reinterpret_cast<uintptr_t>(ptr) is a C++ cast intended for conversions where we ask the compiler to reinterpret a value 
 // as another type. In this case, it converts the Data pointer into its integer representation. If ptr represents an address such as 0x7ffd12345678, 
 // the returned uintptr_t contains an integer representation corresponding to that pointer value. The Data object remains exactly where it was in 
 // memory and nothing inside the object is modified.
 //
 //                 reinterpret_cast<uintptr_t>
 //    Data *  -----------------------------------> uintptr_t
 //                 
 // After serialization, we have an integer representation of the pointer, but we want to recover the original pointer. This is the purpose of
 // deserialize(). The function receives a uintptr_t because that is exactly the type produced by serialize(). It then performs the opposite conversion 
 // using reinterpret_cast<Data *>(raw).
 // 
 // deserialize() returns Data * because the value we originally serialized was also a Data *. We started with a pointer to a Data object, temporarily
 // represented that pointer as an integer, and now want to recover a pointer to that same Data object. The return type is Data *, not Data, because
 // deserialize() does not create or return a new Data object. It only reconstructs the pointer value.
 // 
 //                serialize()                 deserialize()
 //    Data *  -----------------> uintptr_t -----------------> Data *

 // For example, if "original" points to a Data object called car, serialize() converts the address stored in original into a uintptr_t called raw.
 // deserialize(raw) converts that integer representation back into a Data pointer called restored. No new car is created during this process and the
 // original car is never copied. Both original and restored should contain the address of the same object.
 // 
 // If the serialization/deserialization worked correctly, the comparison (original == restored) is true. Pointer comparison in this case compares the addresses
 // stored by the two pointers. It does not compare brand, year or price. The result is true because both pointers refer to the exact same Data object in
 // memory.
 // This also explains why we can access restored->brand, restored->year and restored->price after deserialization. deserialize() did not recreate these
 // values. restored simply points back to the original Data object where those values already exist.
 