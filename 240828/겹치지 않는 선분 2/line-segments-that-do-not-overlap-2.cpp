#include <iostream>
using namespace std;

int main() {
    int n,x1[101],x2[101],ans=0,cnt=1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x1[i] >> x2[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt=1;
            if(i==j)
                continue;
            if((x1[i]<x1[j] && x2[i]>x2[j]) ||(x1[i]>x1[j] && x2[i]<x2[j])){
                cnt=0;
                break;
            }
            else{
                continue;
            }
        }
        ans+=cnt;
    }
    cout<< ans;
    return 0;
}