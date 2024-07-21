/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:27:30 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/21 19:34:02 by emimenza         ###   ########.fr       */
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

void ScalarConverter::convert(std::string const &literal)
{
	std::stringstream ss;
	double d;
	float f;
	int i;
	char c;

	ss << literal;
	ss >> d;

	if (ss.fail())
	{
		if (literal.length() != 1)
		{
			d = std::strtod(literal.c_str(), NULL);

			if (d == 0.0)
			{
				std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;

				return;
			}
		}
		else
			d = static_cast<double>(literal.at(0));
	}

	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);

	if (std::isfinite(d))
	{
		if (d < std::numeric_limits<char>::min() || std::numeric_limits<char>::max() < d)
			std::cout << "char: impossible\n";
		else if (!std::isprint(c))
			std::cout << "char: non displayable\n";
		else
			std::cout << "char: '" << c << "'\n";

		if (d < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < d)
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << i << '\n';
	}
	else
		std::cout << "char: impossible\nint: impossible\n";

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << d << std::endl;

	return;
}