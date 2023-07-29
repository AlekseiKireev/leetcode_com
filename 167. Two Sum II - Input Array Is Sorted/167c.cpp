class Solution {
public:
    vector<int> twoSum(const vector<int>& a, int target) {
        for (int i = 0; i < (int)a.size(); i++) {

            int j = (int)(upper_bound(a.begin(), a.end(), target - a[i]) - a.begin()) - 1;

            // if (j != i && j >= 0 && a[j] == target - a[i]) {return { i + 1, j + 1 };} // equiv
            /*
            UPD: сейчас понял что обе моих проверки: j >= 0 и j != i сворачиваются в 0 <= i < j — то есть в видео более сильное утверждение. 
            Получается, у меня теперь только один вопрос: почему имеет место быть j > i всегда? Опять же, имеет место быть уменьшение j на 1...
            */
            assert(j > i); 
            if (a[j] == target - a[i]) {return { i + 1, j + 1 };} 

        }

        throw invalid_argument("no sum target");
        
    }
};
