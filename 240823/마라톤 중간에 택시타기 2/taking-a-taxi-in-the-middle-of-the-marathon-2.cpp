#include <iostream>
using namespace std;

int main() {
    int n,x[2002],y[2002],mn=100000000,dist=0,tmp=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=1;i<n;i++){
        dist+=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
    }
    for(int i=1;i<n-1;i++){
        tmp=dist;
        tmp=(tmp-abs(x[i]-x[i-1])-abs(y[i]-y[i-1])-abs(x[i+1]-x[i])-abs(y[i+1]-y[i])+abs(x[i+1]-x[i-1])+abs(y[i+1]-y[i-1]));
        mn=min(mn,tmp);
    }
    cout << mn;
    return 0;
}