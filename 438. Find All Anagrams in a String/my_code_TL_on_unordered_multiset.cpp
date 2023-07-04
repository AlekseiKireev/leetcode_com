class Solution {
 public:

//  p == Angr == Anagram
vector<int> findAnagrams(string S, string Angr) {

    int S_len = S.size();
    int Angr_len = Angr.size();

    if(S_len < Angr_len){return {};} 

    vector<int> Idxs;

    unordered_multiset<char> Window;
    unordered_multiset<char> Anagram;

    for(int i = 0; i < Angr_len; ++i){
        Window.insert(S[i]);
        Anagram.insert(Angr[i]);
    }

    if(Anagram == Window){Idxs.push_back(0);}

    for(int i = Angr_len; i < S_len; ++i){

        Window.erase(Window.find(S[i - Angr_len]));
        Window.insert(S[i]);

        if(Anagram == Window){Idxs.push_back(i - Angr_len + 1);}
    }

    return Idxs;
  }
};
