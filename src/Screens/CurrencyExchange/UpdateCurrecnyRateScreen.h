#pragma once

#include "CurrencyBaseScreen.h"
#include "../../Services/CurrencyService.h"
#include "../../Lib/InputValidator.h"
#include "../../Lib/Util.h"

class UpdateCurrecnyRateScreen: protected CurrencyBaseScreen{
    public:
        static void showUpdateCurrencyRateScreen(){
            _drawScreenHeader("\t Update Currency Rate");

            string couurencyCode = _readCurrencyCode("Enter currency Code: ");

            Currency currency;
            currency = CurrencyService::findByCode(couurencyCode);
            _printCurrencyCard(currency);

            char ch = inputValidator::get_char("\nAre you sure you want to update this currecny Rate <y,n>: " ,'y','n');
            if(ch == 'n') return;

            double newRate = inputValidator::get_double("Enter new rate: ");

            bool success = CurrencyService::updateCurrencyRate(couurencyCode,newRate);

            if(success){
                currency = CurrencyService::findByCode(couurencyCode);
                _printCurrencyCard(currency);
                cout << "\nRate updated successfully\n";

            }
            else cout << "couldn't to update\n";
            
            Util::clearInputBuffer();
            Util::wait();
        }
};