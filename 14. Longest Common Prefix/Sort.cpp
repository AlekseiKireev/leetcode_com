class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        int Len = 0;
        sort(v.begin(),v.end());

        int n=v.size();
        string first=v.front(),last=v.back();

        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                break;
            }
            Len++;
        }
        return v.back().substr(0, Len);
    }
};
