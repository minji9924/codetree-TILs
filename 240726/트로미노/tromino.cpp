#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int board[201][201];
int max_sum = 0;

int check_block_1(int i, int j) {
    int size1 = 0, size2 = 0, size3 = 0, size4 = 0;
    if (i+1 < N && j+1 < M) {
        size1 = board[i][j] + board[i+1][j] + board[i][j+1];
        size2 = board[i][j] + board[i+1][j] + board[i+1][j+1];
        size3 = board[i][j] + board[i][j+1] + board[i+1][j+1];
    }
    if (i+1 < N && j-1 >= 0) {
        size4 = board[i][j] + board[i+1][j] + board[i+1][j-1];
    }
    return max({size1, size2, size3, size4});
}

int check_block_2(int i, int j) {
    int size1 = 0, size2 = 0;
    if (j+2 < M) size1 = board[i][j] + board[i][j+1] + board[i][j+2];
    if (i+2 < N) size2 = board[i][j] + board[i+1][j] + board[i+2][j];
    return max(size1, size2);

}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        max_sum = max({max_sum, check_block_1(i, j), check_block_2(i, j)});
        // cout << max_sum;
    }
    cout << max_sum;
    return 0;
}