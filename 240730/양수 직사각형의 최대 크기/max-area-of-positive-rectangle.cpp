#include <iostream>
#include <algorithm>
using namespace std;

#define X first
#define Y second

struct square
{
    pair<int, int> lt;
    pair<int, int> rb;
};

int N, M, answer;
int board[21][21];
square s1;

int is_positive(square s1) {
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if ((i >= s1.lt.X && i <= s1.rb.X) && (j >= s1.lt.Y && j <= s1.rb.Y)) {
            if (board[i][j] < 0) return 0;
        }
    }
    return 1;
}

int calculate_size(square s1) {
    int size = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if ((i >= s1.lt.X && i <= s1.rb.X) && (j >= s1.lt.Y && j <= s1.rb.Y)) {
            size++;
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> board[i][j];
    }

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        s1.lt.X = i;
        s1.lt.Y = j;
        for (int x = i; x < N; x++) for (int y = j; y < M; y++) {
            s1.rb.X = x;
            s1.rb.Y = y;
            if (is_positive(s1)) {
                answer = max(answer, calculate_size(s1));
            }
        }
    }
    if (answer == 0) cout << -1;
    else cout << answer;
    return 0;
}