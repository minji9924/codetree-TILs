#include <iostream>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main() {
    int n,v,nx=0,ny=0,dir_num=0;
    char d;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> d >> v;
        if(d=='E')
            dir_num=0;
        else if(d=='S')
            dir_num=1;
        else if(d=='W')
            dir_num=2;
        else if(d=='N')
            dir_num=3;
        nx=nx+dx[dir_num]*v;
        ny=ny+dy[dir_num]*v;
    }
    cout << nx << ' ' << ny;
    return 0;
}