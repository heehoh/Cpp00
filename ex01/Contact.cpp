/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:53:12 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/23 23:14:42 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"

#include <iostream>

Contact::Contact()
    : _first_name(""),
      _last_name(""),
      _nickname(""),
      _phone_number(""),
      _darkest_secret("") {}

Contact::Contact(std::string first_name, std::string last_name,
                 std::string nickname, std::string phone_number,
                 std::string darkest_secret)
    : _first_name(first_name),
      _last_name(last_name),
      _nickname(nickname),
      _phone_number(phone_number),
      _darkest_secret(darkest_secret) {}

std::string Contact::getFirstName(void) const { return _first_name; }
std::string Contact::getLastName(void) const { return _last_name; }
std::string Contact::getNickname(void) const { return _nickname; }
std::string Contact::getPhoneNumber(void) const { return _phone_number; }
std::string Contact::getDarkestSecret(void) const { return _darkest_secret; }

void Contact::setFirstName(std::string first_name) { _first_name = first_name; }
void Contact::setLastName(std::string last_name) { _last_name = last_name; }
void Contact::setNickname(std::string nickname) { _nickname = nickname; }
void Contact::setPhoneNumber(std::string phone_number) {
  _phone_number = phone_number;
}
void Contact::setDarkestSecret(std::string darkest_secret) {
  _darkest_secret = darkest_secret;
}