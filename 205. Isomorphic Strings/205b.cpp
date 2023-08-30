/*
unordered_map поможет, если размер алфавита большой: например, на вход подается не строка, а vector<int> --> int может быть любой --> 
unordered_map сильно поможет если размер строки значительно меньше чем есть разных варинатов
*/

class Solution {

public:

 bool isIsomorphic(const string& s, const string& t) { 

   assert(s.size() == t.size());
   unordered_map<char, char> sToT;
   unordered_map<char, char> tToS;

   for (size_t i = 0; i < s.size(); i++) {

     char sc = s[i];
     char tc = t[i];
     auto si = sToT.find(sc);
     auto ti = tToS.find(tc);

     if (si == sToT.end() && ti == tToS.end()) { 
       sToT[sc] = tc;
       tToS[tc] = sc;
     } else if (si == sToT.end() || ti == tToS.end()) {    
       return false;
     } else if (si->second == tc && ti->second == sc) {  
       // ok
     } else {
       return false;
     }
   }

   return true;
 }
};

