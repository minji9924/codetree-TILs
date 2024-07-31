#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, board[21][21], num_bomb, answer = 0;
vector<int> explosion;
vector<pair<int, int>> bomb_list;

int explode(vector<int> explosion) {
    int sum = 0;
    int new_board[21][21] = {0};
    for (int i = 0; i < num_bomb; i++) {
        int type = explosion[i];
        int x = bomb_list[i].first, y = bomb_list[i].second;

        if (new_board[x][y] == 0) sum++;
        new_board[x][y] = 1;

        if (type == 1) {
            int dx[4] = {-2, -1, 1, 2};
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (new_board[x+dx[d]][y] == 0) sum++;
                    new_board[x+dx[d]][y] = 1;
                }
            }
        }
        else if (type == 2) {
            int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (new_board[x+dx[d]][y+dy[d]] == 0) sum++;
                    new_board[x+dx[d]][y+dy[d]] = 1;
                }
            }
        }
        else if (type == 3) {
            int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, -1, 1};
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (new_board[x+dx[d]][y+dy[d]] == 0) sum++;
                    new_board[x+dx[d]][y+dy[d]] = 1;
                }
            }
        }

    }
    return sum;
}

void bomb(int n) {
    // 종료 조건 - 폭탄이 n개 놓인 상태이면 재귀 종료
    if (n == num_bomb) {
        answer = max(answer, explode(explosion));
        return;
    }

    for (int i = 1; i <= 3; i++) {
        explosion.push_back(i);
        n++;
        bomb(n);
        explosion.pop_back();
        n--;
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) bomb_list.emplace_back(i, j);
        }

    num_bomb = bomb_list.size();

    bomb(0);
    cout << answer;

    return 0;
}