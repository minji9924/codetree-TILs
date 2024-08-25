#include <iostream>
using namespace std;

int main() {
    int n,k,pos,mnp=10004,mxp=0,score=0,mx=0;
    char c[10005];
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> pos >> c[pos];
        mnp=min(pos,mnp);
        mxp=max(pos,mxp);
    }
    for(int i=1;i<=mxp-k;i++){
        int tmp=k+1;
        while(tmp){
            if(c[i+(k+1)-tmp]=='G')
                score+=1;
            else if(c[i+(k+1)-tmp]=='H')
                score+=2;
            tmp--;
        }
        mx=max(score,mx);
        score=0;
    }  
    cout << mx;
    return 0;
}