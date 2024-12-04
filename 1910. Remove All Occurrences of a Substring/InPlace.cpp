/*
Time complexity: O(nk)
Space complexity: O(1)
*/
class Solution {
public:
    string removeOccurrences(string& Str, string& part) {
	int n = Str.size(), m = part.size(), i, j;
	for (i = 0, j = 0; i < n; i++) {
		Str[j++] = Str[i];
		if (j >= m && Str.substr(j - m, m) == part)
			j -= m;
	}
	return Str.substr(0, j);        
    }
};
