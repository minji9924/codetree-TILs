#include <iostream>
using namespace std;

int IsRange(int x,int y,int n){
    return (x>=0 && x<n && y>=0 && y<n);
}

int main() {
    int a[21][21]={0};
    int win1=0,win2=0,r=0,c=0,tmp=0;
    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++){
            if(j<=15){
                if(a[i][j]==1 && a[i][j+1]==1 && a[i][j+2]==1 && a[i][j+3]==1 && a[i][j+4]==1){
                    win1=1;
                    tmp=1;
                }
                if(a[i][j]==2 && a[i][j+1]==2 && a[i][j+2]==2 && a[i][j+3]==2 && a[i][j+4]==2){
                    win2=1;
                    tmp=1;
                }
            }
            if(i<=15){
                if(a[i][j]==1 && a[i+1][j]==1 && a[i+2][j]==1 && a[i+3][j]==1 && a[i+4][j]==1){
                    win1=1;
                    tmp=2;
                }
                if(a[i][j]==2 && a[i+1][j]==2 && a[i+2][j]==2 && a[i+3][j]==2 && a[i+4][j]==2){
                    win2=1;
                    tmp=2;
                }
            }
            if(i<=15 && j<=15){
                if(a[i][j]==1 && a[i+1][j+1]==1 && a[i+2][j+2]==1 && a[i+3][j+3]==1 && a[i+4][j+4]==1){
                    win1=1;
                    tmp=3;
                }
                if(a[i][j]==2 && a[i+1][j+1]==2 && a[i+2][j+2]==2 && a[i+3][j+3]==2 && a[i+4][j+4]==2){
                    win2=1;
                    tmp=3;
                }
            }
            if(win1 || win2){
                if(tmp==1){
                    r=i;
                    c=j+2;
                }
                else if(tmp==2){
                    r=i+2;
                    c=j;
                }
                else if(tmp==3){
                    r=i+2;
                    c=j+2;
                }
                break;
            }
        }
        if(win1 || win2){
                break;
        }        
    }    
    if(win1==1){
        cout << '1'<<'\n';
        cout << r << ' ' << c;
    }
    else if(win2==1){
        cout << '2'<<'\n';
        cout << r << ' ' << c;
    }
    else
        cout << '0';
    
    return 0;
}