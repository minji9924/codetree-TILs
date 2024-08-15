#include <iostream>
#include <algorithm>
using namespace std;

int N, board[101][101], dp[101][101];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> board[i][j];
    }
    dp[0][N-1] = board[0][N-1];
    for (int i = 1; i < N; i++) dp[i][N-1] = dp[i-1][N-1] + board[i][N-1];
    for (int j = N-2; j >= 0; j--) dp[0][j] = dp[0][j+1] + board[0][j];

    for (int i = 1; i < N; i++) for (int j = N-2; j >= 0; j--) {
        dp[i][j] = min(dp[i-1][j], dp[i][j+1]) + board[i][j];
    }

    cout << dp[N-1][0];
}