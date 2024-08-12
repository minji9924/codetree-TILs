#include <iostream>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool InRange(int x,int y,int n){
    return (x>=0 && x<n && y>=0 && y<n);
}

int DirNum(char a){
    if(a=='E')
        return 0;
    else if(a=='W')
        return 1;
    else if(a=='S')
        return 2;
    else
        return 3;
}

int main() {
    int n,dist,dir_num,x=1000,y=1000,cnt=0,flag=0;
    int s[2002][2002]={0};
    char dir;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> dir >> dist;
        dir_num=DirNum(dir);
        for(int j=0;j<dist;j++){
            if(InRange(x+dx[dir_num],y+dy[dir_num],2002)){
                x=x+dx[dir_num];
                y=y+dy[dir_num];
                cnt++;
                
                if(x==1000 && y==1000){
                    flag=1;
                    break;
                }
                s[x][y]=cnt;
            }
            //cout << dir_num << ' ' << x << ' ' << y << ' ' << x+dx[dir_num] << ' ' << y+dy[dir_num] << ' ' << cnt << '\n';
        }
        if(flag)
            break;
    }
    if(flag)
        cout << cnt;
    else
        cout << -1;

    return 0;
}