#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N, D, K, C, diff_num, answer;
int number[300001];
map<int, int> cont_num;

int main() {
    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; i++) cin >> number[i];

    for (int i = 0; i < K; i++) cont_num.emplace(number[i], 1);

    if (cont_num[C] > 0) cont_num[C]++;
    else cont_num[C] = 1;

    for (int i = K; i < N + K; i++) {

        int size = cont_num.size();
        answer = max(answer, size);

        if (cont_num[number[i-K]] == 1) cont_num.erase(number[i-K]);
        else cont_num[number[i-K]]--;

        if (cont_num[number[i%N]] > 0) cont_num[number[i%N]]++;
        else cont_num[number[i%N]] = 1;

    }

    cout << answer;
    return 0;
}