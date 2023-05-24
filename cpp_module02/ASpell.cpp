#include "ASpell.hpp"
#include <string>

ASpell::ASpell(const std::string name, const std::string effects)
    : _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell &other) { *this = other; }

ASpell &ASpell::operator=(const ASpell &other) {
  if (this != &other) {
    this->_name = other._name;
    this->_effects = other._effects;
  }
  return (*this);
}

ASpell::~ASpell(void) {}

const std::string &ASpell::getName(void) const { return (_name); }

const std::string &ASpell::getEffects(void) const { return (_effects); }

void ASpell::launch(ATarget const &target) const {
  target.getHitBySpell(*this);
}