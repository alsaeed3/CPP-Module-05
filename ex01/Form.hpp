/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:13:50 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/28 14:13:23 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {

	private:

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:

		class GradeTooHighException : public std::exception {
			
			public:

				const char	*what( void ) const throw();
		};

		class GradeTooLowException : public std::exception {
			
			public:

				const char	*what( void ) const throw();
		};

		Form( void );
		Form( std::string name, int signGrade, int execGrade );
		Form( const Form &src );
		Form	&operator=( const Form &rhs );
		~Form( void );

		std::string	getName( void ) const;
		bool		getSigned( void ) const;
		int			getSignGrade( void ) const;
		int			getExecGrade( void ) const;

		void		beSigned( const Bureaucrat &src );
};

std::ostream	&operator<<( std::ostream &os, const Form& rhs );

#endif /* FORM_HPP */