class Solution {

public:

    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;
    
    void DFS(vector<string>& mergedAccount, const string& email) {
        visited.insert(email);                
        
        for (string& neighbor : adjacent[email]) {

            if (visited.find(neighbor) == visited.end()) {
                DFS(mergedAccount, neighbor);
            }

        }

        mergedAccount.push_back(move(email));
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        int accountListSize = accountList.size();
        
         for (vector<string>& account : accountList) {
            
            const string accountFirstEmail = account[1];
            for (int j = 2; j < account.size(); j++) {
                string email = account[j];
                
                adjacent[email].push_back(accountFirstEmail);
                adjacent[accountFirstEmail].push_back(move(email));
            }
        }
        
        vector<vector<string>> mergedAccounts;
        for (vector<string>& account : accountList) {
            string accountName = account[0];
            const string accountFirstEmail = account[1];
            
            if (visited.find(accountFirstEmail) == visited.end()) {
                vector<string> mergedAccount;

                mergedAccount.push_back(move(accountName));
                DFS(mergedAccount, accountFirstEmail);

                sort(mergedAccount.begin() + 1, mergedAccount.end());
                mergedAccounts.push_back(move(mergedAccount));
            }
        }
        
        return mergedAccounts;
    }
};
