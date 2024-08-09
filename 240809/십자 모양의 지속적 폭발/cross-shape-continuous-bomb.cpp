#include <iostream>
using namespace std;

int N, M, bombs[10];
int board[201][201];

void get_input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> board[i][j];
    }
    for (int i = 0; i < M; i++) cin >> bombs[i];
}

void explode(int r, int c) {
    // phase 1 - 폭발
    int dist = board[r][c];
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    board[r][c] = 0;
    for (int d = 0; d < 4; d++) {
        int nx = r + dx[d], ny = c + dy[d];
        for (int n = 1; n < dist; n++) {
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
            else {
                board[nx][ny] = 0; nx += dx[d]; ny += dy[d];
            }
        }   
    }
    int new_array[201][201] = {0};

    // phase 2 - 중력 작용
    for (int j = 0; j < N; j++) {
        int index = N-1;
        for (int i = N-1; i >= 0; i--) {
            if (board[i][j] != 0) {
                new_array[index][j] = board[i][j];
                index--;
            }
        }
        for (int i = 0; i < N; i++) {
            board[i][j] = new_array[i][j];
        }
    }

}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    get_input();

    for (int i = 0; i < M; i++) {
        for (int x = 0; x < N; x++) {
            if (board[x][bombs[i]-1] > 0) {
                explode(x, bombs[i]-1);
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}