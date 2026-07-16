#pragma once
#include <iostream>
#include <fstream>
#include "../Domain/LoginRegister.h"

#include "../Lib/String.h"

class LoginRegisterRepository{
    private:
        static std::string _convertLoginObjectToLine(LoginRegister loginRegister , const std::string delim = "#//#"){
            return loginRegister.getDateTime() + delim + loginRegister.getUserName() + delim + std::to_string(loginRegister.getPermissions()) +  delim + std::to_string(loginRegister.getLoginStatus());
        }

        static std::string _loginRegisterFilePath(){
            return "../Data/LoginRegister.txt";
        }

        static LoginRegister _convertLineToLoginObject(const string &line , std::string delim = "#//#"){
            vector<string>fields = String::split(line,delim);


            return LoginRegister(fields[0],fields[1],stoi(fields[2]),LoginRegister::LoginStatus(stoi(fields[3])));
        }

    public:
        static void addLog(LoginRegister& loginRegister){
            std::fstream file;
            file.open(_loginRegisterFilePath() , std::ios::out | std::ios::app);

            if(!file.is_open()) return;

            file << _convertLoginObjectToLine(loginRegister) << "\n";

            file.close();
        }

        static vector<LoginRegister> getAll(){
            vector<LoginRegister> logs;

            fstream file;

            file.open(_loginRegisterFilePath(),ios::in);
            if(!file.is_open()) return {};

            string line;

            while(getline(file,line)){
                if(!line.empty()){
                    LoginRegister log = _convertLineToLoginObject(line);
                    logs.push_back(log);
                }
            }

            file.close();
            return logs;
        }
};