#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer;
vector<pair<int, int>> lines;
vector<pair<int, int>> choosed_line;

void choose_line(int n) {
    if (n == N) {
        int sum = choosed_line.size();
        answer = max(answer, sum);
        return;
    }
    if (n == 0) {
        choosed_line.push_back(lines[0]);
        choose_line(n+1);
        choosed_line.pop_back();
        choose_line(n+1);
    }
    else {
        // n번째 선분을 선택하거나 - 대신 겹치는지 확인해야함
        if (choosed_line.back().second < lines[n].first) {
            choosed_line.push_back(lines[n]);
            choose_line(n+1);
            choosed_line.pop_back();
        }
        // n번째 선분을 선택하지 않거나
        choose_line(n+1);
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x1, x2; cin >> x1 >> x2;
        lines.emplace_back(x1, x2);
    }
    sort(lines.begin(), lines.end());
    choose_line(0);

    cout << answer;
    return 0;
}