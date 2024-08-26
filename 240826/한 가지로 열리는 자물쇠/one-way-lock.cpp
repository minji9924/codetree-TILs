#include <iostream>
using namespace std;

int main() {
    int n,lck[3],cnt=0;
    cin >> n;
    for(int i=0;i<3;i++){
        cin >> lck[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if((abs(lck[0]-i)<=2) || (abs(lck[1]-j)<=2) || (abs(lck[2]-k)<=2))
                    cnt++;       
            }
        }
    }
    cout << cnt;
    return 0;
}