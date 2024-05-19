class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
    vector<int> result;         // Вектор для хранения результатов
    deque<int> windowIndices;   // Дек для хранения индексов элементов в окне

    for (int i = 0; i < nums.size(); ++i) {

      // Удаляем элементы из дек, которые меньше текущего элемента,
      // потому что они не могут быть максимумом в текущем окне
      while (!windowIndices.empty() && nums[windowIndices.back()] < nums[i]) {
        windowIndices.pop_back();
      }


      // сначала pop_back затем push_back затем  pop_front, иначе ошибка!

      // Добавляем текущий индекс в дек
      windowIndices.push_back(i);


      // Удаляем индексы, которые выходят за границы текущего окна
      if (windowIndices.front() <= i - k) {
        windowIndices.pop_front();
      }

      // Добавляем максимальный элемент в результат, когда окно полностью сформировано
      if (i >= k - 1) { // условный оператор чтобы пропустить первые k-1 символов, пропуск ввиду того, что окно не сформировано еще
        result.push_back(nums[windowIndices.front()]);
      }
    }

    return result;
  }
};
