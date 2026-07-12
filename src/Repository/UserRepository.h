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

        static string _convertUserObjectToLine(SystemUser& user){
            const string delim = "#//#";
            return user.getFirstName() + delim + user.getLastName() + delim + user.getEmail() + delim + user.getPhone() + delim + user.getUserName() + delim + user.getPassword() + delim + to_string(user.getPermissions());
        }

        static void _addLineToFile(string line){
            fstream file;
            file.open(_usersFilePath(),ios::app);

            if(!file.is_open()) return;

            file << line << "\n";
            file.close();
        }

        static bool _add(SystemUser& user){
            _addLineToFile(_convertUserObjectToLine(user));
            user.setMode(SystemUser::Mode::UpdateMode);
            return true;
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

        static SystemUser find(const string& userName){
            fstream file;

            file.open(_usersFilePath(),ios::in);

            if(!file.is_open()) return SystemUser::getEmptyObject();

            string line;

            while(getline(file,line)){
                if(!line.empty()){
                    SystemUser user = _convertLineToUserObject(line);

                    if(user.getUserName() == userName){
                        file.close();
                        return user;
                    }
                }
            }

            file.close();
            return SystemUser::getEmptyObject();
        }

        static bool save(SystemUser& user){
            switch (user.getMode()){
                case SystemUser::Mode::EmptyMode:
                return false;

                case SystemUser::Mode::AddNewMode:
                    _add(user);
                return true;
            
            default:
                break;
            }
            return false;
        }
};