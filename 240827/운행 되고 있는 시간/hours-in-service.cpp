#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n,st[101],ed[101],sum=0,mx=INT_MIN;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> st[i] >> ed[i];
    }
    for(int i=0;i<n;i++){
        int count[1001]={0};
        int cnt=0;
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            for(int k=st[j];k<ed[j];k++){
                count[k]++;
            }
        }
        for(int q=0;q<1001;q++){
            if(count[q])
                cnt++;
        }
        mx=max(cnt,mx);
    }
    cout << mx;
    return 0;
}