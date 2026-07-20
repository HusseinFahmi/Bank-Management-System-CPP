#pragma once

#include <iostream>

class Currency{
    public:
        enum Mode{EmptyMode = 0 , UpdateMode = 1};
    
    private:
        std::string _country;
        std::string _currencyCode;
        std::string _currencyName;
        double _rate;
        Mode _mode;
    
    public:
        Currency():
            _country(""),
            _currencyCode(""),
            _currencyName(""),
            _rate(0.0),
            _mode(Mode::EmptyMode){}
        
        Currency(const std::string country , const std::string currencyCode , const std::string currencyName , double rate , Mode mode):
            _country(country),
            _currencyCode(currencyCode),
            _currencyName(currencyName),
            _rate(rate),
            _mode(mode){}

        void setMode(const Mode mode){
            _mode = mode;
        }

        void setRate(const double rate){
            _rate = rate;
        }

        std::string getCountry() const{
            return _country;
        }

        std::string getCurrencyCode() const{
            return _currencyCode;
        }

        std::string getCurrencyName() const{
            return _currencyName;
        }

        double getRate() const{
            return _rate;
        }

        bool isEmptyMode() const{
            return _mode == Mode::EmptyMode;
        }
};