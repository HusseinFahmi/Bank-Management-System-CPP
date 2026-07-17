#pragma once
#include <iostream>
#include <string> 

class TransferRecord {
    private:
        std::string _dateTime;
        std::string _sourceAccount;
        std::string _destinationAccount;
        double _amount;
        std::string _userName;

    public:
        TransferRecord(std::string dateTime, std::string sourceAccount, std::string destinationAccount, double amount, std::string userName):
            _dateTime(dateTime),
            _sourceAccount(sourceAccount),
            _destinationAccount(destinationAccount),
            _amount(amount),
            _userName(userName){}
        

        void setDateTime(const std::string& dateTime) {
            _dateTime = dateTime;
        }

        void setSourceAccount(const std::string& sourceAccount) {
            _sourceAccount = sourceAccount;
        }

        void setDestinationAccount(const std::string& destinationAccount) {
            _destinationAccount = destinationAccount;
        }

        void setAmount(double amount) {
            _amount = amount;
        }


        void setUserName(const std::string& userName) {
            _userName = userName;
        }

        std::string getDateTime() const {
            return _dateTime;
        }

        std::string getSourceAccount() const {
            return _sourceAccount;
        }

        std::string getDestinationAccount() const {
            return _destinationAccount;
        }

        double getAmount() const {
            return _amount;
        }
        
        std::string getUserName() const {
            return _userName;
        }
};