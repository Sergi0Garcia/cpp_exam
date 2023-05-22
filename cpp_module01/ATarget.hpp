/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 08:57:06 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/22 10:25:49 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>

class ASpell;

class ATarget {
private:
  std::string _type;

public:
  ATarget(std::string const type);
  ATarget(const ATarget &other);
  ATarget &operator=(const ATarget &other);
  virtual ~ATarget();

  std::string const &getType(void) const;
  void getHitBySpell(const ASpell &spell) const;

  virtual ATarget *clone(void) const = 0;
};

#include "ASpell.hpp"

#endif