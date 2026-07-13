#include "Screen.h"
#include "../Global.h"
#include "MainMenuScreen.h"

#include "../Lib/InputValidator.h"
#include "../Lib/Util.h"


#include "../Repository/UserRepository.h"

class LoginScreen: protected Screen{

    private:
        static void _login(){
            bool loginFailed = false;

            string userName,password;

            do{
                if(loginFailed){
                    cout << "\nInvalid username or password\n";
                }

                userName = inputValidator::get_string("username: ");
                password = inputValidator::get_string("password: ");

                currentUser = UserRepository::find(userName,password);

                loginFailed = currentUser.isEmptyMode();
            }while(loginFailed);

            MainMenuScreen::showMainMenu();
        }

    public:
        static void showLoginScreen(){
            Util::clearScreen();
            _drawScreenHeader("\t Login Screen");

            _login();
        }
};