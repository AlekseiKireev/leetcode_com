/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {

public:

    int guessNumber(int n) {
        
        if(n == 2){
            if(guess(1) == 0){return 1;}
            if(guess(2) == 0){return 2;}
        }

        // можно в крайнем случае использовать size_t
        int LeftBorder = 0;
        int RightBorder = n;

        //while(2 != RightBorder - LeftBorder + 1){ // Constraints: "1 <= n <= 2^{31} - 1" -- при таком условии будет переполнение
            while(1 != RightBorder - LeftBorder){

            int Mid = LeftBorder + (RightBorder - LeftBorder) / 2; // Constraints: "1 <= n <= 2^{31} - 1"

            // -1: Your guess is higher than the number I picked (i.e. num > pick).
            if(guess(Mid) == -1){RightBorder = Mid; continue;}

            // 0: your guess is equal to the number I picked (i.e. num == pick).
            if(guess(Mid) == 0){RightBorder = Mid; break;}

            // 1: Your guess is lower than the number I picked (i.e. num < pick).
            if(guess(Mid) == 1){LeftBorder = Mid; continue;}
        }

        return RightBorder;

    }

};
