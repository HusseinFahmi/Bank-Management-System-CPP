#pragma once

#include <iostream>
#include "Date.h"
#include <limits>

using namespace std;

class Util{
    private:


    public:

        enum randType{capital = 1 , small = 2 , digit = 3 , mixChar = 4};

        static void cls(){
            system("cls");
        }

        static void pause(){
            system("pause");
        }

        // void srand(){
        //     srand((unsigned)time(NULL));
        // }

        static int random(const int &from, const int &to) {
            return rand() % (to - from + 1) + from;
        }

        static char generate_rand(randType type){

            if(type == randType::mixChar) type = (randType)random(1,3);

            switch (type){
                case randType::capital:
                    return char(random('A','Z'));
                
                case randType::small:
                    return char(random('a','z'));
                
                case randType::digit:
                    return char(random('0','9'));
                
                default:
                    return '?';
            }
        }

        static string generate_randomWord(const randType &type , const int &len){
            string res = "";
            for(int i=0 ; i<len ; i++){
                res += generate_rand(type);
            }

            return res;
        }

        static string create_banch(const randType &type){
            string res = "";

            for(int i=0 ; i<4 ; i++){
                res += generate_rand(type);
            }

            return res;
        }



        static string generate_key(const randType &type , const int len = 4){
            string res = "";

            for(int i=0 ; i< len ; i++){
                res += create_banch(type);

                if(i!=len-1){
                    res += "-";
                }
            }

            return res;
        }

        static void generate_keys(const randType &type , const int &counts){
            for(int i=1 ; i<=counts ; i++){
                cout << "[" << i << "]: " << generate_key(type) << endl;
            }
        }

        static void swap(int &num1 , int &num2){
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }

        static void swap(string &str1 , string &str2){
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }

        static void swap(Date &d1 , Date &d2){
            Date temp = d1;
            d1 = d2;
            d2 = temp;
        }

        static void shuffleArray(vector<int> &arr){
            int len = arr.size();
            for(int i = 0 ; i < len ; i++){
                swap(arr[i],arr[random(0,len-1)]);
            }
        }

        static void fillArrWithRandom(vector<int> &nums , const short &count , const int &startWith , const int &endWith){
            for(int i=0 ; i<count ; i++){
                nums.push_back(random(startWith , endWith));
            }
        }

        static void fillArrWithRandomWords(vector<string> &strs , const int &count , const randType &rand , const int &len){
            for(int i=0 ; i<count ; i++){
                strs.push_back(generate_randomWord(rand,len));
            }
        }

        static void fillArrWithRandomKeys(vector<string> &keys , const int &count , const randType &rand , const int &len){
            for(int i=0 ; i<count ; i++){
                keys.push_back(generate_key(rand));
            }
        }

        static void tabs(const int &count , const char ch='\t'){
            cout << string(count,ch);
        }

        static string encryptText(string text , const int key){
            for(int i=0 ; i<text.size() ; i++){
                text[i] = text[i]+key;
            }

            return text;
        }

        static string decryptText(string text , const int key){
            for(int i=0 ; i<text.size() ; i++){
                text[i] = text[i]-key;
            }

            return text;
        }

          static string numberToText(long long n){
            string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                            "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

            string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

            if (n == 0)
                return "";

            if (n < 20)
                return ones[n] + " ";

            if (n < 100)
                return tens[n / 10] + " " + numberToText(n % 10);

            if (n < 1000)
                return numberToText(n / 100) + "Hundred " + numberToText(n % 100);

            if (n < 1000000)
                return numberToText(n / 1000) + "Thousand " + numberToText(n % 1000);

            if (n < 1000000000)
                return numberToText(n / 1000000) + "Million " + numberToText(n % 1000000);

            return numberToText(n / 1000000000) + "Billion " + numberToText(n % 1000000000);
        }

        static void clearInputBuffer(){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        static void wait(){
            std::cout << "\nPress Enter to continue...";
            clearInputBuffer();
            std::cin.get();
        }

        static void clearScreen() {
            system("clear"); 
        }
};