#include <iostream>
using namespace std;

int main() {
    int n,x1,x2,offset=100;
    int a[200] = {0};
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x1 >> x2;
        int tmp=x1;
        while(tmp!=x2){
            a[(tmp++)+offset-1]++;
        }
    }
    int mx=a[0];
    for(int i=1;i<200;i++){
        mx=max(mx,a[i]);
    }
    cout << mx;
    return 0;
}