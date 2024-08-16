#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000

int N, board[101][101], dp[101][101];
int LowerBound = MAX, UpperBound = -1, answer = MAX;

void get_input() {
    cin >> N;
    
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> board[i][j];
        LowerBound = min(LowerBound, board[i][j]);
        UpperBound = max(UpperBound, board[i][j]);
        
    }
}

void find_path(int LowerBound) {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        dp[i][j] = MAX;
        if (board[i][j] < LowerBound) board[i][j] = MAX;
    }

    dp[0][0] = board[0][0];
    
    for (int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i-1][0], board[i][0]);
        dp[0][i] = max(dp[0][i-1], board[0][i]);
    }

    for (int i = 1; i < N; i++) for (int j = 1; j < N; j++) {
        dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), board[i][j]);
    }

    if (dp[N-1][N-1] != MAX) {
        answer = min(answer, dp[N-1][N-1] - LowerBound);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    get_input();
    
    for (int i = LowerBound; i < UpperBound; i++) {
        find_path(i);
    }

    cout << answer;
}