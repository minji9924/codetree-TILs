#include <iostream>
using namespace std;

int main() {
    int n,a[20],i=0;
    cin >> n;
    while(n/2 != 0){
        a[i++]=n%2;
        n=n/2;
    }
    a[i]=n;
    if(a[i] !=0)
        cout << a[i];
    for(int j=i-1;j>=0;j--){
        cout << a[j];
    }
    return 0;
}