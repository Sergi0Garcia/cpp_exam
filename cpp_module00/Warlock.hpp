#pragma once
#include <iostream>

class Warlock {
private:
  std::string _name;
  std::string _title;
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
};