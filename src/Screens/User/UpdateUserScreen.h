#pragma once

#include "UserBaseScreen.h"

#include "../../Repository/UserRepository.h"
#include "../../Lib/Util.h"


class UpdateUserScreen: protected UserBaseScreen{
    public:
        static void showUpdateUserScreen(){
            _drawScreenHeader("\t Update user Screen");

            string userName;
            SystemUser user;

            do{
                userName = inputValidator::get_string("Enter user name: ");
                user = UserRepository::find(userName);

                if(user.isEmptyMode()){
                    cout << "User with UserName (" << userName << ") not found, please enter another UserName.\n\n";
                }
            }while(user.isEmptyMode());

            _printUserCard(user);

            char ch = inputValidator::get_char("\nAre you sure you want to update this user <y,n>: " ,'y','n');
            if(ch == 'n') return;

            cout << "\n================================== User Info ==================================\n";
            Util::clearInputBuffer();
            _readUserInfo(user);

            _printResult(UserRepository::save(user),"User","Updated");
            Util::wait();
        }
};