class Solution {

struct Pair{

   int num;
   int count;
};

public:
   vector<int> intersect(const vector<int>& aa, const vector<int>& bb) { 
     const vector<int> &a = aa.size() < bb.size() ? aa : bb;
     const vector<int> &b = aa.size() < bb.size() ? bb : aa; 

      vector<Pair> pairs; pairs.reserve(a.size());

      for(int v : a){pairs.push_back({v, 1});}

      sort(pairs.begin(), pairs.end(), [](const Pair &left, const Pair &right) { 
      return left.num < right.num;
   });
     
   int last = -1;
   for (int i = 0; i < (int)pairs.size(); i++) {
      if (last >= 0 && pairs[i].num == pairs[last].num) { 
         pairs[last].count++;
      } else {
         last++;
         pairs[last] = pairs[i];
      }
   }
     
   pairs.resize(last + 1);
   vector<int> ans;
     
   for (int v : b) {
      auto it = lower_bound(
         pairs.begin(),
         pairs.end(),
         v,
         [](const Pair &p, int v) {
         return p.num < v;
         }
      );
     
      if (it != pairs.end() && it->num == v && it->count > 0) { 
         ans.push_back(v);
         it->count--;
      }
   }
     
   return ans;
}
};
