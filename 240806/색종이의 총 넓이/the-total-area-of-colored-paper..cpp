#include <iostream>
using namespace std;

int main() {
    int n,a,b,offset=100;
    int q[220][220] = {0,};
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        for(int t=a+offset;t<a+offset+8;t++){
            for(int k=b+offset;k<b+offset+8;k++){
                    if(q[t][k] == 0)
                        q[t][k]++;
            }
        }
    }
    int sum=0;
    for(int i=0;i<201;i++){
        for(int j=0;j<201;j++){
            if(q[i][j] != 0){
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}