/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:52:14 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/15 12:05:02 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw() {

	return "Bureaucrat Grade is Too High!!";
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw() {

	return "Bureaucrat Grade is Too Low!!";
}

Bureaucrat::Bureaucrat( void ) : _name( "Default" ), _grade( 150 ) {

	return;
}

Bureaucrat::Bureaucrat( const std::string &name, int grade ) : _name( name ) {

	if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException();

	else if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();

	this->_grade = grade;

	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) : _name( src.getName() ), _grade( src.getGrade() ) {

	return;
}

Bureaucrat&		Bureaucrat::operator=( Bureaucrat const &rhs ) {

	if ( this != &rhs )
		this->_grade = rhs.getGrade();

	return *this;
}

Bureaucrat::~Bureaucrat( void ) {

	return;
}

std::string		Bureaucrat::getName( void ) const {

	return this->_name;
}

int				Bureaucrat::getGrade( void ) const {	

	return this->_grade;
}

void			Bureaucrat::incrementGrade( void ) {

	if ( this->_grade - 1 < 1)
		throw GradeTooHighException();

	this->_grade--;

	return;
}

void			Bureaucrat::decrementGrade( void ) {

	if ( this->_grade + 1 > 150 )
		throw GradeTooLowException();

	this->_grade++;

	return;
}

void			Bureaucrat::signForm( AForm &src ) {

	try {
		
		src.beSigned( *this );
		std::cout << _name << " signed " << src.getName() << std::endl;
	} catch ( std::exception &e ) {

		std::cerr << _name << " couldn't sign " << src.getName() << " because " << e.what() << std::endl;
	}

	return;
}

void			Bureaucrat::executeForm( const AForm &form ) const {

	try {

		form.execute( *this );
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch ( std::exception &e ) {

		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}

	return;
}

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &rhs ) {

	os << rhs.getName() << " grade is " << rhs.getGrade() << std::endl;

	return os;
}
