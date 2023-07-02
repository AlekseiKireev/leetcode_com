class Solution {
public:
    int rand10() {
        
        int Count = 1e9;
        int val;

        while(true){

        const int x = rand7();
        const int y = rand7();

        val = x + (y-1)*7;

        if(val <= 40){break;}

        // воспользуемся псевдо равномерным распределением, чтобы не увеличивать время ожидания ответа. Тем самым можно утверждать, что временная асимптотика в худшем случае O(1)
        if(!Count){

            return 1 + 
        (rand7() + rand7() + rand7() + rand7() + rand7() + rand7() + rand7() + rand7() + rand7() + rand7())%10;
        }
        --Count;

    }

    return 1 + (val - 1)%10;

    }
};
