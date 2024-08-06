#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n,k,a,b;
    int q[100]={0};
    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> a >> b;
        int tmp = a;
        q[tmp-1]++;
        while(tmp != b){
            q[(++tmp)-1]++;
        }
    }
    int mx = q[0];
    for(int i=1;i<n;i++){
        mx = max(mx,q[i]);
    }
    cout << mx;
    return 0;
}