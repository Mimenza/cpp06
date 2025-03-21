/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:27:27 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/21 21:28:24 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <limits>
#include <string>

class ScalarConverter
{

    public:
        static void convert(std::string const &literal);
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter &source);
        virtual ~ScalarConverter(void);

        ScalarConverter &operator=(ScalarConverter &source);

};

#endif
