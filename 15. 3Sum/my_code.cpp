class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> Triplets;

        sort(nums.begin(), nums.end());

        if(nums.front() > 0 || nums.back() < 0 ){return Triplets;}


        //  nums.size() - 2 <-- "3 <= nums.length <= 3000"
        for(int i = 0; i < nums.size() - 2; ++i){ 

            if(i > 0 && nums[i - 1] == nums[i]){ // если текущий элемент nums[i] равен предыдущему, то по нему не собираем статистику, так как вся возможная статистика была учтена при обработке nums[i - 1]
                continue;
            }

            for(int j = i + 1; j < nums.size() - 1; ++j){
               
                const int Target = nums[i] + nums[j];
                if(Target > 0){break;}
                
                int k = nums.size() - 1;
                for(; j + 1 != k && Target + nums[k] > 0; --k); // j + 1 != k // ОБЪЯСНИТЬ!
                if(Target + nums[k] == 0){
                    cout << "push_back " << i  << ' ' << j << ' '<< k  << '\n';
                    Triplets.push_back({nums[i], nums[j], nums[k]});}
            }

        }


        return Triplets;
    }
};
