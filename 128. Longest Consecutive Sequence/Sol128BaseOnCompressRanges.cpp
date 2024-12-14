class Solution {

private:
    
    int compressArray(const vector<int>& arr) {
        
        int Ans = 1; 

        // Преобразуем массив в множество для O(1) доступа
        unordered_set<int> numSet(arr.begin(), arr.end());

        for (int num : arr) {

            // Если текущий элемент уже удален из множества, пропускаем
            if (numSet.find(num) == numSet.end()) {
                continue;
            }

            if(numSet.size() <= 1){
                break;
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


            for (int i = left; i <= right; ++i) {

                numSet.erase(i); // Удаляем элементы из множества
            }

            Ans = max(Ans, right - left + 1);
        }

        return Ans;
    }

public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty()){
            return 0;
        }

        return compressArray(nums);

    }
};
