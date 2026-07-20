#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "../Domain/Currency.h"
#include "../Lib/String.h"

class CurrencyRepository{
    private:
        static std::string _currenciesFilePath(){
            return "../Data/Currencies.txt";
        }

        static Currency getEmptyObject(){
            return Currency();
        }

        static Currency _fromLine(const std::string line , std::string delim = "#//#"){
            std::vector<std::string> fields = String::split(line,delim);
            
            if(fields.size() < 4) return getEmptyObject();

            return Currency(fields[0] , fields[1] , fields[2] , stod(fields[3]) , Currency::Mode::UpdateMode);
        }

        static std::string _toLine(Currency& Currency){
            std::string delim = "#//#";

            return Currency.getCountry() + delim + Currency.getCurrencyCode() + delim + Currency.getCurrencyName() + delim + to_string(Currency.getRate());
        }

        static void _saveToFile(std::vector<Currency> currencies){
            std::fstream file;

            file.open(_currenciesFilePath() , ios::out);
            if(!file.is_open()) return;

            for(Currency& c: currencies){
                file << _toLine(c) << "\n";
            }

            file.close();
        }

    public:
        static std::vector<Currency> getAll(){
            std::vector<Currency> currencies;

            std::fstream file;
            file.open(_currenciesFilePath(), std::ios::in);

            if(!file.is_open()) return {};

            std::string line;

            while(getline(file,line)){
                if(!line.empty()){
                    Currency currency = _fromLine(line);
                    currencies.push_back(currency);
                }
            }
            file.close();
            return currencies;
        }

        static void update(Currency& currency){
            std::vector<Currency> currencies = getAll();

            for(Currency& c: currencies){
                if(currency.getCurrencyCode() == c.getCurrencyCode()){
                    c = currency;
                    break;
                }
            }

            _saveToFile(currencies);
        }

        static Currency findByCode(std::string currencyCode){
            String::toUpperCase(currencyCode);

            std::fstream file;
            file.open(_currenciesFilePath() , ios::in);

            if(!file.is_open()) return getEmptyObject();

            std::string line;

            while(getline(file,line)){
                if(line.empty()) break;
                
                Currency currency = _fromLine(line);
                std::string code = currency.getCurrencyCode();

                if(String::toUpperCase(code) == currencyCode){
                    file.close();
                    return currency;
                }
            }

            file.close();
            return getEmptyObject();
        }

        static Currency findByCountry(std::string country){
            String::toUpperCase(country);

            std::fstream file;
            file.open(_currenciesFilePath() , ios::in);

            if(!file.is_open()) return getEmptyObject();

            std::string line;

            while(getline(file,line)){
                if(line.empty()) continue;
                
                Currency currency = _fromLine(line);
                std::string currentCountry = currency.getCountry();
                if(String::toUpperCase(currentCountry) == country){
                    file.close();
                    return currency;
                }
            }

            file.close();
            return getEmptyObject();
        }

        static bool isExist(const string& currencyCode){
            Currency currency = findByCode(currencyCode);
            return !currency.isEmptyMode();
        }
};