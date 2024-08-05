#include <iostream>
#include <string>
using namespace std;

int main() {
    int m1,d1,m2,d2;
    int month_2024[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    cin >> m1 >> d1 >> m2 >> d2;
    string day;
    string day_2024[7] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    cin >> day;
    int cnt=0,i=0,sum=0;
    while(1){
        if(day == day_2024[cnt])
            break;
        cnt++;
    }
    d1+=cnt;
    while(1){
        if(d1>month_2024[m1-1]){
            d1 -= month_2024[m1-1];
            m1++;
        }
        if((m1>=m2 && d1>d2) || (m1 >= 13))
            break;
        i++;
        d1+=7;
    }
    cout << i;
    return 0;
}