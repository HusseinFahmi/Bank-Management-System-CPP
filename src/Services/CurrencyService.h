#pragma once

#include <iostream>

#include "../Repository/CurrencyRepository.h"
#include "../Repository/CurrencyRepository.h"

class CurrencyService{
    public:
        static bool updateCurrencyRate(std::string currencyCode , double newRate){
            
            Currency currency = CurrencyRepository::findByCode(currencyCode);
            if(currency.isEmptyMode()) return false;
        
            currency.setRate(newRate);
        
            CurrencyRepository::update(currency);
        
            return true;
        }

        static std::vector<Currency> getAllCurrencies(){
            return CurrencyRepository::getAll();
        }

        static Currency findByCode(const string& currencyCode){
            return CurrencyRepository::findByCode(currencyCode);
        }

        static Currency findByCountry(const string& country){
            return CurrencyRepository::findByCountry(country);
        }

        static bool isExist(const string& currencyCode){
            return CurrencyRepository::isExist(currencyCode);
        }

        static double toUSD(const Currency& currency , double amount){
            return amount/currency.getRate();
        }

        static double fromUSD(const Currency& currency , double amountInUSD){
            return currency.getCurrencyCode() == "USD" ? amountInUSD : amountInUSD*currency.getRate();
        }

        
};