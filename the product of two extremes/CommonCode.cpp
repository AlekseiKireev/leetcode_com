class Solution {
    
pair<int,int> FindExtrem(vector<int>& nums, auto comp, int GlobalExtrem){

    int ExtremF = GlobalExtrem;
    int ExtremS = GlobalExtrem;

    for(int num : nums){
        if(comp(num, 0) && comp(num, ExtremF) ){
            ExtremS = ExtremF;
            ExtremF = num;
        } else if ( comp(num, ExtremS) ) {
            ExtremS =  num;
        }
    }

    return {ExtremF, ExtremS};

}

public:
    int maxProduct(vector<int>& nums) {
        auto [F, S] = FindExtrem(nums, greater<int>(), INT_MIN); // также надо сделать проверку на то, что F, S != INT_MIN
        return (F-1)*(S-1);
    }

};
