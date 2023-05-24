#include "SpellBook.hpp"
#include "ASpell.hpp"

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void) {
  size_t arrSize = _arr.size();
  if (arrSize == 0)
    return;
  for (size_t i = 0; i < arrSize; i++) {
    _arr.erase(std::remove(_arr.begin(), _arr.end(), _arr[i]));
  }
  _arr.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
  if (!spell)
    return;
  size_t arrSize = _arr.size();
  if (arrSize == 0) {
    _arr.push_back(spell->clone());
    return;
  }
  for (size_t i = 0; i < arrSize; i++) {
    if (_arr[i]->getName() == spell->getName())
      return;
  }
  _arr.push_back(spell->clone());
}

void SpellBook::forgetSpell(const std::string &name) {
  size_t arrSize = _arr.size();
  if (arrSize == 0)
    return;
  for (size_t i = 0; i < arrSize; i++) {
    if (_arr[i]->getName() == name)
      _arr.erase(std::remove(_arr.begin(), _arr.end(), _arr[i]));
  }
}

ASpell *SpellBook::createSpell(const std::string &name) {
  size_t arrSize = _arr.size();
  if (arrSize == 0)
    return nullptr;
  for (size_t i = 0; i < arrSize; i++) {
    if (_arr[i]->getName() == name)
      return (_arr[i]->clone());
  }
  return nullptr;
}