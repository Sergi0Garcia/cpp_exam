/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 07:51:05 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/23 13:21:30 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>
#include <vector>

class Warlock {
public:
  Warlock(std::string const &name, std::string const &title);
  Warlock(const Warlock &other);
  Warlock &operator=(const Warlock &other);
  virtual ~Warlock();

  std::string const &getName(void) const;
  std::string const &getTitle(void) const;
  void setTitle(std::string const &title);
  void introduce() const;

  void learnSpell(ASpell *spell);
  void forgetSpell(std::string name);
  void launchSpell(std::string name, const ATarget &target);

private:
  std::string _name;
  std::string _title;
  std::vector<ASpell *> spells;
};

#endif