#pragma once
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <iostream>
#include <vector>

class Warlock {
private:
  std::string _name;
  std::string _title;
  SpellBook spell_book;

  Warlock();
  Warlock(const Warlock &other);
  Warlock &operator=(const Warlock &other);

public:
  Warlock(const std::string &name, const std::string &title);
  ~Warlock();

  const std::string &getName(void) const;
  const std::string &getTitle(void) const;

  void introduce(void) const;
  void setTitle(const std::string &title);

  void learnSpell(ASpell *spell);
  void forgetSpell(std::string name);
  void launchSpell(std::string name, const ATarget &target);
};