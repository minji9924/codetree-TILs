#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int x, y;
long long cnt;

int main() 
{
    cin >> n;

    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cin >> x >> y;

    // 팀장 확인
    for (int i = 0; i < n; i++) {
        if (v[i] <= x) {
            cnt++;
            v[i] = 0;
        }
        else {
            cnt++;
            v[i] -= x;
        }
    }

    // 팀원 확인
    for (int i = 0; i < n; i++) {
        if (v[i] <= 0) continue;

        cnt += v[i] / y;
        
        if (v[i] % y > 0) cnt++;
    }

    cout << cnt;

    return 0;
}