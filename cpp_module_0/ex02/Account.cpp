#include "Account.hpp"

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
    _nbDeposits = 0;
    _accountIndex = _nbAccounts;
    _nbWithdrawals = 0;
    _totalAmount = _totalAmount + initial_deposit;
    _nbAccounts++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
    return(_nbAccounts);
}

int Account::getTotalAmount()
{
    return(_totalAmount);
}
int Account::getNbDeposits()
{
    return(_totalNbDeposits);
}
int Account::getNbWithdrawals()
{
    return(_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
    time_t i = time(0);
    tm* t = localtime(&i);
    char buf[80];
    strftime(buf,80,"[%Y%m%d_%H%M%S]",t);
    std::cout << buf;
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals;
    std::cout<<std::endl;
}

int Account::checkAmount() const
{
    return(_amount);
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts;
    std::cout << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals;
    std::cout<<std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int can_withdraw = _amount - withdrawal;
    int old_amount = _amount;
    if(can_withdraw < 0)
    {
        _displayTimestamp();
        std::cout <<" index:"<<_accountIndex;
        std::cout <<";p_amount:" <<_amount;
        std::cout <<";withdrawal:";
        std::cout << "refused" <<std::endl;
        return(false);
    }
    else
    {
        _amount = _amount - withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _displayTimestamp();
        std::cout<<" index:" << _accountIndex;
        std::cout << ";p_amount:" << old_amount;
        std::cout << ";withdrawal:" <<withdrawal;
        std::cout << ";amount:" << _amount;
        std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    }
        
    return(true);
}
void Account::makeDeposit(int deposit)
{
    int old_amount = checkAmount(); 
    _amount = checkAmount() + deposit;
    _totalAmount = _totalAmount + deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << old_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}