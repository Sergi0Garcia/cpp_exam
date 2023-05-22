/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 07:51:05 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/22 08:09:39 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>

class Warlock {
public:
  Warlock(std::string const &name, std::string const &title);
  Warlock(const Warlock &other);
  Warlock &operator=(const Warlock &other);
  ~Warlock();

  std::string const &getName(void) const;
  std::string const &getTitle(void) const;
  void setTitle(std::string const &title);
  void introduce() const;

private:
  std::string _name;
  std::string _title;
};

#endif