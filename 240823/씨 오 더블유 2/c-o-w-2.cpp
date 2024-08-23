#include <iostream>
using namespace std;

int main() {
    int n,cnt=0;
    string a;
    cin >> n;
    cin >> a;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]=='C' && a[j]=='O' && a[k]=='W')
                    cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}