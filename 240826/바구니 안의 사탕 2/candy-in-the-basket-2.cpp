#include <iostream>
using namespace std;

#define MAX_K 200

// n k
// 사탕 개수, 바구니 좌표

int main() {
    int n,k,cnd,x,bsk[500]={0},mx=0,sum=0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> cnd >> x;
        bsk[x]+=cnd;
    }
    for(int i=k;i<MAX_K-k-1;i++){
        for(int j=i-k;j<=i+k;j++){
            sum+=bsk[j];
        }
        mx=max(sum,mx);
        sum=0;
    }
    cout << mx;
    return 0;
}