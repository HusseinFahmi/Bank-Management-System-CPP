#pragma once

#include <iostream>
#include <iomanip>

#include "UserBaseScreen.h"
#include "../../Domain/SystemUser.h"
#include "../../Repository/UserRepository.h"

class UserListScreen: protected UserBaseScreen{
    private:
        static void _print(vector<SystemUser> users){
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(30) << "Full name";
            cout << "| " << left << setw(20) << "Email";
            cout << "| " << left << setw(15) << "phone";
            cout << "| " << left << setw(30) << "Username";
            cout << "| " << left << setw(20) << "Password";
            cout << "| " << left << setw(10) << "Permissions";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";

            if(users.size() <= 0)
                cout << "\t\t\tNo users available in the system! \t\n";
            else
                for (SystemUser &user : users)
                {
                    _printUserRecordLine(user);
                    cout << endl;
                }
            cout << "_____________________________________________________________________________________________________________________________________\n\n";
        }


    public:
        static void showUserListScreen(){
            vector<SystemUser> users = UserRepository::getAllUsers();

            const string title = "\t User List Screen";
            const string subTitle = "\t   (" + to_string(users.size()) + ") User(s).";

            _drawScreenHeader(title, subTitle);

            _print(users);
        }
};