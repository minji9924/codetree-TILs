#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string a,b;
    cin >> a >> b;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int flag=1;
    int i= max(a.size(),b.size());
    while(i--){
        if(a[i] != b[i]){
            flag=0;
            break;
        }
    }
    if(flag)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}