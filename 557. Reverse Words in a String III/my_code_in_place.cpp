class Solution {
public:
    string reverseWords(string s) {
    
    int IdxStartWord = 0;
    for(int i = 0; i < s.size();++i){

      if(s[i] == ' '){
        reverse(s.begin() + IdxStartWord, s.begin() + i);
        IdxStartWord = i + 1;
      }
    }

    reverse(s.begin() + IdxStartWord, s.end());
    return s;
    }
};
