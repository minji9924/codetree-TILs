#include <iostream>
#include <algorithm>
using namespace std;

#define MIN -1

int N, M, board[51][51], dp[51][51];

int in_range(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> board[i][j];
    }
    fill(&dp[0][0], &dp[50][51], MIN);

    dp[0][0] = 1;

    for (int i = 1; i < N; i++) for (int j = 1; j < N; j++) {
        int dest = board[i][j];
        for (int x = 0; x < i; x++) for (int y = 0; y < j; y++) {
            if (board[x][y] < dest && dp[x][y] != MIN) {
                dp[i][j] = dp[x][y] + 1;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (dp[i][j] != MIN) {
            answer = max(answer, dp[i][j]);
        }
    }
    
    cout << answer;
    return 0;
}