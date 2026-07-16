#pragma once
#include <iostream>
#include <string>

class LoginRegister {
    public:
        enum LoginStatus { Success = 1, Failed = 0 };
    
    private:
        std::string _dateTime;
        std::string _userName;
        int _permissions;
        LoginStatus _loginStatus;

    public:
        LoginRegister():
        _dateTime(""),
        _userName(""),
        _permissions(0),
        _loginStatus(){}

        LoginRegister(std::string dateTime, std::string userName, int permissions, LoginStatus loginStatus):
            _dateTime(dateTime),
            _userName(userName),
            _permissions(permissions),
            _loginStatus(loginStatus){}
        

        void setDateTime(const std::string& dateTime) {
            _dateTime = dateTime;
        }

        void setUserName(const std::string& userName) {
            _userName = userName;
        }

        void setPermissions(int permissions) {
            _permissions = permissions;
        }

        void setLoginStatus(LoginStatus loginStatus) {
            _loginStatus = loginStatus;
        }

        std::string getDateTime() const {
            return _dateTime;
        }

        std::string getUserName() const {
            return _userName;
        }

        int getPermissions() const {
            return _permissions;
        }

        LoginStatus getLoginStatus() const {
            return _loginStatus;
        }
};