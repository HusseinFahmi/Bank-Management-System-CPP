#pragma once


#include "../Screen.h"
#include "../../Domain/BankClient.h"
#include "../../Repository/ClientRepository.h"

#include "DepositScreen.h"


class TransactionsMenuScreen : protected Screen{
    private:
        inline static const vector<string> _transactionMenuOptions{
            "Deposit",
            "WithDraw",
            "Total Balances",
            "Main Menu",
        };

        enum _enTransactionMenuOptions{
            eDeposit = 1,
            eWithDraw = 2,
            eTotoalBalances = 3,
            eMainMenu = 4,
        };
    
        static void _depositScreen(){
            DepositScreen::showDepositScreen();
        }

        static void _withdrawScreen(){}
        static void _totalBalancesScreen(){}

        static void _mainMenuScreen(){}

        static bool _performTransactionMenuOption(_enTransactionMenuOptions option){
            Util::clearInputBuffer();
            Util::clearScreen();

            switch(option){
                case _enTransactionMenuOptions::eDeposit:
                    _depositScreen();
                return true;

                case _enTransactionMenuOptions::eWithDraw:
                    _withdrawScreen();
                return true;

                case _enTransactionMenuOptions::eTotoalBalances:
                    _totalBalancesScreen();
                return true;

                case _enTransactionMenuOptions::eMainMenu:
                return false;
            }
                return false;
        }

    protected:
        


    public:
        static void showTransactionScreen(){

            do{
                Util::clearScreen();

                _drawScreenHeader("\t Transaction Screen");

                cout << "\t\t\t\t\t\t  ==================================================\n";
                cout << "\t\t\t\t\t\t\t\t     Transaction Menu\t\t\t\t\n";
                cout << "\t\t\t\t\t\t  ==================================================\n";

                int i;

                for(i =  0 ; i <_transactionMenuOptions.size() ; i++){
                    cout << "\t\t\t\t\t\t\t\t[" << i + 1 << "] " << _transactionMenuOptions[i] << endl;
                }


                    int option = inputValidator::get_int("Choose what you want to do [1-" + to_string(i)  + "]: ", 1, i);

                    if (!_performTransactionMenuOption((_enTransactionMenuOptions)option))
                        return;
                    Util::wait();
                
            }while(true);
        }
};