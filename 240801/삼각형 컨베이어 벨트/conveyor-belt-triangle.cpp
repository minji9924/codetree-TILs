#include <iostream>
#include <deque>
using namespace std;

deque<int> triangle[3];
int N, T;

void move_conveyor() {
    int tmp_number = triangle[2].back();

    for (int i = 2; i >= 0; i--) {
        triangle[i].pop_back();
        if (i == 0) {
            triangle[i].push_front(tmp_number);
        }
        else triangle[i].push_front(triangle[i-1].back());
        
        
    }
}

void print_conveyor() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cout << triangle[i].front() << ' ';
            triangle[i].pop_front();
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> T;
    for (int n = 0; n < 3; n++) {
        for (int i = 0; i < N; i++) {
            int num; cin >> num;
            triangle[n].push_back(num);
        }
    }
    
    for (int t = 0; t < T; t++) {
        move_conveyor();
    }

    print_conveyor();
    
    return 0;
}