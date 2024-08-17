#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, sum; double avg;
priority_queue<int, vector<int>, greater<int>> pq;
int numbers[100001];


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    pq.push(numbers[N-1]); 
    sum += (numbers[N-1]);

    for (int i = N-2; i >= 0; i--) {
        pq.push(numbers[i]); sum += numbers[i];
        double cur_sum = (sum - (double)pq.top()) / ((double)pq.size() - 1);
        if (cur_sum > avg) avg = cur_sum;
    }

    printf("%.2lf", avg);
    return 0;
}