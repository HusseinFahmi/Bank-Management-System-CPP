#pragma once

#include <iomanip>

#include "../Screen.h"
#include "../../Domain/BankClient.h"
#include "../../Repository/ClientRepository.h"
#include "../../Lib/InputValidator.h"


class TransactionBaseScreen: protected Screen{
    protected:
        static void _printClientRecordLine(BankClient client){
            cout << "| " << setw(15) << left << client.getAccountID();
            cout << "| " << setw(30) << left << client.getFullName();
            cout << "| " << setw(30) << left << client.getEmail();
            cout << "| " << setw(15) << left << client.getPhone();
            cout << "| " << setw(15) << left << client.getPinCode();
            cout << "| " << setw(15) << left << client.getAccountBalance();
        }

        static void _printClientCard(BankClient client){
            cout << "\n\t\t\t\t\tClient List (" << 1 << ") Client(s).";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(15) << "Account ID";
            cout << "| " << left << setw(30) << "Client name";
            cout << "| " << left << setw(30) << "Email";
            cout << "| " << left << setw(15) << "Phone";
            cout << "| " << left << setw(15) << "Pin code";
            cout << "| " << left << setw(15) << "Balance";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";

            _printClientRecordLine(client);
            cout << "\n_____________________________________________________________________________________________________________________________________\n";
        }

        static BankClient _getClient(){
            string accountID = inputValidator::get_string("Please enter Account Number: ");

            BankClient client = ClientRepository::find(accountID);

            while (client.isEmptyMode())
            {
                accountID = inputValidator::get_string("Not found, enter another account number: ");
                client = ClientRepository::find(accountID);
            }

            return client;
        }

        static double _requestAmount(){
            double amount;

            do
            {
                amount = inputValidator::get_double("Please enter transaction amount: ");

                if (amount <= 0)
                    cout << "Transaction amount must be greater than zero\n";
            } while (amount <= 0);

            return amount;
        }

        static void _handleTransactionResult(BankClient client, BankClient::TransactionResult result, string transactioName)
        {
            switch (result)
            {
            case BankClient::TransactionResult::Ok:
                ClientRepository::save(client);
                cout << transactioName << " successful \n";
            break;

            case BankClient::TransactionResult::InvalidAmount:
                cout << "Invalid amount \n";
                break;

            case BankClient::TransactionResult::InsufficientFunds:
                cout << "Transaction failed: insufficient funds \n";
                break;

            default:
                break;
            }
        }

};