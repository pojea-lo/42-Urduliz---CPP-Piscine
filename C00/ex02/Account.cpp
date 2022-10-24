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
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created" << std::endl;

	return;
}

//Destructor
Account::~Account (void) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed" << std::endl;

	return;
}

//Getters
int	Account::getNbAccounts( void ) {
	
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	
	return Account::_totalNbWithdrawals;
}

//"Constructor" de depósitos
void	Account::makeDeposit( int deposit) {

	int	p_amount;

	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	p_amount = this->_amount;
	this->_amount += deposit;
	Account::_totalAmount += deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit 
		<< ";amount:" << this->_amount
		<< ";nb_depposits:" << this->_nbDeposits
		<< std::endl;

	return;
}

//"Constructor" de withdrawals
bool	Account::makeWithdrawal( int drawal) {

	int	p_amount;

	p_amount = this->_amount;
	if (drawal <= p_amount) {
		
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		this->_amount -= drawal;
		Account::_totalAmount -= drawal;
		
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:" << drawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	}
	else {
	
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:refused" << std::endl;
		return (false);
	}

	return (true);
}

//metodo para mostrar totales
void	Account::displayAccountsInfos( void ) {

	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount 
		<< ";deposits:" << Account::_totalNbDeposits 
		<< ";withdrawals:" << Account::_totalNbWithdrawals 
		<< std::endl;

	return;
}

//metodo para mostrar datos al inicio
void	Account::displayStatus( void ) const {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
		
	return;
}

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
