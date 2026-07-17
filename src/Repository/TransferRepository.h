#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../Domain/BankClient.h"
#include "../Lib/String.h"

#include "../Domain/TransferRecord.h"

using namespace std;

class TransferRepository{
    private:
        static const string _transfersLogFile() {
            return "../Data/TransfersLog.txt";
        }

        static string _toLine(TransferRecord record){
            string delim = "#//#";
            return record.getDateTime() + delim + record.getSourceAccount() + delim + record.getDestinationAccount() + delim + to_string(record.getAmount()) +  delim + record.getUserName();
        }


        static void _addLineToFile(string line){
            fstream file;
            file.open(_transfersLogFile() , ios::out | ios::app);

            if(!file.is_open()) return;

            file << line << "\n";
            file.close();
        }

        static TransferRecord _fromLine(const string& line , string delim = "#//#"){
            vector<string> fields = String::split(line,delim);

            if(fields.size() < 5) return TransferRecord("","","",0.0,"");
            return TransferRecord(fields[0],fields[1],fields[2],stod(fields[3]),fields[4]);
        }


        public:
            static void addLog(TransferRecord& record){
                string line = _toLine(record);

                _addLineToFile(line);
            }

            static vector<TransferRecord> getAll(){
                vector<TransferRecord> records;

                fstream file;
                file.open(_transfersLogFile(), ios::in);

                if(!file.is_open()) return {};

                string line;

                while(getline(file,line)){
                    if(!line.empty()){
                        TransferRecord record = _fromLine(line);
                        records.push_back(record);
                    }
                }

                file.close();
                return records;
            }
};