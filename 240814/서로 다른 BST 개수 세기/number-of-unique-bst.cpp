#include <iostream>
using namespace std;

int N, dp[20];

int main() {
    cin >> N;
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    cout << dp[N];

    return 0;
}