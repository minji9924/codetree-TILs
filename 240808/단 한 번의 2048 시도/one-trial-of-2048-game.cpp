#include <iostream>
using namespace std;

int board[4][4], new_board[4][4];;
char dir;

void move(char dir) {
    for (int i = 0; i < 4; i++) {
        int cur_dir = 0;
        for (int j = 0; j < 4; j++) {
            if (dir == 'L') {
                if (board[i][j] > 0) {
                    new_board[i][cur_dir] = board[i][j];
                    cur_dir++;
                }
            }
            else if (dir == 'U') {
                if (board[j][i] > 0) {
                    new_board[cur_dir][i] = board[j][i];
                    cur_dir++;
                }
            }
            else if (dir == 'R') {
                if (board[3-i][3-j] > 0) {
                    new_board[3-i][3-cur_dir] = board[3-i][3-j];
                    cur_dir++;
                }
            }
            else if (dir == 'D') {
                if (board[3-j][3-i] > 0) {
                    new_board[3-cur_dir][3-i] = board[3-j][3-i];
                    cur_dir++;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = new_board[i][j];
            new_board[i][j] = 0;
        }
    }
}

void merge(char dir) {
    move(dir);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (dir == 'L') {
                if (board[i][j] == board[i][j+1]) {
                    board[i][j] *= 2;
                    board[i][j+1] = 0;
                }
            }
            else if (dir == 'U') {
                if (board[j][i] == board[j+1][i]) {
                    board[j][i] *= 2;
                    board[j+1][i] = 0;
                }
            }
            else if (dir == 'R') {
                if (board[3-i][3-j] == board[3-i][2-j]) {
                    board[3-i][3-j] *= 2;
                    board[3-i][2-j] = 0;
                }
            }
            else if (dir == 'D') {
                if (board[3-j][3-i] == board[2-j][3-i]) {
                    board[3-j][3-i] *= 2;
                    board[2-j][3-i] = 0;
                }
            }
        }
    }
    move(dir);
    
}

int main() {
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> board[i][j];
    cin >> dir;

    merge(dir);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}