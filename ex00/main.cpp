/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:51:40 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/28 19:51:29 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {

	std::cout << std::endl;
	std::cout << " Case 1: " << std::endl;
	std::cout << std::endl;

    try {

        Bureaucrat b1( "Ali", 1 );
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
    } catch ( std::exception &e ) {

        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << " ----------------------------- " << std::endl;
	std::cout << " Case 2: " << std::endl;
	std::cout << std::endl;
 
    try {
        Bureaucrat b2( "Bob", 151 );
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;
        b2.incrementGrade();
        std::cout << b2 << std::endl;
    } catch ( std::exception &e ) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << " ----------------------------- " << std::endl;
	std::cout << " Case 3: " << std::endl;
	std::cout << std::endl;

    try {
        Bureaucrat b3( "Charlie", 42 );
        std::cout << b3 << std::endl;
        b3.incrementGrade();
        std::cout << b3 << std::endl;
        b3.decrementGrade();
        std::cout << b3 << std::endl;
    } catch ( std::exception &e ) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}