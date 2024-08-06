#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int answer;
vector<vector<int>> v;

int main() 
{
    cin >> n;

    v.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            int tmp = v[i][j] + v[i][j + 1] + v[i][j + 2];
            tmp += v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2];
            tmp += v[i + 2][j] + v[i + 2][j + 1] + v[i + 2][j + 2];

            answer = max(tmp, answer);
        }
    }

    cout << answer;

    return 0;
}