#include <iostream>
using namespace std;

int main() {
    int N,M,v,t;
    int pos_a[1000002]={0},pos_b[1000002]={0},time=0,flag=0,cnt=0;
    int loc=0;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> v >> t;
        time+=t;
        while(t--){
            pos_a[loc]=v+pos_a[loc-1];
            loc++;
        }
    }
    loc=0;
    for(int i=0;i<M;i++){
        cin >> v >> t;
        while(t--){
            pos_b[loc]=v+pos_b[loc-1];
            loc++;
        }
    }
    for(int i=1;i<=time;i++){
        if((pos_a[i]==pos_b[i]) && (flag!=1)){
            flag=1;
            cnt++;
        }
        else if((pos_a[i]>pos_b[i]) && (flag!=2)){
            flag=2;
            cnt++;
        }
        else if((pos_b[i]>pos_a[i]) && (flag!=3)){
            flag=3;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}