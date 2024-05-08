/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:51:56 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/08 06:34:58 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>

class GradeTooHighException : public std::exception {

	public:
	
		const char	*what( void ) const throw();
};

class GradeTooLowException : public std::exception {

	public:
	
		const char	*what( void ) const throw();
};

class Bureaucrat {
	
	private:

		const std::string	_name;
		int					_grade;	

	public:

		Bureaucrat( void );
		Bureaucrat( const std::string &name, int grade );
		Bureaucrat( const Bureaucrat &source );
		Bureaucrat	&operator=( const Bureaucrat &src );
		~Bureaucrat( void );

		std::string	getName( void ) const;
		int			getGrade( void ) const;

		void		incrementGrade( void );
		void		decrementGrade( void );
};

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &rhs );

#endif /* BUREAUCRAT_HPP */