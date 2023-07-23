/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:43:13 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/21 11:31:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  std::cout << "[19920104_091532] "
            << "accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
    : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
  _accountIndex = _nbAccounts++;
  _totalAmount += _amount;
  std::cout << "[19920104_091532] "
            << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
}

Account::~Account() {
  --_nbAccounts;
  _totalAmount -= _amount;
  std::cout << "[19920104_091532] "
            << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
}

void Account::makeDeposit(int deposit) {
  int p_amount = _amount;
  _amount += deposit;
  _totalAmount += deposit;
  ++_nbDeposits;
  ++_totalNbDeposits;
  std::cout << "[19920104_091532] "
            << "index:" << _accountIndex << ";p_amount:" << p_amount
            << ";deposit:" << deposit << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  int p_amount = _amount;
  if (_amount < withdrawal) {
    std::cout << "[19920104_091532] "
              << "index:" << _accountIndex << ";p_amount:" << p_amount
              << ";withdrawal:refused" << std::endl;
    return false;
  }
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  ++_nbWithdrawals;
  ++_totalNbWithdrawals;
  std::cout << "[19920104_091532] "
            << "index:" << _accountIndex << ";p_amount:" << p_amount
            << ";withdrawal:" << withdrawal << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const {
  std::cout << "[19920104_091532] "
            << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

// std::cout << "[19920104_091532] "

void Account::_displayTimestamp(void) {
  std::time_t t = std::time(NULL);
  std::tm* tm = std::localtime(&t);
  std::cout << "[" << tm->tm_year + 1900 << std::setw(2) << std::setfill('0')
            << tm->tm_mon + 1 << std::setw(2) << std::setfill('0')
            << tm->tm_mday << "_" << std::setw(2) << std::setfill('0')
            << tm->tm_hour << std::setw(2) << std::setfill('0') << tm->tm_min
            << std::setw(2) << std::setfill('0') << tm->tm_sec << "] ";
}