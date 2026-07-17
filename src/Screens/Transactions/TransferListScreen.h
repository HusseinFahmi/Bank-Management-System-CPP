#pragma once

#include "../Screen.h"
#include "../../Domain/TransferRecord.h"
#include "../../Repository/TransferRepository.h"

class TransferListScreen: protected Screen{
    private:

        static void _printUserRecordLine(TransferRecord& record){
            cout << "| " << setw(30) << left << record.getDateTime();
            cout << "| " << setw(15) << left << record.getSourceAccount();
            cout << "| " << setw(15) << left << record.getDestinationAccount();
            cout << "| " << setw(20) << left << record.getAmount();
            cout << "| " << setw(20) << left << record.getUserName();
        }

        static void _print(vector<TransferRecord> records){
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";
            cout << "| " << left << setw(30) << "DateTime";
            cout << "| " << left << setw(15) << "Sender";
            cout << "| " << left << setw(15) << "Reciever";
            cout << "| " << left << setw(20) << "Amount";
            cout << "| " << left << setw(20) << "UserName";
            cout << "\n_____________________________________________________________________________________________________________________________________\n\n";

            if(records.size() <= 0)
                cout << "\t\t\tNo records available in the system! \t\n";
            else
                for (TransferRecord &record : records)
                {
                    _printUserRecordLine(record);
                    cout << endl;
                }
            cout << "_____________________________________________________________________________________________________________________________________\n\n";
        }

    public:
        static void TansferListScreen(){
            _drawScreenHeader("\t Transfer List Screen");
            vector<TransferRecord> records = TransferRepository::getAll();

            _print(records);
        }
};