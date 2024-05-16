/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:10:39 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/15 12:10:19 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private:

		std::string	_target;

	public:

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &src );
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &rhs );
		~ShrubberyCreationForm( void );

		void	execute( const Bureaucrat & executor ) const;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */