#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, board[501][501], dp[501][501];
vector<tuple<int, int, int>> smallest;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int in_range(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> board[i][j];
        smallest.emplace_back(board[i][j], i, j);
        dp[i][j] = 1;
    }
    sort(smallest.begin(), smallest.end());

    for (int i = 0; i < smallest.size(); i++) {
        int num, x, y;
        num = get<0>(smallest[i]), x = get<1>(smallest[i]), y = get<2>(smallest[i]);
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (in_range(nx, ny) && board[nx][ny] > num) {
                dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
            }
        }
    }
    int answer = 1;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        answer = max(answer, dp[i][j]);
    }

    cout << answer;
    
    return 0;
}