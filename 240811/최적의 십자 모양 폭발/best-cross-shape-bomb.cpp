#include <iostream>
using namespace std;

int N, answer = 0;
int board[101][101], cur_board[101][101];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void get_input() {
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> board[i][j];
       cur_board[i][j] = board[i][j];
    }
}

void explode(int r, int c) {
    // phase 1 - 폭발
    int dist = cur_board[r][c]; // 십자 모양의 크기
    cur_board[r][c] = 0;
    for (int d = 0; d < 4; d++) { // 상하좌우 4방향으로 폭발
        int nx = r + dx[d], ny = c + dy[d];
        for (int n = 1; n < dist; n++) {
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
            else {
                cur_board[nx][ny] = 0; nx += dx[d]; ny += dy[d];
            }
        }
    }
    int new_array[101][101] = {0};
    // phase 2 - 중력 작용
    for (int j = 0; j < N; j++) {
        int index = N-1;
        for (int i = N-1; i >= 0; i--) { // 위에서 아래로 떨어짐 -> 아래서부터 채우기
            if (cur_board[i][j] != 0) {
                new_array[index][j] = cur_board[i][j];
                index--;
            }
        }
        for (int i = 0; i < N; i++) {
            cur_board[i][j] = new_array[i][j];
        }
    }
}

int calculate_pair() {
    int sum = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            int p = cur_board[i][j];
            for (int d = 0; d < 4; d++) { // 상하좌우 4방향 검사
                int nx = i + dx[d], ny = j + dy[d];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (cur_board[nx][ny] == p && p > 0) sum++;
            }
        }

    // 보드 원상복구
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            cur_board[i][j] = board[i][j];
        }

    return sum/2;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    get_input();

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            explode(i, j);
            // cout << "board after explosion!\n";
            // for (int i = 0; i < N; i++) {
            //     for (int j = 0; j < N; j++) {
            //         cout << cur_board[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            int sum = calculate_pair();
            answer = max(sum, answer);
        }
    cout << answer;
    return 0;
}