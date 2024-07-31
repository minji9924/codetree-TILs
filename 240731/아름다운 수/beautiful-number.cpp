#include <iostream>
using namespace std;

int N, sum = 0, answer;

int beautiful(int n) {
//    cout << n << '\n';
    if (n == 0) {
        sum++;
    }
    for (int i = 1; i <=4; i++) {
        if (n >= i) {
            n -= i;
            beautiful(n);
            n += i;
        }
        else break;
    }
    return 0;
}

int main() {
    cin >> N;
    beautiful(N);
    cout << sum;
    return 0;
}