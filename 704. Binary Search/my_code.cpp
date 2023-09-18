class Solution {

	const int ZERO = []() {

		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		return 0;

	}();

public:

	int search(const vector<int>& a, int target) {

		if (a.back() < target || target < a.front()) { return -1; } // если этот условный оператор не сработал, то гарантируется, что a[left] / a[right] существует
		
		// left и right -- противоположные инварианты: a[left] < target, a[right] >= target --> ответ будет right или -1
		int left = -1;
		int right = (int)a.size();

		/*
		//2 / 47 testcases passed
		//nums = [5] 
		//target = 5
  		int left = 0;
		int right = a.size() - 1;
		*/
		
		// right - left - 1 == количество элементов в интервале (left, right)
		while (1 != right - left) { // <-->  1 < right - left <--> цикл до тех пор, пока left + 1 != right -- 
					    // то есть пока не дошли до соседних гранично-инвариантных индексов, пока между left и right есть хотя бы один элемент
			int mid = (left + right) / 2;

			if (target <= a[mid]) {
				right = mid;
			}
			else {
				left = mid;
			}
		}

		return (a[right] != target) ? -1 : right;

	}

};
