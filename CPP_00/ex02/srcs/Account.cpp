/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 05:16:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/03/26 15:44:48 by rmedeiro         ###   ########.fr       */
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
    Account::_displayTimestamp();
    this->_amount = initial_deposit;

    this->_accountIndex = this->_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    std::cout << "index:" << this->_accountIndex << ';';
    std::cout << "amount:" << this->_amount << ';';
    std::cout << "created" << std::endl;
    this->_totalAmount += this->_amount;
    _nbAccounts++;
}

// destructor
Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';' ;
    std::cout << "amount:" << this->_amount << ';' ;
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ';' << "total:" << getTotalAmount() << ';' ;
    std::cout <<"deposits:" << getNbDeposits() << ';' << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';' ;
    std::cout << "amount:" << this->_amount << ';';
    std::cout << "deposits:" << this->_nbDeposits << ';';
    std::cout << "withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
}

void Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';' ;
    std::cout << "p_amount:" << this->_amount << ';';
    std::cout << "deposit:" << deposit << ';';
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    this->_amount+= deposit;
    std::cout << "amount:" << this->_amount << ';';
    std::cout << "nb_deposits:" << this->_nbDeposits;
    std::cout << std::endl;
    _totalAmount+=deposit;
}

bool Account::makeWithdrawal( int Withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';' ;
    std::cout << "p_amount:" << this->_amount << ';';
    if(this->_amount > Withdrawal)
    {
        std::cout << "withdrawal:" << Withdrawal << ';';
        this->_nbWithdrawals++;
        this->_totalNbWithdrawals++;
        this->_amount-= Withdrawal;
        std::cout << "amount:" << this->_amount << ';';
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
        std::cout << std::endl;
        _totalAmount-=Withdrawal;
        return(true);
    }
    else
        std::cout << "withdrawal:refused";
    std::cout << std::endl;
    return(false);
}
