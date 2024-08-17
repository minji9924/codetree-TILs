#include <iostream>
#include <queue>
using namespace std;

int N, X;
priority_queue<int> pq;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X;
        if (X > 0) pq.push(X);
        else {
            if (pq.size() == 0) cout << "0\n";
            else {
                cout << pq.top() << '\n'; 
                pq.pop();
            }
        }
    }
    return 0;
}