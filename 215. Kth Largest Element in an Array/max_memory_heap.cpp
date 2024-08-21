class Solution {

public:

    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, less<int>> p_q (nums.begin(), nums.end());

        for(int i = 0; i < k - 1; ++i){

            p_q.pop();

        }

        return p_q.top();

    }

};
