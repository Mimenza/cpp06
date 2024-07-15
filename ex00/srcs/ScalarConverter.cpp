/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:27:30 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/15 13:51:25 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"


class ScalarConverter::ConversionException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "impossible";
        }
    };


class ScalarConverter::NonDisplayableException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Non displayable";
        }
    };
   
    
ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}


ScalarConverter::ScalarConverter(ScalarConverter &source)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = source;
}


ScalarConverter& ScalarConverter::operator=(ScalarConverter &source)
{
    std::cout << "ScalarConverter copy assignment called" << std::endl;
    *this = source;
    return(*this);
}


ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}


void ScalarConverter::convertToChar(std::string literal)
{
    (void)literal;
    
    std::cout << "convertToChar" << std::endl;
}

void ScalarConverter::convertToInt(std::string literal)
{
    (void)literal;
    std::cout << "convertToInt" << std::endl;
}

void ScalarConverter::convertToFloat(std::string literal)
{
    (void)literal;
    std::cout << "convertToFloat" << std::endl;
}

void ScalarConverter::convertToDouble(std::string literal)
{
    (void)literal;
    std::cout << "convertToDouble" << std::endl;
}

void ScalarConverter::convert(std::string &literal)
{   
    try
    {
        convertToChar(literal);
    } catch (const std::exception &e) {
        std::cerr << "char: " << e.what() << std::endl;
    }

    try {
        convertToInt(literal);
    } catch (const std::exception &e) {
        std::cerr << "int: " << e.what() << std::endl;
    }

    try {
        convertToFloat(literal);
    } catch (const std::exception &e) {
        std::cerr << "float: " << e.what() << std::endl;
    }

    try {
        convertToDouble(literal);
    } catch (const std::exception &e) {
        std::cerr << "double: " << e.what() << std::endl;
    }
}
