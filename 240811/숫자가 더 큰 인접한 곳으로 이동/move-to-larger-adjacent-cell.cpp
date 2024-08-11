#include <iostream>
#include <vector>
using namespace std;

int N, R, C;
int board[101][101];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int is_valid(int r, int c) {
    // 격자 밖이면 잘못된 범위
    if (r < 0 || c < 0 || r >= N || c >= N) return false;
    else return true;
}

vector<int> can_move(int r, int c) {
    vector<int> answer;
    for (int d = 0; d < 4; d++) {
        // 현재 내 위치 기준으로 상하좌우 중 움직일수 있는 곳이 하나라도 있는지
        int nx = r + dx[d], ny = c + dy[d];
        if (is_valid(nx, ny) && board[r][c] < board[nx][ny]) {
            answer.push_back(1); answer.push_back(nx); answer.push_back(ny);
        }
    }
    answer.push_back(0);
    return answer;
}

void move(int r, int c) {  
    while(true) {
        vector<int> answer = can_move(r, c); 
        if (answer [0]) {
            cout << board[r][c] << ' ';
            r = answer[1], c = answer[2];
        } 
        else break;
    }
    cout << board[r][c];
    
}

int main() {
    cin >> N >> R >> C;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];

    move(R-1, C-1);

    return 0;
}