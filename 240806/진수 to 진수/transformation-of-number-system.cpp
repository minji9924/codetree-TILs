#include <iostream>
using namespace std;

int main() {
    int a,b,n,cnt=0,tmp=1,q[100],sum=0;
    cin >> a >> b;
    cin >> n;
    while(n/10!=0){
        sum += n%10*tmp;
        n/=10;
        tmp*=a;
    }
    sum+=n*tmp;
    while(sum/b!=0){
        q[cnt++]=sum%b;
        sum/=b;
    }
    q[cnt]=sum;
    for(int i=cnt;i>=0;i--){
        if(q[i]==0 && i==cnt)
            continue;
        cout << q[i];
    }
    return 0;
}