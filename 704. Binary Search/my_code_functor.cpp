class Solution {
public:
	int search(const vector<int>& a, int target, function<int(int, int)>  Operator = less_equal<int>()) {

		// 45 / 47 testcases passed nums = [-1] target = 2
		if (a.back() < target || target < a.front()) { return -1; } // теперь можно гарантировать, что a.back() <= target <= a.front() --> left и right не будут указывать за границы исходного массива чисел

		// left и right -- противоположные инварианты: a[left] < target, a[right] >= target --> ответ будет right или -1
		int left = -1;
		int right = (int)a.size();
		// left и right указывают за границы массива с целью обработки случаев: 
		// right == (int)a.size() если a.back() < target
		// left == -1 если target < a.front()
		
		// примечательно также то, что данная реализация будет работать для пустого массива
		// right - left - 1 == количество элементов в интервале (left, right)
		while (2 != right - left + 1) { // <-->  1 < right - left <--> цикл до тех пор, пока left + 1 != right -- 
						// то есть пока не дошли до соседних гранично-инвариантных индексов, пока между left и right есть хотя бы один элемент
			int mid = (left + right) / 2;

			(Operator(target, a[mid])) ? right = mid : left = mid;
			//if (target <= a[mid]) {
			//	right = mid;
			//}
			//else {
			//	left = mid;
			//}
		}

		return (a[right] != target) ? -1 : right; // делаем вывод, что для a[right] записывается инвариант из правдивой ветки условного оператора 
	}
};
