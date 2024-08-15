#include <iostream>
using namespace std;

int N, board[101][101], dp[101][101];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> board[i][j];
    }
    dp[0][0] = board[0][0];
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i-1][0] + board[i][0];
        dp[0][i] = dp[0][i-1] + board[0][i];
    }
    for (int i = 1; i < N; i++) for (int j = 1; j < N; j++) {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + board[i][j];
    }
    cout << dp[N-1][N-1];
}