#include <iostream>
#include <deque>
using namespace std;

int answer = 10000000;
deque<char> A_string;

int run_length_encoding() {
    deque<pair<char, int>> encoding;
    encoding.emplace_back(A_string.front(), 1);
    for (int i = 1; i < A_string.size(); i++) {
        if (A_string[i] == encoding.back().first) {
            encoding.back().second++;
        }
        else {
            encoding.emplace_back(A_string[i], 1);
        }
    }
    int sum = encoding.size();

    for (int i = 0; i < encoding.size(); i++) {
        if (encoding[i].second < 10) sum++;
        else sum += 2;
    }

    return sum;

}


int main() {
    string A; cin >> A;
    for (int i = 0; i < A.size(); i++) {
        A_string.push_back(A[i]);
    }

    for (int i = 0; i < A.size(); i++) {
        answer = min(answer, run_length_encoding());
        char back = A_string.back();
        A_string.pop_back();
        A_string.push_front(back);
    }
    cout << answer;

    return 0;
}