#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, board[101][101];
vector<pair<int, int>> dp[101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            dp[i][j].emplace_back(board[i][j], board[i][j]);
        }

    for (int i = 1; i < N; i++) {
        dp[i][0][0].first = max(dp[i-1][0][0].first, board[i][0]);
        dp[i][0][0].second = min(dp[i-1][0][0].second, board[i][0]);
        dp[0][i][0].first = max(dp[0][i-1][0].first, board[0][i]);
        dp[0][i][0].second = min(dp[0][i-1][0].second, board[0][i]);
    }

    for (int i = 1; i < N; i++) for (int j = 1; j < N; j++) {
        pair<int, int> dp1, dp2;
        int diff1 = 10000, diff2 = 10000;
        for (int k = 0; k < dp[i-1][j].size(); k++) {
            // 위
            dp1.first = max(dp[i - 1][j][k].first, board[i][j]);
            dp1.second = min(dp[i - 1][j][k].second, board[i][j]);
            if (k == 1 && diff1 < dp1.first - dp1.second) {
                dp1 = make_pair(max(dp[i - 1][j][0].first, board[i][j]), min(dp[i - 1][j][0].second, board[i][j]));
            }
            diff1 = min(diff1, dp1.first - dp1.second);
        }
        for (int k = 0; k < dp[i][j-1].size(); k++) {
            //왼쪽
            dp2.first = max(dp[i][j - 1][k].first, board[i][j]);
            dp2.second = min(dp[i][j - 1][k].second, board[i][j]);
            if (k == 1 && diff2 < dp2.first - dp2.second) {
                dp2 = make_pair(max(dp[i][j - 1][0].first, board[i][j]), min(dp[i][j - 1][0].second, board[i][j]));
            }
            diff2 = min(diff2, dp2.first - dp2.second);
        }

        if (diff1 < diff2) dp[i][j][0] = dp1;
        else if (diff1 == diff2) {
            dp[i][j][0] = dp1;
            dp[i][j].push_back(dp2);
        }
        else dp[i][j][0] = dp2;

    }

    cout << dp[N-1][N-1][0].first - dp[N-1][N-1][0].second;
    return 0;
}