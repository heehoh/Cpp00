/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:10:31 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/31 19:51:11 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : _contact_idx(0) {}

std::string getInfo(std::string info);
int warningMessage(void);

void PhoneBook::add(void) {
  std::string input;
  if (_contact_idx >= _CONTACT_MAX && warningMessage()) return;
  std::cout << "추가하실 정보를 입력해주세요" << std::endl;
  _contact[_contact_idx % _CONTACT_MAX].setFirstName(getInfo("first name"));
  _contact[_contact_idx % _CONTACT_MAX].setLastName(getInfo("last name"));
  _contact[_contact_idx % _CONTACT_MAX].setNickname(getInfo("nickname"));
  _contact[_contact_idx % _CONTACT_MAX].setPhoneNumber(getInfo("phone number"));
  _contact[_contact_idx % _CONTACT_MAX].setDarkestSecret(
      getInfo("darkest secret"));
  ++_contact_idx;
}

void PhoneBook::search(void) {
  if (_contact_idx == 0)
    std::cout << "입력된 정보가 없습니다!" << std::endl;
  else
    showPhoneBook(_contact_idx < 8 ? _contact_idx : 8);
}

int warningMessage(void) {
  std::string input;
  std::cout << "Warning: 추가하면 이전 입력된 정보가 삭제됩니다.\n"
            << "추가하시려면 yes를 취소하시려면 no를 입력하세요" << std::endl;
  while (true) {
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::clearerr(stdin);
      std::cin.clear();
    };
    if (input == "yes")
      return 0;
    else if (input == "no")
      return 1;
    std::cout << "잘못된 입력입니다. 다시 입력해주세요" << std::endl;
  }
}

std::string getInfo(std::string info) {
  std::string input;
  while (true) {
    std::cout << info << ": ";
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      clearerr(stdin);
      std::cin.clear();
      std::cout << "\n";
    } else if (input != "")
      break;
    std::cout << "잘못된 입력입니다. 다시 입력해주세요" << std::endl;
  }
  return input;
}

void PhoneBook::showInfo(std::string tmp) {
  if (tmp.length() > 10) {
    tmp[9] = '.';
    std::cout << tmp.substr(0, 10);
  } else {
    std::cout << std::setw(10) << std::right << tmp;
  }
}

void PhoneBook::showPhoneBook(int idx) {
  std::cout << "---------------------------------------------\n"
            << "|           ☎ Phone Book Info ☎             |\n"
            << "---------------------------------------------\n"
            << "|     index|first name| last name|  nickname|\n";
  for (int i = 0; i < idx; i++) {
    std::cout << "|" << std::setw(10) << std::right << i + 1;
    std::cout << "|";
    showInfo(_contact[i].getFirstName());
    std::cout << "|";
    showInfo(_contact[i].getLastName());
    std::cout << "|";
    showInfo(_contact[i].getNickname());
    std::cout << "|\n";
  }
  std::cout << "---------------------------------------------" << std::endl;
  showDetailInfo();
}

bool isIndex(std::string input) {
  if (input.length() == 1 && std::isdigit(input[0]) && input[0] > '0' &&
      input[0] <= '8')
    return true;
  return false;
}

void PhoneBook::showDetailInfo(void) {
  std::string input;
  int idx;
  std::cout << "자세한 정보를 표시할 index를 입력하세요(1 ~ 8).\n"
            << "나가시려면 q를 입력하세요." << std::endl;
  while (true) {
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::clearerr(stdin);
      std::cin.clear();
    } else if (input == "q")
      return;
    else if (isIndex(input)) {
      idx = input[0] - '0' - 1;
      if (idx >= _contact_idx) {
        std::cout << idx + 1
                  << "번 index는 아직 저장되지 않았습니다. 다시 입력해주세요!"
                  << std::endl;
        continue;
      }
      std::cout << "first name: " << _contact[idx].getFirstName() << "\n"
                << "last name: " << _contact[idx].getLastName() << "\n"
                << "nickname: " << _contact[idx].getNickname() << "\n"
                << "phone number: " << _contact[idx].getPhoneNumber() << "\n"
                << "darkest secret: " << _contact[idx].getDarkestSecret()
                << std::endl;
      return;
    }
    std::cout << "잘못된 입력입니다. 다시 입력해주세요!" << std::endl;
  };
}
