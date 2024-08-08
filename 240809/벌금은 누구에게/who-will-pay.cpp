#include <iostream>
using namespace std;

int main() {
    int n,m,k,a[101]={0},st,tmp=-1;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> st;
        a[st]++;
        if(a[st]==k){
            tmp=st;
        }
    }
    cout << tmp;
    return 0;
}