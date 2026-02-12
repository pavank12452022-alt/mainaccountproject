#include "Account.h"

Account::Account(int accno, std::string name, double balance) 
    : accno{accno}, name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

void Account::print(std::ostream &os) const  {
    os.precision(2);
    os << std::fixed;
    os << "[Account: " << name << ": " << balance << "]";
}
std::string Account::get_name() const {
    return name;
}
double Account::get_balance() const {
    return balance;
}
