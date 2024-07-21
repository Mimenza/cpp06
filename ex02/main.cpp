/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:31:56 by emimenza          #+#    #+#             */
/*   Updated: 2024/07/21 21:31:56 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/A.hpp"
#include "incs/B.hpp"
#include "incs/C.hpp"
#include "incs/Base.hpp"

#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>


Base *generate(void)
{
    int const random = std::rand() % 3;

    if(random == 1)
        return (new A());
    else if (random == 2)
        return (new B());
    else
        return (new C());
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Is C" << std::endl;
    else
        std::cout << "IDK" << std::endl;
}

void identify(Base &p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "Is A" << std::endl;
    }
    catch (const std::bad_cast &)
    {
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "Is B" << std::endl;
        }
        catch (const std::bad_cast &)
        {
            try
            {
                dynamic_cast<C&>(p);
                std::cout << "Is C" << std::endl;
            }
            catch (const std::bad_cast &)
            {
                std::cout << "IDK" << std::endl;
            }
        }
    }
}

int main (void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Base* obj = generate();
    identify(obj);
    identify(*obj);
}