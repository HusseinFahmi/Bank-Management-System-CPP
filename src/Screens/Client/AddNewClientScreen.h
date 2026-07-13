#pragma once

#include<iostream>
#include "../../Domain/BankClient.h"
#include "ClientScreenBase.h"
#include "../../Repository/ClientRepository.h"
#include "../../Lib/InputValidator.h"


class AddNewClientScreen: protected ClientScreenBase{
    public:
        static void showAddClientScreen(){
            if(!checkPermission(SystemUser::writePermission)) return;
            
            _drawScreenHeader("\t Add client Screen");
            string accountID;

            BankClient client;

            do{
                accountID = inputValidator::get_string("Enter account number: ");
                client = ClientRepository::find(accountID);

                if(!client.isEmptyMode()){
                    cout << "Client with Account ID (" << accountID << ") already exists, please enter another account number.\n\n";

                }
            }while(!client.isEmptyMode());

            client = BankClient::create(accountID);


            cout << "============ client info =============\n";

            ClientScreenBase::_readClientInfo(client);

            if(ClientRepository::save(client)){
                cout << "\nClient added successfully\n";
                Util::wait();
            }else{
                cout << "\nFailed TO add client\n";
                Util::wait();
            }
        }
};