int solve(vector <int> &a) {
    int first_odd_pos = -1; // нечетный
    const int first_even_pos = 0; // четный

    int prefix_sum = 0;
    int ans = 0;
  
    for (int i = 0; i < (int)a.size(); ++i) {
      
        prefix_sum += a[i];
      
        if (prefix_sum % 2) { // сумма нечетная
            if (first_odd_pos != -1) {
              ans = max(ans, i - first_odd_pos + 1);
            }
            else {
              first_odd_pos = i;
            }
        } else { // сумма четная
            ans = max(ans, i - first_even_pos + 1);
        }
    }
  
    return ans;
}
