#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,tmp1=0,tmp2=0,tmp3=0,tmp4=0,mx=0,sum=0;
    int s[25];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                tmp1=s[i]%10+s[j]%10+s[k]%10;
                tmp2=(s[i]%100)/10+(s[j]%100)/10+(s[k]%100)/10;
                tmp3=(s[i]%1000)/100+(s[j]%1000)/100+(s[k]%1000)/100;
                tmp4=(s[i]%10000)/1000+(s[j]%10000)/1000+(s[k]%10000)/1000;
                if(tmp1<10 && tmp2<10 && tmp3<10 && tmp4<10)
                    sum=s[i]+s[j]+s[k];
                mx=max(sum,mx);
                sum=0;
            }
        }
    }
    cout << mx;
    return 0;
}