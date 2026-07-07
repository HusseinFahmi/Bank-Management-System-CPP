#pragma once 


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../Domain/BankClient.h"
#include "../Lib/String.h"

using namespace std;

class ClientREpository{
    private:
        static const string _clientsFilePath() {
            return "Data/Clients.txt";
        }

        static BankClient _convertLineToClientObject(const string line){
            string delim = "#//#";
            vector<string> fields = String::split(line,delim);

            if(fields.size() < 7) return BankClient::getEmptyMode();

            return BankClient(fields[0], fields[1], fields[2], fields[3], BankClient::Mode::UpdateMode, fields[4], fields[5], stod(fields[6]));
        }

        static string _convertClientObjectToLine(BankClient client){
            string delim = "#//#";

            return client.getFirstName() + delim + client.getLastName() + delim + client.getEmail() + delim + client.getPhone() + delim + client.getAccountID() + delim + client.getPinCode() + delim + to_string(client.getAccountBalance())    ;
        }

        static void _saveAllClientsToFile(vector<BankClient>& clients){
            fstream file;

            file.open(_clientsFilePath(), ios::out);

            if(!file.is_open()) return;

            for(BankClient& c: clients){
                if(!c.isMarkedForDelete()){
                    string line = _convertClientObjectToLine(c);
                    file << line << "\n";
                }
            }
            file.close();
        }

        static void _addLineToFile(string line){
            fstream file;
            file.open(_clientsFilePath() , ios::app);

            if(!file.is_open()) return;

            file << line << "\n";
            file.close();
        }

        static void _update(BankClient client){
            vector<BankClient> clients = getAllClients();

            for(BankClient&c :clients){
                if(c.getAccountID() == client.getAccountID()){
                    c = client;
                    break;
                }
            }
            _saveAllClientsToFile(clients);
        }

        static bool _add(BankClient& client){
            if(isExist(client.getAccountID())) return false;

            _addLineToFile(_convertClientObjectToLine(client));
            client.setMode(BankClient::Mode::UpdateMode);
            return true;
        }


        public:
            static vector<BankClient> getAllClients(){
                vector<BankClient> clients;

                fstream file;
                file.open(_clientsFilePath(), ios::in);

                if(!file.is_open()) return;

                string line;

                while (getline(file,line))
                {
                    if(!line.empty()){
                        BankClient client = _convertLineToClientObject(line);
                        clients.push_back(client);
                    }
                }
                file.close();

                return clients;
            }

            static BankClient find(const string& accountID){
                fstream file;
                file.open(_clientsFilePath() , ios::in);

                if(!file.is_open()) return;

                string line;

                while(getline(file,line)){
                    if(!line.empty()){
                        BankClient client = _convertLineToClientObject(line);

                        if(client.getAccountID() == accountID){
                            file.close();

                            return client;
                        }
                    }
                }
                file.close();
                return BankClient::getEmptyMode();
            }

            static bool isExist(const string& accountID){
                BankClient client = find(accountID);
                return !client.isEmptyMode();
            }

            static bool save(BankClient& client){

                switch (client.getMode())
                {
                    case BankClient::Mode::EmptyMode:
                        return false;
                    
                    case BankClient::Mode::UpdateMode:
                        _update(client);
                    return true;

                    case BankClient::Mode::AddNewMode:
                        _add(client);
                    return true;

                    return false;
                }
            }

            static bool deleteClient(BankClient& client){
                if(client.isEmptyMode()) return false;

                vector<BankClient> clietns = getAllClients();

                for(BankClient& c : clietns){
                    if(c.getAccountID() == client.getAccountID()){
                        c.setMarkForDelete(true);
                        break;
                    }
                }

                _saveAllClientsToFile(clietns);
                client = BankClient::getEmptyMode();
                return true;
            }



};


