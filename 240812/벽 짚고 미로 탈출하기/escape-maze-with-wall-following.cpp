//
// Created by Minji Jun on 8/12/24.
//
#include <iostream>
using namespace std;

int N, X, Y;
int board[101][101];
int dx[4] = {0, 1, 0, -1}; // 시계방향 회전
int dy[4] = {1, 0, -1, 0};

int check_possible() {
    int count = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if ((i == 0 || j == 0 || i == N-1 || j == N-1) && board[i][j] == 1) {
            count++;
        }
    }
    if (count > 0) return 1;
    else return 0;
}

int check_forward(int x, int y, int dir) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if (nx < 0 || ny < 0 || nx >= N-1 || ny >= N) return true;
    if (board[nx][ny] == 1) return false;
    else return true;
}
// dir : 0 - 우, 1 - 하, 2 - 좌, 3 - 상
int escape_maze(int x, int y, int dir) {
    int length = 0;
    while (true) {
        // 전진 방향이 막혀있는 경우
        while (!check_forward(x, y, dir)) {
            dir = (3 - dir) % 4;
        }
        if (length > 0 && x == X-1 && y == Y-1) return -1;
        int nx = x + dx[dir], ny = y + dy[dir]; // 한칸 이동한 위치
        int new_dir = (dir + 1) % 4; // 시계방항 회전
        int ndx = nx +dx[new_dir], ndy = ny + dy[new_dir]; // 이동 후 오른쪽 벽 위치
        // 격자 밖이면 탈출
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
            length++;
            return length;
        }
        // 한칸 움직인 위치에서 오른쪽에 짚을 벽이 있다면 한칸 전진
        else if (board[ndx][ndy] == 1) {
            x = nx; y = ny;
            length++;
        }
        else if (board[ndx][ndy] == 0) {
            x = ndx; y = ndy;
            dir = new_dir;
            length += 2;
        }
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> X >> Y;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        char c; cin >> c;
        if (c == '.') board[i][j] = 0;
        else board[i][j] = 1;
    }
    if (check_possible()) {
        int count = escape_maze(X-1, Y-1, 0);
        cout << count;
    }
    else cout << -1;


    return 0;
}