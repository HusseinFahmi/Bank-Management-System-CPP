#pragma once

#include <iostream>
#include <vector>

#include "../Screen.h"

#include "../../Lib/Util.h"
#include "../../Lib/InputValidator.h"

#include "UsersListScreen.h"
#include "AddNewUserScreen.h"
#include "DeleteUserScreen.h"
#include "UpdateUserScreen.h"
#include "FindUserScreen.h"

class UsersMenuScreen: protected Screen{
    private:
        inline static const vector<string> _usersMenuOptions{
            "List all users",
            "Add new user",
            "Delete user",
            "Update user",
            "Find user",
            "Main Menu",
        };

        enum _enUsersMenuOptions{
            eListUsers = 1,
            eAddNewUser = 2,
            eDeleteUser = 3,
            eUpdateUser = 4,
            eFindUser = 5,
            eMainMenue = 6,
        };

        static void _showUsersListScreen(){
            UserListScreen::showUserListScreen();
        }

        static void _showAddNewUserScreen(){
            AddNewUserScreen::showAddNewUserScreen();
        }

        static void _showDeleteUserScreen(){
            DeleteUserScreen::showDeleteUserScreen();
        }

        static void _showUpdateUserScreen(){
            UpdateUserScreen::showUpdateUserScreen();
        }

        static void _showFindUserScreen(){
            FindUserScreen::showFindUserScreen();
        }

        static bool _performUsersMenuOption(_enUsersMenuOptions option){
            Util::clearInputBuffer();
            Util::clearScreen();
            
            switch (option){
                case _enUsersMenuOptions::eListUsers:
                    _showUsersListScreen();
                return true;

                case _enUsersMenuOptions::eAddNewUser:
                    _showAddNewUserScreen();
                return true;

                case _enUsersMenuOptions::eDeleteUser:
                    _showDeleteUserScreen();
                return true;

                case _enUsersMenuOptions::eUpdateUser:
                    _showUpdateUserScreen();
                return true;

                case _enUsersMenuOptions::eFindUser:
                    _showFindUserScreen();
                return true;

                case _enUsersMenuOptions::eMainMenue:
                return false;
            }
            return false;
        }
    
    public:
        static void showUserScreen(){

            do{
                Util::clearScreen();

                _drawScreenHeader("\t Transaction Screen");

                cout << "\t\t\t\t\t\t  ==================================================\n";
                cout << "\t\t\t\t\t\t\t\t     Users Menu Screen\t\t\t\t\n";
                cout << "\t\t\t\t\t\t  ==================================================\n";

                int i;

                for(i =  0 ; i <_usersMenuOptions.size() ; i++){
                    cout << "\t\t\t\t\t\t\t\t[" << i + 1 << "] " << _usersMenuOptions[i] << endl;
                }


                int option = inputValidator::get_int("Choose what you want to do [1-" + to_string(i)  + "]: ", 1, i);

                if (!_performUsersMenuOption((_enUsersMenuOptions)option))
                    return;    
                Util::wait();            
            }while(true);
        }

};