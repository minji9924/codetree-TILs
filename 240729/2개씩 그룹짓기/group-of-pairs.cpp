#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[2000];
    int mx=0;
    for(int i=0;i<n*2;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n*2);

    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]+arr[2*n-1-i]);
    }
    cout << mx;

    return 0;
}