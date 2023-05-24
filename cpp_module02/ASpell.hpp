#pragma once
#include <iostream>

class ATarget;

class ASpell {
private:
  std::string _name;
  std::string _effects;
  ASpell();

public:
  ASpell(const std::string name, const std::string effects);
  ASpell(const ASpell &other);
  ASpell &operator=(const ASpell &other);
  virtual ~ASpell();

  const std::string &getName(void) const;
  const std::string &getEffects(void) const;

  virtual ASpell *clone(void) const = 0;

  void launch(ATarget const &target) const;
};

#include "ATarget.hpp"