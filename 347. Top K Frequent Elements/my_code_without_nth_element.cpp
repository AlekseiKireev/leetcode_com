/*
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if(nums.size() == k){ 
            return nums;
        }   

        unordered_map<int, int> NumToCount; 
        //NumToCount.reserve(nums.size() - 1); // медленно работает, сам. докуменатцию!

        for(int num : nums){
            ++NumToCount[num];
        } 

        vector<vector<int>> CountToNum(nums.size() + 1);

         for(auto [num, cnt] : NumToCount){

            CountToNum[cnt].push_back(num);

         }        

        vector<int> TopK; TopK.reserve(k);

        for(int i = nums.size(); i > 0; --i){
            for(int num : CountToNum[i]){

                if(TopK.size() != k){
                    TopK.push_back(num);
                }

                if(TopK.size() == k) {return TopK;}
            }
            
        }

        return TopK;
    }
};
