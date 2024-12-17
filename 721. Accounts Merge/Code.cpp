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

        // Add the email vector that contains the current component's emails
        mergedAccount.push_back(move(email));
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        int accountListSize = accountList.size();
        
         for (vector<string>& account : accountList) {
            
            // Building adjacency list. Adding edge between first email to all other emails in the account
            // account[0] == name
            const string accountFirstEmail = account[1];
            for (int j = 2; j < account.size(); j++) {
                string email = account[j];
                
                adjacent[email].push_back(accountFirstEmail);
                adjacent[accountFirstEmail].push_back(move(email));
            }
        }
        
        // Traverse over all th accounts to store components
        vector<vector<string>> mergedAccounts;
        for (vector<string>& account : accountList) {
            string accountName = account[0];
            const string accountFirstEmail = account[1];
            
            // If email is visited, then it's a part of different component
            // Hence perform DFS only if email is not visited yet
            if (visited.find(accountFirstEmail) == visited.end()) {
                vector<string> mergedAccount;
                // Adding account name at the 0th index
                mergedAccount.push_back(move(accountName));
                DFS(mergedAccount, accountFirstEmail);
                // Skip the first element (name)
                // Name should be the first element, we only need to sort the emails:
                // "the first element of each account is the name, and the rest of the elements are emails in sorted order. 
                // The accounts themselves can be returned in any order."
                sort(mergedAccount.begin() + 1, mergedAccount.end());
                mergedAccounts.push_back(move(mergedAccount));
            }
        }
        
        return mergedAccounts;
    }
};
