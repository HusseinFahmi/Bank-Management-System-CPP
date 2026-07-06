#pragma once

#include "Person.h"

class BankClient : public Person {
    public:
        enum Mode { EmptyMode = 1 , UpdateMode = 2 , AddNewMode = 2};
        enum TransactionResult { Ok = 1 , InvalidAmount = 2, InsufficientFunds = 3 };
    
    private:
        Mode _mode;
        string _accountID;
        string _pinCode;
        double _accountBalance;
        bool _markForDelete = false;

        TransactionResult _adjustBalance(const double delta){
            if(delta == 0) return TransactionResult::InvalidAmount;

            if(delta < 0 && -delta > _accountBalance) return TransactionResult::InsufficientFunds;

            _accountBalance += delta;
            return TransactionResult::Ok;
        }
    
    public:
        BankClient():
        Person(),
        _mode(Mode::EmptyMode),
        _accountID(""),
        _pinCode(""),
        _accountBalance(0.0){}

        BankClient(string firstName , string lastName , string email , string phone , Mode mode , string accountID , string pinCode , double balance):
        Person(firstName,lastName,email,phone),
        _mode(mode),
        _accountID(accountID),
        _pinCode(pinCode),
        _accountBalance(balance){}

        // Getters & Setters
        string getAccountID(){ 
            return _accountID; 
        }

        string getPinCode(){ 
            return _pinCode; 
        }

        double getAccountBalance(){ 
            return _accountBalance; 
        }

        Mode getMode(){ 
            return _mode; 
        }

        bool isMarkedForDelete(){ 
            return _markForDelete; 
        }

        void setPinCode(string pinCode) { 
            _pinCode = pinCode; 
        }

        void setAccountBalance(double balance) { 
            _accountBalance = balance; 
        }

        void setMode(Mode mode) { 
            _mode = mode; 
        }

        void setMarkForDelete(bool mark) { 
            _markForDelete = mark; 
        }

        // --------------------------------

        bool isEmptyMode(){
            return _mode == Mode::EmptyMode;
        }

        static BankClient getEmptyMode(){
            return BankClient();
        }

        static BankClient create(const string accountID){
            return BankClient("", "", "", "", Mode::AddNewMode, accountID, "", 0.0);
        }

        TransactionResult deposit(const double amount) {
            if (amount <= 0) return TransactionResult::InvalidAmount;
            return _adjustBalance(amount);
        }

        TransactionResult withdraw(const double amount) {
            if (amount <= 0) return TransactionResult::InvalidAmount;
            return _adjustBalance(-amount);
        }
};