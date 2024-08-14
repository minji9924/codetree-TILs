#include <iostream>
using namespace std;

long long N, dp[1001];

int main() {
    cin >> N;

    dp[0] = 1; dp[1] = 2; dp[2] = 7;
    // 여기에 코드를 작성해주세요.
    for (int i = 3; i <= N; i++) {
        dp[i] = ((dp[i-1] * 2) % 1000000007 + (dp[i-2] * 3) % 1000000007 + (dp[i-3] * 2) % 1000000007) % 1000000007;
    }      
    cout << dp[N];
    return 0;
}