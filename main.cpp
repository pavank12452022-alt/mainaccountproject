#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

Checking_Account* find_checking_account(
    const std::vector<std::unique_ptr<Account>>& accounts, 
    const int& target_name)
{
    for (const auto& acc : accounts) {
        auto checking = dynamic_cast<Checking_Account*>(acc.get());// here get() is used to return raw pointer which is neccesary for dynamic cast
        if (!checking)
            continue;
        if (checking->get_accno() == target_name) {
            return checking;   
        }
    }
    return nullptr; 
}
Savings_Account* find_savings_account(
    const std::vector<std::unique_ptr<Account>>& accounts,
    const int& target_name)
{
    for (const auto& acc : accounts) {
        auto checking = dynamic_cast<Savings_Account*>(acc.get());
            continue;
        if (checking->get_accno() == target_name) {
            return checking;   
        }
    }
    return nullptr; 
}
// it is of no use , as Account is abstract class
// Account* find_account(
//     const std::vector<std::unique_ptr<Account>>& accounts,
//     const int& target_name)
// {
//     for (const auto& acc : accounts) {
//         auto checking = dynamic_cast<Account*>(acc.get());
//         if (!checking)
//             continue;
//         if (checking->get_accno() == target_name) {
//             return checking;   
//         }
//     }
//     return nullptr; 
// }
Trust_Account* find_trust_account(
    const std::vector<std::unique_ptr<Account>>& accounts,
    const int& target_name)
{
    for (const auto& acc : accounts) {
        auto checking = dynamic_cast<Trust_Account*>(acc.get());
        if (!checking)
            continue;
        if (checking->get_accno() == target_name) {
            return checking;   
        }
    }
    return nullptr; 
}

// class Test {
// private:
//     int data;
// public:
//     Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
//     Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
//     int get_data() const {return data; }
//     ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
// };

using namespace std;
int main() 
{
    vector<unique_ptr<Account>> accounts;
    bool flag = true;

    while (flag)
    {   
        int n;
        cout << "Enter a number (-1 to exit): " << endl
             << "1. for checking account operations" << endl
             << "2. for savings account operations" << endl
             << "3. for trust account operations " << endl;
        cin >> n;

        switch (n)
        {
            case 1:
            {
                bool flag2 = true;
                while (flag2)
                {
                    int choice;
                    cout << "1. Create Checking Account" << endl
                         << "2. deposit" << endl
                         << "3. withdraw" << endl
                         << "4. display account details" << endl;
                    cin >> choice;

                    switch (choice)
                    {
                        case 1:
                        {
                            string name;
                            double balance;
                            int accno;
                            cout << "Enter account number: ";
                            cin >> accno;
                            cout << "Enter account name: ";
                            cin >> name;
                            cout << "Enter initial balance: ";
                            cin >> balance;
                            accounts.push_back(make_unique<Checking_Account>(accno, name, balance));
                            break;
                        }
                        case 2:
                        {
                            double amount;
                            cout << "Enter deposit amount: ";
                            cin >> amount;  
                            cout << "enter them accno to which you want to deposit" << endl;
                            int accno;
                            cin >> accno;
                            if (find_checking_account(accounts, accno))
                            {
                                find_checking_account(accounts, accno)->deposit(amount);
                            }
                            else
                            {
                                cout << "Account not found" << endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            double amount;
                            cout << "Enter withdrawal amount: ";
                            cin >> amount;
                            int accno;
                            cout << "enter them accno to which you want to withdraw" << endl;
                            cin >> accno;
                            if (find_checking_account(accounts, accno))
                            {
                                find_checking_account(accounts, accno)->withdraw(amount);
                            }
                            else
                            {
                                cout << "Account not found" << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            int accno;
                            cout << "enter them accno which you want to display" << endl;
                            cin >> accno;
                            if (find_checking_account(accounts, accno))
                            {
                                cout << *(find_checking_account(accounts, accno)) << endl;
                            }
                            else
                            {
                                cout << "Account not found" << endl;
                            }
                            break;
                        }
                        case 5:
                        {
                            flag2 = false;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    }
                }
                break;
            } 

            case 2:
            {
                bool flag3 = true;
                while (flag3)
                {
                    int choice;
                    cout << "1. Create Savings Account" << endl
                         << "2. deposit" << endl
                         << "3. withdraw" << endl
                         << "4. display account details" << endl;
                    cin >> choice;

                    switch (choice)
                    {
                        case 1:
                        {
                            string name;
                            double balance;
                            int accno;
                            double int_rate;
                            cout << "Enter account number: ";
                            cin >> accno;
                            cout << "Enter account name: ";
                            cin >> name;
                            cout << "Enter initial balance: ";
                            cin >> balance;
                            cout << "Enter interest rate: ";
                            cin >> int_rate;
                            accounts.push_back(make_unique<Savings_Account>(accno, name, balance, int_rate));
                            break;
                        }
                        case 2:
                        {
                            double amount;
                            cout << "Enter deposit amount: ";
                            cin >> amount;  
                            cout << "enter them accno to which you want to deposit" << endl;
                            int accno;
                            cin >> accno;
                            if (find_savings_account(accounts, accno))
                            {
                                find_savings_account(accounts, accno)->deposit(amount);
                            }
                            else
                            {
                                cout << "Account not found" << endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            double amount;
                            cout << "Enter withdrawal amount: ";
                            cin >> amount;
                            int accno;
                            cout << "enter them accno to which you want to withdraw" << endl;
                            cin >> accno;
                            if (find_savings_account(accounts, accno))
                            {
                                find_savings_account(accounts, accno)->withdraw(amount);
                            }
                            else
                            {
                                cout << "Account not found" << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            int accno;
                            cout << "enter them accno which you want to display" << endl;
                            cin >> accno;
                            if (find_savings_account(accounts, accno))
                            {
                                cout << *(find_savings_account(accounts, accno)) << endl;
                            }
                            else
                            {
                                cout << "Account not found" << endl;
                            }
                            break;
                        }
                        case 5:
                        {
                            flag3 = false;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                    } 
                } 
                break;
            } 

            case 3:
            {
                bool flag4 = true;
                while (flag4)
                {
                    int choice;
                    cout << "1. Create Trust Account" << endl
                         << "2. deposit" << endl
                         << "3. withdraw" << endl
                         << "4. display account details" << endl;
                    cin >> choice;

                    switch (choice)
                    {
                        case 1:
                        {
                            string name;
                            double balance;
                            int accno;
                            double int_rate;
                            cout << "Enter account number: ";
                            cin >> accno;
                            cout << "Enter account name: ";
                            cin >> name;
                            cout << "Enter initial balance: ";
                            cin >> balance;
                            cout << "Enter interest rate: ";
                            cin >> int_rate;
                            accounts.push_back(make_unique<Trust_Account>(accno, name, balance, int_rate));
                            break;
                        }
                        case 2:
                        {
                            double amount;
                            cout << "Enter deposit amount: ";
                            cin >> amount;  
                            cout << "enter them accno to which you want to deposit" << endl;
                            int accno;
                            cin >> accno;
                            if (find_trust_account(accounts, accno))
                            {
                                find_trust_account(accounts, accno)->deposit(amount);
                            }
                            else
                            {
                                cout << "Account not found" << endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            double amount;
                            cout << "Enter withdrawal amount: ";
                            cin >> amount;
                            int accno;
                            cout << "enter them accno to which you want to withdraw" << endl;
                            cin >> accno;
                            if (find_trust_account(accounts, accno))
                            {
                                find_trust_account(accounts, accno)->withdraw(amount);
                            }
                            else
                            {
                                cout << "Account not found" << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            int accno;
                            cout << "enter them accno which you want to display" << endl;
                            cin >> accno;
                            if (find_trust_account(accounts, accno))
                            {
                                cout << *(find_trust_account(accounts, accno)) << endl;
                            }
                            else
                            {
                                cout << "Account not found" << endl;
                            }
                            break;
                        }
                        case 5:
                        {
                            flag4 = false;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid choice" << endl;
                            break;
                        }
                } 
                } 
                break;
            } 

            case -1:
            {
                flag = false;
                break;
            }

            default:
            {
                cout << "Invalid input" << endl;
                break;
            }
     } 
    }
 return 0;
}

// Test *t1 = new Test {1000};
   //  delete t1;
//   std::unique_ptr<Test> t1 {new Test{100}};
//   std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
//   
//   std::unique_ptr<Test> t3;
//   t3 = std::move(t1);
//   if (!t1) 
//       std::cout << "t1 is nullptr" << std::endl;
       
    //    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    //    std::cout << *a1 << std::endl;
    //    a1->deposit(5000);
    //    std::cout << *a1 << std::endl;

    //    std::vector<std::unique_ptr<Account>> accounts;

    //    accounts.push_back( make_unique<Checking_Account>("James", 1000));
    //    accounts.push_back( make_unique<Savings_Account>("Billy", 4000, 5.2));
    //    accounts.push_back( make_unique<Trust_Account>("Bobby", 5000, 4.5));

    //     for (const auto &acc: accounts)
    //         std::cout << *acc << std::endl;