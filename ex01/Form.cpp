/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:13:57 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/08 06:28:06 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name( "Default" ), _signed( false ), _signGrade( 150 ), _execGrade( 150 ) {

	return;
}

Form::Form( const std::string &name, const int exec_grade ) {
	

	return;
}

Form::Form( const Form &src ) {
	

	return;
}

Form&	Form::operator=( const Form &rhs ) {
	

	return;
}

Form::~Form( void ) {

	return;
}

const std::string	Form::getName( void ) const {

	return this->_name;
}

bool				Form::getSigned( void ) const {

	return this->_signed;
}

const int			Form::getSignGrade( void ) const {

	return this->_signGrade;
}

const int			Form::getExecGrade( void ) const {

	return this->_execGrade;
}

std::ostream	&operator<<( std::ostream &os, const Form& rhs ) {

	return;
}
