#pragma once

#include "CurrencyBaseScreen.h"
#include "../../Lib/InputValidator.h"
#include "../../Lib/Util.h"

#include "CurrenciesListScreen.h"
#include "FindCurrencyScreen.h"
#include "UpdateCurrecnyRateScreen.h"

#include "CurrencyCalculatorScreen.h"



class CurrencyExchangeMainMenu: protected CurrencyBaseScreen{
    private:
        inline static const vector<std::string> _currencyMenuOption{
            "List currencies",
            "Find currency",
            "Update Currency",
            "Currency Calculator",
            "Main Menu"
        };

        enum _enCurrencyMenuOptions{
            eShowCurrenciesList = 1,
            eFindCurrency = 2,
            eUpdateCurrency = 3,
            eCurrencyCalculator = 4,
        };

        static void _showCurrenciesListScreen(){
            CurrenciesListScreen::showCurrenciesListScreen();
        }

        static void _showFindCurrencyScreen(){
            FindCurrencyScreen::showFindCurrencyScreen();
        }

        static void _showUpdateCurrencyScreen(){
            UpdateCurrecnyRateScreen::showUpdateCurrencyRateScreen();
        }

        static void _showCurrencyCalculatorScreen(){
            CurrencyCalculatorScreen::showCurrencyCalculatorScreen();
        }

        static bool _performCurrencyMenuOption(_enCurrencyMenuOptions option){
            Util::clearInputBuffer();
            Util::clearScreen();
 
            switch (option) {
                case _enCurrencyMenuOptions::eShowCurrenciesList:
                    _showCurrenciesListScreen();
                return true;

                case _enCurrencyMenuOptions::eFindCurrency:
                    _showFindCurrencyScreen();
                return true;

                case _enCurrencyMenuOptions::eUpdateCurrency:
                    _showUpdateCurrencyScreen();
                return true;

                case _enCurrencyMenuOptions::eCurrencyCalculator:
                    _showCurrencyCalculatorScreen();
                return true;
            
            default:
                break;
            }
            return false;
        }

    public:
        static void showCurrencyExchangeMainMenu(){
            do{
                Util::clearScreen();
                _drawScreenHeader("\t Currency Exchange Main Screen");

                cout << "\t\t\t\t\t\t  ==================================================\n";
                cout << "\t\t\t\t\t\t\t\t     Currency Exchange Menu\t\t\t\t\n";
                cout << "\t\t\t\t\t\t  ==================================================\n";
                
                int i;
                for(i = 0 ; i < _currencyMenuOption.size() ; i++){
                    cout << "\t\t\t\t\t\t\t\t[" << i + 1 << "] " << _currencyMenuOption[i] << endl;
                }
                int option = inputValidator::get_int("Choose what you want to do [1-" + to_string(i)  + "]: ", 1, i);
                if (!_performCurrencyMenuOption((_enCurrencyMenuOptions)option))
                    return;
            }while(true);
        }

};