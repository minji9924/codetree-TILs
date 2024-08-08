#include <iostream>
using namespace std;

int main() {
    int n,m,v,t,pos_a[1000020]={0},pos_b[1000020]={0},tmp,ta=0,tb=0,ans=0,flag=0,k=0,time_a=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> v >> t;
        tmp=t;
        while(tmp--){
            ta++;
            pos_a[ta]=pos_a[ta-1]+v;
        }
        time_a+=t;
    }
    for(int i=0;i<m;i++){
        cin >> v >> t;
        tmp=t;
        while(tmp--){
            tb++;
            pos_b[tb]=pos_b[tb-1]+v;
            //cout << "posb: " << pos_b[tb] << '\n';
        }
    }
    for(int i=2;i<time_a;i++){
        if((pos_a[i]>pos_b[i])&&(pos_a[i-1]<=pos_b[i-1])){
            ans++;
        }
        else if((pos_b[i]>pos_a[i])&&(pos_b[i-1]<=pos_a[i-1])){
            ans++;
        }
        //if(pos_a[i]>pos_b[i])
        //    flag=1;
        //else if(pos_b[i]>pos_a[i])
        //    flag=-1;
        //if(k!=flag){
        //    ans++;
            //cout << "i: " << i << " pos_a: "<< pos_a[i] << " pos_b: " << pos_b[i] << '\n';
        //}
        //k=flag;
    }
    cout << ans-1;
    return 0;
}