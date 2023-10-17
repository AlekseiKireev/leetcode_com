#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {

private:

	struct PairHash {
		size_t operator()(const pair<int, int> p) const { // передавать pair<int, int> по ссылке или нет?

			return (size_t)(h_i_1(p.first) * 37 * 37 + h_i_1(p.second) * 37 + 117);
		}
		hash<int> h_i_1;
		hash<int> h_i_2;
	};


	// тип cnt <-- "-108 <= points[i][j] <= 10^8"
	 // "const" будет ошибкой, так как можем обратится к несущест-у элементу в "PointToExist[{cnt - point[0], point[1]}]"
	bool CheckCoordinate(const vector<vector<int>>& points, /*const*/ unordered_map<pair<int, int>, bool, PairHash>& PointToExist, const int cnt/* = x_min + x_max*/) {
		for (/*const*/ auto point : points) { // "const" будет ошибкой, так как можем обратится к несущест-у элементу в "PointToExist[{cnt - point[0], point[1]}]"

			if (!PointToExist[{cnt - point[0], point[1]}]) { return false; }
		}
		return true;
	}

	/*
	Если расположить PairHash ниже CheckCoordinate, то в MSVS будет ошибка: Error (active)	E0308	more than one instance of overloaded function "CheckCoordinate" matches the argument list:
	*/

public:

    bool isReflected(const vector<vector<int>>& points) {
		if (points.empty()) { return true; } // проверка пустого points -- такой тест есть в тестирующей системе
		int x_min = points.front().front();
		int x_max = points.back().front();
		unordered_map<pair<int, int>, bool, PairHash> PointToExist; // необходимо для реализации CheckCoordinate

		for (const auto& point : points) {

			const int x = point[0];
			const int y = point[1];
			x_min = min(x_min, x);
			x_max = max(x_max, x);
			if (!PointToExist[{x, y}]) { PointToExist[{x, y}] = true; }

		} // отрезок, проходящий через (x_min, y*) и (x_max, y*) будет иметь максимальную длину. Примечательно, что не получатся рассуждения через поиск концов отрезка минимальной длины!

		//if(PointToExist.size() % 2 == 1){return false;} // error: { {0,0} } true
		return CheckCoordinate(points, PointToExist, x_min + x_max);
    }

};

int main() {

	cout << Solution().isReflected({ {1,1},{-1,1} }) << '\n';
	cout << Solution().isReflected({ {1,1},{-1,-1} }) << '\n';
	cout << Solution().isReflected({ {0,0} }) << '\n';

}
