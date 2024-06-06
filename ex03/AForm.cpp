/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:13:57 by alsaeed           #+#    #+#             */
/*   Updated: 2024/06/06 23:37:14 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what( void ) const throw() {

	return "AForm Grade is too High!!";
}

const char* AForm::GradeTooLowException::what( void ) const throw() {

	return "AForm Grade is too Low!!";
}

const char* AForm::NotSignedException::what( void ) const throw() {

	return "AForm is not Signed!!";
}

const char* AForm::FileNotOpenException::what( void ) const throw() {

	return "File could not be opened!!";
}

AForm::AForm( void ) : _name( "Default" ), _signed( false ), _signGrade( 150 ), _execGrade( 150 ) {

	return;
}

AForm::AForm( std::string name, int signGrade, int execGrade ) : _name( name ), _signed( false ), _signGrade( signGrade ), _execGrade( execGrade ) {	

	if ( _signGrade < 1 || _execGrade < 1 )
		throw GradeTooHighException();
	if ( _signGrade > 150 || _execGrade > 150 )
		throw GradeTooLowException();

	return;
}

AForm::AForm( const AForm &src ) : _name( src._name ), _signed( src._signed ), _signGrade( src._signGrade ), _execGrade( src._execGrade ) {

	return;
}

AForm&	AForm::operator=( const AForm &rhs ) {

	if ( this != &rhs )
		_signed = rhs._signed;

	return *this;
}

AForm::~AForm( void ) {

	return;
}

std::string	AForm::getName( void ) const {

	return this->_name;
}

bool		AForm::getSigned( void ) const {

	return this->_signed;
}

int			AForm::getSignGrade( void ) const {

	return this->_signGrade;
}

int			AForm::getExecGrade( void ) const {

	return this->_execGrade;
}

void		AForm::beSigned( const Bureaucrat &src ) {

	if ( src.getGrade() <= _signGrade )
		_signed = true;
	else
		throw( AForm::GradeTooLowException() );

	return;
}

std::ostream	&operator<<( std::ostream &os, const AForm& rhs ) {

	os << "AForm name is: " << rhs.getName() << ", AForm::_signed: " << (rhs.getSigned() ? "true" : "false") << ", AForm::_signGrade: " << rhs.getSignGrade() << ", AForm::_execGrade: " << rhs.getExecGrade() << std::endl;

	return os;
}

void		AForm::execute( Bureaucrat const & executor ) const {

	if ( !getSigned() )
		throw NotSignedException();
	if ( executor.getGrade() > getExecGrade() )
		throw GradeTooLowException();
}