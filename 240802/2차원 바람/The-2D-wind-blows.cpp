#include <iostream>
#include <vector>
using namespace std;

int N, M, Q;
int board[101][101], new_board[101][101];;
vector<int> winds[101];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void get_input() {

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> board[i][j];
    }
    for (int q = 0; q < Q; q++) {
        for (int i = 0; i < 4; i++) {
            int n; cin >> n;
            winds[q].push_back(n);  
        }   
    }
}

void shift_clockwise(int r1, int c1, int r2, int c2) {
    for (int y = c1+1; y <= c2; y++) { // 위쪽
        new_board[r1][y] = board[r1][y-1];
    }
    for (int x = r1+1; x <= r2; x++) { // 오른쪽
        new_board[x][c2] = board[x-1][c2];
    }
    for (int y = c2-1; y >= c1; y--) { // 아래쪽
        new_board[r2][y] = board[r2][y+1];
    }
    for (int x = r2-1; x >= r1; x--) { // 왼쪽
        new_board[x][c1] = board[x+1][c1];
    }

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        board[i][j] = new_board[i][j];
    }
}

int check_range(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return 0;
    else return 1;
}

void calculate_average(int r1, int c1, int r2, int c2) {
    for (int i = r1; i <= r2; i++) for (int j = c1; j <= c2; j++) {
        int sum = board[i][j], num = 1;
        for (int d = 0; d < 4; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            if (check_range(nx, ny)) {
                sum += board[nx][ny];
                num++;
            }
        }
        new_board[i][j] = sum / num;
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        board[i][j] = new_board[i][j];
    }
}

void move_building(int r1, int c1, int r2, int c2) {
    
    // 기존 상태 복사하기
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        new_board[i][j] = board[i][j];
    }

    // 경계 - 시계방향으로 shift
    shift_clockwise(r1, c1, r2, c2);

    // 전체 - 평균값 계산
    calculate_average(r1, c1, r2, c2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> Q;

    get_input();

    for (int q = 0; q < Q; q++) {
        int r1 = winds[q][0]-1, c1 = winds[q][1]-1;
        int r2 = winds[q][2]-1, c2 = winds[q][3]-1;
        move_building(r1, c1, r2, c2);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}