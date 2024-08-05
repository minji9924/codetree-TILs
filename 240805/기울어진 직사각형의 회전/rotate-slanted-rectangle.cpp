#include <iostream>
using namespace std;

int N, R, C, m1, m2, m3, m4, dir;
int board[101][101], new_board[101][101];
int dx[4] = {-1, -1, 1, 1}, dy[4] = {1, -1, -1, 1};

void get_input() {
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    cin >> R >> C >> m1 >> m2 >> m3 >> m4 >> dir;
}

void rotate_board(int dir) {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            new_board[i][j] = board[i][j];
        }
    int x = R-1, y = C-1;
    int move[4] = {m1, m2, m3, m4};
    if (dir == 0) {
        for (int d = 0; d < 4; d++) {
            for (int i = 0; i < move[d]; i++) {
                int nx = x + dx[d], ny = y + dy[d];
                new_board[nx][ny] = board[x][y];
                x = nx, y = ny;
            }

        }
    }
    else {
        for (int d = 3; d >= 0; d--) {
            for (int i = 0; i < move[d]; i++) {
                int nx = x - dx[d], ny = y - dy[d];
                new_board[nx][ny] = board[x][y];
                x = nx, y = ny;
            }
        }
    }
}

void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << new_board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    get_input();

    rotate_board(dir);

    print_board();

    return 0;
}