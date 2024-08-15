#include <iostream>
using namespace std;

int dc[4]={0,-1,0,1};
int dr[4]={1,0,-1,0};

//i: n으로 나눈 나머지
// n+1의 몫 0 -> [0][i-1]
//       몫 1 -> [i-1][n-1]
//       몫 2 -> [n-1][2-i]
//       몫 3 -> [0][2-i]

int IsRange(int x,int y,int n){
    return (x>=0 && x<n && y>=0 && y<n);
}

int main() {
    int n,k,r,c,arr,dir=-1,cnt=0;
    cin >> n;
    char s[1002][1002];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> s[i][j];
        }
    }
    cin >> k;
    arr = (k-1)/(n);
    if(arr==0){
        r=0;
        c=k%(n)-1;
        dir=0;
    }
    else if(arr==1){
        r=k-n-1;
        c=n-1;
        dir=1;
    }
    else if(arr==2){
        r=n-1;
        c=n*3-k;
        dir=2;
    }
    else{
        r=n*4-k;
        c=0;
        dir=3;
    }
    //cout << arr << ' ' << r << ' ' << c << ' ' << dir << '\n';
    int i=0;
    while(IsRange(r,c,n)){
        //cout << r << ' ' << c << ' ' << dir << '\n';
        if(dir==0){
            //cout << "dir0" << '\n';
            if(s[r][c] == '/'){
                cnt++;
                dir=1;
                r=r+dr[dir];
                c=c+dc[dir];
            }
            else{
                cnt++;
                dir=3;
                r=r+dr[dir];
                c=c+dc[dir];
            }
        }
        else if(dir==1){
            //cout << "dir1" << '\n';
            if(s[r][c] == '/'){
                cnt++;
                dir=0;
                r=r+dr[dir];
                c=c+dc[dir];
            }
            else{
                cnt++;
                dir=2;
                r=r+dr[dir];
                c=c+dc[dir];         
            }
        }
        else if(dir==2){
            //cout << "dir2" << '\n';
            if(s[r][c] == '/'){
                cnt++;
                dir=3;
                r=r+dr[dir];
                c=c+dc[dir];
            }
            else{
                cnt++;
                dir=1;
                r=r+dr[dir];
                c=c+dc[dir];           
            }
        }
        else{
            //cout << "dir3" << '\n';
            if(s[r][c] == '/'){
                cnt++;
                dir=2;
                r=r+dr[dir];
                c=c+dc[dir];
            }
            else{
                cnt++;
                dir=0;
                r=r+dr[dir];
                c=c+dc[dir];            
            }
        }
    }
    cout << cnt;
    return 0;
}