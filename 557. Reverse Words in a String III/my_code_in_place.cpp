class Solution {
public:
    string reverseWords(string s) {
    
    int IdxStartWord = 0;
    for(int i = 0; i < s.size();++i){

      if(s[i] == ' '){
        reverse(s.begin() + IdxStartWord, s.begin() + i); // правая граница должна указывать за границу, т.е. разорачивается полуинтервал: [s.begin() + IdxStartWord, s.begin() + i)
        IdxStartWord = i + 1;
      }
    }

        // на случай если в s одно слово, также ввиду того, что в конце s не пробелов, т.е. не развернули последнее слово в s
    reverse(s.begin() + IdxStartWord, s.end());
    return s;
    }
};
