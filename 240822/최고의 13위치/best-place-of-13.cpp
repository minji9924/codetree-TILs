#include <iostream>
using namespace std;

int main() {
    int n,a[21][21]={0},sum=0,mx=0;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
            if(a[i][j]==1)
                sum++;
            if(a[i][j+1]==1)
                sum++;
            if(a[i][j+2]==1)
                sum++;
            mx=max(sum,mx);
            sum=0;
        }
    }
    cout << mx;
    return 0;
}