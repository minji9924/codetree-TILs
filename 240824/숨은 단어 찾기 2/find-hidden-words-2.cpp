#include <iostream>
using namespace std;

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};

int IsRange(int x,int y,int n,int m){
    return (x>=0 && y>=0 && x<m && y<n);
}

int main() {
    int n,m,cnt=0;
    char c[52][52];
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c[i][j];
        }
    } 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int curt=0;
            int curx=j;
            int cury=i;
            if(c[i][j]=='L'){
                for(int k=0;k<8;k++){
                    int nx=curx+dx[k];
                    int ny=cury+dy[k];
                    int nx2=curx+2*dx[k];
                    int ny2=cury+2*dy[k];
                    if(IsRange(nx,ny,n,m) && IsRange(nx2,ny2,n,m) && c[ny][nx]=='E' && c[ny2][nx2]=='E'){
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt;   
    return 0;
}