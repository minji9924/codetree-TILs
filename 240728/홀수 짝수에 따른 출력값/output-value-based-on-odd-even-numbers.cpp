#include <iostream>
using namespace std;

int F(int n){
    if(n==1)
        return 1;
    if(n==0)
        return 0;
    return F(n-2)+n;
}

int main() {
    int n;
    cin >> n;
    cout << F(n);
    return 0;
}