#include "Account.hpp"
#include <iostream>
#include <stdio.h>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//Constructor default
Account::Account ( void) {

	return;
}

//Constructor complete
Account::Account ( int initial_deposit ) {

	Account::_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;

	return;
}

//Destructor
Account::~Account (void) {

	return;
}

//metodo para mostrar totales
void	Account::displayAccountsInfos( void ) {

	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << std::endl;

	return;
}

//

//metodo para mostrar el tiempo
void	Account::_displayTimestamp( void ) {

	time_t now = time(0);
	tm *local = localtime(&now);

	std::cout << "[" << local->tm_year + 1900;
	if (local->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << local->tm_mon;
	if (local->tm_mday < 10)
		std::cout << "0";
	std::cout << local->tm_mday;
	std::cout << "_";
	if (local->tm_hour < 10)
		std::cout << "0";
	std::cout << local->tm_hour;
	if (local->tm_min < 10)
		std::cout << "0";
	std::cout << local->tm_min;
	if (local->tm_sec < 10)
		std::cout << "0";
	std::cout << local->tm_sec << "] ";

	return;
}


