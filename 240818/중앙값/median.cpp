#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;

void median() {
    priority_queue<int> small; // 작은 것중에 제일 큰거
    priority_queue<int, vector<int>, greater<>> big; // 큰거중에 제일 작은거

    cin >> T;
    int pivot, n;
    cin >> n;
    pivot = n; cout<< pivot << ' ';
    for (int i = 2; i <= T; i++) {
        cin >> n;
        if (i % 2 == 0) {
            if (n > pivot) big.push(n);
            else small.push(n);
        }
        else {
            if (n > pivot) {
                if (big.size() > small.size()) {
                    small.push(pivot);
                    int tmp = big.top(); big.pop();
                    pivot = min(n, tmp); big.push(max(n, tmp));
                }
                else big.push(n);
            }
            else {
                if (small.size() > big.size()) {
                    big.push(pivot);
                    int tmp = small.top(); small.pop();
                    pivot = max(n, tmp); small.push(min(n, tmp));
                }
                else small.push(n);
            }
            cout << pivot << ' ';
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        median();
        cout <<  '\n';
    }
    return 0;
}