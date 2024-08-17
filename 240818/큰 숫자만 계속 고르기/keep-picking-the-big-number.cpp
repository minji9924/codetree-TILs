#include <iostream>
#include <queue>
using namespace std;

int N, M, answer;
priority_queue<int> number;

int main() {
    cin >> N >> M; 
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        number.push(x);
    }
    for (int i = 0; i < M; i++) {
        int cur_max = number.top() - 1;
        number.pop();
        number.push(cur_max);
    }
    cout << number.top();
    return 0;
}