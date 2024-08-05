#include <iostream>
using namespace std;

int main() {
    int n,a[8],sum=0,cnt=0,tmp=1;
    cin >> n;
    while(1){
        if(n/10 == 0)
            break;
        a[cnt]=n%10;
        cnt++;
        n = n/10;
    }
    a[cnt]=n;

    for(int i=0;i<=cnt;i++){
        sum+=a[i]*tmp;
        tmp *=2;
        
    }
    cout << sum;
    return 0;
}