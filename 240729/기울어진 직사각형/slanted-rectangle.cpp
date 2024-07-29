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
            int k1 = min(i-1, N-j-1); 
            for (int x = 1; x <= k1; x++) {
                // 2, 4번 방향으로 몇번 움직일지
                int k2 = min(i-x, j+x); 
                for (int y = 1; y <= k2; y++) {
                    int sum = 0;
                    
                    for (int k = 0; k <= x; k++) {
                        sum += board[i-k][j+k];
                        sum += board[i-y-k][j-y+k];
                        
                    }
                    for (int k = 1; k < y; k++) {
                        sum += board[i-k][j-k];
                        sum += board[i-x-k][j+x-k];
                        
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