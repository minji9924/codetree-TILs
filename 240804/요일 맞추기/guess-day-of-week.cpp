#include <iostream>
#include <string>
using namespace std;

int main() {
    int m1,d1,m2,d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int month_2011[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    string day[7] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    int sum = (month_2011[m2]+d2)-(month_2011[m1]+d1);
    if(sum>=0){
        cout << day[sum%7];
    }
    else{
        while(1){
            sum += 7;
            if(sum>0){
                cout << day[sum];
                break; 
            }
        }
    }
    return 0;
}