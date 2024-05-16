/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:10:56 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/15 09:46:10 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private:

		std::string	_target;

	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &src );
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &rhs );
		~RobotomyRequestForm( void );

		void	execute( const Bureaucrat & executor ) const;

};

#endif /* ROBOTOMYREQUESTFORM_HPP */