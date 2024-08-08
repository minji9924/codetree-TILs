#include <iostream>
using namespace std;

int main() {
    int n,m,v,t,pos_a[1000020]={0},pos_b[1000020]={0},tmp,ta=0,tb=0,ans=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> v >> t;
        tmp=t;
        while(tmp--){
            ta++;
            pos_a[ta]=pos_a[ta-1]+v;
        }
    }
    for(int i=0;i<n;i++){
        cin >> v >> t;
        tmp=t;
        while(tmp--){
            tb++;
            pos_b[tb]=pos_b[tb-1]+v;
        }
    }
    for(int i=2;i<1000020;i++){
        if((pos_a[i]>pos_b[i])&&(pos_a[i-1]<=pos_b[i-1])){
            ans++;
            cout << i <<'\n';
        }
        else if((pos_b[i]>pos_a[i])&&(pos_b[i-1]<=pos_a[i-1])){
            ans++;
            cout << i <<'\n';
        }
    }
    cout << ans++;
    return 0;
}