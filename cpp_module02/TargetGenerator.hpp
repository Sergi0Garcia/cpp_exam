#pragma once
#include "ATarget.hpp"
#include <iostream>
#include <vector>

class TargetGenerator {
private:
  std::vector<ATarget *> _arr;
  TargetGenerator(const TargetGenerator &other);
  TargetGenerator &operator=(const TargetGenerator &other);

public:
  TargetGenerator();
  ~TargetGenerator();

  void learnTargetType(ATarget *target);
  void forgetTargetType(const std::string &name);
  ATarget *createTarget(const std::string &name);
};