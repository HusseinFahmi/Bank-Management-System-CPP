#pragma once

#include "../Screen.h"
#include "../../Domain/Currency.h"
#include "../../Services/CurrencyService.h"
#include <iostream>

class CurrencyBaseScreen: protected Screen{
    protected:
        static void _printCurrencyRecordLine(const Currency currency){
            cout << "| " << setw(40) << left << currency.getCountry();
            cout << "| " << setw(20) << left << currency.getCurrencyCode();
            cout << "| " << setw(50) << left << currency.getCurrencyName();
            cout << "| " << setw(30) << left << currency.getRate();
        }

        static void _printCurrencyCard(const Currency currency){
            cout << "\n\t\t\t\t\tCurrencies List (" << 1 << ") currency(ies).";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(40) << "Country";
            cout << "| " << left << setw(20) << "Currency Code";
            cout << "| " << left << setw(50) << "Currency Name";
            cout << "| " << left << setw(30) << "Rate";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";

            _printCurrencyRecordLine(currency);
            cout << "\n_____________________________________________________________________________________________________________________________________\n";
        }     

        static string _readCurrencyCode(const string& message){
            string couurencyCode = inputValidator::get_string(message);

            while(!CurrencyService::isExist(couurencyCode)){
                couurencyCode = inputValidator::get_string("Not found ,Enter another currency code: ");
            }
            return couurencyCode;
        }

        static Currency _getValidCurrency(const string& message){
            std::string couurencyCode = inputValidator::get_string(message);
            Currency currency = CurrencyService::findByCode(couurencyCode);

            while(currency.isEmptyMode()){
                couurencyCode = inputValidator::get_string("Not found ,Enter another currency code: ");
                currency = CurrencyService::findByCode(couurencyCode);
            }
            return currency;
        }
};