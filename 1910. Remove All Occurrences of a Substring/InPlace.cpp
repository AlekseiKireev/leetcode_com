/*
Time complexity: O(nk)
Space complexity: O(1)
*/
class Solution {
public:
    string removeOccurrences(string& Str, string& part) {
	int n = Str.size(), m = part.size();
	int  i, j;
	for (i = 0, j = 0; i < n; i++) {
		Str[j++] = Str[i];
		/*
		 если j больше или равно m, это означает, что мы увидели по крайней мере m элементов, 
   		поэтому мы можем проверить, равна ли подстрока из последних m символов part или нет. 
		 Если оно равно, мы уменьшаем переменную 'j' на m, показывая, что мы удалили эту подстроку, 
   		и теперь мы перепишем символы из индекса j.
		*/
		if (j >= m && Str.substr(j - m, m) == part) {
			j -= m;
		}
	}
	return Str.substr(0, j);        
    }
};
/*
class Solution {
public:
    string removeOccurrences(string& text, string& pattern) {
        int textLength = text.size(), patternLength = pattern.size();
        int writeIndex = 0; // Указатель на текущую позицию в результирующей строке
        
        for (int readIndex = 0; readIndex < textLength; readIndex++) {
            text[writeIndex++] = text[readIndex]; // Перемещаем текущий символ в корректную позицию
            
            // Проверяем, не совпадает ли последняя подстрока с `pattern`
            if (writeIndex >= patternLength && text.substr(writeIndex - patternLength, patternLength) == pattern) {
                writeIndex -= patternLength; // Удаляем подстроку, сдвигая указатель назад
            }
        }
        
        return text.substr(0, writeIndex); // Возвращаем строку без удаленных вхождений `pattern`
    }
};

*/
