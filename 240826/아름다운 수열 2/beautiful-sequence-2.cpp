#include <iostream>
using namespace std;

int main() {
    int n,m,ans=0,cnt=0;
    int a[101],b[101],ack[101]={0},bck[101]={0};
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<m;j++){
            for(int k=i;k<m+i;k++){
                if(a[k]==b[j] && !bck[j] && !ack[k]){
                    cnt++;
                    bck[j]=1;
                    ack[k]=1;
                    break;
                }
            }
        }
        for(int j=0;j<m;j++){
            bck[j]=0;
        }
        for(int k=i;k<m+i;k++){
            ack[k]=0;
        }        
        if(cnt==m)
            ans++;
        cnt=0;
    }
    cout << ans;
    return 0;
}