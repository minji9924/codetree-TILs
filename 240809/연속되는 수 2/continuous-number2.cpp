#include <iostream>
using namespace std;

int main() {
    int n,a[1000],cnt=0,mx_cnt=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i==0||a[i]==a[i-1]){
            cnt++;
        }
        else{
            cnt=1;
        }
        mx_cnt=max(cnt,mx_cnt);
    }
    cout << mx_cnt;
    return 0;
}