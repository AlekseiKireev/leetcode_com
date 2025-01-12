class Solution {

public:

    unordered_set<string> visited;
    unordered_map<string, vector<string>> FirstEmailToChild;
    vector<string> mergedAccount;

    void DFS(const string& email) {
        visited.insert(email);                
        
        for (string& neighbor : FirstEmailToChild[email]) {

            if (visited.count(neighbor) == 0) {
                DFS(neighbor);
            }

        }

        mergedAccount.push_back(email);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        
         for (vector<string>& account : accountList) {
            
            for (int j = 2; j < account.size(); j++) {
                
                FirstEmailToChild[account[j]].push_back(account[1]);
                FirstEmailToChild[account[1]].push_back(account[j]);
            }
        }
        
        vector<vector<string>> mergedAccounts;
        for (vector<string>& account : accountList) {
            
            if (visited.count(account[1]) == 0) {
                
                mergedAccount.push_back(account[0]);

                DFS(account[1]);

                sort(mergedAccount.begin() + 1, mergedAccount.end());
                mergedAccounts.push_back(move(mergedAccount));
            }
        }
        
        return mergedAccounts;
    }
};
