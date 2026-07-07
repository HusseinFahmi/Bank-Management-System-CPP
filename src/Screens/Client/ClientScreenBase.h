#pragma once

#include <iostream>
#include <iomanip>

#include "../Screen.h"
#include "../../Domain/BankClient.h"

class ClientScreenBase: protected Screen{
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
        

};