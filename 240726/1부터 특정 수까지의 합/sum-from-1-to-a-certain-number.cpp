#include <iostream>
using namespace std;

int main() {
    int sum=0,n;
    cin >> n;
    for(int i=1;i<=n;i++)
        sum += i;
    cout << sum/10;
    return 0;
}