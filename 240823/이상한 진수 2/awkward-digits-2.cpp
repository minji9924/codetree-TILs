#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    int sum=0,tmp=1,flag=0;
    cin >> a;
    for(int i=0;i<a.size();i++){
        if(a[i]=='0'){
            a[i]='1';
            flag=1;
            break;
        }
    }
    for(int i=a.size()-1;i>=0;i--){
        sum+=tmp*(a[i]-'0');
        tmp*=2;
    }
    if(flag)
        cout << sum;
    else
        cout << sum-1;
    return 0;
}