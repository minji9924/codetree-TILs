#include <iostream>
using namespace std;

int F(int n){
    if(n==1)
        return 2;
    if(n==2)
        return 4;
    
    return F(n-1)*F(n-2)%100;
}

int main() {
    int n;
    cin >> n;
    cout << F(n);
    return 0;
}