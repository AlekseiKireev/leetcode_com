class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int target) {
        
        if(arr.size() == k){return arr;}

        function<bool(int, int)>  Operator = [target](const int a, const int b){

            assert(a <= b);
            return target - a <= b - target;
        };

		int left = 0;
		int right = (int)arr.size() - k; // если не делать " - k" затруднительно написать условие выхода из while
        cout << right  << '\n';
		
        while (1 != right - left + 1) { // ищем самую оптимальную левую границу до тех пор, пока  right и left не станут указывать на один и тот же элемент
            
            assert(left < right); // --> может сделать "+1" в "left = mid + 1" и не выйти за грницу right
            const int mid = left + (right - left) / 2;
            
            // target - arr[mid] > arr[mid + k] - target <--> префикс {..., arr[mid]} не должен быть в ответе --> сдвигаем указатель на arr[mid + 1] ввиду требования оптимизации left
            // target - arr[mid] <= arr[mid + k] - target <--> постфикс {arr[mid + k], ...} не должен быть в ответе --> сдвигаем right левее, до mid. При этом right = mid - 1 будет ошибочным, так как mid может равняться 0, да и смысла в этом нет, ибо оптимизируем левую границу
            Operator(arr[mid], arr[mid + k]) ?  right = mid : left = mid + 1; // why "+1"?!

            assert(left <= right); 
            cout << mid << ' ' << left << ' ' << right  << '\n';
        }

        return {arr.begin() + left, arr.begin() + left + k};        
    }
};
