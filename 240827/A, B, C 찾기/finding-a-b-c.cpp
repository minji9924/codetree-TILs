#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 7

int main() {
    int a[MAX_N];
    for(int i=0;i<MAX_N;i++){
        cin >> a[i];
    }
    sort(a,a+MAX_N);
    cout << a[0] << ' ' << a[1] << ' ' << a[6]-a[0]-a[1];
    return 0;
}