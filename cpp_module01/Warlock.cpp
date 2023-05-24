#include "Warlock.hpp"
#include "ASpell.hpp"
#include <algorithm>
#include <string>
#include <sys/_types/_size_t.h>
#include <type_traits>
#include <vector>

Warlock::Warlock(const std::string &name, const std::string &title)
    : _name(name), _title(title) {
  std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &other) { *this = other; }

Warlock &Warlock::operator=(const Warlock &other) {
  if (this != &other) {
    this->_name = other._name;
    this->_title = other._title;
  }
  return (*this);
}

Warlock::~Warlock(void) {
  std::cout << _name << ": My job here is done!" << std::endl;
  size_t arrSize = _arr.size();
  if (arrSize == 0)
    return;
  for (size_t i = 0; i < arrSize; i++) {
    _arr.erase(std::remove(_arr.begin(), _arr.end(), _arr[i]));
  }
  _arr.clear();
}

const std::string &Warlock::getName(void) const { return (_name); }

const std::string &Warlock::getTitle(void) const { return (_title); }

void Warlock::introduce(void) const {
  std::cout << _name << ": I am " << _name << ", " << _title << "!"
            << std::endl;
}

void Warlock::setTitle(const std::string &title) { _title = title; }

void Warlock::learnSpell(ASpell *spell) {
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

void Warlock::forgetSpell(std::string name) {
  size_t arrSize = _arr.size();
  if (arrSize == 0)
    return;
  for (size_t i = 0; i < arrSize; i++) {
    if (_arr[i]->getName() == name) {
      _arr.erase(std::remove(_arr.begin(), _arr.end(), _arr[i]));
    }
  }
}

void Warlock::launchSpell(std::string name, const ATarget &target) {
  size_t arrSize = _arr.size();
  if (arrSize == 0)
    return;
  for (size_t i = 0; i < arrSize; i++) {
    if (_arr[i]->getName() == name) {
      _arr[i]->launch(target);
    }
  }
}