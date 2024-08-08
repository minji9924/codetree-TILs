#include <iostream>
#include <deque>
using namespace std;

int N, M, bomb_size;
deque<pair<int, int>> info;
int bombs[101];

bool is_explode() {
    int flag = 0;
    info.emplace_back(bombs[0], 1);
    if (M == 1) flag = 1;
    for (int i = 1; i < bomb_size; i++) {
        if (bombs[i] == info.back().first && bombs[i] > 0) {
            info.back().second++;
            if (info.back().second >= M) flag = 1;
        }
        else {
            info.emplace_back(bombs[i], 1);
        }
    }
    int curr = 0, s = info.size();
    for (int i = 0; i < s; i++) {
        if (info.front().second >= M) {
            for (int i = curr; i < curr + info.front().second; i++) bombs[i] = 0;

        }
        curr += info.front().second;
        info.pop_front();
    }
    info.clear();
    return flag;
}

void drop() {
    int curr_size = 0, new_bombs[101] = {0};
    for (int i = 0; i < bomb_size; i++) {
        if (bombs[i] != 0) {
            new_bombs[curr_size] = bombs[i];
            curr_size++;
        }
    }
    for (int i = 0; i < N; i++) bombs[i] = new_bombs[i];
    bomb_size = curr_size;
}

int main() {
    cin >> N >> M;
    for (int i = N-1; i >= 0; i--) cin >> bombs[i];
    bomb_size = N;
    while (is_explode()) {
        drop();
        if (bomb_size == 0) break;
    }

    cout << bomb_size << '\n';
    if (bomb_size > 0) {
        for (int i = N-1; i >= 0; i--) {
            if (bombs[i] > 0) cout << bombs[i] << '\n';
        }
    }
    return 0;
}