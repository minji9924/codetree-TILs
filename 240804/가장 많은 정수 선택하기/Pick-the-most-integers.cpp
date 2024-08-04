#include <iostream>
#include <deque>
using namespace std;

int N, D, K, C, diff_num, answer;
int number[300001], diff[300001];
deque<int> cont_num;

int count_diff() {
    int check[300001] = {0}, sum = 0;
    check[C] = 1;
    for (int i = 0; i < K; i++) {
        check[cont_num[i]] = 1;
    }
    for (int i = 0; i <= D; i++) {
        if (check[i]) sum++;
    }
    return sum;
}

int main() {
    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; i++) cin >> number[i];

    for (int i = 0; i < K; i++) cont_num.push_back(number[i]);

    for (int i = K; i < N + K; i++) {
        diff_num = count_diff();
        answer = max(diff_num, answer);
        cont_num.pop_front();
        cont_num.push_back(number[i % N]);
    }

    cout << answer;
    return 0;
}