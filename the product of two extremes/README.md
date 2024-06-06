the minimum product of two numbers in an any numbers array https://www.geeksforgeeks.org/minimum-product-pair-an-array-of-positive-integers/

      #include <iostream>
      #include <vector>
      
      int main() {
        int max1 = INT_MIN, max2 = INT_MIN;
        std::vector<int> s{ 5, 4, 3, 6, 8, 2 };
        for (int i = 0; i < s.size(); ++i) {
          if (s[i] > max1) {
            max2 = max1;
            max1 = s[i];
          }
          else if (s[i] > max2) {
            max2 = s[i];
          }
        }
        std::cout << max1 << ' ' << max2;
      }





      решу эту задачу: https://www.geeksforgeeks.org/minimum-product-pair-an-array-of-positive-integers/ -- только для любых чисел в массиве (как положительных, так и отрицательных) -- реши без явной сортировки на C++
      ANSWER | PHIND-70B MODEL
      Для решения этой задачи без использования явной сортировки, можно модифицировать подход, представленный в исходнике, чтобы он работал с массивами, содержащими как положительные, так и отрицательные числа. Вместо поиска двух минимальных элементов, мы должны искать два числа, произведение которых будет минимальным. Это могут быть два самых маленьких положительных числа или два самых больших отрицательных числа, в зависимости от контекста.
      
      #include <iostream>
      #include <climits>
      #include <algorithm>
      
      using namespace std;
      
      int findMinProduct(int arr[], int n) {
          // Инициализация переменных для хранения двух чисел с минимальным произведением
          long long minProduct = LLONG_MAX;
          int num1 = INT_MAX, num2 = INT_MAX;
          int negNum1 = INT_MIN, negNum2 = INT_MIN;
      
          for (int i = 0; i < n; ++i) {
              // Обновление пары чисел с минимальным произведением среди положительных чисел
              if (arr[i] > 0 && arr[i] <= num1) {
                  num2 = num1;
                  num1 = arr[i];
              } else if (arr[i] > 0 && arr[i] <= num2) {
                  num2 = arr[i];
              }
      
              // Обновление пары чисел с максимальным произведением среди отрицательных чисел
              if (arr[i] < 0 && arr[i] >= negNum1) {
                  negNum2 = negNum1;
                  negNum1 = arr[i];
              } else if (arr[i] < 0 && arr[i] >= negNum2) {
                  negNum2 = arr[i];
              }
          }
      
          // Выбор минимального произведения между парами положительных и отрицательных чисел
          long long posProduct = static_cast<long long>(num1) * num2;
          long long negProduct = static_cast<long long>(negNum1) * negNum2;
          return (posProduct < negProduct)? posProduct : negProduct;
      }
      
      int main() {
          int arr[] = {-10, -20, 30, 40, -50};
          int n = sizeof(arr) / sizeof(arr[0]);
      
          cout << "Минимальное произведение пары чисел: " << findMinProduct(arr, n) << endl;
      
          return 0;
      }
      Этот код сначала ищет две пары чисел: одну из положительных чисел с минимальным произведением (num1, num2) и другую из отрицательных чисел с максимальным произведением (negNum1, negNum2). Затем выбирается минимальное произведение из этих двух пар. Этот метод работает за время O(n), что делает его эффективным для больших массивов.
      
      Shareable 
      SUGGESTIONS
      окей, а как найти максимальлное произведение используя аналогичный алгоритм?
      ANSWER | PHIND-70B MODEL
      Чтобы найти максимальное произведение пары чисел в массиве, содержащем как положительные, так и отрицательные числа, можно использовать следующий алгоритм, который не требует сортировки:
      
      Инициализируйте переменные для хранения двух наибольших положительных чисел и двух наименьших отрицательных чисел.
      Пройдите по массиву, обновляя эти переменные при необходимости.
      После прохода по массиву, вычислите произведения для обоих случаев: произведение двух наибольших положительных чисел и произведение двух наименьших отрицательных чисел (которое будет положительным).
      Верните большее из двух полученных произведений.
      Пример реализации на C++:
      
      #include <iostream>
      #include <climits>
      #include <algorithm>
      
      using namespace std;
      
      long long findMaxProduct(int arr[], int n) {
          // Инициализация переменных для хранения двух наибольших положительных чисел
          long long maxPosProduct = LLONG_MIN;
          int maxPos1 = INT_MIN, maxPos2 = INT_MIN;
      
          // Инициализация переменных для хранения двух наименьших отрицательных чисел
          long long maxNegProduct = LLONG_MIN;
          int minNeg1 = INT_MAX, minNeg2 = INT_MAX;
      
          for (int i = 0; i < n; ++i) {
              // Обновление двух наибольших положительных чисел
              if (arr[i] > maxPos1) {
                  maxPos2 = maxPos1;
                  maxPos1 = arr[i];
              } else if (arr[i] > maxPos2) {
                  maxPos2 = arr[i];
              }
      
              // Обновление двух наименьших отрицательных чисел
              if (arr[i] < 0 && abs(arr[i]) < abs(minNeg1)) {
                  minNeg2 = minNeg1;
                  minNeg1 = arr[i];
              } else if (arr[i] < 0 && abs(arr[i]) < abs(minNeg2)) {
                  minNeg2 = arr[i];
              }
          }
      
          // Вычисление произведений
          maxPosProduct = static_cast<long long>(maxPos1) * maxPos2;
          maxNegProduct = static_cast<long long>(minNeg1) * minNeg2;
      
          // Возвращение максимального произведения
          return max(maxPosProduct, maxNegProduct);
      }
      
      int main() {
          int arr[] = {-10, -20, 30, 40, -50};
          int n = sizeof(arr) / sizeof(arr[0]);
      
          cout << "Максимальное произведение пары чисел: " << findMaxProduct(arr, n) << endl;
      
          return 0;
      }
      Этот код проходит через массив один раз, обновляя переменные для хранения двух наибольших положительных и двух наименьших отрицательных чисел. Затем он вычисляет и сравнивает произведения этих чисел, возвращая наибольшее произведение.
