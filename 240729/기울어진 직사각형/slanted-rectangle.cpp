#include <iostream>
#include <algorithm>
using namespace std;

int N, board[21][21];
int answer = 0;
int check_start(int x, int y) {
    if (x < 2 || x >= N) return 0;
    if (y < 1 || y >= N-1) return 0;
    else return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        // 시작 위치가 i, j일 때
        if (check_start(i, j)) {
            // 1, 3번 방향으로 몇번 움직일지
            int k1 = min(i-1, N-j); 
            for (int x = 1; x <= k1; x++) {
                // 2, 4번 방향으로 몇번 움직일지
                int k2 = min(i-k1, j+k1); 
                for (int y = 1; y <= x; y++) {
                    int sum = 0;
                    for (int k = 0; k <= k1; k++) {
                        sum += board[i-k][j+k];
                        sum += board[i-k2-k][j-k2+k];
                        // cout << board[i-k][j+k] << ' ' << board[i-k2-k][j-k2+k];
                    }
                    for (int k = 1; k < k2; k++) {
                        sum += board[i-k][j-k];
                        sum += board[i-k1-k][j-k1-k];
                        // cout << board[i-k][j-k] << ' ' << board[i-k1-k][j-k1-k];
                    }
                    // cout << "i, j, k1, k2, ans: " << i << ' ' <<  j << ' ' << x << ' ' << y << ' ' << sum <<'\n';
                    answer = max(sum, answer);
                }
            }
        }
    }
    cout << answer;
    return 0;
}