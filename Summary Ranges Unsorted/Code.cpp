    vector<vector<int>> compressArray(const vector<int>& arr) {
        
        // Преобразуем массив в множество для O(1) доступа
        unordered_set<int> NumUnSet(arr.begin(), arr.end());
        vector<vector<int>> result;

        for (int num : arr) {

            if(NumUnSet.empty()){
                break;
            }

            // Если текущий элемент уже удален из множества, пропускаем
            if (NumUnSet.find(num) == NumUnSet.end()) {
                continue;
            }

            // Ищем границы последовательности
            int left = num;
            int right = num;

            for (;NumUnSet.find(left - 1) != NumUnSet.end(); left--);

            for (; NumUnSet.find(right + 1) != NumUnSet.end(); right++);

            // Добавляем последовательность в результат
            for (int i = left; i <= right; ++i) {

                NumUnSet.erase(i); // Удаляем элементы из множества
            }

            result.push_back(
                (left == right ? vector<int>({left}) : vector<int>({left, right}) )
            );
        }

        return result;
    }
