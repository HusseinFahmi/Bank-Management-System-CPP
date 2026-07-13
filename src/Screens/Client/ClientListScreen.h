#pragma once

#include <vector>

#include "ClientScreenBase.h"
#include "../../Domain/BankClient.h"
#include "../../Repository/ClientRepository.h"

class ClientListScreen : protected ClientScreenBase{
    private:
        static void _print(vector<BankClient> clients){
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(15) << "Account ID";
            cout << "| " << left << setw(30) << "client name";
            cout << "| " << left << setw(30) << "email";
            cout << "| " << left << setw(15) << "Phone";
            cout << "| " << left << setw(15) << "Pin code";
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

    public:
        static void showClientList()
        {       
            if(!checkPermission(SystemUser::readPermission)) return;
            
            vector<BankClient> clients = ClientRepository::getAllClients();

            const string title = "\t Client List Screen";
            const string subTitle = "\t   (" + to_string(clients.size()) + ") Client(s).";

            _drawScreenHeader(title,subTitle);

            _print(clients);
        }
};