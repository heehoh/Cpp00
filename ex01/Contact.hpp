/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:30:35 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/23 23:11:38 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
 public:
  Contact();
  Contact(std::string first_name, std::string last_name, std::string nickname,
          std::string phone_number, std::string darkest_secret);
  std::string getFirstName(void) const;
  std::string getLastName(void) const;
  std::string getNickname(void) const;
  std::string getPhoneNumber(void) const;
  std::string getDarkestSecret(void) const;
  void setFirstName(std::string first_name);
  void setLastName(std::string last_name);
  void setNickname(std::string nickname);
  void setPhoneNumber(std::string phone_number);
  void setDarkestSecret(std::string darkest_secret);

 private:
  std::string _first_name;
  std::string _last_name;
  std::string _nickname;
  std::string _phone_number;
  std::string _darkest_secret;
};

#endif