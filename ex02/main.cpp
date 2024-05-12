/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:51:40 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/12 13:00:43 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main(void)
{
	try {

		Bureaucrat	bureaucrat( "Ali", 100 );
		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;

		Form form("Form", 42, 42);
		std::cout << form;

		bureaucrat.signForm( form );
		
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;

		bureaucrat.signForm( form );
		std::cout << form;
	} catch( std::exception &e ) {

		std::cout << e.what() << std::endl;
	}
}