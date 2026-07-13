#pragma once


#include "ClientScreenBase.h"
#include "../../Repository/ClientRepository.h"
#include "../../Lib/Util.h"
#include "../../Lib/InputValidator.h"

class UpdateClientScreen: protected ClientScreenBase{
    public:
        static void showUpdateClientScreen(){
            if(!checkPermission(SystemUser::updatePermission)) return;

            _drawScreenHeader("\t Update client Screen");

            string accountID;
            BankClient client;

            do{
                accountID = inputValidator::get_string("Enter client account number: ");
                client = ClientRepository::find(accountID);

                if(client.isEmptyMode()){
                    cout << "There is no Client with Account ID (" << accountID << ") ,please enter another account number.\n\n";
                }
            }while(client.isEmptyMode());

            _printClientCard(client);

            char choice = inputValidator::get_char("\nAre you sure you want to update this client <y,n>: " ,'y','n');

            Util::clearInputBuffer();

            if(choice == 'n') return;



            cout << "--------- update client info ---------\n";

            _readClientInfo(client);

            if(ClientRepository::save(client)){
                cout << "\nClient updated successfully\n";
            }else{
                cout << "\nFailed to update client\n";
            }

            Util::wait();
        }
};