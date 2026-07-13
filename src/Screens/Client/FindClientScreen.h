#pragma once
#include "ClientScreenBase.h"
#include "../../Lib/InputValidator.h"
#include "../../Repository/ClientRepository.h"

class FindClientScreen: protected ClientScreenBase{
    public:
        static void showFindClientScreen(){
            
            if(!checkPermission(SystemUser::findPermission)) return;

            _drawScreenHeader("\t Find Client Screen");

            string accountID = inputValidator::get_string("Enter account ID: ");

            BankClient client = ClientRepository::find(accountID);

            if(client.isEmptyMode()){
                cout << "Client with Id (" << accountID << ") not found\n";
                return;
            }

            _printClientCard(client);
        }
};