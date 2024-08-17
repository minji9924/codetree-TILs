#include <iostream>
using namespace std;

int dc[4]={1,0,-1,0};
int dr[4]={0,-1,0,1};

int IsRange(int r,int c,int n){
    return (r>=0 && r<n && c>=0 && c<n);
}

int main() {
    int n,r,c,cnt=1;
    int s[100][100]={0},dir=0;
    cin >> n;
    r=(n-1)/2;
    c=(n-1)/2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s[r][c]=cnt++;
            if(!IsRange(r+dr[dir],c+dc[dir],n) || s[r+dr[dir]][c+dc[dir]]!=0)
                dir=(dir+1)%4;
            r=r+dr[dir];
            c=c+dc[dir];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << s[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}