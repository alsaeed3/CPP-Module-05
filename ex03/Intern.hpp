/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:17:39 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/16 16:28:35 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern {
	
	public:
	
		class UnkownFormNameException : public std::exception {
			
			public:
			
				virtual const char	*what() const throw();
		};

		Intern( void );
		Intern( const Intern &src );
		Intern	&operator=( const Intern &rhs );
		~Intern( void );

		AForm	*createShrubberyCreationForm( std::string &target );
		AForm	*createRobotomyRequestForm( std::string &target );
		AForm	*createPresidentialPardonForm( std::string &target );

		AForm	*makeForm( std::string name, std::string target );
};

#endif /* INTERN_HPP */