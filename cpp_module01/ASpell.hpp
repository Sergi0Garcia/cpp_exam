/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 08:20:36 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/22 10:25:45 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>

class ATarget;

class ASpell {
public:
  ASpell(std::string const name, std::string const effects);
  ASpell(const ASpell &other);
  ASpell &operator=(const ASpell &other);
  virtual ~ASpell();

  std::string const &getName(void) const;
  std::string const &getEffects(void) const;

  virtual ASpell *clone(void) const = 0;
  void launch(ATarget const &target) const;

private:
  std::string _name;
  std::string _effects;
};

#include "ATarget.hpp"

#endif