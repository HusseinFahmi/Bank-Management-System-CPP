#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "CurrencyBaseScreen.h"
#include "../../Lib/Util.h"
#include "../../Lib/InputValidator.h"

#include "../../Services/CurrencyService.h"

class CurrencyCalculatorScreen:protected CurrencyBaseScreen{
    public:
        static void showCurrencyCalculatorScreen(){
            char ch;
            do{
                Util::clearScreen();
                
                _drawScreenHeader("\t Currency Calcualtor Screen");

                Currency fromCurrency = _getValidCurrency("Enter Source currency code: ");
                Currency toCurrency = _getValidCurrency("\nEnter destination currency code: ");

                double amount = inputValidator::get_double("\nEnter Amount to change: ");

                std::cout << std::fixed << std::setprecision(2);

                double amountInUSD = CurrencyService::toUSD(fromCurrency,amount);

                if(fromCurrency.getCurrencyCode() != "USD"){
                    std::cout << "\n\n\nConvert from:";
                    _printCurrencyCard(fromCurrency);
    
                    std::cout << "\n" << amount << " " << fromCurrency.getCurrencyCode() << " = " << amountInUSD << " USD\n";
                }

                std::cout << "\n\n\nConvert to:";
                _printCurrencyCard(toCurrency);

                std::cout << "\n" << amount << " " << fromCurrency.getCurrencyCode() << " = " << CurrencyService::fromUSD(toCurrency,amountInUSD) << " " << toCurrency.getCurrencyCode() << "\n\n";

                ch = inputValidator::get_char("Do you want to perform another calcualtion <y,n>: ",'y','n');
                Util::clearInputBuffer();
            }while(ch == 'y');
        }
};