#include <iostream>
using namespace std;

int N, M, bomb_size;
int bombs[101];

bool is_explode() {
    int before = bombs[0], cont = 1, flag = false;
    for (int i = 1; i < bomb_size; i++) {
        if (bombs[i] == before) {
            cont++;
            if (cont >= M) flag = true;
        }
        else {
            if (cont >= M) {
                for (int x = i-cont; x < i; x++) bombs[x] = 0;
                cont = 1;
            } 
        }
        before = bombs[i];
    }
    if (cont >= M) {
        for (int x = bomb_size - cont; x < bomb_size; x++) bombs[x] = 0;
        cont = 1;
    }
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
    }

    cout << bomb_size << '\n';
    if (bomb_size > 0) {
        for (int i = N-1; i >= 0; i--) {
            if (bombs[i] > 0) cout << bombs[i] << '\n';
        }
    }
    return 0;
}