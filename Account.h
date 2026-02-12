// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
#include "I_Printable.h"

class Account: public I_Printable {
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    static constexpr int def_accno=0;
protected:
    int accno;
    std::string name;
    double balance;
public:
    Account(int accno=def_accno, std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual std::string get_name() const;
    virtual double get_balance() const;
    virtual int get_accno() const { return accno; }
    virtual void print(std::ostream &os) const override;
    virtual ~Account() = default;
};
#endif