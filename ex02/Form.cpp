/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:13:57 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/12 13:00:22 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what( void ) const throw() {
	
	return "Form Grade is too High!!";
}

const char* Form::GradeTooLowException::what( void ) const throw() {
	
	return "Form Grade is too Low!!";
}

Form::Form( void ) : _name( "Default" ), _signed( false ), _signGrade( 150 ), _execGrade( 150 ) {

	return;
}

Form::Form( std::string name, int signGrade, int execGrade ) : _name( name ), _signed( false ), _signGrade( signGrade ), _execGrade( execGrade ) {	

	if ( _signGrade < 1 || _execGrade < 1 )
		throw GradeTooHighException();
	if ( _signGrade > 150 || _execGrade > 150 )
		throw GradeTooLowException();

	return;
}

Form::Form( const Form &src ) : _name( src._name ), _signed( src._signed ), _signGrade( src._signGrade ), _execGrade( src._execGrade ) {

	return;
}

Form&	Form::operator=( const Form &rhs ) {

	if ( this != &rhs )
		_signed = rhs._signed;

	return *this;
}

Form::~Form( void ) {

	return;
}

std::string	Form::getName( void ) const {

	return this->_name;
}

bool		Form::getSigned( void ) const {

	return this->_signed;
}

int			Form::getSignGrade( void ) const {

	return this->_signGrade;
}

int			Form::getExecGrade( void ) const {

	return this->_execGrade;
}

/* A member function that will check the grade between bureaucrat and form objects */
/* in case */
void		Form::beSigned( const Bureaucrat &src ) {

	if ( src.getGrade() < _signGrade )
		throw( Form::GradeTooLowException() );
	else
		_signed = true;

	return;
}

/* A non-member funtion to overload << after cout or any output stream functions */
/* It will show the given statement in case cout received an object of the class in the parameter after << */
std::ostream	&operator<<( std::ostream &os, const Form& rhs ) {

	os << "Form name is: " << rhs.getName() << ", Form::_signed = " << rhs.getSigned() << ", Form::_signGrade = " << rhs.getSignGrade() << ", Form::_execGrade = " << rhs.getExecGrade() << std::endl;

	return os;
}
