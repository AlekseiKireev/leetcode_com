class Solution {
public:

    vector<vector<int>> merge(vector < vector < int>>& intervals) {

        vector<bool> used(intervals.size(), false);

        vector<vector<int>> ans;

        for (int i = 0; i < (int)intervals.size(); i++) {

            assert(intervals[i][0] <= intervals[i][1]); // <-- "0 <= starti <= endi <= 10^4"

            if (!used[i]) {

                used[i] = true;

                int leftl = intervals[i][0];

                int rightl = intervals[i][1];

                while (true) {

                    bool change = false;

                    for (int j = 0; j < (int)intervals.size(); j++) {

                        int leftJ = intervals[j][0];
                        int rightJ = intervals[j][1];

                        if (!used[j] && !(rightl < leftJ || rightJ < leftl)) {

                            leftl = min(leftl, leftJ);
                            rightl = max(rightl, rightJ);

                            used[j] = true;
                            change = true;

                        }

                    }


                    if (!change) {break;}

                }

                ans.push_back({ leftl, rightl });

            }

        }

        return ans;

    }
};


