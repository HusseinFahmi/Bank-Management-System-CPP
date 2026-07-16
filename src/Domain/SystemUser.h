#pragma once

#include "Person.h"


class SystemUser: public Person{

    public:
        enum Mode{EmptyMode = 1 , UpdateMode = 2 , AddNewMode = 3 , DeleteMode = 4};
        enum Permissions {readPermission = 1, writePermission = 2, deletePermission = 4, updatePermission = 8, findPermission = 16, manageUsersPermission = 32, transactionPermission = 64, allPermissions = -1 , ShowLoginRegister = 128};

    private:
        Mode _mode;
        string _userName;
        string _password;
        int _permissions;
        bool _markForDelete = false;
    
    public:

        SystemUser():Person(),_mode(Mode::EmptyMode),_userName(""),_password(""),_permissions(0){}

        SystemUser(string firstName , string lastName , string email , string phone , Mode mode , string userName , string password , int permissions):
        Person(firstName,lastName,email,phone),
        _mode(mode),
        _userName(userName),
        _password(password),
        _permissions(permissions){}

        void setMode(const Mode mode){
            _mode = mode;
        }

        void setUserName(const string& userName){
            _userName = userName;
        }

        void setPassword(const string& password){
            _password = password;
        }

        void setpermissions(const int permissions){
            _permissions = permissions;
        }

        void setMarkForDelete(const bool markForDelete){
            _markForDelete = markForDelete;
        }

        Mode getMode() const{
            return _mode;
        }

        string getUserName() const{
            return _userName;
        }

        string getPassword() const{
            return _password;
        }

        int getPermissions() const{
            return _permissions;
        }

        bool isMarkedForDelete() const{ 
            return _markForDelete; 
        }

        bool isEmptyMode() const{
            return _mode == Mode::EmptyMode;
        }

        static SystemUser getEmptyObject(){
            return SystemUser();
        }

        static SystemUser create(const string userName){
            return SystemUser("","","","",Mode::AddNewMode,userName,"",0);
        }
};