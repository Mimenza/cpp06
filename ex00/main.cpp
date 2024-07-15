/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:32:44 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/15 13:46:33 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "incs/ScalarConverter.hpp"

int main (void)
{
    ScalarConverter sc;
    std::string patata;

    patata = 'c';
    sc.convert(patata);
    
    // patata = 54;
    // sc.convert(patata);

    // patata = 56.7f;
    // sc.convert(patata);

    // patata = 89.5;
    // sc.convert(patata);

}
