/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:16:20 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/22 09:27:55 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(std::string const type) : _type(type) {}

ATarget::~ATarget(void) {}

ATarget::ATarget(const ATarget &other) { *this = other; }

ATarget &ATarget::operator=(const ATarget &other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return (*this);
}

std::string const &ATarget::getType(void) const { return (this->_type); }

void ATarget::getHitBySpell(const ASpell &spell) const {
  std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}