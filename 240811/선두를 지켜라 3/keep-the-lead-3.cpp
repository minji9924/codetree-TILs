#include <iostream>
using namespace std;

int main() {
    int n,m,v,t,loc=0,time=0,flag=0,cnt=0;
    int pos_a[2000000]={0};
    int pos_b[2000000]={0};
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> v >> t;
        time+=t;
        while(t--){
            loc++;
            pos_a[loc]=pos_a[loc-1]+v;
        }
    }
    loc=0;
    for(int i=0;i<m;i++){
        cin >> v >> t;
        while(t--){
            loc++;
            pos_b[loc]=pos_b[loc-1]+v;
        }
    }

    for(int i=1;i<time;i++){
        if((pos_a[i]==pos_b[i]) && flag!=1){
            cnt++;
            flag=1;
            }
       else if((pos_a[i]>pos_b[i]) && flag!=2){
            cnt++;
            flag=2;
       }
       else if((pos_b[i]>pos_a[i]) && (flag!=3)){
            cnt++;
            flag=3;
    }
    }
    cout << cnt;
    return 0;
}