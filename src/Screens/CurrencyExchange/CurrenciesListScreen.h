#pragma once

#include "CurrencyBaseScreen.h"
#include "../../Services/CurrencyService.h"
#include "../../Domain/Currency.h"


#include "../../Lib/Util.h"
#include "../../Lib/InputValidator.h"

class CurrenciesListScreen: protected CurrencyBaseScreen{
    private:
        static void _print(std::vector<Currency> currencies){
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(40) << "Country";
            cout << "| " << left << setw(20) << "Currency Code";
            cout << "| " << left << setw(50) << "Currency Name";
            cout << "| " << left << setw(30) << "Rate";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";

            if(currencies.size() <= 0)
                cout << "\t\t\tNo currencies available in the system! \t\n";
            else
                for (Currency &c : currencies)
                {
                    _printCurrencyRecordLine(c);
                    cout << endl;
                }
            cout << "_____________________________________________________________________________________________________________________________________\n\n";
        }
    public:
        static void showCurrenciesListScreen(){
            std::vector<Currency> currencies = CurrencyService::getAllCurrencies();

            const string title = "\t Currencies List Screen\n";
            const string subTitle = "(" + to_string(currencies.size()) + ") Currency"; 

            _drawScreenHeader(title + subTitle);

            _print(currencies);
            Util::wait();
        }
};