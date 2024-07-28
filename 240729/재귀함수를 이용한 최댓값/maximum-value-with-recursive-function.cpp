#include <iostream>
using namespace std;
#include <algorithm>

int F(int n){
    if(n==0)
        return 1;
    int k;
    cin >> k;
    int mx = max(F(n-1),k);
    return mx;

}

int main() {
    int n;
    cin >> n;

    cout << F(n);
    return 0;
}