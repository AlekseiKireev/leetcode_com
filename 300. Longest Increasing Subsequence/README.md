https://leetcode.com/problems/longest-increasing-subsequence/description/

https://walkccc.me/LeetCode/problems/300/

https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

    For each number in nums, we perform the following steps:
    
    If the number is greater than the last element of the last bucket (i.e., the largest element in the current subsequence), we append the number to the end of the list. This indicates that we have found a longer subsequence.
    Otherwise, we perform a binary search on the list of buckets to find the smallest element that is greater than or equal to the current number. This step helps us maintain the property of increasing elements in the buckets.
    Once we find the position to update, we replace that element with the current number. This keeps the buckets sorted and ensures that we have the potential for a longer subsequence in the future.
    
    Для каждого числа в nums мы выполняем следующие действия:
    
    Если число больше, чем последний элемент последнего сегмента (т.е. самый большой элемент в текущей подпоследовательности), мы добавляем это число в конец списка. Это указывает на то, что мы нашли более длинную подпоследовательность.
    В противном случае мы выполняем бинарный поиск в списке сегментов, чтобы найти наименьший элемент, который больше или равен текущему номеру. Этот шаг помогает нам сохранить свойство увеличения элементов в сегментах.
    Как только мы находим позицию для обновления, мы заменяем этот элемент текущим номером. Это обеспечивает сортировку сегментов и гарантирует, что в будущем у нас будет возможность использовать более длинную подпоследовательность.
