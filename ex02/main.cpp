/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:51:40 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/15 21:08:51 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



int main(void)
{
	try
	{
		Bureaucrat	bureaucrat("Ali", 26);
		std::cout << bureaucrat;
		
		// #=========== ShrubberyCreationForm =======#
		// ShrubberyCreationForm	shrubbery("Home");
		// std::cout << shrubbery;

		// bureaucrat.signForm(shrubbery);
		// bureaucrat.executeForm(shrubbery);

		// #=========== RobotomyRequestForm =======#
		// RobotomyRequestForm	robotomy("Robot");
		// std::cout << robotomy;

		// bureaucrat.signForm(robotomy);
		// bureaucrat.executeForm(robotomy);


		// #=========== PresidentialPardonForm =======#
		PresidentialPardonForm	presidential("President");
		std::cout << presidential;

		bureaucrat.signForm(presidential);
		bureaucrat.executeForm(presidential);
		
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}