/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:11:10 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/15 11:50:42 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm( "RobotomyRequestForm", 72, 45 ), _target( "default" ) {

	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm( "RobotomyRequestForm", 72, 45 ), _target( target ) {

	return;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src )
	: AForm( src.getName(), src.getSignGrade(), src.getExecGrade() ), _target( src._target ) {

	return;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm &rhs ) {

	if ( this != &rhs ) {
		
		AForm::operator=( rhs );
		_target = rhs._target;
	}

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

	return;
}

void	RobotomyRequestForm::execute( const Bureaucrat & executor ) const {

	if ( this->getSigned() == false )
		throw NotSignedException();
	if ( executor.getGrade() > this->getExecGrade() )
		throw GradeTooLowException();
	
	std::cout << "Drrrr... Some Drilling Noises!!" << std::endl;
	std::srand( std::time(NULL) );
	if ( std::rand() % 2 == 0 )
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " Robotomy failed" << std::endl;

	return;
}
