#include <iostream>
using namespace std;

bool IsRange(int x,int y, int r, int c){
    return (x>=0 && y>=0 && x<r && y<c);
}
int dc[4] = {1,0,-1,0};
int dr[4] = {0,1,0,-1};
int main() {
    int r,c,a[100][100]={0},dir=0,x=0,y=0;
    cin >> r >> c;
    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            a[x][y]=++cnt;
            if(!IsRange(x+dr[dir],y+dc[dir],r,c) || a[x+dr[dir]][y+dc[dir]] !=0 ){
                dir = (dir+1)%4;
            }
            x = x+dr[dir];
            y = y+dc[dir];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << a[i][j]<<' ';
        }
        cout << '\n';
    }


    return 0;
}