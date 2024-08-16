#include <iostream>
using namespace std;

int N, num[1001], dp[1001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> num[i];

    dp[0] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < N; i++) answer = max(answer, dp[i]);
    cout << answer;

    return 0;
}