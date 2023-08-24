class Solution {

struct Pair{
   int num;
   bool present;
};

public:

   vector<int> intersect(const vector<int>& aa, const vector<int>& bb) { 
     const vector<int> &a = aa.size() < bb.size() ? aa : bb;
     const vector<int> &b = aa.size() < bb.size() ? bb : aa; 

      vector<Pair> pairs; pairs.reserve(a.size());

      for(int v : a){pairs.push_back({v, true});}

      sort(pairs.begin(), pairs.end(), [](const Pair &left, const Pair &right) { 
      return left.num < right.num;
       });

     vector<int> ans;
     for (int v : b) {
        
        auto it = lower_bound(
           pairs.begin(),
           pairs.end(),
           v,
           [](const Pair &p, int v) { // "Iterator pointing to the first element in the range [first, last) such that comp(element, value) is false" <-- https://en.cppreference.com/w/cpp/algorithm/lower_bound
           return p.num < v || (p.num == v && !p.present);
           }
        );
       
        if (it != pairs.end() && it->num == v && it->present > 0) { 
           ans.push_back(v);
            it->present = false;
        }
        
     }
     return ans;
  }
};
