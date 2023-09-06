class Solution {
public:
    bool isValid(string s) {
        while (true) {

            if (s.empty()) {
                return true;
            }
            { size_t pos = s.find("()");
            if (pos != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            }

            {
                size_t pos = s.find("[]");
                if (pos != string::npos) {
                    s.erase(pos, 2);
                    continue;
                }
            }

            {
                size_t pos = s.find("{}");
                if (pos != string::npos) {
                    s.erase(pos, 2);
                    continue;
                }
            }
            return false;
        }

    }
};

