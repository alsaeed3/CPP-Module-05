/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:11:24 by alsaeed           #+#    #+#             */
/*   Updated: 2024/05/15 09:45:59 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private:

		std::string	_target;

	public:

		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &src );
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &rhs );
		~PresidentialPardonForm( void );

		void	execute( const Bureaucrat & executor ) const;

};

#endif /* PRESIDENTIALPARDONFORM_HPP */