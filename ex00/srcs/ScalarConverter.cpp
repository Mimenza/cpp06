/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:27:30 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/16 12:58:50 by emimenza         ###   ########.fr       */
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
    if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
    {
        std::cout << "char: " << literal[0] << std::endl;
    }
    else
    {
        long value = std::strtol(literal.c_str(), NULL, 10);
        if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        {
            throw ConversionException();
        }
        if (!isprint(static_cast<char>(value)))
        {
            throw NonDisplayableException();
        }
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    }
}

void ScalarConverter::convertToInt(std::string literal)
{
    if (literal.length() == 1)
    {
        char c = literal[0];
        int value = static_cast<int>(c);
        std::cout << "int: " << value << std::endl;
    }
    else
    {
        char* end;
        double value = strtod(literal.c_str(), &end);

        if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        {
            throw ConversionException();
        }
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }  
}

void ScalarConverter::convertToFloat(std::string literal)
{
     if (literal.length() == 1)
    {
        char c = literal[0];
        int value = static_cast<float>(c);
        std::cout << "float: " << value << "f" << std::endl;
    }
    else
    {
        char* end;
        double value = strtod(literal.c_str(), &end);

        if (std::isnan(value) || value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
        {
            throw ConversionException();
        }
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }  
}

void ScalarConverter::convertToDouble(std::string literal)
{
 if (literal.length() == 1)
    {
        char c = literal[0];
        int value = static_cast<double>(c);
        std::cout << "double: " << value << "d" << std::endl;
    }
    else
    {
        char* end;
        double value = strtod(literal.c_str(), &end);

        if (std::isnan(value) || value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
        {
            throw ConversionException();
        }
        std::cout << "double: " << static_cast<double>(value) << "d" << std::endl;
    }  
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
