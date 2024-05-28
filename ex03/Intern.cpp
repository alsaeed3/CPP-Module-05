/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:17:42 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/28 17:33:38 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const char*	Intern::UnkownFormNameException::what() const throw() {

	return "There is no Form with the given name!!";	
}

Intern::Intern( void ) {

	return;	
}

Intern::Intern( const Intern &src ) {

	( void )src;

	return;	
}

Intern&		Intern::operator=( const Intern &rhs ) {

	if ( this != &rhs ) {

		( void )rhs;
	}

	return *this;	
}

Intern::~Intern( void ) {

	return;	
}

AForm*		Intern::createShrubberyCreationForm( std::string &target ) {

	return new ShrubberyCreationForm( target );	
}

AForm*		Intern::createRobotomyRequestForm( std::string &target ) {

	return new RobotomyRequestForm( target );	
}

AForm*		Intern::createPresidentialPardonForm( std::string &target ) {

	return new PresidentialPardonForm( target );	
}

AForm*		Intern::makeForm( std::string name, std::string target ) {

	AForm	*( Intern::*forms[ 3 ])( std::string &_target ) = { &Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm };
	std::string formNames[ 3 ] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	int formNameIndex = 0;

	for ( ; formNameIndex < 3; formNameIndex++ ) {
		
		if ( formNames[ formNameIndex ] == name )
			break;
	}

	if ( formNameIndex >= 3 )
		throw UnkownFormNameException();

	std::cout << "Intern creates " << name << " form" << std::endl;

	return (this->*forms[ formNameIndex ])( target );	
}
