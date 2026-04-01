/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 05:16:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/04/01 10:53:10 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// prints timestamp in the format: [YYYYMMDD_HHMMSS] followed by a space.
// [19920104_091532] index:0;amount:42;created
void Account::_displayTimestamp( void )
{
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);
    char output[50];

    std::cout << '[';
    strftime(output, 50, "%Y%m%d", &datetime);
    std::cout << output << "_";
    strftime(output, 50, "%H%M%S", &datetime);
    std::cout << output;
    std::cout << "] ";
}

// constructor
// assigns an index to the account (current number of accounts)
// initializes amount and per-account counters
Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

int Account::checkAmount( void ) const
{
	return (this->_amount);
}

// displays the current state of all accounts: total nb of accounts, total amount, total nb of deposits and total nb of withdrawals.
void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ';';
	std::cout << "total:" << Account::getTotalAmount() << ';';
	std::cout << "deposits:" << Account::getNbDeposits() << ';';
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

// displays the current state of the account: index, amount, nb of deposits and nb of withdrawals.
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "deposits:" << this->_nbDeposits << ';';
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// displays the index, previous amount, deposit amount, new amount and nb of deposits. Updates the total amount and nb of deposits.
void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	std::cout << "deposit:" << deposit << ';';
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

// displays the index, previous amount and withdrawal amount. 
//If the withdrawal is successful, also displays the new amount and nb of withdrawals. 
// Updates the total amount and nb of withdrawals if the withdrawal is successful.
bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}
