#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, board[101][101];
vector<pair<int, int>> dp[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> board[i][j];
        dp[i].emplace_back(board[i][j], board[i][j]);
    }
    
    for (int i = 1; i < N; i++) {
        dp[i][0].first = max(dp[i-1][0].first, board[i][0]);
        dp[i][0].second = min(dp[i-1][0].second, board[i][0]);
        dp[0][i].first = max(dp[0][i-1].first, board[0][i]);
        dp[0][i].second = min(dp[0][i-1].second, board[0][i]);
    }

    for (int i = 1; i < N; i++) for (int j = 1; j < N; j++) {
        pair<int, int> dp1, dp2;
        int diff1 = 0, diff2 = 0;
        // 위
        dp1.first = max(dp[i-1][j].first, board[i][j]);
        dp1.second = min(dp[i-1][j].second, board[i][j]);
        diff1 = dp1.first - dp1.second;
        //왼쪽
        dp2.first = max(dp[i][j-1].first, board[i][j]);
        dp2.second = min(dp[i][j-1].second, board[i][j]);
        diff2 = dp2.first - dp2.second;

        if (diff1 < diff2) dp[i][j] = dp1;
        else dp[i][j] = dp2;
    }

    cout << dp[N-1][N-1].first - dp[N-1][N-1].second;
    return 0;
}