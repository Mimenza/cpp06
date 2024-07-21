/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:32:44 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/21 21:28:37 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "incs/ScalarConverter.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << "Error, usage: ./executable input" << std::endl, 0);
    std::string literal = argv[1];

    ScalarConverter::convert(literal);

}
