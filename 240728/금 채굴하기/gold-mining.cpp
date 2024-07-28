#include <iostream>
#include <algorithm>
using namespace std;

int N, gold, K, answer;
int board[21][21];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int is_gold(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >=N) return 0;
    if (board[x][y] == 1) return 1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> gold;
    
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> board[i][j];
    }
    if (N % 2 == 0) K = N/2;
    else K = (N-1)/2;
    
    int answer = 1;
    for (int k = 1; k <= K; k++) { 
        int cost = k * k + (k+1) * (k+1);
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            int num_gold = 0;
            // 중심점이 i, j 이고 마름모 반지름이 K일 때의 채굴할 수 있는 금의 개수
            for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) {
                if (abs(x - i) + abs(y - j) <= k) num_gold += is_gold(x, y);
            }
            // cout << num_gold << ' ' << cost << ' ' << num_gold * gold << '\n';
            if (num_gold * gold >= cost && num_gold > answer) {
                // cout << k << ' ' << i << ' ' << j << ' ' << num_gold << '\n';
                answer = num_gold;
            }
        }
    }
    cout << answer;

    return 0;
}