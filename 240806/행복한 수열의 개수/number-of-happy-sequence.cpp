#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v;
    v.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int answer = 0;

    if (m != 1) {
        // 행 확인
        for (int i = 0; i < n; i++) {
            int tmp = 1;
            for (int j = 0; j < n - 1; j++) {
                if (v[i][j] == v[i][j + 1]) tmp++;
                else tmp = 1;

                if (tmp >= m) {
                    answer++;
                    break;
                }
            }
        }

        // 열 확인
        for (int i = 0; i < n; i++) {
            int tmp = 1;
            for (int j = 0; j < n - 1; j++) {
                if (v[j][i] == v[j + 1][i]) tmp++;
                else tmp = 1;

                if (tmp >= m) {
                    answer++;
                    break;
                }
            }
        }
    }
    else {
        answer = 2 * n;
    }

    cout << answer;

    return 0;
}