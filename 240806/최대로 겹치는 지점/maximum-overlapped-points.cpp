#include <iostream>
using namespace std;

int main() {
    int n,x1,x2;
    int x[100]={0};
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x1 >> x2;
        int tmp = x1;
        x[tmp-1]++;
        while(tmp != x2){
            x[(++tmp)-1]++;
        }
    }
    int mx=0;
    for(int i=0;i<100;i++){
        mx=max(mx,x[i]);
    }
    cout << mx;
    return 0;
}