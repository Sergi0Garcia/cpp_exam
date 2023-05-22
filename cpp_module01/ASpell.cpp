/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 08:28:58 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/22 09:28:07 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(std::string const name, std::string const effects)
    : _name(name), _effects(effects) {}

ASpell::~ASpell() {}

ASpell::ASpell(const ASpell &other) { *this = other; }

ASpell &ASpell::operator=(const ASpell &other) {
  if (this != &other) {
    this->_name = other._name;
    this->_effects = other._effects;
  };
  return (*this);
}

std::string const &ASpell::getName(void) const { return (this->_name); }

std::string const &ASpell::getEffects(void) const { return (this->_effects); }

void ASpell::launch(ATarget const &target) const {
  target.getHitBySpell(*this);
}