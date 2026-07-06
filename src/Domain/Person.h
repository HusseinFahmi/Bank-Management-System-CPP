#pragma once 

#include <string>

using namespace std;

class Person{
    private:
        string _firstName;
        string _lastName;
        string _email;
        string _phone;
        
    public:
        Person(): _firstName(""), _lastName(""), _email(""), _phone(""){}

        Person(string firstName , string lastName , string email , string phone):
        _firstName(firstName),
        _lastName(lastName),
        _email(email),
        _phone(phone){}

        // Setters

        void setFirstName(string firstName) {
            _firstName = firstName;
        }

        void setLastName(string lastName) {
            _lastName = lastName; 
        }

        void setEmail(string email) {
            _email = email; 
        }

        void setPhone(string phone) {
            _phone = phone;
        }

        // Getters

        string getFirstName(){ 
            return _firstName; 
        }

        string getLastName(){ 
            return _lastName; 
        }

        string getEmail(){ 
            return _email; 
        }

        string getPhone(){ 
            return _phone; 
        }

        string getFullName(){ 
            return _firstName + " " + _lastName; 
        }



};