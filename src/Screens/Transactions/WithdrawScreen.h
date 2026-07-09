#pragma once

#include "TransactionBaseScreen.h"
#include "../../Lib/Util.h"

class WithdrawScreen: protected TransactionBaseScreen{
    public:
        static void showWithdrawScreen(){
            _drawScreenHeader("\t Withdraw screen");

            BankClient client = _getClient();

            _printClientCard(client);
            
            char choice = inputValidator::get_char("\nAre you sure you want to withdraw from this account <y,n>: ",'y','n');
            if(choice == 'n') return;

            double depositAmount = _requestAmount();

            char performTransaction = inputValidator::get_char("\nAre you sure tou want to perform this transaction <y,n>: ",'y','n');
            if(performTransaction == 'n') return;

            BankClient::TransactionResult result = client.withdraw(depositAmount);
            _handleTransactionResult(client,result,"withdraw");

            _printClientCard(client);

            Util::wait();
        }
};