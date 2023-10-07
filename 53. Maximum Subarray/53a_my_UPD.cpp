class Solution {

public:
    int maxSubArray(const vector<int>& nums) {

        // "nums.front()" существует ввиду "1 <= nums.length <= 10^5"
        int CurrentMaxAffixSum = nums.front();
        int TotalMaxAffixSum = nums.front();

        for (size_t i = 1; i < nums.size(); i++) {
            CurrentMaxAffixSum = max(CurrentMaxAffixSum + nums[i], nums[i]); //  Условие CurrentMaxAffixSum проверяет, выгодно ли прибавить новое число к текущей сумме. Делается это исходя из предположения, что nums[i] последний элемент.
            TotalMaxAffixSum = max(TotalMaxAffixSum, CurrentMaxAffixSum);
        }

        return TotalMaxAffixSum;

    }
};

/*
Заметим, что CurrentMaxAffixSum зависит от i.
    При i = 0 есть всего один аффикс, его и записываем
    при i = 1 есть два возможных аффикса: [0,1] и [1] -- один из них, максимальный, и окажется в CurrentMaxAffixSum
    ...
    Положим, CurrentMaxAffixSum верно работает для любого i = n - 1 : n \in |N. 
    
    Докажем, что оно верно работате и для i = n : нам даны элементы из диапозона: [0,1,...,n-1,n]. 
    Известно, что для [0,1,...,n-1] подсчитан верно CurrentMaxAffixSum -- это произошло при обработке i = n - 1.
    Тогда [0,1,...,n-1,n] можно свернуть в [CurrentMaxAffixSum,n] -- тут есть два возможных аффикса: [CurrentMaxAffixSum,n] и [n] -- один из них, максимальный, и окажется в CurrentMaxAffixSum
    Значит, для i = n работает верно. Доказали верность формулы с помощью мат. индукции. 
*/
