#include <iostream>
using namespace std;

struct belt {
    int belt_0[201];
    int belt_1[201];
};

int N, T;
belt init_belt, answer_belt;

belt push_belt(belt init_belt) {
    belt tmp_belt;

    int tmp1 = init_belt.belt_0[N-1];
    int tmp2 = init_belt.belt_1[0];

    for (int i = 1; i < N; i++) tmp_belt.belt_0[i] = init_belt.belt_0[i-1];
    for (int i = 0; i < N-1; i++) tmp_belt.belt_1[i] = init_belt.belt_1[i+1];
    tmp_belt.belt_0[0] = tmp2;
    tmp_belt.belt_1[N-1] = tmp1;

    return tmp_belt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T;
    for (int i = 0; i < N; i++) cin >> init_belt.belt_0[i];
    for (int i = N-1; i >= 0; i--) cin >> init_belt.belt_1[i];

    for (int i = 0; i < T; i++) {
        answer_belt = push_belt(init_belt);
        init_belt = answer_belt;
    }

    for (int i = 0; i < N; i++) cout << answer_belt.belt_0[i] << ' ';
    cout << '\n';
    for (int i = N-1; i >= 0; i--) cout << answer_belt.belt_1[i] << ' ';
    
    return 0;
}