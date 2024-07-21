/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:40:13 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/21 19:40:13 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <string>


typedef struct s_data
{
	int id;
	std::string name;
} Data;


class Serializer
{

    private:
        Serializer();
        Serializer(Serializer &source);
        virtual ~Serializer(void);

        Serializer &operator=(Serializer &source);

    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);

};

#endif