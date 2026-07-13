#pragma once

#include "../Global.h"

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
            cout << "\n\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  " << title;
            if (subtitle != "") {
                cout << "\n\t\t\t\t\t  " << subtitle;
            }
            cout << "\n\t\t\t\t\t______________________________________\n\n";
        }

        static bool checkPermission(int permission){
            if(!_hasPermission(permission)){
                std::cout << "\nAccess Denied\n";
                return false;
            }

            return true;
        } 


};