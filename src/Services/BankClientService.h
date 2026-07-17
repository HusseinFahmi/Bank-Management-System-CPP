#pragma once

#include "../Domain/BankClient.h"
#include "../Domain/TransferRecord.h"

#include "../Lib/Date.h"


#include "../Repository/TransferRepository.h"

class BankClientService{
    public:
        static BankClient::TransactionResult transfer(double amount ,BankClient& sourceClient , BankClient& destinationClient , const string& userName){
            if(amount <= 0) return BankClient::TransactionResult::InvalidAmount;

            if(sourceClient.getAccountBalance() < amount) return BankClient::TransactionResult::InsufficientFunds;

            sourceClient.withdraw(amount);
            destinationClient.deposit(amount);

            ClientRepository::save(sourceClient);
            ClientRepository::save(destinationClient);

            TransferRecord record(Date::getSystemDateAndTime(), sourceClient.getAccountID() , destinationClient.getAccountID() , amount , userName);
            TransferRepository::addLog(record);

            return BankClient::TransactionResult::Ok;
        }
        
};