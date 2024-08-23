#include <iostream>
using namespace std;

int main() {
    int n,a[1005],stn,mn=1000000000,dist=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        stn=i;
        for(int j=1;j<=n;j++){
            if(stn>j)
                dist+=a[j]*(n-(stn-j));
            else
                dist+=a[j]*abs(j-stn);
        }
        mn=min(mn,dist);
        dist=0;
    }
    cout << mn;
    return 0;
}