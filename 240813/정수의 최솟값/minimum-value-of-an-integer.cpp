#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int mn=1000;
    mn = min(a,b);
    mn = min(mn,c);
    cout << mn;
    return 0;
}