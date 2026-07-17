#pragma once

#include "../Screen.h"

#include "../../Domain/BankClient.h"

#include "../../Repository/ClientRepository.h"
#include "../../Domain/BankClient.h"

#include "../../Lib/InputValidator.h"

#include "../../Global.h"

#include "../../Services/BankClientService.h"




class TransferScreen:protected Screen{

    private:
        static BankClient getClient(string action){
            string accountId = inputValidator::get_string("\nEnter account number to Transfer " + action + " : ");
            BankClient client = ClientRepository::find(accountId);

            while(client.isEmptyMode()){
                accountId = inputValidator::get_string("Not found, enter another account number to Transfer  " + action + " : ");
                client = ClientRepository::find(accountId);
            }

            return client;
        } 

        static void _printClientRecordLine(BankClient client){
            cout << "| " << setw(15) << left << client.getAccountID();
            cout << "| " << setw(30) << left << client.getFullName();
            cout << "| " << setw(15) << left << client.getAccountBalance();
        }

        static void _printClientCard(BankClient client){
            cout << "\n\t\t\t\t\tClient List (" << 1 << ") Client(s).";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(15) << "Account ID";
            cout << "| " << left << setw(30) << "Client name";
            cout << "| " << left << setw(15) << "Balance";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";

            _printClientRecordLine(client);
            cout << "\n_____________________________________________________________________________________________________________________________________\n";
        }

        static double _requestAmount(){
            double amount;

            do
            {
                amount = inputValidator::get_double("\n\nPlease enter transaction amount: ");

                if (amount <= 0)
                    cout << "Transaction amount must be greater than zero\n";
            } while (amount <= 0);

            return amount;
        }


    public:
        static void showTransferScreen(){
            _drawScreenHeader("\t Transfer Screen");

            BankClient sourceClient = getClient("from");
            _printClientCard(sourceClient);

            BankClient destinationClient = getClient("to");
            _printClientCard(destinationClient);

            double amount = _requestAmount();

            char performTransaction = inputValidator::get_char("\nAre you sure tou want to perform this transaction <y,n>: ",'y','n');
            if(performTransaction == 'n') return;

            BankClient::TransactionResult result = BankClientService::transfer(amount, sourceClient, destinationClient, currentUser.getUserName());

            switch (result)
            {
                case BankClient::TransactionResult::Ok:
                    std::cout << "Transfer Success\n"; 
                break;

                case BankClient::TransactionResult::InsufficientFunds:
                    std::cout << "Transaction failed: insufficient funds\n";
                break;
                
                default:
                    std::cout << "Transaction failed: Invalid amount\n";
                break;
            }

            Util::wait();
        }
};