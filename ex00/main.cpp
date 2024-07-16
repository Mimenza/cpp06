/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:32:44 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/16 14:21:47 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "incs/ScalarConverter.hpp"

int main (int argc, char **argv)
{
    ScalarConverter sc;

    if (argc != 2)
        return (std::cerr << "Error, usage: ./executable input" << std::endl, 0);
    std::string literal = argv[1];

    sc.convert(literal);

    #https://github.com/Dsite42/CPP06/tree/master/ex00
}
