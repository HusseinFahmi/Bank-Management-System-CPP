#pragma once

#include "TransactionBaseScreen.h"

#include "../../Lib/InputValidator.h"
#include "../../Domain/BankClient.h"
#include "../../Repository/ClientRepository.h"



class DepositScreen: protected TransactionBaseScreen{

    private:
        static double _requestAmount(){
            double amount;

            do
            {
                amount = inputValidator::get_double("Please enter deposit amount: ");

                if (amount <= 0)
                    cout << "Deposit amount must be greater than zero\n";
            } while (amount <= 0);

            return amount;
        }

        

    public:
        static void showDepositScreen(){
            _drawScreenHeader("\t Deposit Screen");


            BankClient client = _getClient();

            _printClientCard(client);

            char choice = inputValidator::get_char("\nAre you sure you want to deposit from this client <y,n>: " ,'y','n');
            if(choice == 'n') return;

            double depositAmount = _requestAmount();

            char performTransaction = inputValidator::get_char("\nAre you sure tou want to perform this transaction <y,n>: ",'y','n');

            if(performTransaction == 'n') return;

            BankClient::TransactionResult result = client.deposit(depositAmount);
            _handleTransactionResult(client,result,"Deposit");

            _printClientCard(client);

            Util::wait();
        }
};