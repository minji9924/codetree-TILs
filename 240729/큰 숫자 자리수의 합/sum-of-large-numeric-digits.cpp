#include <iostream>
using namespace std;
int tmp=0;
int F(int n){
    if(n<10)
        return n;

    tmp = F(n/10)+n%10;
    
    return tmp;
}

int main() {
    int a[3];
    int sum=1;
    for(int i=0;i<3;i++){
        cin >> a[i];
        sum *= a[i];
    }
    cout << F(sum);
    return 0;
}