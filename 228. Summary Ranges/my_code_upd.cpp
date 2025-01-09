/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans; 

        for(int RightPtr = 0; RightPtr < nums.size(); ++RightPtr){
            
            const int LeftPtr = RightPtr;

            // послденяя итерация цикла когда RightPtr+1 == nums.size() - 1 -->
            // ++RightPtr и RightPtr указывает на nums.size() - 1 --> RightPtr+1 = nums.size() - выход цз цикла
            for(;RightPtr+1 < nums.size() && nums[RightPtr] == nums[RightPtr+1] - 1; ++RightPtr); 

            if(LeftPtr == RightPtr){
                ans.push_back(to_string(nums[LeftPtr])); 
            }else{
                ans.push_back(to_string(nums[LeftPtr]) + "->" + to_string(nums[RightPtr])); 
            }
        }

        return ans;
    }
};

/*
A+0     A+1     A+2     A+3
L
R

A+0     A+1     A+2     A+3
L
        R 

A+0     A+1     A+2     A+3
L
                R       R+1 == N.size()-1

A+0     A+1     A+2     A+3     NULL or A + k : k > 4
L
                        R       R+1 == N.size()                            
*/

/*
class Solution {
public:
    vector<string> summaryRanges(vector<int>& N) {
        
        vector<string> A;

        for(int L = 0; L < N.size(); ){

            int R = L;
            for(;R + 1 < N.size() && N[R] == N[R + 1] - 1; ++R);
            

            if(L == R){
                A.push_back(to_string(N[L]));
            }else{
                A.push_back(to_string(N[L]) + "->" + to_string(N[R]));
            }
            L = R + 1;
        }

        return A;
    }
};
*/
