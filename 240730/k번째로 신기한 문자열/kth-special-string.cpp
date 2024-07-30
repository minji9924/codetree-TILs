#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string T;
    cin >> T;
    string W[100];
    string tmp[100];
    int cnt = 0;
    int flag = 1;
    for (int i = 0; i < n; i++) {
        cin >> W[i];
        for (int j = 0; j < T.size(); j++) {
            if (W[i][j] != T[j])
                flag = 0;    
        }
        if(flag)
            tmp[cnt++] = W[i];
        flag = 1;
    }
    sort(tmp, tmp + cnt);

    cout << tmp[k-1];

    return 0;
}