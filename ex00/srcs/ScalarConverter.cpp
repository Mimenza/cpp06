/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:27:30 by emimenza          #+#    #+#             */
/*   Updated: 2024/08/28 17:52:45 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"


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

int convertChar(std::string const &literal)
{
	 // Detectar si el literal es un char
    if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
        char c = literal[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << i << '\n';
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << std::endl;
        return 1;
    }
	return 0;
}

int convertInt(std::string const &literal)
{
	 // Intentar convertir a int
    char *end;
    long l = std::strtol(literal.c_str(), &end, 10);
    if (*end == '\0' && l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max())
	{
        int i = static_cast<int>(l);
        char c = static_cast<char>(i);
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);

        if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
            std::cout << "char: impossible\n";
        else if (!std::isprint(c))
            std::cout << "char: non displayable\n";
        else
            std::cout << "char: '" << c << "'\n";

        std::cout << "int: " << i << '\n';
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << std::endl;
        return 1;
    }
	return 0;
}

int convertFloat(std::string const &literal)
{
    // Intentar convertir a float
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        float f = std::strtof(literal.c_str(), NULL);
        double d = static_cast<double>(f);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << std::endl;
        return 1;
    }

    char *end;
    float f = std::strtof(literal.c_str(), &end);
    if (*end == 'f' && *(end + 1) == '\0')
    {
        double d = static_cast<double>(f);
        int i = static_cast<int>(f);
        char c = static_cast<char>(f);

        if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
            std::cout << "char: impossible\n";
        else if (!std::isprint(c))
            std::cout << "char: non displayable\n";
        else
            std::cout << "char: '" << c << "'\n";

        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << i << '\n';

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << std::endl;
        return 1;
    }
    return 0;
}

int convertDouble(std::string const &literal)
{
    // Intentar convertir a double
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        double d = std::strtod(literal.c_str(), NULL);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << static_cast<float>(d) << "f\n";
        std::cout << "double: " << d << std::endl;
        return 1;
    }

    char *end;
    double d = std::strtod(literal.c_str(), &end);
    if (*end == '\0')
    {
        int i = static_cast<int>(d);
        char c = static_cast<char>(d);
        float f = static_cast<float>(d);

        if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
            std::cout << "char: impossible\n";
        else if (!std::isprint(c))
            std::cout << "char: non displayable\n";
        else
            std::cout << "char: '" << c << "'\n";

        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << i << '\n';

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << std::endl;
        return 1;
    }
    return 0;
}

void ScalarConverter::convert(std::string const &literal)
{

	if (convertInt(literal) == 1)
		return;
	if (convertChar(literal) == 1)
		return;
	if (convertFloat(literal) == 1)
		return;
	if (convertDouble(literal) == 1)
		return;
    // Si no se pudo detectar el tipo
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible" << std::endl;
}