#include <iostream>
#include <algorithm>
using namespace std;

#define X first
#define Y second
// 1) 1번 직사각형 왼쪽 위 꼭짓점, 오른쪽 아래 꼭짓점 좌표 선택 -> 5^4
// 2) 1번 직사각형과 겹치지 않은 2번 직사각형의 왼쪽 위 꼭짓점, 오른쪽 아래 꼭짓점의 좌표 선택
// 겹치지 않으려면 2번 직사각형의 두 꼭짓점이 1번 직사각형의 꼭짓점 밖에 존재해야 함.
// 3) 두 직사각형 내부의 숫자 합 구하기
//
struct square
{
    pair<int, int> left_top;
    pair<int, int> right_btm;
};

int N, M, answer = -1000000000;
int board[10][10];
square s1, s2;

int check_square(square s1, square s2) {
    int s1square[6][6] = {0};
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if (i >= s1.left_top.X && i <= s1.right_btm.X) {
                if (j >= s1.left_top.Y && j <= s1.right_btm.Y) {
                    s1square[i][j] = 1;
                }
            }
        }
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if (i >= s2.left_top.X && i <= s2.right_btm.X) {
                if (j >= s2.left_top.Y && j <= s2.right_btm.Y) {
                    if (s1square[i][j] == 1) return 0;
                }
            }
        }
    return 1;
}
int caculate_sum(square s1, square s2) {
    int sum = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if (i >= s1.left_top.X && i <= s1.right_btm.X) {
            if (j >= s1.left_top.Y && j <= s1.right_btm.Y) {
                sum += board[i][j];
            }
        }
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if (i >= s2.left_top.X && i <= s2.right_btm.X) {
            if (j >= s2.left_top.Y && j <= s2.right_btm.Y) {
                sum += board[i][j];
            }
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            s1.left_top.X = i;
            s1.left_top.Y = j;
            for (int x = i; x < N; x++) for (int y = j; y < M; y++) {
                    s1.right_btm.X = x;
                    s1.right_btm.Y = y;
                    for (int i_ = 0; i_ < N; i_++) for (int j_ = 0; j_ < M; j_++) {
                            s2.left_top.X = i_;
                            s2.left_top.Y = j_;
                            for (int x_ = i_; x_ < N; x_++) for (int y_ = j_; y_ < M; y_++) {
                                    s2.right_btm.X = x_;
                                    s2.right_btm.Y = y_;
                                    if (check_square(s1, s2)) {
//                                        cout << caculate_sum(s1, s2) << '\n';
                                        answer = max(answer, caculate_sum(s1, s2));
                                    }
                                }

                        }
                }
        }
    cout << answer;
    return 0;
}