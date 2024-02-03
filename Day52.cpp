#include <iostream>
using namespace std;


// virtual functions


class Account{
    protected:
        float balance;
    public:
        Account(float balance){
            this->balance=balance;
        }
        virtual void Withdraw(float amount){}
        virtual void Deposit(float amount){}
        virtual void printBalance(){}
};


class Savings : public Account{
    float interest_rate =0.8;
    public:
        Savings(int balance): Account(balance){}
        void Withdraw(float amount){
            balance-=amount+(amount*interest_rate);
        }
        void Deposit(float amount){
            balance+=amount+(amount*interest_rate);
        }
        void printBalance(){
            cout<<"Balance in your savings account is: "<<balance<<endl;
        }
};

class Current : public Account{
    public:
        Current(float balance): Account(balance){}
        void Withdraw(float amount){
            balance-=amount;
        }
        void Deposit(float amount){
            balance+=amount;
        }
        void printBalance(){
            cout<<"Balance in your current account is: "<<balance<<endl;
        }
};




//pure virtual functions



class Account{
    protected:
        float balance;
    public:
        Account(float balance){
            this->balance=balance;
        }
        virtual void Withdraw(float amount)=0;
        virtual void Deposit(float amount)=0;
        virtual void printBalance()=0;
};


class Savings : public Account{
    float interest_rate =0.8;
    public:
        Savings(int balance): Account(balance){}
        void Withdraw(float amount){
            balance-=amount+(amount*interest_rate);
        }
        void Deposit(float amount){
            balance+=amount+(amount*interest_rate);
        }
        void printBalance(){
            cout<<"Balance in your savings account is: "<<balance<<endl;
        }
};

class Current : public Account{
    public:
        Current(float balance): Account(balance){}
        void Withdraw(float amount){
            balance-=amount;
        }
        void Deposit(float amount){
            balance+=amount;
        }
        void printBalance(){
            cout<<"Balance in your current account is: "<<balance<<endl;
        }
};

int main()
{
    // Savings s1(50000);
    // Account * acc = &s1;
    // acc->Deposit(1000);
    // acc->printBalance();
    // acc->Withdraw(3000);
    // acc->printBalance();
    // Current c1(50000);
    // acc = &c1;
    // acc->Deposit(1000);
    // acc->printBalance();
    // acc->Withdraw(3000);
    // acc->printBalance();  



    Account * acc[2];
    acc[0] = new Savings(50000);   // pointing acc to savings object
    acc[0]->Deposit(1000);
    acc[0]->printBalance();
    acc[0]->Withdraw(3000);
    acc[0]->printBalance();
    cout << endl;
    // creating current account object by calling account pointer
    acc[1] = new Current(50000);     // pointing acc to current object
    acc[1]->Deposit(1000);
    acc[1]->printBalance();
    acc[1]->Withdraw(3000);
    acc[1]->printBalance();  

    return 0;
}
