#include <iostream>
using namespace std;

int dc[4] = {0,1,0,-1};
int dr[4] = {-1,0,1,0};

int IsRange(int r,int c,int n){
    return (r>=0 && r<n && c>=0 && c<n);
}

int main() {
    int n,t,dir=0,s[100][100]={0};
    char chr[100002];
    cin >> n >> t;
    for(int i=0;i<t;i++)
        cin >> chr[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> s[i][j];
        }
    }
    int r=(n-1)/2,c=(n-1)/2;
    int sum = s[r][c];
    for(int i=0;i<t;i++){
        if(chr[i]=='L')
            dir=(dir-1+4)%4;
        else if(chr[i]=='R')
            dir=(dir+1+4)%4;
        else{
            if(IsRange(r+dr[dir],c+dc[dir],n)){
            r=r+dr[dir];
            c=c+dc[dir];
            sum+=s[r][c];
            }
        }
    }
    cout << sum;
    return 0;
}