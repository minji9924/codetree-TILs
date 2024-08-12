#include <iostream>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int IsRange(int x,int y,int n){
    return (x>=0 && x<n && y>=0 && y<n);
}

int main() {
    int n,m,r,c,cnt=0;
    int s[101][101]={0};
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> r >> c;
        s[r][c]=1;
        for(int j=0;j<4;j++){
            if(IsRange(r+dx[j],c+dy[j],101) && s[r+dx[j]][c+dy[j]]==1)
                cnt++;
        }
        if(cnt==3)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
        cnt=0;
    }
    
    return 0;
}