#include <iostream>
using namespace std;

int main() {
    int n,a[22][22],sum1=0,sum2=0,mx1=0,mx2=0,r,c,r2,c2;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j]; 
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
             if(a[i][j]==1)
                sum1++;
            if(a[i][j+1]==1)
                sum1++;
            if(a[i][j+2]==1)
                sum1++;
            
            if(mx1<=sum1){
                mx1=max(mx1,sum1);
                r=i;
                c=j;
            }
            sum1=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
            if((((j+2)>=c) && (j<=(c+2))) && r==i) continue;
            else{
                if(a[i][j]==1)
                    sum2++;
                if(a[i][j+1]==1)
                    sum2++;
                if(a[i][j+2]==1)
                    sum2++;       
            }
            if(mx2<sum2){
                mx2=max(mx2,sum2);
                r2=i;
                c2=j;
            }
            sum2=0;        
        }
    }
    cout << mx1+mx2;
    return 0;
}