#pragma once

#include "Screen.h"
#include "../Domain/LoginRegister.h"
#include "../Repository/LoginRegisterRepository.h"

#include "../Domain/SystemUser.h"

class LoginRegisterScreen: protected Screen{

    private:

        static string _prtintStatus(LoginRegister::LoginStatus status){
            return status == LoginRegister::Success ? "Success" : "Failed";
        }

        static void _printLogRecordLine(LoginRegister log){
            cout << "| " << setw(30) << left << log.getDateTime();
            cout << "| " << setw(20) << left << log.getUserName();
            cout << "| " << setw(10) << left << log.getPermissions();
            cout << "| " << setw(10) << left << _prtintStatus(log.getLoginStatus());

        }

        static void _printLogCard(LoginRegister log){
            cout << "\n\t\t\t\tLog List (" << 1 << ") log(s).";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(30) << "Date & Time";
            cout << "| " << left << setw(20) << "Username";
            cout << "| " << left << setw(10) << "Permissions";
            cout << "| " << left << setw(10) << "Status";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";

            _printLogRecordLine(log);
            cout << "\n_____________________________________________________________________________________________________________________________________\n";
        }

        static void _print(vector<LoginRegister> logs){
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(30) << "Date & Time";
            cout << "| " << left << setw(20) << "Username";
            cout << "| " << left << setw(10) << "Permissions";
            cout << "| " << left << setw(10) << "Status";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";

            if(logs.size() <= 0)
                cout << "\t\t\tNo logs available in the system! \t\n";
            else
                for (LoginRegister &l : logs)
                {
                    _printLogRecordLine(l);
                    cout << endl;
                }
            cout << "_____________________________________________________________________________________________________________________________________\n\n";
        }


    public:
        static void showLoginRegisterScreen(){
            if(!checkPermission(SystemUser::Permissions::ShowLoginRegister)) return;

            _drawScreenHeader("\t Login Register Screen");

            vector<LoginRegister> logs = LoginRegisterRepository::getAll();

            _print(logs);
        }
};