class Solution {

    vector<vector<int>> compressArray(const vector<int>& arr) {
        
        // Преобразуем массив в множество для O(1) доступа
        unordered_set<int> numSet(arr.begin(), arr.end());
        vector<vector<int>> result;

        for (int num : arr) {

            if(numSet.empty()){
                break;
            }

            // Если текущий элемент уже удален из множества, пропускаем
            if (numSet.find(num) == numSet.end()) {
                continue;
            }

            // Ищем границы последовательности
            int left = num;
            int right = num;

            while (numSet.find(left - 1) != numSet.end()) {
                left--;
            }

            while (numSet.find(right + 1) != numSet.end()) {
                right++;
            }

            // Добавляем последовательность в результат
            vector<int> range;
            for (int i = left; i <= right; ++i) {
                //range.push_back(i);
                numSet.erase(i); // Удаляем элементы из множества
            }

            result.push_back(
                (left == right ? vector<int>({left}) : vector<int>({left, right}) )
            );
        }

        return result;
    }

public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty()){
            return 0;
        }
        vector<vector<int>> Ranges = compressArray(nums);

        int Ans = 1; 
        for(auto& Range : Ranges){

            if(Range.size() == 2){
                Ans = max(Ans, Range[1] - Range[0] + 1);
            }
            
        }

        return Ans;

    }
};
