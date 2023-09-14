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
            if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0) {continue;}
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {return Triplets;}

            int k = nums.size() - 1; // необходим в этой области видимости для ограничения на j сверху
            for(int j = i + 1; j < k; ++j){
               
                const int Target = nums[i] + nums[j];
                if(Target > 0){break;}
                
                
                for(; j + 1 != k && Target + nums[k] > 0; --k); // j + 1 != k // ОБЪЯСНИТЬ!
                if(Target + nums[k] == 0/* &&(Triplets.empty() || Triplets.back() != vector<int>{nums[i], nums[j], nums[k]})*/){ // либо  &&(Triplets.empty() || Triplets.back() != vector<int>{nums[i], nums[j], nums[k]}), либо  while(j + 1 != k && nums[j] == nums[j + 1]){++j;}
                    Triplets.push_back({nums[i], nums[j], nums[k]});
                }

                /* если для (i,j,k) ВЫПОЛНЯЕТСЯ требуемое, то ввиду того что i -- фиксированно, j уже найдено --> может быть только одно k = -i-j, то нет смысла 
                   проверять nums[j] == nums[j + 1], так как получим тот же самый результат*/
                /* если для (i,j,k) НЕ ВЫПОЛНЯЕТСЯ, то ввиду того что i -- фиксированно, для заданного j уже проверенно, что нет подходящих k , то нет смысла 
                   проверять nums[j] == nums[j + 1], так как получим тот же самый результат*/
                while(j + 1 != k && nums[j] == nums[j + 1]){++j;} // если закомментировать будет ошибка: Wrong Answer 79 / 312 testcases passed nums = [0,0,0,0] Expected[[0,0,0]]
                
                
                // while(j != k + 1 && nums[k-1] == nums[k]){--k;} // если раскомментировать будет ошибка: Wrong Answer 261 / 312 testcases passed Input nums = [-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0] Expected[[-5,1,4],[-4,0,4],[-4,1,3],[-2,-2,4],[-2,1,1],[0,0,0]]
            }

        }

        return Triplets;
    }
};
