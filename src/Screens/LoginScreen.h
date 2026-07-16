#include "Screen.h"
#include "../Global.h"
#include "MainMenuScreen.h"

#include "../Lib/InputValidator.h"
#include "../Lib/Util.h"


#include "../Repository/UserRepository.h"
#include "../Repository/LoginRegisterRepository.h"


class LoginScreen: protected Screen{

    private:
        static bool _login(){
            short remainingAttempts = 3;

            while (remainingAttempts > 0)
            {
                string username = inputValidator::get_string("Username: ");
                string password = inputValidator::get_string("Password: ");

                currentUser = UserRepository::find(username, password);

                bool loginSucceeded = !currentUser.isEmptyMode();

                LoginRegister log(Date::getSystemDateAndTime(), username, currentUser.getPermissions(), loginSucceeded ? LoginRegister::LoginStatus::Success : LoginRegister::LoginStatus::Failed);

                LoginRegisterRepository::addLog(log);

                if (loginSucceeded)
                    return true;

                    --remainingAttempts;

                    cout << "\nInvalid username or password.\n";

                    if (remainingAttempts > 0){
                    cout << "You have "
                        << remainingAttempts
                        << " login attempts remaining.\n\n";
                }
            }

            return false;
        }

    public:
        static bool showLoginScreen(){
            Util::clearScreen();
            _drawScreenHeader("\t Login Screen");


            bool loginSucceeded = _login();

            if(loginSucceeded){
                MainMenuScreen::showMainMenu();
            }

            return loginSucceeded;
        }
};