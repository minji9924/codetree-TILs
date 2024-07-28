#include <iostream>
using namespace std;

int Fact(int n){
    if(n==1)
        return 1;
    int sum = Fact(n-1)+n;
    return sum;
}

int main() {
    int n;
    cin >> n;

    cout << Fact(n);

    return 0;
}