#include <iostream>
using namespace std;

int main() {
    int n,p[102],sum=0,mn=1000000000;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=abs(i-j)*(p[j]);
        }
        mn=min(sum,mn);
        sum=0;
    }
    cout << mn;
    return 0;
}