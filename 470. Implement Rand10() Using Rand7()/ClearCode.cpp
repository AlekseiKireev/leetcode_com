class Solution {
public:
    int rand10() {
        int val = 41;
        while(val > 40){

        const int x = rand7();
        const int y = rand7();

        val = x + (y-1)*7;

    }

    assert(1 <= val <= 40);        
    return 1 + (val)%10;

    }
};
