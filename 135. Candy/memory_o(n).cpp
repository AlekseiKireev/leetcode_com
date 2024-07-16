class Solution {
public:
  int candy(vector<int>& ratings) {

    printVector("ratings    ", ratings);

    const int n = ratings.size();
    int totalCandies = 0;
    // "Each child must have at least one candy."
    vector<int> leftToRight(n, 1);  // Вектор для хранения количества конфет при проходе слева направо (подсчитваем вес для возвышенностей)
    vector<int> rightToLeft(n, 1);  // Вектор для хранения количества конфет при проходе справа налево (подсчитваем вес для впадин)

    // Заполнение вектора leftToRight
    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1])
        leftToRight[i] = leftToRight[i - 1] + 1;
    }

    printVector("leftToRight", leftToRight);


    // Заполнение вектора rightToLeft
    for (int i = n - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1])
        rightToLeft[i] = rightToLeft[i + 1] + 1;
    }

    printVector("rightToLeft", rightToLeft);


    // Вычисление общего количества конфет
    for (int i = 0; i < n; ++i) {
      totalCandies += max(leftToRight[i], rightToLeft[i]);
    }
            

    return totalCandies;
  }

private:

  // Функция для вывода вектора
  void printVector(const string& name, const vector<int>& vec) const {
    cout << name << ": ";
    for (int num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

};
