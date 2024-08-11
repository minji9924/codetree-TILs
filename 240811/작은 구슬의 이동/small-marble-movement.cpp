#include <iostream>
using namespace std;

int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};

bool InRange(int x,int y,int n){
    return (x>=1 && y>=1 && y<=n && x<=n);
}
int dir_num(char a){
    if(a=='L')
        return 3;
    else if(a=='R')
        return 0;
    else if(a=='U')
        return 1;
    else if(a=='D')
        return 2;
    
}
int main() {
    int n,t,r,c,a[50][50]={0},x,y;
    char dir;
    cin >> n >> t;
    cin >> r >> c >> dir;
    int d = dir_num(dir);
    int rr=r-1;
    int cc=c-1;
    int flag=0;
    while(t--){
        if(!InRange(r+dy[d],c+dx[d],n) && !flag){
            d= 3-d;
            flag=1;
            continue;
        }
        r=r+dy[d];
        c=c+dx[d];
        flag=0;
    }
    cout << r << ' ' << c;
    return 0;
}