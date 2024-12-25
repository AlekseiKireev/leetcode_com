class Solution {

 public:
  vector<string> letterCombinations(string digits) {
    
    if (digits.empty()){
        return {};
    }
      
    // инициализация пустой строкой нужна чтобы войти в цикл for (string& s : ans){
    // позже она затрется при ans = move(temp);
    vector<string> ans{""}; 
    const vector<string> digitToLetters{"",    "",    "abc",  "def", "ghi",
                                        "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for (const char d : digits) {
      vector<string> temp;
      for (const string& s : ans){
        for (const char c : digitToLetters[d - '0']){
            temp.push_back(s+c);
        }
      }
          
      ans = move(temp);
    }

    return ans;
  }
};
