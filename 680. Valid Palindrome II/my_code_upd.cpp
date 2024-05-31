class Solution {

/*
Важно, что условие LeftPtr < RightPtr, а не LeftPtr != RightPtr в циклах!
Это можно заметить, например, 
    при s.size() = 5, в определенный момент LeftPtr == RightPtr
    при s.size() = 4 условие LeftPtr != RightPtr вообще не будет выполнено
*/

private:

bool ChechkvalidPalindrome(string_view s, int LeftPtr, int RightPtr){

    for(; LeftPtr < RightPtr; ++LeftPtr, --RightPtr){

        if(s[LeftPtr] != s[RightPtr]){return false;}

    }    
    return true;
}

public:
    bool validPalindrome(string_view s) {
        

        for( int LeftPtr = 0, RightPtr = s.size() - 1; LeftPtr < RightPtr; ++LeftPtr, --RightPtr){

            if(s[LeftPtr] != s[RightPtr]){

                // воспользуется свойством палиндрома: если удалить с конца одинакового размера префикс и постфикс, тогда свойства палиндрома не изменются
                // abceeba || abeecba
                return (ChechkvalidPalindrome(s, LeftPtr + 1, RightPtr) /*удалили символ s[LeftPtr], проверяем  {...,s[LeftPtr + 1] , ..., s[RightPtr],...} на палиндром*/
                                            || 
                        ChechkvalidPalindrome(s, LeftPtr, RightPtr - 1) /*удалили символ s[RightPtr], проверяем {...,s[LeftPtr] , ..., s[RightPtr - 1],...} на палиндром*/
                        );
            }

        }

        // сюда попадаем если ни разу не правдиво услвоие s[LeftPtr] != s[RightPtr], например: abeeba
        return true;
    }
};
