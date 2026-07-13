#include <iostream>
#include "Screens/LoginScreen.h"

SystemUser currentUser = SystemUser::getEmptyObject();

int main() {

    while (true){
        LoginScreen::showLoginScreen();
    }
    
    return 0;
}