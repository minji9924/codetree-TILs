#include <iostream>
using namespace std;

int main() {
    int n,b,a[10],i=0;
    cin >> n >> b;
    while(n/b!=0){
        a[i++]=n%b;
        n=n/b;
    }
    a[i] = n%b;
    for(int j=i;j>=0;j--){
        if(a[j]==0)
            continue;
        else
            cout << a[j];
    }
    return 0;
}