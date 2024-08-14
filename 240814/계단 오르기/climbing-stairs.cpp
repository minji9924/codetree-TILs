#include <iostream>
using namespace std;

int N, dp[1001];

int main() {
    cin >> N;
    dp[2] = 1; dp[3] = 1;
    for (int i = 4; i <= N; i++) {
        dp[i] = (dp[i-3] + dp[i-2]) % 10007;
    }
    cout << dp[N];
    return 0;
}