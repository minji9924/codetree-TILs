#include <iostream>
using namespace std;

int main() {
    int n,tmp=1,a[100],cnt=0,cnt2=0,sum=0;
    cin >> n;
    while(n/10!=0){
        sum+=n%10*tmp;
        n=n/10;
        tmp*=2;
    }
    sum+=n*tmp;
    sum*=17;
    while(sum/2!=0){
        a[cnt2++]=sum%2;
        sum/=2;
    }
    a[cnt2]=sum;
    for(int i=cnt2;i>=0;i--){
        if(i==cnt2 && a[i]==0)
            continue;
        cout << a[i];

    }
    return 0;
}