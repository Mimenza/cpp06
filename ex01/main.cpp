/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:39:27 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/21 19:39:27 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Serializer.hpp"

int main (void)
{
    Data data;
	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	data.id = 1234567890;
	data.name = "Patata";

	std::cout << "Info: &data: " << std::hex << &data << std::endl;
	std::cout << "Info: raw:   0x" << raw << std::endl;
	std::cout << "Info: ptr:   " << ptr << std::dec << std::endl;
	std::cout << "Info: data.id: " << data.id << ", data.name: " << data.name  << std::endl;
	std::cout << "Info: ptr->id: " << ptr->id << ", ptr->name: " << ptr->name << std::endl;

}