#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if((a<11)||(a>=11 && b<11)||(a>=11 && b>=11 & c<11))
        cout << -1;
    int sum = (a-11)*1440+(b-11)*60+(c-11);
    cout << sum;
    return 0;
}