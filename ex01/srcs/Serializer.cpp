/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:40:12 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/21 19:40:12 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serializer.hpp"


Serializer::Serializer()
{
    std::cout << "Serializer default constructor called" << std::endl;
}


Serializer::Serializer(Serializer &source)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = source;
}


Serializer& Serializer::operator=(Serializer &source)
{
    std::cout << "Serializer copy assignment called" << std::endl;
    *this = source;
    return(*this);
}


Serializer::~Serializer()
{
    std::cout << "Serializer destructor called" << std::endl;
}


uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}