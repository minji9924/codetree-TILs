#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, D, K, C, diff_num, answer;
int number[300001];
set<int> cont_num;

int main() {
    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; i++) cin >> number[i];

    for (int i = 0; i < K; i++) cont_num.insert(number[i]);

    for (int i = K; i < N + K; i++) {
        cont_num.insert(C);
        int size = cont_num.size();
        answer = max(answer, size);
        cont_num.erase(number[i-K]);
        cont_num.insert(number[i]);
    }

    cout << answer;
    return 0;
}