/*
Time complexity: O(N) * O(3^0 + ... + 3^N) * O(3) = O(N) * O(3^N)
Space complexity: O(N*3^N)
*/
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

    for (const char d : digits) { // основной цикл
      vector<string> temp;
      for (const string& s : ans){ // для добавлениях новых букы
        for (const char c : digitToLetters[d - '0']){ // цикл по буквам, которые будут добавлен, т.к. digitToLetters[d - '0'] изоморф. d
            temp.push_back(s+c);
        }
      }
          
      ans = move(temp);
    }

    return ans;
  }
};
