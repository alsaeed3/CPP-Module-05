/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:51:40 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/16 16:45:52 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



int main( void ) {

	try {
		Intern someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm( "robotomy request", "Bender" );
		std::cout << *rrf << std::endl;
		delete rrf;
	} catch( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}