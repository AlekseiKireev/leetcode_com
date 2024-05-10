class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int target) {
        
        function<bool(int, int)>  Operator = [target](const int a, const int b){

            assert(a <= b);
            return target - a <= b - target;
        };

		int left = 0;
		int right = (int)arr.size() - 1;

		while (k != right - left + 1) { Operator(arr[left], arr[right]) ?  --right : ++left; }

        return {arr.begin() + left, arr.begin() + right + 1};        
    }
};
