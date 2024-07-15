/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:27:27 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/15 13:49:04 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <math.h>

class ScalarConverter
{
    private:
        static void convertToChar(std::string literal);
        static void convertToInt(std::string literal);
        static void convertToFloat(std::string literal);
        static void convertToDouble(std::string literal);

        class ConversionException;
        class NonDisplayableException;

    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter &source);
        ScalarConverter& operator=(ScalarConverter &source);
        ~ScalarConverter();

        static void convert(std::string &literal);
};

#endif
