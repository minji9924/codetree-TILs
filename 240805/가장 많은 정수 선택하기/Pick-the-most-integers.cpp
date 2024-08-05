#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N, D, K, C, answer;
int number[300001];
map<int, int> cont_num;

int main() {
    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; i++) cin >> number[i];

    for (int i = 0; i < K; i++) {
        if (cont_num[number[i]] > 0) cont_num[number[i]]++;
        else cont_num[number[i]] = 1;
    }

    if (cont_num[C] > 0) cont_num[C]++;
    else cont_num[C] = 1;

    for (int i = 0; i < N; i++) {

        int size = cont_num.size();
        answer = max(answer, size);

        int add = i+K;

        if (cont_num[number[i]] > 1) cont_num[number[i]]--;
        else cont_num.erase(number[i]);


        if (cont_num[number[add%N]] > 0) cont_num[number[add%N]]++;
        else cont_num[number[add%N]] = 1;

    }

    cout << answer;
    return 0;
}