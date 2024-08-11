#include <iostream>
using namespace std;

bool InRange(int x,int y,int n){
    //if((x>=0 && x<n) && (y>=0 && y<n))
    //    return 1;
    //return 0;
    return (x>=0 && y>=0 && x<n && y<n);
}
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main() {
    int n,a[100][100]={0},cnt=0,ans=0;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    int tmp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                if(InRange(i+dx[k],j+dy[k],n) && a[i+dx[k]][j+dy[k]]==1){
                    cnt++;
                }
            }
            if(cnt>=3)
                ans++;
            cnt=0;
        }
    }
    cout << ans;
    return 0;
}