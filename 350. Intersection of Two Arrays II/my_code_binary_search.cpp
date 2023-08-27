class Solution {

private:

struct Pair{

int val = -1;
bool IsUsed = false;

};

public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()){return intersect(nums2, nums1);}

        assert(nums1.size() <= nums2.size()); // созданный инвариант необходим по оптимизации по памяти: к nums1 будет применен sort / lower_bound


        sort(nums1.begin(), nums1.end());

        vector<Pair> Upd_nums1;
        Upd_nums1.reserve(nums1.size());

        for(const int num : nums1){
            Upd_nums1.push_back({num, false});
        }

        nums1.clear();


        vector<int> intersection;
        intersection.reserve(nums1.size()); // максимальное количество элементов в пересечении равно размеру минимального множетсва

        for(const int num : nums2){
            
            const auto it = lower_bound(

                Upd_nums1.begin(),
                Upd_nums1.end(),
                num,
                [](const Pair& pair, const int num){
                    return pair.val < num || (pair.val == num && pair.IsUsed ); // возвращается первый false
                }
            );

            if(it !=  Upd_nums1.end() && it->val == num){
                intersection.push_back(num);
                it->IsUsed = true;
            }

        }


        intersection.shrink_to_fit();
        return intersection;

    }
};
