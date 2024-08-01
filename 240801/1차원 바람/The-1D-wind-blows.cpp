#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, M, Q;
deque<int> building[101];
vector<pair<int, bool>> wind;


void get_input() {
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            int stat; cin >> stat;
            building[i].push_back(stat);
        }

    for (int i = 0; i < Q; i++) {
        int r; char d; cin >> r >> d;
        // 왼쪽 바람 - (L = false), 오른쪽 바람 - (R = true)
        if (d == 'L') d = false;
        else d = true;
        wind.emplace_back(r, d);
    }
}
void move_board(int r, bool d) {
    deque<int> b = building[r];
    if (d == false) { // 왼쪽 바람 -> 오른쪽으로 한칸씩 밀기
        b.push_front(b.back());
        b.pop_back();
    }
    else { // 오른쪽 바람 -> 왼쪽으로 한칸씩 밀기
        b.push_back(b.front());
        b.pop_front();
    }
    building[r] = b;
}

int check_same(int a, int b) {
    for (int i = 0; i < M; i++) {
        if (building[a][i] == building[b][i]) return 1;
    }
    return 0;
}

void blow_wind(int r, bool d) {
    bool orig_dir = d;
    move_board(r, orig_dir);
    // 윗부분 전파
    for (int i = r-1; i >= 0; i--) {
        if (check_same(i+1, i)) {
            d = !d;
            move_board(i, d);
        }
    }
    d = orig_dir;
    // 아랫부분 전파
    for (int i = r+1; i < N; i++) {
        if (check_same(i-1, i)) {
            d = !d;
            move_board(i, d);
        }
    }
}

void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << building[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> Q;

    get_input();

    for (int i = 0; i < Q; i++) {
        int r = wind[i].first-1, d = wind[i].second;
        // r번째 열에 바람이 d 방향으로 붐
        blow_wind(r, d);
    }
    
    print_board();

    return 0;
}