class Solution {
public:
	int numSquares(int N) {

		vector<int> DP(N + 1, 101); // DP[i] == наименьшее число слагаемых в кубическом разложении числа i : i \in |N --> искомое == DP.back()
		// заполнение 101 необходимо чтобы хоть раз зайти в "if (DP[i] > DP[i - square] + 1) { DP[i] = DP[i - square] + 1; }"
		DP[0] = 0; // виртуальнео разложение, необходимо чтобы далее удобно работать в натуральных числах

		for (int i = 1; i < N + 1; ++i) {
			
			int square = 1;
			
			for (int step_square = 1; square <= i; ++step_square) {

				if (square == i) { DP[i] = 1; break; }
				if (DP[i] > DP[i - square] + 1) { DP[i] = DP[i - square] + 1; } // ищем наиболее оптимальные предшестчвующие кубические разложения для DP[i] 

				const int power_indicator = 2; // 2 -- степенной показатель, обусловленный условием задачи. При замене его на число k, получаем решение для k-ых степеней
				
         			 square = 1;
				 for (int idx = 0; idx < power_indicator; ++idx) {square *= step_square;}

			}
		}

		return DP.back();
	}
};
/*
https://contest.yandex.ru/contest/45469/problems/21/ -- аналогичная задача для const int power_indicator = 3;
*/
