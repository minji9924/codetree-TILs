#include <iostream>
using namespace std;

int N, M, K;
int board[101][101];

void get_input() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> board[i][j];
    }
}

void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int drop_block(int m, int k) {
    for (int x = 0; x < N-1; x++) {
        for (int y = k; y < k+m; y++) {
            if (board[x+1][y] == 1) return x;
        }
    }
    return N-1;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    get_input();

    int row = drop_block(M, K-1);
    for (int y = K-1; y < K+M-1; y++) board[row][y] = 1;

    print_board();

    return 0;
}