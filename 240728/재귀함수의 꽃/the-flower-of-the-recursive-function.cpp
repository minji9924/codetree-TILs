#include <iostream>
using namespace std;

void Printnum(int n){
    if(n==0)
        return;
    cout << n << ' ';
    Printnum(n-1);
    cout<< n << ' ';
}

int main() {
    int n;
    cin >> n;
    Printnum(n);
    return 0;
}