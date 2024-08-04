#include <iostream>
using namespace std;

int main() {
    int month_2011[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int m1,d1,m2,d2,sum=0;
    cin >> m1 >> d1 >> m2 >> d2;

    int tmp=m1;
    if(m1 != m2)
        sum = month_2011[tmp++]-d1+1;
    else
        sum = d2-d1+1;
    for(int i=0;i<(m2-m1);i++){
        if(tmp == m2){
            sum+=d2;
            break;
        }
        sum += month_2011[tmp++];
    }
    cout << sum;
    return 0;
}