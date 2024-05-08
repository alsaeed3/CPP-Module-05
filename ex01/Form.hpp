/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:13:50 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/08 06:22:39 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form {

	private:

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:

		Form( void );
		Form( const std::string &name, const int exec_grade );
		Form( const Form &src );
		Form	&operator=( const Form &rhs );
		Form( void );

		const std::string	getName( void ) const;
		bool				getSigned( void ) const;
		const int			getSignGrade( void ) const;
		const int			getExecGrade( void ) const;
};

std::ostream	&operator<<( std::ostream &os, const Form& rhs );

#endif