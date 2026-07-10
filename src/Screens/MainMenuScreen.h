#pragma once

#include<iostream>
#include<vector>
#include<string>

#include "Screen.h"

#include "../Lib/InputValidator.h"
#include "../Lib/Util.h"
#include "Client/FindClientScreen.h"
#include "Client/ClientListScreen.h"
#include "Client/AddNewClientScreen.h"
#include "Client/UpdateClientScreen.h"
#include "Client/DeleteClientScreen.h"

#include "Transactions/TransactionsMenuScreen.h"

#include "User/UsersMenuScreen.h"



using namespace std;

class MainMenuScreen : protected Screen{
    private:
        inline static const vector<string> _menuOptions{
            "Show Client List",
            "Add New Client",
            "Delete Client",
            "Update Client",
            "Find Client",
            "Transactions",
            "Manage Users",
            "Logout",
        };

        enum _enMainMenuOptions{
            eShowClientList = 1,
            eAddNewClient = 2,
            eDeleteClient = 3,
            eUpdateClient = 4,
            eFindClient = 5,
            eTransactions = 6,
            eManageUsers = 7,
            eLogout = 8,
        };

        static void _showClientListScreen(){
            ClientListScreen::showClientList();
        }

        static void _addNewClientScreen(){
            AddNewClientScreen::showAddClientScreen();
        }
        
        static void _deleteClientScreen(){
            DeleteClientScreen::showDeleteClientScreen();
        }
        
        static void _updateClientScreen(){
            UpdateClientScreen::showUpdateClientScreen();
        }

        static void _findClientScreen(){
            FindClientScreen::showFindClientScreen();
        }

        static void _transactionsScreen(){
            TransactionsMenuScreen::showTransactionScreen();
        }

        static void _manageUsersScreen(){
            UsersMenuScreen::showUserScreen();
        }

        static bool _performMainMenuOption(_enMainMenuOptions option){

            Util::clearInputBuffer();
            Util::clearScreen();

            switch(option){
                case _enMainMenuOptions::eShowClientList:
                    _showClientListScreen();                
                return true;

                case _enMainMenuOptions::eAddNewClient:
                    _addNewClientScreen();
                return true;
                
                case _enMainMenuOptions::eDeleteClient:
                    _deleteClientScreen();
                return true;

                case _enMainMenuOptions::eUpdateClient:
                    _updateClientScreen();
                return true;
                
                case _enMainMenuOptions::eFindClient:
                    _findClientScreen();
                return true;

                case _enMainMenuOptions::eTransactions:
                    _transactionsScreen();
                return true;
            
                case _enMainMenuOptions::eManageUsers:
                    _manageUsersScreen();
                return true;
            
                case _enMainMenuOptions::eLogout:
                return false;


                return false;
            }
        }

    public:
            static void showMainMenu(){

                do{
                    Util::clearScreen();
                    _drawScreenHeader("Main Screen");

                    cout << "\t\t\t\t\t\t  ==================================================\n";
                    cout << "\t\t\t\t\t\t\t\t     Main Menu\t\t\t\t\n";
                    cout << "\t\t\t\t\t\t  ==================================================\n";

                    int i;
                    for(i = 0 ; i < _menuOptions.size() ; i++){
                        cout << "\t\t\t\t\t\t\t\t[" << i + 1 << "] " << _menuOptions[i] << endl;
                    }

                    int option = inputValidator::get_int("Choose what you want to do [1-" + to_string(i)  + "]: ", 1, i);

                    if (!_performMainMenuOption((_enMainMenuOptions)option))
                        return;
                    Util::wait();
                }while(true);
            }
};