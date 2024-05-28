/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:13:50 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/28 14:14:38 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {

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

		class NotSignedException : public std::exception {

			public:

				const char	*what( void ) const throw();
		};

		class FileNotOpenException : public std::exception {

			public:

				const char	*what( void ) const throw();
		};

		AForm( void );
		AForm( std::string name, int signGrade, int execGrade );
		AForm( const AForm &src );
		AForm			&operator=( const AForm &rhs );
		virtual ~AForm( void );

		std::string		getName( void ) const;
		bool			getSigned( void ) const;
		int				getSignGrade( void ) const;
		int				getExecGrade( void ) const;

		void			beSigned( const Bureaucrat &src );
		
		virtual void	execute( Bureaucrat const & executor ) const = 0;
};

std::ostream	&operator<<( std::ostream &os, const AForm& rhs );

#endif /* AFORM_HPP */