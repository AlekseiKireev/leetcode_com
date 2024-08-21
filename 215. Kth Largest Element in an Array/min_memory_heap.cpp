class Solution {

public:

    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> p_q;

        for(int num : nums){

            p_q.push(num);

            if(p_q.size() > k){
                p_q.pop();
            }
            

        }

        return p_q.top();

    }

};
