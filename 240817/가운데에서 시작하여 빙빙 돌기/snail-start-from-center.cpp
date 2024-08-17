#include <iostream>
using namespace std;

int dc[4]={1,0,-1,0};
int dr[4]={0,-1,0,1};

int IsRange(int r,int c,int n){
    return (r>=0 && r<n && c>=0 && c<n);
}

int main() {
    int n,r,c,cnt=1;
    int s[100][100]={0},dir=0,tmp=0,tmp2=1,a=1;
    cin >> n;
    r=(n-1)/2;
    c=(n-1)/2;
    for(int i=1;i<=n*n;i++){
            if(a>=(n*2))
                break;
            tmp=(a+1)/2;
            for(int j=0;j<(a+1)/2;j++){
                s[r][c]=cnt++;
                r=r+dr[dir];
                c=c+dc[dir];
            }
            dir=(dir+1)%4;
            a++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << s[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}