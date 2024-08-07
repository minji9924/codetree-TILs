#include <iostream>
using namespace std;

int N, blocks[101];
int s1, s2, e1, e2;
int answer;

void remove_block(int s, int e) {

    int new_blocks[101] = {0}, curr_block = 1;

    for (int i = 1; i <= N; i++) {
        if ((i < s || i > e) && (blocks[i] != 0))  {
            new_blocks[curr_block] = blocks[i];
            curr_block++;
        }
    }
    for (int i = 1; i <= N; i++) {
        blocks[i] = new_blocks[i];
    }
    answer = curr_block - 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> blocks[i];
    }

    cin >> s1 >> e1 >> s2 >> e2;

    remove_block(s1, e1);
    remove_block(s2, e2);

    cout << answer << '\n';

    for (int i = 1; i <= N; i++) {
        if (blocks[i] > 0) cout << blocks[i] << '\n';
    }

    return 0;
}