#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    int cnt=0;
    cin >> a;
    for(int i=0;i<a.size()-3;i++){
        if(a[i]=='(' && a[i+1]=='('){
            for(int j=i+2;j<a.size();j++){
                if(a[j]==')' && a[j+1]==')')
                    cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}