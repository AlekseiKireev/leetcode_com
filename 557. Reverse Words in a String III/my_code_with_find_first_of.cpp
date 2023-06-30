class Solution {
public:
    string reverseWords(string s) {
    
    int left = 0;
    while (true) {
      
      int idx = s.find_first_of(' ', left);

      int right = idx;
      if (idx == string::npos) {right = s.size();} // крайний случай, когда пробелов в слове больше нет
      reverse(s.begin() + left, s.begin() + right);
      
      if (idx == string::npos) {break;}

      left = idx + 1;
      
    }

    return s;
    }
};
