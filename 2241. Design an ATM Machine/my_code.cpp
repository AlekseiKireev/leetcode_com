const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class ATM {

private:

array<size_t, 5> BankAccount;
const array<int, 5> denominations = {20, 50, 100, 200, 500};

public:
    
    // конструктор занимается выделением памяти для контейнеров в приватной секции
    ATM() {BankAccount.fill(0);}
    

    void deposit(const vector<int>& banknotesCount) { // "Deposits new banknotes in the order $20, $50, $100, $200, and $500."
        
       for(int i = 0 ; i < 5 ; ++i){BankAccount[i] += banknotesCount[i];}

    }
    
    
    vector<int> withdraw(int amount) { // "When withdrawing, the machine prioritizes using banknotes of larger values."
        
        if(amount % 10 || amount < 20){return {-1};}


        vector<int> WithdrawBanknotes(5);
        const array<size_t, 5> CopyBankAccount = BankAccount;

        for(int i = 4 ; i >= 0 ; --i){

            size_t Count = amount / denominations[i];

            Count = min(Count, BankAccount[i]); // либо Count <= BankAccount[i], тогда списываем ВЕСЬ необходимый Count, либо Count > BankAccount[i], тогда придется брать из остальных номиналов 
            amount -= Count * denominations[i];

            WithdrawBanknotes[i] = Count;
            BankAccount[i] -= Count;

            if(amount == 0) {return WithdrawBanknotes;}
        }

        BankAccount = CopyBankAccount;
        return {-1}; // <-- "Returns [-1] if it is not possible (do not withdraw any banknotes in this case)."
        
        
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
