/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:32:44 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/16 12:56:02 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "incs/ScalarConverter.hpp"

int main (void)
{
    ScalarConverter sc;
    std::string patata;

    patata = "c";
    sc.convert(patata);
    std::cout << std::endl;
    patata = "110";
    sc.convert(patata);
    std::cout << std::endl;
    patata = "120.7f";
    sc.convert(patata);
    std::cout << std::endl;
    patata = "89.5";
    sc.convert(patata);

}
