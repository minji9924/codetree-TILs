#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> commands;

int main() {
    cin >> N; 
    for (int i = 0; i < N; i++) {
        string com; cin >> com;

        if (com == "push") {
            int A; cin >> A; 
            commands.push(A);
        }
        else if (com == "pop") {
            int m = commands.top(); 
            commands.pop(); 
            cout << m << '\n';
        }
        else if (com == "size") cout << commands.size() << '\n';
        else if (com == "empty") {
            commands.empty() ? cout << "1\n" : cout << "0\n";
        }
        else if (com == "top") cout << commands.top() << '\n';
    }
    return 0;
}