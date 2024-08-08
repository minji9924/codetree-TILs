#include <iostream>
using namespace std;

int main() {
    int x1,y1,x2,y2,s[2000][2000]={0},of=1000,sum=0;
    for(int i=0;i<3;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if(i<=1){
            for(int j=x1;j<x2;j++){
                for(int k=y1;k<y2;k++){
                    s[j+of][k+of]=1;
                    sum++;
                }
            }
        }
        else if(i==2){
            for(int j=x1;j<x2;j++){
                for(int k=y1;k<y2;k++){
                    if(s[j+of][k+of]==1)
                        sum--;
                }
            }
        }
    }
    cout << sum;
    return 0;
}