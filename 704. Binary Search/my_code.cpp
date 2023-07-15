class Solution {

	const int ZERO = []() {

		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		return 0;

	}();

public:

	int search(const vector<int>& a, int target) {

		if (a.back() < target || target < a.front()) { return -1; }
		
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
		
		// примечательно также то, что данная реализация будет работать для пустого массива
		while (1 != right - left) { // <-->  1 < right - left <--> цикл до тех пор, пока left + 1 != right -- 
					    // то есть пока не дошли до соседних гранично-инвариантных индексов, пока расстояние между left и right не равно 1
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
