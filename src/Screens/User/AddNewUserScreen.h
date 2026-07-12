#pragma once

#include "UserBaseScreen.h"
#include "../../Repository/UserRepository.h"

#include "../../Lib/Util.h"

class AddNewUserScreen: protected UserBaseScreen{
    public:
        static void showAddNewUserScreen(){
            _drawScreenHeader("\t Add new User");

            string userName;
            SystemUser user;

            do{
                userName = inputValidator::get_string("Enter userName: ");
                user = UserRepository::find(userName);

                if(!user.isEmptyMode()){
                    cout << "User with UserName (" << userName << ") already exists, please enter another UserName.\n\n";

                }
            }while(!user.isEmptyMode());

            user = SystemUser::create(userName);

            cout << "\n============ user info =============\n";
            _readUserInfo(user);

            _printResult(UserRepository::save(user),"User","Added");

            Util::wait();
        }
};