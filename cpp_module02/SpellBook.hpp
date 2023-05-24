#pragma once
#include "ASpell.hpp"
#include <iostream>
#include <vector>

class SpellBook {
private:
  std::vector<ASpell *> _arr;
  SpellBook(const SpellBook &other);
  SpellBook &operator=(const SpellBook &other);

public:
  SpellBook();
  ~SpellBook();

  void learnSpell(ASpell *spell);
  void forgetSpell(const std::string &name);
  ASpell *createSpell(const std::string &name);
};