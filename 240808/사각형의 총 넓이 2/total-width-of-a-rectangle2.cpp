#include <iostream>
using namespace std;

int main() {
    int n,x1,y1,x2,y2,s[300][300]={0},sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int p=x1;p<x2;p++){
            for(int q=y1;q<y2;q++){
                if(s[p][q]!=1){
                    s[p][q]++;
                    sum++;
                }
            }
        }
    }
    cout << sum;
    return 0;
}