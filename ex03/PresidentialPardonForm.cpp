/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:11:30 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/28 20:32:18 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm( "PresidentialPardonForm", 25, 5 ), _target( "default" ) {

	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm( "PresidentialPardonForm", 25, 5 ), _target( target ) {

	return;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) : AForm( src.getName(), src.getSignGrade(), src.getExecGrade() ), _target( src._target ) {

	return;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm &rhs ) {

	if ( this != &rhs ) {
		
		AForm::operator=( rhs );
		_target = rhs._target;
	}

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

	return;
}

void	PresidentialPardonForm::execute( const Bureaucrat & executor ) const {

	if ( this->getSigned() == false )
		throw NotSignedException();
	if ( executor.getGrade() > this->getExecGrade() )
		throw GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;

	return;
}
