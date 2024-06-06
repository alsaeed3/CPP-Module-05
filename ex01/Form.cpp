/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:13:57 by alsaeed           #+#    #+#             */
/*   Updated: 2024/06/06 23:37:37 by alsaeed          ###   ########.fr       */
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

void		Form::beSigned( const Bureaucrat &src ) {

	if ( src.getGrade() <= _signGrade )
		_signed = true;
	else
		throw( Form::GradeTooLowException() );

	return;
}

std::ostream	&operator<<( std::ostream &os, const Form& rhs ) {

	os << "Form name is: " << rhs.getName() << ", Form::_signed: " << (rhs.getSigned() ? "true" : "false") << ", Form::_signGrade: " << rhs.getSignGrade() << ", Form::_execGrade: " << rhs.getExecGrade() << std::endl;

	return os;
}
