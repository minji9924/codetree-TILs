#include <iostream>
#include <string>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int dir_num = 0;

int Dir(char d){
    if(d=='L')
        return -1;
    else if(d=='R')
        return 1;    
}
int main() {
    int n,d,x=0,y=0,cnt=0,flag=0,ans=0;
    string dir;
    cin >> dir;
    for(int i=0;i<dir.size();i++){
        if(dir[i]=='L' || dir[i]=='R')
            dir_num = (dir_num + Dir(dir[i])+4)%4;
        else{
            x+=dx[dir_num];
            y+=dy[dir_num];
        }
        ans++;
        if(x==0 && y==0){
            flag=1;
            break;
        }
    }
    if(flag)
        cout << ans;
    else
        cout << -1;
    return 0;
}