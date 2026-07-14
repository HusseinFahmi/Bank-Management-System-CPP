#include <iostream>
#include "Screens/LoginScreen.h"

SystemUser currentUser = SystemUser::getEmptyObject();

int main() {

    while (true){
        if(!LoginScreen::showLoginScreen()){
            break;
        }
    }
    
    return 0;
}