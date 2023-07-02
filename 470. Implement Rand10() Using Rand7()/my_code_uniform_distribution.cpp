class Solution {
public:
    int rand10() {
        int val;
        while(true){

        const int x = rand7();
        const int y = rand7();

        val = x + (y-1)*7;

        if(val <= 40){break;}

    }

    return 1 + (val - 1)%10;

    }
};
