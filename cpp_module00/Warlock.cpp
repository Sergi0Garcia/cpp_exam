/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 07:59:25 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/22 08:09:12 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
    : _name(name), _title(title) {
  std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void) {
  std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName(void) const { return (this->_name); }

std::string const &Warlock::getTitle(void) const { return (this->_title); }

void Warlock::setTitle(std::string const &title) { this->_title = title; }

void Warlock::introduce(void) const {
  std::cout << _name << ": I am " << _name << ", " << _title << "!"
            << std::endl;
}