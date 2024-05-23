class Solution {
public:
    int rand10() {
        int val;
        while(true){

        const int x = rand7();
        const int y = rand7();

        val = x + (y-1)*7;

        if(val <= 40){break;}
        //if(val <= 9){break;} // error
        //if(val <= 10){break;} // working!
    }

    assert(1 <= val <= 40);        
    return 1 + (val)%10;

    }
};
