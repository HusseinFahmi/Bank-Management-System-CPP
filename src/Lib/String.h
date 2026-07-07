#pragma once

#include <iostream>
#include <vector>

using namespace std;

class String{
    private:
        string _value;

        // =======================================================
        static void _swap(string &s1 , string &s2){
            string temp = s1;
            s1 = s2;
            s2 = temp;
        }

        static bool _isUpperCase(const char &ch){
            return ch >= 'A' && ch <= 'Z';
        }

        static bool _isLowerCase(const char &ch){
            return ch >= 'a' && ch <= 'z';
        }

        static bool _isLetter(const char ch){
            return _isUpperCase(ch) || _isLowerCase(ch);
        }

        static char _charToUpper(const char &ch){
            if (_isLetter(ch) && islower(ch)) return ch - 32;
            return ch;
        }

        static char _charToLower(const char &ch)
        {
            if (_isLetter(ch) && _isUpperCase(ch)) return ch + 32;
            return ch;
        }

        static bool _isVowel(char ch){
            ch = _charToUpper(ch);
            return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
        }

        static bool _isPunctuation(char ch){
            return ch == '.' || ch == ',' || ch == '!' || ch == '?' || ch == ';' || ch == ':' || ch == '\'' || ch == '"' || ch == '-' || ch == '(' || ch == ')';
        }

        static char _toggleCase(char ch){
            if (_isUpperCase(ch))
                return ch + 32;
            if (_isLowerCase(ch))
                return ch - 32;
            return ch;
        }

    public:

        String(){
            _value = "";
        }

        String(const char *ch){
            _value = ch;
        }

        void setValue(const string &value){
            this->_value = value;
        }

        string &getValue(){
            return _value;
        }

        int find(const string word, const string &pattern){
            
            if (empty(pattern)) return 0;

            int wordLen = word.length();
            int pattLen = pattern.length();

            if (pattLen > wordLen) return -1;

            for (int i = 0, len = wordLen - pattLen; i <= len; i++)
            {
                bool matched = true;
                for (int j = 0; j < pattLen; j++)
                {
                    if (word[i + j] != pattern[j])
                    {
                        matched = false;
                        break;
                    }
                }

                if (matched)
                    return i;
            }

            return -1;
        }

        static int countWords(string sentence , string delim = " "){
            int pos = 0, counter = 0;

            string word = "";

            while ((pos = sentence.find(delim)) != std::string::npos)
            {
                word = sentence.substr(0, pos);

                if (word != "")
                    counter++;

                sentence.erase(0, pos + delim.length());
            }

            if (sentence != " ")
                counter++;
            return counter;
        }

        int countWords(){
            return countWords(_value);
        }

        static int countLowercaseLetters(const string &sentence){
            int counter = 0;
            for (char ch : sentence)
            {
                if (_isLowerCase(ch))
                    counter++;
            }

            return counter;
        }

        int countLowercaseLetters(){
            return countLowercaseLetters(_value);
        }

        static int countUppercaseLetters(const string &sentence){
            int counter = 0;

            for (char ch : sentence)
            {
                if (_isUpperCase(ch))
                    counter++;
            }

            return counter;
        }

        int countUppercaseLetters(){
            return countUppercaseLetters(_value);
        }

        static int countLetters(const string &sentence){
            int counter = 0;

            for (char ch : sentence){
                if (_isLetter(ch)) counter++;
            }

            return counter;
        }

        int countLetters()
        {
            return countLetters(_value);
        }

        static int countChar(const string &sentence, char letter){
            int counter = 0;

            for (char ch : sentence){
                if (ch == letter) counter++;
            }

            return counter;
        }

        int countChar(char letter){
            return countChar(_value, letter);
        }

        static int countVowels(const string &sentence){
            int counter = 0;

            for (char ch : sentence){
                if (_isVowel(ch)) counter++;
            }

            return counter;
        }

        int countVowels(){
            return countVowels(_value);
        }


        static string toggleCase(string &sentence)
        {
            for (char &ch : sentence)
            {
                ch = _toggleCase(ch);
            }
            return sentence;
        }

        string toggleCase()
        {
            return toggleCase(_value);
        }

        static string toLowerCase(string &sentence){
            for(char &ch : sentence){
                ch = _charToLower(ch);
            }
            return sentence;
        }

        string toLowerCase(){
            return toLowerCase(_value);
        }

        static string toUpperCase(string &sentence){
            for(char &ch : sentence){
                ch = _charToUpper(ch);
            }
            return sentence;
        }

        string toUpperCase(){
            return toUpperCase(_value);
        }

        static string capitalizeFirstLetters(string &sentence){
            int isFirstLetter = true;

            for(char &ch:sentence){
                if(ch != ' ' && isFirstLetter){
                    ch = _charToUpper(ch);
                }

                isFirstLetter = (ch == ' ' ? true : false);
            }

            return sentence;
        }

        string capitalizeFirstLetters(){
            return capitalizeFirstLetters(_value);
        }

        static string lowercaseFirstLetters(string &sentence){
            bool isFirstLetter = true;

            for(char &ch : sentence){
                if(ch != ' ' && isFirstLetter) ch = _charToLower(ch);
                isFirstLetter = (ch == ' ');
            }
            return sentence;
        }

        string lowercaseFirstLetters(){
            return lowercaseFirstLetters(_value);
        }

        static string removePunctuation(string &sentence){
            string result = "";
            for(char &ch:sentence){
                if(!_isPunctuation(ch)) result += ch;
            }

            return sentence;
        }

        string removePunctuation(){
            return removePunctuation(_value);
        }

        static vector<string> split(string sentence , string &delim){
            if(delim.empty()) return {sentence};

            vector<string> result ;

            string word = "";
            int pos = 0;

            while((pos = sentence.find(delim)) != std::string::npos){
                word = sentence.substr(0,pos);

                if(!word.empty()) result.push_back(word);

                sentence.erase(0,pos+delim.length());
            }

            if(!sentence.empty()) result.push_back(sentence);

            return result;
        }

        vector<string> split(string &delim){
            return split(_value , delim);
        }

        static string join(const vector<string> &words, const string &delim)
        {
            if (words.empty()) return "";
            string result = "";

            for (int i = 0; i < words.size(); i++)
            {
                result += words[i];

                if (i != words.size() - 1) result += delim;
            }

            return result;
        }

        string join(vector<string> &words)
        {
            return join(words, _value);
        }

        static string replaceWord(string &sentence , string &replFrom , const string &replTo , bool matchCase = false){
            string delim = " ";
            vector<string> words = split(sentence, delim);

            for(string &word: words){
                if(matchCase && word == replFrom) word = replTo;
                else if(!matchCase && toLowerCase(word) == toLowerCase(replFrom)) word = replTo;
            }

            return join(words," ");
        }

        string replace(string &replFrom , const string &replTo , bool matchCase = false){
            return this->replaceWord(_value , replFrom , replTo , matchCase);
        }

        static string reverseWords(string &sentence){
            string delim = " ";
            vector<string> words = split(sentence , delim);

            int last = words.size()-1;

            for(int i=0 ,len = words.size()/2; i<len ; i++){
                _swap(words.at(i),words.at(last--));
            }
            return join(words,delim);
        }

        string reverseWords(){
            return reverseWords(_value);
        }

        static string trimStart(string &sentence){
            for(int i=0 ; i<sentence.length() ; i++){
                if(sentence[i] != ' ') return sentence.erase(0,i);
            }
            sentence.clear();
            return sentence;
        }

        string trimStart(){
            return trimStart(_value);
        }

        static string trimEnd(string &sentence){
            for(int i=sentence.length()-1 ; i > 0 ; i--){
                if(sentence[i] != ' ') return sentence.erase(i+1);
            }

            sentence.clear();
            return sentence;
        }

        string trimEnd(){
            return trimEnd(_value);
        }

        static string trim(string &sentence){
            trimEnd(sentence);
            trimStart(sentence);
            return sentence;
        }

        string trim(){
            return trim(_value);
        }

        static int length(const string &sentence)
        {
            return sentence.length();
        }

        int length()
        {
            return length(_value);
        }
};