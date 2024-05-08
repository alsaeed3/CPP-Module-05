/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:52:14 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/08 06:00:58 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char	*GradeTooHighException::what( void ) const throw() {
	
	return "Exception: Bureaucrat Grade is Too High!!";
}

const char	*GradeTooLowException::what( void ) const throw() {
	
	return "Exception: Bureaucrat Grade is Too Low!!";
}

Bureaucrat::Bureaucrat( void ) : _name( "Default" ), _grade( 150 ) {

	return;
}

Bureaucrat::Bureaucrat( std::string const &name, int grade ) : _name( name ) {

	if ( grade < 1 )
		throw GradeTooHighException();

	else if ( grade > 150 )
		throw GradeTooLowException();

	this->_grade = grade;

	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) : _name( src.getName() ), _grade( src.getGrade() ) {

	return;
}

Bureaucrat&			Bureaucrat::operator=( Bureaucrat const &rhs ) {

	if ( this != &rhs )
		this->_grade = rhs.getGrade();

	return *this;
}

Bureaucrat::~Bureaucrat( void ) {

	return;
}

std::string			Bureaucrat::getName( void ) const {

	return this->_name;
}

int					Bureaucrat::getGrade( void ) const {	

	return this->_grade;
}

void				Bureaucrat::incrementGrade( void ) {

	if ( this->_grade - 1 < 1)
		throw GradeTooHighException();

	this->_grade--;

	return;
}

void				Bureaucrat::decrementGrade( void ) {

	if ( this->_grade + 1 > 150 )
		throw GradeTooLowException();

	this->_grade++;

	return;
}

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &rhs ) {
	
	os << rhs.getName() << ", bureaucrat grade is " << rhs.getGrade() << std::endl;
	
	return os;
}
