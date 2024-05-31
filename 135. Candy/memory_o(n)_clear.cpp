class Solution {
public:
  int candy(vector<int>& ratings) {

    const int n = ratings.size();
    int totalCandies = 0;
    // "Each child must have at least one candy."
    vector<int> leftToRight(n, 1);  // Вектор для хранения количества конфет при проходе слева направо
    vector<int> rightToLeft(n, 1);  // Вектор для хранения количества конфет при проходе справа налево

    // Заполнение вектора leftToRight
    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1])
        leftToRight[i] = leftToRight[i - 1] + 1;
    }


    // Заполнение вектора rightToLeft
    for (int i = n - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1])
        rightToLeft[i] = rightToLeft[i + 1] + 1;
    }


    // Вычисление общего количества конфет
    for (int i = 0; i < n; ++i) {
      totalCandies += max(leftToRight[i], rightToLeft[i]);
    }           

    return totalCandies;
  }


};
