#include <iostream>
using namespace std;

int main() {
    int x1,y1,x2,y2,of=1000,s[2000][2000]={0},mxx=0,mxy=0,xx1,yy1,xx2,yy2;
    for(int i=0;i<2;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int p=x1;p<x2;p++){
            for(int q=y1;q<y2;q++){
                if(i==0){
                    xx1=x1+of;
                    yy1=y1+of;
                    xx2=x2+of;
                    yy2=y2+of;
                    s[p+of][q+of]=1;
                }
                else{
                    s[p+of][q+of]=0;
                }
            }
        }
    }
    
    for(int p=xx1;p<xx2;p++){
        for(int q=yy1;q<yy2;q++){
            if(s[p][q]==1){
                mxx = max(mxx,p);
                mxy = max(mxy,q);
            }
        }
    }
    cout << (mxx-xx1+1)*(mxy-yy1+1);
    return 0;
}