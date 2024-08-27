#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n,x[101],y[101],mn=INT_MAX;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int dist=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);
            mn=min(mn,dist);
        }
    }
    cout << mn;
    return 0;
}