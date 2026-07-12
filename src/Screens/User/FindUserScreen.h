#pragma once

#include "UserBaseScreen.h"

#include "../../Repository/UserRepository.h"
#include "../../Lib/Util.h"

class FindUserScreen: protected UserBaseScreen{
    public:
        static void showFindUserScreen(){
            _drawScreenHeader("\t Find User Screen");

            string userName = inputValidator::get_string("Enter user name: ");
            SystemUser user = UserRepository::find(userName); 

            if(user.isEmptyMode()){
                cout << "User with UserName (" << userName << ") not found\n";
                return;
            }

            _printUserCard(user);
        }
};