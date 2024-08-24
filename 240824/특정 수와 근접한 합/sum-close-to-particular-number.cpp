#include <iostream>
using namespace std;

int main() {
    int n,s,sum=0,a[105],mn=100050;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=0;i<n-1;i++){
        int tmp=sum;
        for(int j=i+1;j<n;j++){
            mn=min(mn,abs(tmp-a[i]-a[j]-s));
        }
    }
    cout << mn;
    return 0;
}