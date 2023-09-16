class Solution {

 int firstIndex(const vector<int>& a, int target) { 
   int left = -1;
   int right = (int)a.size();
   while (left + 1 < right) {
     int mid = (left + right) / 2;
     if (a[mid] < target) {
       left = mid;
     } else {
       right = mid;
     }
   }
   return right; // target <= a[right]
 }

 int lastIndex(const vector<int>& a, int target) { 
   int left = -1;
   int right = (int)a.size();
   while (left + 1 < right) {
     int mid = (left + right) / 2;
     if (a[mid] <= target) {
       left = mid;
     } else {
       right = mid;
     }
   }
   return left; // a[left] <= target
 }

public:

 vector<int> searchRange(const vector<int>& a, int target) { 
   int first = firstIndex(a, target);
   if (first == (int)a.size() || a[first] != target) { 
     return {-1, -1};
   }
   int last = lastIndex(a, target);
   return {first, last};
 }
};
