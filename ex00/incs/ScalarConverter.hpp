/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:27:27 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/16 14:05:54 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <limits>
# include <cstdlib>
# include <cerrno>
# include <cmath>
# include <sstream>
# include <iomanip>

class ScalarConverter
{
    private:
        static void convertToChar(std::string literal);
        static void convertToInt(std::string literal);
        static void convertToFloat(std::string literal);
        static void convertToDouble(std::string literal);


    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter &source);
        ScalarConverter& operator=(ScalarConverter &source);
        ~ScalarConverter();

        static void convert(std::string &literal);
        class ConversionException;
        class NonDisplayableException;
        
};

#endif
