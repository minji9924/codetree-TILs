#include <iostream>
#include <algorithm>
using namespace std;

int N, jump[1001], dp[1001], answer;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> jump[i];

    fill(&dp[0], &dp[1000], -1);
    dp[0] = 0;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (j + jump[j] >= i && dp[j] >= 0) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    // for (int i = 0; i < N; i++) {
    //     cout << dp[i] << ' ';
    // }

    for (int i = 0; i < N; i++) {
        answer = max(answer, dp[i]);
    }
    cout << answer;
    return 0;
}