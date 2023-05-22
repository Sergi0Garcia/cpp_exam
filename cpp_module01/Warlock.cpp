/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 07:59:25 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/22 10:18:15 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "ATarget.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
    : _name(name), _title(title) {
  std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void) {
  std::cout << _name << ": My job here is done!" << std::endl;
  std::vector<ASpell *>::iterator ite = this->spells.end();
  for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != ite;
       ++it)
    delete *it;
  this->spells.clear();
}

std::string const &Warlock::getName(void) const { return (this->_name); }

std::string const &Warlock::getTitle(void) const { return (this->_title); }

void Warlock::setTitle(std::string const &title) { this->_title = title; }

void Warlock::introduce(void) const {
  std::cout << _name << ": I am " << _name << ", " << _title << "!"
            << std::endl;
}

void Warlock::learnSpell(ASpell *spell) {
  if (spell) {
    std::vector<ASpell *>::iterator ite = this->spells.end();
    for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != ite;
         ++it)
      if ((*it)->getName() == spell->getName())
        return;
    this->spells.push_back(spell->clone());
  }
}

void Warlock::forgetSpell(std::string const &name) {
  std::vector<ASpell *>::iterator ite = this->spells.end();
  for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != ite;
       ++it) {
    if ((*it)->getName() == name) {
      delete *it;
      it = this->spells.erase(it);
    }
  }
}

void Warlock::launchSpell(std::string const &name, const ATarget &target) {
  std::vector<ASpell *>::iterator ite = this->spells.end();
  for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != ite;
       ++it) {
    if ((*it)->getName() == name) {
      (*it)->launch(target);
      return;
    }
  }
}