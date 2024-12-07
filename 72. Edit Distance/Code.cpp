class Solution {
 public:
  int minDistance(string word1, string word2) {
    const int m = word1.length();
    const int n = word2.length();
    // dp[i][j] := the minimum number of operations to convert word1[0..i) to word2[0..j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Заполнение первой колонки: преобразование word1[0..i) в пустую строку требует i удалений
    for (int i = 1; i <= m; ++i) {
      dp[i][0] = i;
    }

    // Заполнение первой строки: преобразование пустой строки в word2[0..j) требует j вставок
    for (int j = 1; j <= n; ++j) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          // Если текущие символы совпадают, операции не требуется
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          // dp[i - 1][j - 1]: операция замены
          // dp[i - 1][j]: операция удаления
          // dp[i][j - 1]: операция вставки
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
      }
    }

    return dp[m][n];
  }
};
