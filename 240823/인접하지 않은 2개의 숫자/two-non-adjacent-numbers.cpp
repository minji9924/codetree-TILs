#include <iostream>
using namespace std;

int main() {
    int n,a[102],mx=0,sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+2;j<n;j++){
            sum=a[i]+a[j];
            mx=max(sum,mx);
        }
        sum=0;
    }
    cout << mx;
    return 0;
}