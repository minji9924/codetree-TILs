#include <iostream>
#include <string>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main() {
    int i=0,dir_num=3,nx=0,ny=0;
    string dir;
    cin >> dir;
    for(int j=0;j<dir.size();j++){
        if(dir[j]=='L'){
            dir_num--;
            dir_num=(dir_num+4)%4;
        }
        else if(dir[j]=='R'){
            dir_num++;
            dir_num=dir_num%4;
        }
        if(dir[j]=='F'){
            nx=nx+dx[dir_num];
            ny=ny+dy[dir_num];
        }
    }
    cout << nx << ' ' << ny;
    return 0;
}