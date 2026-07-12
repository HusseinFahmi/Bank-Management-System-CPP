#pragma once

#include "UserBaseScreen.h"


#include "../../Repository/UserRepository.h"
#include "../../Lib/Util.h"


class DeleteUserScreen: protected UserBaseScreen{
    public:
        static void showDeleteUserScreen(){
            _drawScreenHeader("\t Delete user Screen");

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

            char ch = inputValidator::get_char("\nAre you sure you want to delete this user <y,n>: " ,'y','n');

            if(ch == 'n') return;

            user.setMode(SystemUser::Mode::DeleteMode);

            _printResult(UserRepository::save(user),"User","Deleted");
            Util::wait();
        }
};

