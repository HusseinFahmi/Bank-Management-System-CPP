#pragma once

#include "../Global.h"

#include "../Lib/Date.h"

#include <iostream>
#include <string>

using namespace std;

class Screen {

    private:
        static bool _hasPermission(int permission){
            return (currentUser.getPermissions() & permission) == permission;
        }

    protected:
        static void _drawScreenHeader(string title, string subtitle = "") {
            Date date;

            cout << "\n\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t   " << title;
            if (subtitle != "") {
                cout << "\n\t\t\t\t\t  " << subtitle;
            }
            cout << "\n\t\t\t\t\t______________________________________\n\n";

            cout << "\t\t\t\t\t Date:" << date.toString() << "\n";
            if(!currentUser.isEmptyMode())
            cout << "\t\t\t\t\t User: " << currentUser.getUserName() << "\n\n\n";
        }

        static bool checkPermission(int permission){
            if(!_hasPermission(permission)){
                std::cout << "\nAccess Denied\n";
                return false;
            }

            return true;
        } 


};