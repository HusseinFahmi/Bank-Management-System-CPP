#pragma once

#include <iostream>
#include <string>

#include "CurrencyBaseScreen.h"
#include "../../Lib/Util.h"
#include "../../Lib/InputValidator.h"

#include "../../Services/CurrencyService.h"

class FindCurrencyScreen:protected CurrencyBaseScreen{
    public:
        static void showFindCurrencyScreen(){
            _drawScreenHeader("\t Find Currency Screen");

            short choice = inputValidator::get_short("[1] Search by Currency Code \t [2] Search by Country name \n\nEnter your choice: " ,1,2);

            Util::clearInputBuffer();
            Currency Currency;

            switch (choice){
                case 1: {
                    string currencyCode = inputValidator::get_string("Enter currency code: ");
                    Currency = CurrencyService::findByCode(currencyCode);
                    break;
                }

                case 2: {
                    string country = inputValidator::get_string("Enter country name: ");
                    Currency = CurrencyService::findByCountry(country);
                    break;
                }
            }

            if (!Currency.isEmptyMode()) {
                std::cout << "\nCurrency Found!\n";
                _printCurrencyCard(Currency); 
            } 
            else {
                std::cout << "\nSorry, Currency not found!\n";
            }

            Util::wait();
        }

};