#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, X;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X;
        if (X == 0) {
            if (pq.size() == 0) cout << "0\n";
            else {
                cout << pq.top() <<'\n';
                pq.pop();
            }
        }
        else {
            pq.push(X);
        }
    }
    return 0;
}