/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:27:30 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/16 16:01:17 by emimenza         ###   ########.fr       */
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
        if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || literal == "nanf" || literal == "inff" || literal == "-inff" || literal == "nan" || literal == "inf" || literal == "-inf")
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
    char* end;
    double value = std::strtod(literal.c_str(), &end);

    if ((*end != '\0' && *end != 'f') || literal == "nanf" || literal == "inff" || literal == "-inff" || literal == "nan" || literal == "inf" || literal == "-inf")
    {
        throw ConversionException();
    }

    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        throw NonDisplayableException();
    }

    int intValue = static_cast<int>(value);
    std::cout << "Int: " << intValue << std::endl;
}

void ScalarConverter::convertToFloat(std::string literal)
{
    char* end;
    float value = std::strtof(literal.c_str(), &end);

    if (literal == "nanf" || literal == "inff" || literal == "-inff")
    {
        std::cout << "Float: " << literal << std::endl;
        return;
    }

    if ((*end != '\0' && *end != 'f'))
    {
        throw ConversionException();
    }

    if ((value < std::numeric_limits<float>::min() && value != 0.0f) || 
        value > std::numeric_limits<float>::max()) {
        throw NonDisplayableException();
    }

    std::cout << std::fixed << std::setprecision(1) << "Float: " << value << "f" << std::endl;
}

void ScalarConverter::convertToDouble(std::string literal)
{
    char* end;
    double value = std::strtod(literal.c_str(), &end);

     if (literal == "nan" || literal == "inf" || literal == "-inf")
    {
        std::cout << "Double: " << literal << std::endl;
        return;
    }

    if ((*end != '\0' && *end != 'f' && *end != 'd')) {
        throw ConversionException();
    }

    if ((value < std::numeric_limits<double>::min() && value != 0.0) || 
        value > std::numeric_limits<double>::max()) {
        throw NonDisplayableException();
    }

    std::cout << std::fixed << std::setprecision(1) << "Double: " << value << std::endl;
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

    //std::cout << literal << std::endl;
}
