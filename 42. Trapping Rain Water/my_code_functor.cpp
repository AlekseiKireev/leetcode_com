class Solution {

struct PreDecrement {
    int operator()(int& x) const {
        return --x;
    }
};

struct PreIncrement {
    int operator()(int& x) const {
        return ++x;
    }
};

int Trap = 0;

void Check(int idxMaxHeight, int Ptr, auto comp, vector<int>& height){

    int IdxLocalMaxHeight = 0;
    for(; idxMaxHeight != Ptr; comp(Ptr)){
        IdxLocalMaxHeight = max(IdxLocalMaxHeight, height[Ptr]);
        Trap += (IdxLocalMaxHeight - height[Ptr]);
    }
}

public:
    int trap(vector<int>& height) {
        
        int idxMaxHeight = ranges::max_element(height) - height.begin();
        Check(idxMaxHeight, 0, PreIncrement(), height);
        Check(idxMaxHeight, height.size() - 1, PreDecrement(), height);

        return Trap;
    }
};
