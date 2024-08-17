#include <iostream>
using namespace std;

int dc[4]={0,1,0,-1};
int dr[4]={1,0,-1,0};

int IsRange(int r,int c,int n,int m){
    return (r>=0 && r<n && c>=0 && c<m);
}

int main() {
    int n,m,cnt=1,dir=0,c=0,r=0;
    int s[100][100]={0};
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            s[r][c]=cnt++;
            if(!IsRange(r+dr[dir],c+dc[dir],n,m) || s[r+dr[dir]][c+dc[dir]] != 0)
                dir=(dir+1)%4;
            r=r+dr[dir];
            c=c+dc[dir];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << s[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}