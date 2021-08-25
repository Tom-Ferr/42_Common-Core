/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:22:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/15 20:23:30 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

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

void	Account::_displayTimestamp( void )
{
	std::time_t time_now = std::time(nullptr);
	std::cout << std::put_time(std::localtime(&time_now), "[%Y%m%d_%OH%OM%OS] ");
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();

	std::cout << "accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_displayTimestamp();

	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";ceated" << std::endl;

	Account::_nbAccounts += 1;
	Account::_totalAmount += this->_amount;

}

Account::~Account( void )
{
	this->_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount;
	this->_nbDeposits += 1;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > Account::checkAmount())
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	std::cout << ";amount:" << this->_amount;
	this->_nbWithdrawals += 1;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;

	return (true);
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
