#pragma once

#include <iostream>
#include "Date.h"

using namespace std;

class inputValidator{

    public:
        static bool isBetween(const int num , const int min , const int max){
            return num >= min && num <= max;
        }

        static bool isBetween(const double num , const double min , const double max){
            return num >= min && num <= max;
        }

        static bool isBetween(const float num , const float min , const float max){
            return num >= min && num <= max;
        }

        static bool isBetween(const Date date , Date minDate , Date maxDate){
            if(minDate > maxDate) Date::swap(minDate,maxDate);
            return date >= minDate && date <= maxDate;
        }

        static int get_int(const std::string &message, int minValue , int maxValue )
        {
            int number;
            while (true)
            {
                std::cout << message;
                std::cin >> number;

                if (std::cin.fail() || number < minValue || number > maxValue){
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid num between [" << minValue << "-" << maxValue << "].\n";
                }
                else{
                    return number;
                }
            }
        }

        static int get_int(const std::string &message)
        {
            int number;
            while (true)
            {
                std::cout << message;
                std::cin >> number;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid num\n";
                }
                else
                {
                    return number;
                }
            }
        }

        static short get_short(const std::string &message)
        {
            short number;
            while (true)
            {
                std::cout << message;
                std::cin >> number;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid num\n";
                }
                else
                {
                    return number;
                }
            }
        }

        static short get_short(const std::string &message, short minValue, short maxValue)
        {
            short number;
            while (true)
            {
                std::cout << message;
                std::cin >> number;

                if (std::cin.fail() || number < minValue || number > maxValue)
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid num between [" << minValue << "-" << maxValue << "].\n";
                }
                else
                {
                    return number;
                }
            }
        }

        static long long get_long(const std::string &message)
        {
            long long number;
            while (true)
            {
                std::cout << message;
                std::cin >> number;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid num\n";
                }
                else
                {
                    return number;
                }
            }
        }

        static double get_double(const std::string &message, int minValue, int maxValue)
        {
            double number;
            while (true)
            {
                std::cout << message;
                std::cin >> number;

                if (std::cin.fail() || number < minValue || number > maxValue)
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid num between [" << minValue << "-" << maxValue << "].\n";
                }
                else
                {
                    return number;
                }
            }
        }

        static double get_double(const std::string &message)
        {
            double number;
            while (true)
            {
                std::cout << message;
                std::cin >> number;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid num\n";
                }
                else
                {
                    return number;
                }
            }
        }

        static double get_float(const std::string &message)
        {
            float number;
            while (true)
            {
                std::cout << message;
                std::cin >> number;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid num\n";
                }
                else
                {
                    return number;
                }
            }
        }

        static char get_char(const std::string &message)
        {
            char ch;
            while (true)
            {
                std::cout << message;
                std::cin >> ch;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid character\n";
                }
                else
                {
                    return ch;
                }
            }
        }

        static char get_char(const std::string &message , const char value1 , const char value2)
        {
            char ch;
            while (true)
            {
                std::cout << message;
                std::cin >> ch;

                if (std::cin.fail() || (ch != value1 && ch!= value2))
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid character [" << value1 << "," << value2 << "]\n";
                }
                else
                {
                    return ch;
                }
            }
        }

        static std::string get_string(const std::string &message)
        {
            std::string s;
            while (true)
            {
                std::cout << message;
                std::getline(std::cin, s);

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input! Please enter a valid string\n";
                }
                else
                {
                    return s;
                }
            }
        }

        static bool isValidDate(const Date &date){
            return Date::isValidDate(date);
        }
};