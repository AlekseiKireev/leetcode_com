class Solution {
public:
    int rand10() {
        return 1 + 
        (rand7() + rand7() + rand7() + rand7() + rand7() + rand7() + rand7() + rand7() + rand7() + rand7())%10;
    }
};
