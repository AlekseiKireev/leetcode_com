class Solution {
public:
    int firstUniqChar(string s) {
  	
	const int power_English_alphabet = 26;
	array<int, power_English_alphabet> char_to_count;
	char_to_count.fill(0);

	for (const char chr : s) {
		++char_to_count[chr - 'a'];
	}

	for (int i = 0; i < s.size(); ++i) {
        // s[i] - 'a' == chr - 'a'
		if (char_to_count[s[i] - 'a'] == 1) { return i; } // "find the first non-repeating character in it and return its index."
	}

	return -1; // " If it does not exist, return -1."
    }
};
