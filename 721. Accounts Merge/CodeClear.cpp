/*
Here N is the number of accounts and K is the maximum length of an account.

Time complexity: O(NKlogNK)    
Space complexity: O(NK)
*/

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

            const string accountFirstEmail = account[1];
            
            if (visited.find(accountFirstEmail) == visited.end()) {
                vector<string> mergedAccount;

                mergedAccount.push_back(move(account[0]));
                DFS(mergedAccount, accountFirstEmail);

                sort(mergedAccount.begin() + 1, mergedAccount.end());
                mergedAccounts.push_back(move(mergedAccount));
            }
        }
        
        return mergedAccounts;
    }
};
