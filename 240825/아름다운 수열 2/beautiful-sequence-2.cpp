#include <iostream>
using namespace std;

int main() {
    int n,m,ans=0,cnt=0;
    int a[101],b[101];
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<m;j++){
            for(int k=i;k<m+i;k++){
                if(a[k]==b[j])
                    cnt++;
            }
        }
        if(cnt==m)
            ans++;
        cnt=0;
    }
    cout << ans;
    return 0;
}