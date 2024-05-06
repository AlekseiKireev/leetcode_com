    int removeDuplicates(vector<int>& nums) {

        long long CountDuplicates = 0;
        for(int i = 1; i < nums.size();++i){

            if(nums[i - 1] != nums[i]){ // смещаем влево. CountDuplicates -- значение того, насколько надо смещать
                // 1 2 3 3 3 4 5 6 6 7 --> 1 2 3 _ _ 4 5 6 6 7 --> 1 2 3 4 5 6 7 _ _ _
                nums[i-CountDuplicates] = nums[i]; // 1 3 2 2 4 5 --> 1 3 2 4 5 _
            }
            else{ //nums[i] == nums[i-1]
                ++CountDuplicates;
            }
        }

        return nums.size() - CountDuplicates;
    }
