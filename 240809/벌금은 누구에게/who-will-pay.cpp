#include <iostream>
using namespace std;

int main() {
    int n,m,k,a[100]={0},st,tmp=-1;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> st;
        a[st]++;
        if(a[st]==k){
            tmp=st;
            break;
        }
    }
    cout << tmp;
    return 0;
}