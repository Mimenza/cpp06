/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:27:30 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/16 14:10:46 by emimenza         ###   ########.fr       */
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
    //std::cout << "ScalarConverter default constructor called" << std::endl;
}


ScalarConverter::ScalarConverter(ScalarConverter &source)
{
    //std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = source;
}


ScalarConverter& ScalarConverter::operator=(ScalarConverter &source)
{
    //std::cout << "ScalarConverter copy assignment called" << std::endl;
    *this = source;
    return(*this);
}


ScalarConverter::~ScalarConverter()
{
    //std::cout << "ScalarConverter destructor called" << std::endl;
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
        int value = static_cast<int>(c) - '0';
        std::cout << "int: " << value << std::endl;
    }
    else
    {
        char* end;
        double value = strtod(literal.c_str(), &end) - '0';

        if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        {
            throw ConversionException();
        }
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::convertToFloat(std::string literal)
{
    char* end;
    float value;

    // Intentar convertir a float
    if (literal.length() == 1 && isdigit(literal[0]))
    {
        // Si es un único carácter numérico, convertir directamente
        value = static_cast<float>(literal[0] - '0');
    }
    else
    {
        value = strtof(literal.c_str(), &end); // Usar strtof para convertir a float

        // Verificar si la conversión fue exitosa
        if (end == literal.c_str() || *end != '\0' || std::isnan(value) ||
            value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
        {
            throw ConversionException();
        }
    }

    std::cout << std::fixed << std::setprecision(1) << "float: " << value << "f" << std::endl; // Ensure 0.0f
}

void ScalarConverter::convertToDouble(std::string literal)
{
    char* end;
    double value;

    // Intentar convertir a double
    if (literal.length() == 1 && isdigit(literal[0]))
    {
        // Si es un único carácter numérico, convertir directamente
        value = static_cast<double>(literal[0] - '0');
    }
    else
    {
        value = strtod(literal.c_str(), &end); // Usar strtod para convertir a double

        // Verificar si la conversión fue exitosa
        if (end == literal.c_str() || *end != '\0' || std::isnan(value) ||
            value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
        {
            throw ConversionException();
        }
    }

    std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl; // Ensure 0.0
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
