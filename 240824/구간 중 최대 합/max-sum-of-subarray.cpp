#include <iostream>
using namespace std;

int main() {
    int n,k,a[102],sum=0,mx=0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<=n-k;i++){
        for(int j=i;j<i+k;j++){
            sum+=a[j];
        }
        mx=max(sum,mx);
        sum=0;
    }
    cout << mx;
    return 0;
}