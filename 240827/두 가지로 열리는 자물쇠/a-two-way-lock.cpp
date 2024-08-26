#include <iostream>
using namespace std;

int IsRange(int a,int i,int n){
    return (abs(a-i)<=2 || (((a==n-1) && (i==1))) || (((a==n) && (i<=2))) || (((i==n-1) && (a==1))) || (((i==n) && (a<=2))));
}

int main() {
    int n,a1,b1,c1,a2,b2,c2,cnt=0,cnt1=0,cnt2=0;
    cin >> n;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(IsRange(a1,i,n) && IsRange(b1,j,n) && IsRange(c1,k,n)){
                    cnt1=1;
                }
                else if(IsRange(a2,i,n) && IsRange(b2,j,n) && IsRange(c2,k,n)){
                    cnt1=1;
                }
                if(cnt1 || cnt2)
                    cnt++;
                cnt1=0;
                cnt2=0;
            }
        }
    }
    cout << cnt;
    return 0;
}