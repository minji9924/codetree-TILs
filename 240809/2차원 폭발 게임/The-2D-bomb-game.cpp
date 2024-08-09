#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int board[101][101];

pair<int, int> check_range(int x, int y) {
    int count = 1, ori = board[x][y];
    pair<int, int> answer;
    for (int i = x+1; i < N; i++) {
        if (board[i][y] == ori) count++;
        else break;
    }
    if (count >= M) {
        answer.first = 1; answer.second = count;
    }
    return answer;
}

int explode_if_possible(int x, int y) {
    pair<int, int> result = check_range(x, y);
    if (result.first) {
        for (int i = x; i < x + result.second; i++) {
            board[i][y] = 0;
        }
    }
    return result.second;
}

void rearrange_board() {
    int new_board[101][101] = {0};
    for (int j = 0; j < N; j++) {
        int curr = N-1;
        for (int i = N-1; i >= 0; i--) {
            if (board[i][j] > 0) {
                new_board[curr][j] = board[i][j];
                curr--;
            }
        }
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) board[i][j] = new_board[i][j];
}

void explode() {
    // 각 열에 대해서 폭탄 터트리기
    int flag = 1;
    while (flag) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            for (int i = 0; i <= N-M; i++) {
                if (board[i][j] > 0) {
                    int jump = explode_if_possible(i, j);
                    if (jump > 0) count++;
                    if (jump > 1) i += jump-1;

                }
            }
        }
        if (count == 0) flag = 0;
        rearrange_board();
    }
}

void rotate_90() {
    int new_board[101][101] = {0};
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            new_board[j][N-1-i] = board[i][j];
        }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) board[i][j] = new_board[i][j];
    rearrange_board();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];

    for (int i = 0; i < K; i++) {
        explode();
        rotate_90();
        explode();
    }
    int bomb_number = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            if (board[i][j] > 0) bomb_number++;
        }
    cout << bomb_number;
    return 0;
}