#include <iostream>
using namespace std;

int main() {
    int n,a[1000],cnt=0,mxcnt=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i==0 || (a[i-1]*a[i])>0){
            cnt++;
        }
        else{
            cnt=1;
        }
        mxcnt = max(cnt,mxcnt);
    }
    cout << mxcnt;
    return 0;
}