/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:51:56 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/28 14:14:14 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "AForm.hpp"


class Bureaucrat {
	
	private:

		const std::string	_name;
		int					_grade;	

	public:
		
		class GradeTooHighException : public std::exception {

			public:

				const char	*what( void ) const throw();
		};

		class GradeTooLowException : public std::exception {

			public:

				const char	*what( void ) const throw();
		};

		Bureaucrat( void );
		Bureaucrat( const std::string &name, int grade );
		Bureaucrat( const Bureaucrat &source );
		Bureaucrat	&operator=( const Bureaucrat &src );
		~Bureaucrat( void );

		std::string	getName( void ) const;
		int			getGrade( void ) const;

		void		incrementGrade( void );
		void		decrementGrade( void );

		void		signForm( AForm &src );
		void		executeForm( const AForm &src ) const;
};

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &rhs );

#endif /* BUREAUCRAT_HPP */