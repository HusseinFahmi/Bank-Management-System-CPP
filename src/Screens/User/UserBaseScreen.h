#pragma once


#include "../Screen.h"
#include "../../Domain/SystemUser.h"
#include "../../Lib/InputValidator.h"

#include <iomanip>

class UserBaseScreen: protected Screen{
    protected:
        static void _printUserRecordLine(SystemUser user){
            cout << "| " << setw(30) << left << user.getFullName();
            cout << "| " << setw(20) << left << user.getEmail();
            cout << "| " << setw(15) << left << user.getPhone();
            cout << "| " << setw(30) << left << user.getUserName();
            cout << "| " << setw(20) << left << user.getPassword();
            cout << "| " << setw(10) << left << user.getPermissions();
        }

        static void _printUserCard(SystemUser user){
            cout << "\n\t\t\t\t\tClient List (" << 1 << ") user(s).";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(30) << "Full name";
            cout << "| " << left << setw(20) << "Email";
            cout << "| " << left << setw(15) << "phone";
            cout << "| " << left << setw(30) << "Username";
            cout << "| " << left << setw(20) << "Password";
            cout << "| " << left << setw(10) << "Permissions";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";

            _printUserRecordLine(user);
            cout << "\n_____________________________________________________________________________________________________________________________________\n";
        }        
};