/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:32:44 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/21 19:30:09 by emimenza         ###   ########.fr       */
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

}
