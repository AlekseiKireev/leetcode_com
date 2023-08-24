class Solution {
public:
   vector<int> intersect(vector<int>& a, vector<int>& b) { 
     sort(a.begin(), a.end());
     sort(b.begin(), b.end()); 
      
     size_t ia = 0;
     size_t ib = 0;
      
     vector<int> ans;
      
     while (ia < a.size() && ib < b.size()) {
       if (a[ia] < b[ib]) {
          ia++;
       } else if (b[ib] < a[ia]) {
          ib++;
       } else { // a[ia] == b[ib]
          ans.push_back(a[ia]);
          ia++; 
          ib++;
     } 
}
     return ans;
   }
} ;
/*
class Solution {
public:
   vector<int> intersect(vector<int>& a, vector<int>& b) { 
     sort(a.begin(), a.end());
     sort(b.begin(), b.end()); 
      
     size_t ia = 0;
     size_t ib = 0;
      
     vector<int> ans;
      
     while (ia < a.size() && ib < b.size()) { // <--> https://en.cppreference.com/w/cpp/algorithm/set_intersection

       if(a[ia] == b[ib]){
          ans.push_back(a[ia]);
          ia++; 
          ib++;
       } else{
         (a[ia] < b[ib]) ? ia++ : ib++;
       }

     } 

     return ans;
   }
};
*/
