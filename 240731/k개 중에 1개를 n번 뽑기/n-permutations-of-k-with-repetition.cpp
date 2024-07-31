#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> answer;

void Choose(int num, int max) {
    if (num == N){
        // cout << answer.size();
        for (int i = 0; i < N; i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= max; i++) {
        answer.push_back(i);
        Choose(num+1, max);
        answer.pop_back();
    }
    return;
}

int main() {
    cin >> K >> N;

    Choose(0, K);

    return 0;
}