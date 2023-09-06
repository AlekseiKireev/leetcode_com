const int FASTIO = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	bool isAlphaNum(char c) {
		return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9');
	}

	char toLower(char c) {
		if ('A' <= c && c <= 'Z') {
			return char(c - 'A' + 'a');
		}
		else {
			return c;
		}
	}

	bool isPalindrome(const string& s) {
		int i = 0;
		int j = (int)s.size() - 1;

		while (true) {
			while (i < j && !isAlphaNum(s[i])) {
				i++;
			}
			while (i < j && !isAlphaNum(s[j])) {
				j--;
			}

			if (i < j) {

				if (toLower(s[i]) != toLower(s[j])) { return false; }
				i++;
				j--;
			}
			else {
				return true;
			}
		}
	}

};
