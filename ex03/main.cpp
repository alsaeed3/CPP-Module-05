/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:51:40 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/29 18:11:16 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void ) {

	AForm	*rrf = NULL;

	try {

		Intern someRandomIntern;

		rrf = someRandomIntern.makeForm( "shrubbery creation", "Bender" );
		std::cout << *rrf << std::endl;
	} catch( const std::exception &e ) {

		std::cout << e.what() << std::endl;
	}

	Bureaucrat	bureaucrat( "Ali", 5 );
	bureaucrat.signForm( *rrf );
	bureaucrat.executeForm( *rrf );
	delete rrf;

	return 0;
}