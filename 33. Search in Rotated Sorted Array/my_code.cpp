class Solution {

private:

int BinarySearch(const vector<int>& a, int target) {

        int left = 0;
        int right = (int)a.size() - 1;

        while (1 != right - left) {
                       
            int mid = (left + right) / 2;
            assert(mid != left && mid != right);

            int sortedLeft, sortedRight, secondLeft, secondRight;
            if (a[left] <= a[mid]) { // "<=" необходим, например, для обработки участков вида: [..., 2,2,2,2,...]
                // is_sorted({left, ..., mid}) == true
                // assert(is_sorted(a.begin() + left, a.begin() + mid + 1)); // https://en.cppreference.com/w/cpp/algorithm/is_sorted // работает, закоментировал чтобы не увеличивать расходы по памяти
                sortedLeft = left;
                sortedRight = mid;
                secondLeft = mid;
                secondRight = right;
            }
            else { // в диапозоне [mid + 1, ..., left*, ..., right] существует is_sorted({left*, ..., right}) == true
                sortedLeft = mid;
                sortedRight = right;
                secondLeft = left;
                secondRight = mid;
            }
            
            if (a[sortedLeft] <= target && target < a[sortedRight]) { // знак "<" в "target < a[sortedRight]" необходим ввиду поддержки инварианта "a[sortedLeft] <= target " чтобы позже обработать случай "(a[left] == target"
                auto It = lower_bound(a.begin() + sortedLeft, a.begin() + sortedRight + 1, target); // " + 1" чтобы поиск была в границах [a.begin() + sortedLeft, a.begin() + sortedRight]
                return (*It == target ? It - a.begin() : -1);
            }
            else {
                left = secondLeft;
                right = secondRight;
            }

            if(a[left] == target) {return left;}
        }
    
    return  -1;
}

public:
    int search(const vector<int>& a, int target) {

        // 3 последующих оператора обработывают случаи вида: Wrong Answer 176 / 195 Input nums = [1,3] target = 3
        // это необходимо для того, чтобы изначально в BinarySearch указатели были указаны на "int left = 0; int right = (int)a.size() - 1;"
        if (a.front() == target ) {return 0;}
        if (a.size() == 1) {return -1;}
        if (a.back() == target) {return (int)a.size() - 1;}

        if(a.front() < a.back()) { // is_sorted(nums) == true
            auto It = lower_bound(a.begin(), a.end(), target); 
            return (It == a.end() || *It != target ? -1 : It - a.begin());
        }

        const int Idx = BinarySearch(a, target);
        return  Idx;

    }
};
