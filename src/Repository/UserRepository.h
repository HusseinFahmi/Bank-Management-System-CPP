#pragma once

#include <vector>
#include <fstream>

#include "../Domain/SystemUser.h"
#include "../Lib/String.h"

class UserRepository{
    private:
        static const string _usersFilePath(){
            return "../Data/Users.txt";
        }

        static SystemUser _convertLineToUserObject(const string& line , string delim = "#//#"){
            vector<string> fields = String::split(line,delim);

            if(fields.size() < 7) return SystemUser::getEmptyObject();

            return SystemUser(fields[0],fields[1],fields[2],fields[3],SystemUser::Mode::UpdateMode,fields[4],fields[5],stoi(fields[6]));
        }

    public:
        static vector<SystemUser> getAllUsers(){

            vector<SystemUser> users;
            fstream file;

            file.open(_usersFilePath(),ios::in);
            if(!file.is_open()) return {};

            string line;

            while(getline(file,line)){
                if(!line.empty()){
                    SystemUser user = _convertLineToUserObject(line);
                    users.push_back(user);
                }
            }

            file.close();

            return users;
       }
};