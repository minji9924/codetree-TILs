#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, X;
priority_queue<int> pq;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X; pq.push(X);
    }

    while(pq.size() >= 2) {
        int a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        if (a - b != 0) pq.push(abs(a-b));
    }
    if (pq.size() == 1) cout << pq.top();
    else cout << "-1";
    return 0;
}