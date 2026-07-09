#pragma once

#include "TransactionBaseScreen.h"

#include "../../Repository/ClientRepository.h"
#include "../../Lib/Util.h"

class TotalBalancesScreen:protected TransactionBaseScreen{
    private:
        static void _printClientRecordLine(BankClient client){
            cout << "| " << setw(15) << left << client.getAccountID();
            cout << "| " << setw(30) << left << client.getFullName();
            cout << "| " << setw(15) << left << client.getAccountBalance();
        }

        static void _print(vector<BankClient>& clients){
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(15) << "Account ID";
            cout << "| " << left << setw(30) << "client name";
            cout << "| " << left << setw(15) << "Balance";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";

            if(clients.size() <= 0)
                cout << "\t\t\tNo clients available in the system! \t\n";
            else
                for (BankClient &client : clients)
                {
                    _printClientRecordLine(client);
                    cout << endl;
                }

            cout << "_____________________________________________________________________________________________________________________________________\n\n";
        }

        static double _totalBalances(vector<BankClient> clients){
            double totalBalances = 0;
            for(BankClient &c: clients){
                totalBalances += c.getAccountBalance();
            }

            return totalBalances;
        }

    public:
        void static showTotalBalancesScreen(){
            vector<BankClient> clients = ClientRepository::getAllClients();

            _drawScreenHeader("\t Total Balances Screen\n\t\t\t\t\t\t\t" + to_string(ClientRepository::getTotalBalances()) , Util::numberToText(ClientRepository::getTotalBalances()));

            _print(clients);
        }
};