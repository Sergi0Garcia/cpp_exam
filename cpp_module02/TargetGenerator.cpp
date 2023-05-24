#include "TargetGenerator.hpp"
#include "ATarget.hpp"
#include <sys/_types/_size_t.h>

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator(void) {
  size_t arrSize = _arr.size();
  if (arrSize == 0)
    return;
  for (size_t i = 0; i < arrSize; i++) {
    _arr.erase(std::remove(_arr.begin(), _arr.end(), _arr[i]));
  }
  _arr.clear();
}

void TargetGenerator::learnTargetType(ATarget *target) {
  if (!target)
    return;
  size_t arrSize = _arr.size();
  if (arrSize == 0) {
    _arr.push_back(target->clone());
    return;
  }
  for (size_t i = 0; i < arrSize; i++) {
    if (_arr[i]->getType() == target->getType())
      return;
  }
  _arr.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const std::string &name) {
  size_t arrSize = _arr.size();
  if (arrSize == 0)
    return;
  for (size_t i = 0; i < arrSize; i++) {
    if (_arr[i]->getType() == name)
      _arr.erase(std::remove(_arr.begin(), _arr.end(), _arr[i]));
  }
}

ATarget *TargetGenerator::createTarget(const std::string &name) {
  size_t arrSize = _arr.size();
  if (arrSize == 0)
    return nullptr;
  for (size_t i = 0; i < arrSize; i++) {
    if (_arr[i]->getType() == name)
      return (_arr[i]->clone());
  }
  return nullptr;
}