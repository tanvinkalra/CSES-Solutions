#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int N = s.length(), M = t.length();
  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, INT_MAX));
  for (int i = 0; i < M; ++i) {
    dp[N][i] = M - i;
  }
  for (int i = 0; i < N; ++i) {
    dp[i][M] = N - i;
  }
  dp[N][M] = 0;
  for (int i = N - 1; i >= 0; --i) {
    for (int j = M - 1; j >= 0; --j) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i + 1][j + 1];
      } else {
        dp[i][j] = 1 + std::min(dp[i + 1][j + 1],
                                std::min(dp[i][j + 1], dp[i + 1][j]));
      }
    }
  }

  std::cout << dp[0][0] << "\n";

  return 0;
}