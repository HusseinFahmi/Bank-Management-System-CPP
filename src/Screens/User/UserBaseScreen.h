#pragma once


#include "../Screen.h"
#include "../../Domain/SystemUser.h"
#include "../../Lib/InputValidator.h"

#include <iomanip>

class UserBaseScreen: protected Screen{
    private:
        static int _getPermission(){
            int permission = 0;
            char choice = 'n';

            choice = inputValidator::get_char("\nDo you want to give full access <y,n>: ", 'y', 'n');
            if (choice == 'y') return -1;

            cout << "Do you want to give access to: \n";

            choice = inputValidator::get_char("show client list <y,n>: ", 'y', 'n');
            if (choice == 'y') permission |= SystemUser::Permissions::readPermission;

            choice = inputValidator::get_char("add new client <y,n>: ", 'y', 'n');
            if (choice == 'y') permission |= SystemUser::Permissions::writePermission;;

            choice = inputValidator::get_char("delete client <y,n>: ", 'y', 'n');
            if (choice == 'y') permission |= SystemUser::Permissions::deletePermission;

            choice = inputValidator::get_char("update client <y,n>: ", 'y', 'n');
            if (choice == 'y') permission |= SystemUser::Permissions::updatePermission;

            choice = inputValidator::get_char("find client <y,n>: ", 'y', 'n');
            if (choice == 'y') permission |= SystemUser::Permissions::findPermission;

            choice = inputValidator::get_char("manage Users <y,n>: ", 'y', 'n');
            if (choice == 'y') permission |= SystemUser::Permissions::manageUsersPermission;

            choice = inputValidator::get_char("transactions <y,n>: ", 'y', 'n');
            if (choice == 'y') permission |= SystemUser::Permissions::transactionPermission;

            return permission;
        }

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
        
        static void _readUserInfo(SystemUser& user){
            user.setFirstName(inputValidator::get_string("Enter first name: "));
            user.setLastName(inputValidator::get_string("Enter last name: "));
            user.setEmail(inputValidator::get_string("Enter email: "));
            user.setPhone(inputValidator::get_string("Enter phone number: "));
            user.setPassword(inputValidator::get_string("Enter password: "));
            user.setpermissions(_getPermission());
        }

        static void _printResult(bool isSuccess, const string& entity, const string& action){            
            string successMessage = "\n" + entity + " " + action + " Successfully.\n";
            string failMessage = "\nError: " + entity + " was NOT " + action + "!\n";
            
            isSuccess ? cout << successMessage : cout << failMessage;
        }
};