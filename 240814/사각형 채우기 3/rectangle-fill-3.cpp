#include <iostream>
using namespace std;

long long N, dp[1001], left_dp[1001];

int main() {
    cin >> N;

    dp[0] = 1; dp[1] = 2; dp[2] = 7;
    left_dp[0] = 1; left_dp[1] = 3; left_dp[2] = 10;
    // 여기에 코드를 작성해주세요.
    for (int i = 3; i <= N; i++) {
        dp[i] = ((dp[i-1] * 2) + (dp[i-2] * 3) + (left_dp[i-3] * 2)) % 1000000007;
        left_dp[i] = (dp[i] + left_dp[i-1]) % 1000000007;
    }      
    cout << dp[N];
    return 0;
}