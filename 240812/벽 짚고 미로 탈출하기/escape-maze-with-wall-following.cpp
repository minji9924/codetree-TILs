//
// Created by Minji Jun on 8/12/24.
//
#include <iostream>
using namespace std;

int N, X, Y;
int board[101][101], vis[101][101][4];
int dx[4] = {0, 1, 0, -1}; // 시계방향 회전
int dy[4] = {1, 0, -1, 0};

int check_forward(int x, int y, int dir) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if (nx < 0 || ny < 0 || nx >= N || ny >= N) return true;
    if (board[nx][ny] == 1) return false;
    else return true;
}
// dir : 0 - 우, 1 - 하, 2 - 좌, 3 - 상
int escape_maze(int x, int y, int dir) {
    int length = 0;

    while (true) {
        if (vis[x][y][dir] == 1) return -1;
        vis[x][y][dir] = 1;

        int nx = x + dx[dir], ny = y + dy[dir]; // 한칸 이동한 위치

        // 전진 방향이 막혀있는 경우
        if (!check_forward(x, y, dir)) {
            if (dir == 0) dir = 3;
            else dir--;
        }

        // 격자 밖이면 탈출
        else if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
            length++;
            return length;
        }

        else {
            int new_dir = (dir + 1) % 4; // 시계방항 회전
            int ndx = nx +dx[new_dir], ndy = ny + dy[new_dir]; // 이동 후 오른쪽 벽 위치

            // 한칸 움직인 위치에서 오른쪽에 짚을 벽이 있다면 한칸 전진
            if (board[ndx][ndy] == 1) {
                x = nx; y = ny;
                length++;
            }
            else {
                x = ndx; y = ndy;
                dir = new_dir;
                length += 2;
            }
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

    int count = escape_maze(X-1, Y-1, 0);
    cout << count;

    return 0;
}