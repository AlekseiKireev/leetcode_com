class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
    vector<int> result;         // Вектор для хранения результатов
    result.reserve(nums.size() + 1 - k);
    deque<int> windowIndices;   // Дек для хранения индексов элементов в окне

    for (int i = 0; i < nums.size(); ++i) {

      // Удаляем элементы из дек, которые меньше текущего элемента,
      // потому что они не могут быть максимумом в текущем окне
      // необходим для максимизации фронтового элемента в windowIndices
      while (!windowIndices.empty() && nums[windowIndices.back()] <= nums[i]) { // так ка в дальнейшем положим i, то nums[windowIndices.back()] = nums[i] не нужны!
        windowIndices.pop_back();
      }

      // сначала pop_back затем push_back затем  pop_front, иначе ошибка!

      // Добавляем текущий индекс в дек. Кладется в любом случае так ккак в следующем из окон он может быть локальным максимум
      windowIndices.push_back(i);


      // Удаляем индексы, которые выходят за границы текущего окна в рамках индексов: [i - k + 1, i] --> если windowIndices.front() < i - k + 1 -- удаляем
      if (windowIndices.front() < i - k + 1) { // если элемент windowIndices.front() находится в необходимом окне, то он выйдет за i. Можно заметить на примере 1  3 [-1  -3  5] 3   
        windowIndices.pop_front();
      }

      // "k - 1" ввиду индексов, см. пример, т.е. при i = k - 1 искомое окно уже будет сформировано. Сформировано когда i - k + 1 >= 0
      // Добавляем максимальный элемент в результат, когда окно полностью сформировано
      if (i - k + 1 >= 0) { // условный оператор чтобы пропустить первые k-1 символов, пропуск ввиду того, что окно не сформировано еще
        result.push_back(nums[windowIndices.front()]); // если nums возрастает, то в windowIndices будет один элемент -- забираем front. 
                                          // если тест вида: nums = [-1,-2,42,0,1] k = 3 можно заметить, как индекс 42 упирается в windowIndices.front
      }
      
    }

    return result;
  }
};
