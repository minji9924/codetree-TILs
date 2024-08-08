#include <iostream>
using namespace std;

int main() {
    int n,t,a[1000],cnt=0,mx=0;
    cin >> n >> t;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]>t)
            cnt++;
        else{
            cnt=0;
        }
        mx=max(cnt,mx);
    }
    cout << mx;
    return 0;
}