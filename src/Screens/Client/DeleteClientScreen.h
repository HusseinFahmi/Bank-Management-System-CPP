#pragma once

#include "ClientScreenBase.h"

#include<iostream>
#include "../../Domain/BankClient.h"
#include "ClientScreenBase.h"
#include "../../Repository/ClientRepository.h"
#include "../../Lib/InputValidator.h"

class DeleteClientScreen: protected ClientScreenBase{
    public:
        static void showDeleteClientScreen(){
            if(!checkPermission(SystemUser::deletePermission)) return;

            _drawScreenHeader("\t Delete Client Screen");

            string accountID = inputValidator::get_string("Enter client acount number: ");

            BankClient client = ClientRepository::find(accountID);

            while (client.isEmptyMode())
            {
                accountID = inputValidator::get_string("Not found, enter another account number: ");
                client = ClientRepository::find(accountID);
            }

            _printClientCard(client);

            char ch = inputValidator::get_char("\nAre you sure you want to delete this client <y,n>: " ,'y','n');

            if(ch == 'n') return;

            if(ClientRepository::deleteClient(client)){
                cout << "\nClient deleted successfully\n";
            }else{
                cout << "\nFailed to delete client, try again\n";
            }     
            
            Util::wait();
        }
};